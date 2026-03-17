theApp.EvtMax = -1

import re, os, glob

evntfiles=[]
xssum=0.
effsum=0.
nfiles=0

period="run2"
joboption="900007"
rangelimit=1

if period == "run2":
    energy = "13TeV"
elif period == "run3":
    energy = "13p6TeV"

if joboption == "900001":
    joboption_msg = "pty_17_35"
elif joboption == "900002":
    joboption_msg = "pty_35_70"
elif joboption == "900003":
    joboption_msg = "pty_70_140"
elif joboption == "900004":
    joboption_msg = "pty_140_280"
elif joboption == "900005":
    joboption_msg = "pty_280_500"
elif joboption == "900006":
    joboption_msg = "pty_500_1000"
elif joboption == "900007":
    joboption_msg = "pty_1000_ECMS"
else:
    joboption_msg = "unknown"

dir="/eos/user/d/dcamarer/PostDoc/PMG/SherpaNLO2216/" + energy + "/" + joboption + "_merging/" + joboption + "_parts"
for part in range(1, rangelimit+1):
    evntfile=dir+"/" + period + "_" + joboption + "_part" + str(part) + ".EVNT.root"
    print(f"Checking part {part}: {evntfile}")
    if os.path.exists(evntfile):
        print(f"  → EVNT file exists")
        with open(dir+"/log.generate_part" + str(part)) as logfile:
            line_num = 0
            for line in logfile:
                line_num += 1
                line = line.strip()
                if not line: continue

                # Cross-section
                xsline = re.findall(r'MetaData: cross-section', line)
                if xsline:
                    xsline = line.split(' ')[4]
                    xssum += float(xsline)
                    evntfiles.append(evntfile)
                    nfiles += 1
                    print(f"  → Part {part} (line {line_num}): xs={float(xsline):.2e}, running xssum={xssum:.2e}")
                
                # Filter efficiency
                effline = re.findall(r'MetaData: GenFiltEff', line)
                if effline:
                    effline = line.split(' ')[4]
                    effsum += float(effline)
                    print(f"  → Part {part} (line {line_num}): eff={float(effline):.5f}, running effsum={effsum:.5f}")
    else:
        print(f"  → EVNT file MISSING")
    
    # Print totals ONCE per part, with safety check
    if nfiles > 0:
        print(f"  → Part {part} totals: nfiles={nfiles}, xssum={xssum:.2e}, effsum={effsum:.5f}")
        print(f"  → CrossSection = 1000 * xssum/nfiles * effsum/nfiles = {1000 * xssum/nfiles * effsum/nfiles:.2e} pb")
    else:
        print(f"  → Part {part}: no data found yet")

import AthenaPoolCnvSvc.ReadAthenaPool
svcMgr.EventSelector.InputCollections = evntfiles

from AthenaCommon.AlgSequence import AlgSequence
job = AlgSequence()

from xAODEventInfoCnv.xAODEventInfoCnvConf import xAODMaker__EventInfoCnvAlg
job += xAODMaker__EventInfoCnvAlg()

from Rivet_i.Rivet_iConf import Rivet_i

rivet = Rivet_i()
rivet.Analyses += [ 'ATLAS_2019_I1772071' ]
rivet.RunName = ''
rivet.HistoFile = period + '_' + joboption + '_' + joboption_msg + '.yoda.gz'
print (f"  → CrossSection = {1000 * xssum/float(nfiles) * effsum/float(nfiles)} pb")
rivet.CrossSection = 1000 * xssum/nfiles * effsum/nfiles # The factor 1000 is needed to move from nb to pb
#rivet.IgnoreBeamCheck = True
#rivet.SkipWeights=True
job += rivet

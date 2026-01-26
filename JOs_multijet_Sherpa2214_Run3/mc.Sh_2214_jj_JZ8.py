include("Sherpa_i/Base_Fragment.py")

evgenConfig.description = "QCD 2->2 JZ8"
evgenConfig.keywords = ["SM", "2jet", "LO" ]
evgenConfig.contact  = [ "atlas-generators-sherpa@cern.ch", "matthew.gignac@cern.ch" ]
evgenConfig.nEventsPerJob = 10000
evgenConfig.tune = "CT18NNLO"

genSeq.Sherpa_i.RunCard="""
(run){
 ACTIVE[25]=0;
 PDF_LIBRARY LHAPDFSherpa; PDF_SET CT18NNLO;
 CORE_SCALE QCD;
}(run)

(processes){
 Process 93 93 -> 93 93;
 Enhance_Function: VAR{(PPerp2(p[2])+PPerp2(p[3]))/200};
 Order (*,0);
 Integration_Error 0.02 {2};
 End process;                 
}(processes)

(selector){
 NJetFinder  2  10.0  0.0  0.4  -1  9999.0  10.0
 NJetFinder  1  1650.0  0.0  0.4  -1  9999.0  10.0
}(selector)           
"""

genSeq.Sherpa_i.Parameters += [ "MASS[6]=14000.0", "WIDTH[6]=0" ]
genSeq.Sherpa_i.Parameters += [ "PDF_VARIATIONS=CT18NNLO[all] PDF4LHC21_40_pdfas[all] MMHT2014nnlo68cl MSHT20nnlo_as118 CT14nnlo CT18NNLO_as_0116 CT18NNLO_as_0117 CT18NNLO_as_0119 CT18NNLO_as_0120 CT18ANNLO CT18XNNLO CT18ZNNLO" ]

include ("GeneratorFilters/FindJets.py")
CreateJets(prefiltSeq, 0.6)
AddJetsFilter(filtSeq,runArgs.ecmEnergy, 0.6)
JZSlice(8, filtSeq)

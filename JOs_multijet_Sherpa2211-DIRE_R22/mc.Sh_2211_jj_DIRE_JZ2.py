include("Sherpa_i/Base_Fragment.py")

evgenConfig.description = "pp -> j j @ LO in QCD (no electroweak processes included) using the DIRE parton shower."
evgenConfig.keywords = [ "jets", "dijet", "LO", "QCD", "SM"]
evgenConfig.contact  = [ "javier.llorente.merino@cern.ch"]
evgenConfig.tune = "CT14nnlo + AHADIC"
evgenConfig.nEventsPerJob = 1000

genSeq.Sherpa_i.RunCard="""
(run){
 ACTIVE[25]=0;
 PDF_LIBRARY LHAPDFSherpa; PDF_SET CT14nnlo;
 CORE_SCALE QCD;
 SHOWER_GENERATOR=Dire;
 CSS_FS_AS_FAC 1;
 CSS_FS_PT2MIN 3;
 CSS_IS_AS_FAC 1;
 CSS_IS_PT2MIN 3;
}(run)

(processes){
 Process 93 93 -> 93 93;   
 Order (*,0);
 Integration_Error 0.02 {2};
 End process;                 
}(processes)

(selector){
 NJetFinder  2  10.0  0.0  0.4  -1  999.0  10.0
 NJetFinder  1  33.0  0.0  0.4  -1  999.0  10.0
}(selector)
"""
genSeq.Sherpa_i.Parameters += [ "MASS[6]=14000.0", "WIDTH[6]=0" ]
genSeq.Sherpa_i.Parameters += [ "PDF_VARIATIONS=CT14nnlo[all] MMHT2014nnlo68cl PDF4LHC15_nnlo_30_pdfas[all]" ]

include("GeneratorFilters/FindJets.py") 
CreateJets(prefiltSeq, 0.6)
AddJetsFilter(filtSeq, runArgs.ecmEnergy, 0.6)
include("GeneratorFilters/JetFilter_JZX.py")
JZSlice(2, filtSeq)

include("MC15JobOptions/Sherpa_2.2.5_Base_Fragment.py")
evgenConfig.tune = "CT10"

evgenConfig.description = "QCD: 2 jets in ME (no electro-weak processes included). The CT14NNLO PDF is used with the CT10 tune. The CSSHOWERING is used. Alternative event weighting is computed on-the-fly for a variety of MUR, MUF, and PDF settings."   
evgenConfig.keywords = [ "jets", "dijet", "LO", "QCD", "SM"]
evgenConfig.contact  = [ "cgarner@physics.utoronto.ca"]
evgenConfig.minevents = 100


evgenConfig.process="""
(run){
 ACTIVE[25]=0;
 PDF_LIBRARY LHAPDFSherpa; PDF_SET CT14nnlo;
 CORE_SCALE QCD;
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
 NJetFinder  1  2000.0  0.0  0.4  -1  999.0  10.0
}(selector)           
"""

genSeq.Sherpa_i.Parameters += [
    "PDF_VARIATIONS=NNPDF30_nnlo_as_0118[all] NNPDF30_nnlo_as_0117 NNPDF30_nnlo_as_0119 MMHT2014nnlo68cl CT14nnlo PDF4LHC15_nnlo_30_pdfas[all]",
    ]

include("MC15JobOptions/JetFilterAkt6.py")

filtSeq.QCDTruthJetFilter.MinPt = 3200*GeV
filtSeq.QCDTruthJetFilter.MaxPt = 7000*GeV




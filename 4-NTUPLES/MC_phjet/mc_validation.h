   // Declaration of leaf types
   UInt_t          RunNumber;
   ULong64_t       EventNumber;
   UInt_t          ChannelNumber;
   Double_t        weightmc;
   vector<double>  *weightmcVAR;
   Double_t        weightmc_p;
   Int_t           ID_hardbrem;
   Int_t           ph_g1;
   Double_t        PhotgET;
   Double_t        PhotgETA;
   Double_t        PhotgPHI;
   Double_t        PhotgETISO_40;
   Double_t        PhotgETISO_30;
   Double_t        PhotgETISO_20;
   Double_t        PartongET;
   Double_t        PartongETA;
   Double_t        PartongRAP;
   Double_t        PartongPHI;
   Double_t        PartongTHETA;
   Double_t        PartongE;
   Double_t        PartongPTX;
   Double_t        PartongPTY;
   Double_t        PartongPTZ;
   Double_t        PartongM;
   Double_t        PartongDelR;
   Double_t        PartongPDGID;
   Double_t        PartongSTATUS;
   Double_t        PartongANCESTORN;
   Int_t           MEParton_num;
   vector<double>  *MEPartonPT;
   vector<double>  *MEPartonETA;
   vector<double>  *MEPartonRAP;
   vector<double>  *MEPartonPHI;
   vector<double>  *MEPartonE;
   vector<double>  *MEPartonM;
   vector<double>  *MEPartonPDG;
   Double_t        MEParton_htsum;
   Int_t           jet_g1;
   vector<double>  *JettPT;
   vector<double>  *JettETA;
   vector<double>  *JettRAP;
   vector<double>  *JettPHI;
   vector<double>  *JettE;
   vector<double>  *JettM;
   vector<double>  *JettPX;
   vector<double>  *JettPY;
   vector<double>  *JettPZ;
   vector<int>     *JettLABELID;
   Double_t        rho_truth_isocentral;
   Double_t        rho_truth_isoforward;
   Double_t        rho_truth_isocentral_sigma;
   Double_t        rho_truth_isoforward_sigma;

   // List of branches
   TBranch        *b_RunNumber;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_ChannelNumber;   //!
   TBranch        *b_weightmc;   //!
   TBranch        *b_weightmcVAR;   //!
   TBranch        *b_weightmc_p;   //!
   TBranch        *b_ID_hardbrem;   //!
   TBranch        *b_ph_g1;   //!
   TBranch        *b_PhotgET;   //!
   TBranch        *b_PhotgETA;   //!
   TBranch        *b_PhotgPHI;   //!
   TBranch        *b_PhotgETISO_40;   //!
   TBranch        *b_PhotgETISO_30;   //!
   TBranch        *b_PhotgETISO_20;   //!
   TBranch        *b_PartongET;   //!
   TBranch        *b_PartongETA;   //!
   TBranch        *b_PartongRAP;   //!
   TBranch        *b_PartongPHI;   //!
   TBranch        *b_PartongTHETA;   //!
   TBranch        *b_PartongE;   //!
   TBranch        *b_PartongPTX;   //!
   TBranch        *b_PartongPTY;   //!
   TBranch        *b_PartongPTZ;   //!
   TBranch        *b_PartongM;   //!
   TBranch        *b_PartongDelR;   //!
   TBranch        *b_PartongPDGID;   //!
   TBranch        *b_PartongSTATUS;   //!
   TBranch        *b_PartongANCESTORN;   //!
   TBranch        *b_MEParton_num;   //!
   TBranch        *b_MEPartonPT;   //!
   TBranch        *b_MEPartonETA;   //!
   TBranch        *b_MEPartonRAP;   //!
   TBranch        *b_MEPartonPHI;   //!
   TBranch        *b_MEPartonE;   //!
   TBranch        *b_MEPartonM;   //!
   TBranch        *b_MEPartonPDG;   //!
   TBranch        *b_MEParton_htsum;   //!
   TBranch        *b_jet_g1;   //!
   TBranch        *b_JettPT;   //!
   TBranch        *b_JettETA;   //!
   TBranch        *b_JettRAP;   //!
   TBranch        *b_JettPHI;   //!
   TBranch        *b_JettE;   //!
   TBranch        *b_JettM;   //!
   TBranch        *b_JettPX;   //!
   TBranch        *b_JettPY;   //!
   TBranch        *b_JettPZ;   //!
   TBranch        *b_JettLABELID;   //!
   TBranch        *b_rho_truth_isocentral;   //!
   TBranch        *b_rho_truth_isoforward;   //!
   TBranch        *b_rho_truth_isocentral_sigma;   //!
   TBranch        *b_rho_truth_isoforward_sigma;   //!

   // Set object pointer
   weightmcVAR = 0;
   MEPartonPT = 0;
   MEPartonETA = 0;
   MEPartonRAP = 0;
   MEPartonPHI = 0;
   MEPartonE = 0;
   MEPartonM = 0;
   MEPartonPDG = 0;
   JettPT = 0;
   JettETA = 0;
   JettRAP = 0;
   JettPHI = 0;
   JettE = 0;
   JettM = 0;
   JettPX = 0;
   JettPY = 0;
   JettPZ = 0;
   JettLABELID = 0;

   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("ChannelNumber", &ChannelNumber, &b_ChannelNumber);
   fChain->SetBranchAddress("weightmc", &weightmc, &b_weightmc);
   fChain->SetBranchAddress("weightmcVAR", &weightmcVAR, &b_weightmcVAR);
   fChain->SetBranchAddress("weightmc_p", &weightmc_p, &b_weightmc_p);
   fChain->SetBranchAddress("ID_hardbrem", &ID_hardbrem, &b_ID_hardbrem);
   fChain->SetBranchAddress("ph_g1", &ph_g1, &b_ph_g1);
   fChain->SetBranchAddress("PhotgET", &PhotgET, &b_PhotgET);
   fChain->SetBranchAddress("PhotgETA", &PhotgETA, &b_PhotgETA);
   fChain->SetBranchAddress("PhotgPHI", &PhotgPHI, &b_PhotgPHI);
   fChain->SetBranchAddress("PhotgETISO_40", &PhotgETISO_40, &b_PhotgETISO_40);
   fChain->SetBranchAddress("PhotgETISO_30", &PhotgETISO_30, &b_PhotgETISO_30);
   fChain->SetBranchAddress("PhotgETISO_20", &PhotgETISO_20, &b_PhotgETISO_20);
   fChain->SetBranchAddress("PartongET", &PartongET, &b_PartongET);
   fChain->SetBranchAddress("PartongETA", &PartongETA, &b_PartongETA);
   fChain->SetBranchAddress("PartongRAP", &PartongRAP, &b_PartongRAP);
   fChain->SetBranchAddress("PartongPHI", &PartongPHI, &b_PartongPHI);
   fChain->SetBranchAddress("PartongTHETA", &PartongTHETA, &b_PartongTHETA);
   fChain->SetBranchAddress("PartongE", &PartongE, &b_PartongE);
   fChain->SetBranchAddress("PartongPTX", &PartongPTX, &b_PartongPTX);
   fChain->SetBranchAddress("PartongPTY", &PartongPTY, &b_PartongPTY);
   fChain->SetBranchAddress("PartongPTZ", &PartongPTZ, &b_PartongPTZ);
   fChain->SetBranchAddress("PartongM", &PartongM, &b_PartongM);
   fChain->SetBranchAddress("PartongDelR", &PartongDelR, &b_PartongDelR);
   fChain->SetBranchAddress("PartongPDGID", &PartongPDGID, &b_PartongPDGID);
   fChain->SetBranchAddress("PartongSTATUS", &PartongSTATUS, &b_PartongSTATUS);
   fChain->SetBranchAddress("PartongANCESTORN", &PartongANCESTORN, &b_PartongANCESTORN);
   fChain->SetBranchAddress("MEParton_num", &MEParton_num, &b_MEParton_num);
   fChain->SetBranchAddress("MEPartonPT", &MEPartonPT, &b_MEPartonPT);
   fChain->SetBranchAddress("MEPartonETA", &MEPartonETA, &b_MEPartonETA);
   fChain->SetBranchAddress("MEPartonRAP", &MEPartonRAP, &b_MEPartonRAP);
   fChain->SetBranchAddress("MEPartonPHI", &MEPartonPHI, &b_MEPartonPHI);
   fChain->SetBranchAddress("MEPartonE", &MEPartonE, &b_MEPartonE);
   fChain->SetBranchAddress("MEPartonM", &MEPartonM, &b_MEPartonM);
   fChain->SetBranchAddress("MEPartonPDG", &MEPartonPDG, &b_MEPartonPDG);
   fChain->SetBranchAddress("MEParton_htsum", &MEParton_htsum, &b_MEParton_htsum);
   fChain->SetBranchAddress("jet_g1", &jet_g1, &b_jet_g1);
   fChain->SetBranchAddress("JettPT", &JettPT, &b_JettPT);
   fChain->SetBranchAddress("JettETA", &JettETA, &b_JettETA);
   fChain->SetBranchAddress("JettRAP", &JettRAP, &b_JettRAP);
   fChain->SetBranchAddress("JettPHI", &JettPHI, &b_JettPHI);
   fChain->SetBranchAddress("JettE", &JettE, &b_JettE);
   fChain->SetBranchAddress("JettM", &JettM, &b_JettM);
   fChain->SetBranchAddress("JettPX", &JettPX, &b_JettPX);
   fChain->SetBranchAddress("JettPY", &JettPY, &b_JettPY);
   fChain->SetBranchAddress("JettPZ", &JettPZ, &b_JettPZ);
   fChain->SetBranchAddress("JettLABELID", &JettLABELID, &b_JettLABELID);
   fChain->SetBranchAddress("rho_truth_isocentral", &rho_truth_isocentral, &b_rho_truth_isocentral);
   fChain->SetBranchAddress("rho_truth_isoforward", &rho_truth_isoforward, &b_rho_truth_isoforward);
   fChain->SetBranchAddress("rho_truth_isocentral_sigma", &rho_truth_isocentral_sigma, &b_rho_truth_isocentral_sigma);
   fChain->SetBranchAddress("rho_truth_isoforward_sigma", &rho_truth_isoforward_sigma, &b_rho_truth_isoforward_sigma);
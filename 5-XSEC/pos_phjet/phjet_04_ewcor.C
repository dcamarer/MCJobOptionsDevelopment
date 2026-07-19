///////////////////
// Control plots //
///////////////////

void phjet_04_ewcor()
{

  // std::cout << std::scientific;

  string data_mode = "run3";

  string mmc[10];
  string epp = "pdf";

  ostringstream histo, file;

  int id[200];
  string xt[200];
  string zt[200];
  string yt[200];
  string xtt[200];
  string wt[5];

  string anal[200];
  for (int i = 0; i <= 3; i++)
  {
    anal[i] = "Inclusive photon: ";
  }
  for (int i = 4; i <= 26; i++)
  {
    anal[i] = "Photon + jet: ";
  }
  for (int i = 31; i <= 36; i++)
  {
    anal[i] = "Inclusive photon: ";
  }

  ////////////////
  // Axis names //
  ////////////////

  // eTiso distribution
  xt[0] = "E_{T}^{iso} [GeV]";
  id[0] = 0;
  //
  xtt[0] = "E_{T}^{iso} [nb/GeV]";

  // Inclusive photon histograms
  xt[1] = "E_{T}^{#gamma} [GeV]";
  id[1] = 1;
  xt[2] = "|#eta^{#gamma}|";
  id[2] = 2;
  xt[3] = "#phi^{#gamma} [rad]";
  id[3] = 3;
  //
  xtt[1] = "E_{T}^{#gamma} [nb/GeV]";
  xtt[2] = "|#eta^{#gamma}| [nb]";
  xtt[3] = "#phi^{#gamma} [nb/rad]";

  // Photon+jet general histograms
  xt[11] = "E_{T}^{#gamma} [GeV]";
  id[4] = 11;
  xt[12] = "|#eta^{#gamma}|";
  id[5] = 12;
  xt[13] = "#phi^{#gamma} [rad]";
  id[6] = 13;
  xt[14] = "p_{T}^{jet} [GeV]";
  id[7] = 14;
  xt[15] = "|y^{jet}|";
  id[8] = 15;
  xt[16] = "#phi^{jet} [rad]";
  id[9] = 16;
  xt[17] = "|#Deltay^{#gamma-jet}|";
  id[10] = 17;
  xt[18] = "#Delta#phi^{#gamma-jet}";
  id[11] = 18;
  xt[19] = "m^{#gamma-jet} [GeV]";
  id[12] = 19;
  xt[20] = "|cos #theta*|";
  id[13] = 20;
  //
  xtt[11] = "E_{T}^{#gamma} [nb/GeV]";
  xtt[12] = "|#eta^{#gamma}| [nb]";
  xtt[13] = "#phi^{#gamma} [nb/rad]";
  xtt[14] = "p_{T}^{jet} [nb/GeV]";
  xtt[15] = "|y^{jet}| [nb]";
  xtt[16] = "#phi^{jet} [nb/rad]";
  xtt[17] = "|#Deltay^{#gamma-jet}| [nb]";
  xtt[18] = "#Delta#phi^{#gamma-jet} [nb/rad]";
  xtt[19] = "m^{#gamma-jet} [nb/GeV]";
  xtt[20] = "|cos #theta*| [nb]";

  // Photon+jet different configuration histograms
  xt[21] = "E_{T}^{#gamma} [GeV]";
  id[14] = 21;
  xt[22] = "E_{T}^{#gamma} [GeV]";
  id[15] = 22;
  xt[23] = "E_{T}^{#gamma} [GeV]";
  id[16] = 23;
  xt[24] = "E_{T}^{#gamma} [GeV]";
  id[17] = 24;
  xt[25] = "E_{T}^{#gamma} [GeV]";
  id[18] = 25;
  xt[26] = "E_{T}^{#gamma} [GeV]";
  id[19] = 26;
  //
  xtt[21] = "E_{T}^{#gamma} [nb/GeV]";
  xtt[22] = "E_{T}^{#gamma} [nb/GeV]";
  xtt[23] = "E_{T}^{#gamma} [nb/GeV]";
  xtt[24] = "E_{T}^{#gamma} [nb/GeV]";
  xtt[25] = "E_{T}^{#gamma} [nb/GeV]";
  xtt[26] = "E_{T}^{#gamma} [nb/GeV]";

  // Inclusive photon etagamma regions
  xt[31] = "E_{T}^{#gamma} [GeV]";
  id[20] = 31;
  xt[32] = "E_{T}^{#gamma} [GeV]";
  id[21] = 32;
  xt[33] = "E_{T}^{#gamma} [GeV]";
  id[22] = 33;
  xt[34] = "E_{T}^{#gamma} [GeV]";
  id[23] = 34;
  xt[35] = "E_{T}^{#gamma} [GeV]";
  id[24] = 35;
  xt[36] = "E_{T}^{#gamma} [GeV]";
  id[25] = 36;
  //
  xtt[31] = "E_{T}^{#gamma} [nb/GeV]";
  xtt[32] = "E_{T}^{#gamma} [nb/GeV]";
  xtt[33] = "E_{T}^{#gamma} [nb/GeV]";
  xtt[34] = "E_{T}^{#gamma} [nb/GeV]";
  xtt[35] = "E_{T}^{#gamma} [nb/GeV]";
  xtt[36] = "E_{T}^{#gamma} [nb/GeV]";

  for (int i = 0; i <= 36; i++)
  {

    if (i >= 4 and i <= 10)
      continue;
    if (i >= 27 and i <= 30)
      continue;

    histo.str("");
    histo << "d#sigma/d";
    histo << xtt[i];
    yt[i] = histo.str().c_str();
  }

  if (data_mode == "run2")
  {
    wt[1] = "#sqrt{s} = 13 TeV";
  }
  else if (data_mode == "run3")
  {
    wt[1] = "#sqrt{s} = 13.6 TeV";
  }

  // This will be selected afterwards
  double lum = 0.;
  double elum = 0.;

  // 2015 + 2016 datasets
  double lum1516 = 36214.46; // pb-1
  double elum1516 = 0.017;   // This is valid for 2015-2018

  // 2017 dataset
  double lum17 = 44307.4; // pb-1
  double elum17 = 0.017;  // This is valid for 2015-2018

  // 2018 dataset
  double lum18 = 58450.1; // pb-1
  double elum18 = 0.017;  // This is valid for 2015-2018

  // Run-2
  double lumR2 = 138971.96; // pb-1
  double elumR2 = 0.017;    // This is valid for 2015-2018

  double maxi[200] = {0};
  double mini[200] = {0};

  // MC
  TH1 *hh_sherpa16[50];
  TH1 *hh_sherpa16_ww[350];
  TH1 *hh_standard[50];
  TH1 *hh_standard_ww[350];

  // Ratios
  TH1 *hhr_sherpa16[50];
  TH1 *hhr_sherpa16_ww[350];
  TH1 *hhr_standard[50];
  TH1 *hhr_standard_ww[350];

  // TFile for each of the inputs
  TFile *snlo_standard;
  TFile *snlo_sherpa16;

  int ik = 0;
  int ij = 0;

  // for (int ip=1; ip<=25; ip++){
  for (int ip = 1; ip <= 25; ip++)
  {

    cout << "\nPlot " << ip;
    //
    if (ip == 0)
    {
      cout << ": INCLUSIVE photon eTiso; " << endl;
    }
    //
    if (ip == 1)
    {
      cout << ": INCLUSIVE photon pT; " << endl;
    }
    if (ip == 2)
    {
      cout << ": INCLUSIVE photon eta; " << endl;
    }
    if (ip == 3)
    {
      cout << ": INCLUSIVE photon phi; " << endl;
    }
    //
    if (ip == 4)
    {
      cout << ": PHOTON+JET photon pT; " << endl;
    }
    if (ip == 5)
    {
      cout << ": PHOTON+JET photon eta; " << endl;
    }
    if (ip == 6)
    {
      cout << ": PHOTON+JET photon phi; " << endl;
    }
    if (ip == 7)
    {
      cout << ": PHOTON+JET jet pT; " << endl;
    }
    if (ip == 8)
    {
      cout << ": PHOTON+JET jet rapidity; " << endl;
    }
    if (ip == 9)
    {
      cout << ": PHOTON+JET jet phi; " << endl;
    }
    //
    if (ip == 10)
    {
      cout << ": PHOTON+JET jet DeltaRapidity; " << endl;
    }
    if (ip == 11)
    {
      cout << ": PHOTON+JET jet DeltaPhi; " << endl;
    }
    if (ip == 12)
    {
      cout << ": PHOTON+JET jet InvariantMass; " << endl;
    }
    if (ip == 13)
    {
      cout << ": PHOTON+JET jet CosThetaStar; " << endl;
    }
    //
    if (ip == 14)
    {
      cout << ": PHOTON+JET photon pT - central SS; " << endl;
    }
    if (ip == 15)
    {
      cout << ": PHOTON+JET photon pT - central OS; " << endl;
    }
    if (ip == 16)
    {
      cout << ": PHOTON+JET photon pT - forward SS; " << endl;
    }
    if (ip == 17)
    {
      cout << ": PHOTON+JET photon pT - forward OS; " << endl;
    }
    if (ip == 18)
    {
      cout << ": PHOTON+JET photon pT - most forward SS; " << endl;
    }
    if (ip == 19)
    {
      cout << ": PHOTON+JET photon pT - most forward OS; " << endl;
    }
    //
    if (ip == 20)
    {
      cout << ": INCLUSIVE photon pT - eta < 0.6; " << endl;
    }
    if (ip == 21)
    {
      cout << ": INCLUSIVE photon pT - 0.6 < eta < 0.8; " << endl;
    }
    if (ip == 22)
    {
      cout << ": INCLUSIVE photon pT - 0.8 < eta < 1.37; " << endl;
    }
    if (ip == 23)
    {
      cout << ": INCLUSIVE photon pT - 1.52 < eta < 1.81; " << endl;
    }
    if (ip == 24)
    {
      cout << ": INCLUSIVE photon pT - 1.81 < eta < 2.01; " << endl;
    }
    if (ip == 25)
    {
      cout << ": INCLUSIVE photon pT - 2.01 < eta < 2.37; " << endl;
    }
    //
    cout << endl;

    int k = 500 + id[ip];

    // SNLO 2.2.16

    histo.str(""); histo << "/Users/danielcamarero/PostDoc/PMG/MCJobOptionsDevelopment/4-NTUPLES/MC_phjet/pos/ph_validation_" << data_mode << "_sherpa2216_r2_wSyes_wRno_wSFno_01.root";
    snlo_sherpa16 = new TFile(histo.str().c_str(), "read");

    // nominal prediction
    for (unsigned int ij = 2; ij <= 2; ij++)
    {
      histo.str("");
      histo << "TH1_h_" << k << "_" << ik << "_" << ij;
      hh_sherpa16[ip] = (TH1 *)snlo_sherpa16->Get(histo.str().c_str());
    }
    // ew-corrected prediction
    for (unsigned int iv = 0; iv <= 345; iv++)
    {
      histo.str("");
      histo << "TH1_h_snlo" << k << "_" << iv << "_" << ik;
      hh_sherpa16_ww[iv] = (TH1 *)snlo_sherpa16->Get(histo.str().c_str());
    }

    // SNLO 2.2.2 MC

    histo.str(""); histo << "/Users/danielcamarero/PostDoc/PMG/MCJobOptionsDevelopment/4-NTUPLES/MC_phjet/pos/ph_validation_sherpa222_r2_wSyes_wRno_wSFno_01.root";

    snlo_standard = new TFile(histo.str().c_str(), "read");

    // nominal prediction
    for (unsigned int ij = 2; ij <= 2; ij++)
    {
      histo.str("");
      histo << "TH1_h_" << k << "_" << ik << "_" << ij;
      hh_standard[ip] = (TH1 *)snlo_standard->Get(histo.str().c_str());
    }
    // ww prediction
    for (unsigned int iv = 0; iv <= 114; iv++)
    {
      histo.str("");
      histo << "TH1_h_snlo" << k << "_" << iv << "_" << ik;
      hh_standard_ww[iv] = (TH1 *)snlo_standard->Get(histo.str().c_str());
    }

    // Ratios
    hhr_sherpa16[ip] = (TH1 *)hh_standard[ip]->Clone(histo.str().c_str());
    hhr_sherpa16[ip]->Reset();    
    hhr_standard[ip] = (TH1 *)hh_standard[ip]->Clone(histo.str().c_str());
    hhr_standard[ip]->Reset();
    for (unsigned int iv = 0; iv <= 345; iv++)
    {
      hhr_sherpa16_ww[iv] = (TH1 *)hh_sherpa16_ww[iv]->Clone(histo.str().c_str());
      hhr_sherpa16_ww[iv]->Reset();
      hhr_standard_ww[iv] = (TH1 *)hh_sherpa16_ww[iv]->Clone(histo.str().c_str());
      hhr_standard_ww[iv]->Reset();
    }

    // variables definition
    double xbins[500] = {}, ex[500] = {}, exx[500] = {};
    //
    double mc_standard[500] = {}, emc_standard[500] = {};
    double mc_sherpa16[500] = {}, emc_sherpa16[500] = {};
    double mc_sherpa16_wwad[500] = {}, emc_sherpa16_wwad[500] = {};
    double mc_sherpa16_wwmul[500] = {}, emc_sherpa16_wwmul[500] = {};
    double mc_sherpa16_wwexp[500] = {}, emc_sherpa16_wwexp[500] = {};

    int nb = 0, ni = 1;
    nb = hh_sherpa16[ip]->GetNbinsX();

    // bin control
    // Inclusive photon
    if (ip == 0)
    {
    } // eTiso (~125 bins)
    if (ip == 1)
    {
    } // eT (bin 13 - only 1 events for full Run2)
    if (ip == 2)
    {
    } // 12 eta
    if (ip == 3)
    {
    } // 16 phi
    // Photon + jet
    if (ip == 4)
    {
    } // eT (bin 13 - only 1 events for full Run2)
    if (ip == 5)
    {
    } // 12 eta
    if (ip == 6)
    {
    } // 16 phi
    if (ip == 7)
    {
    } // pT (bin 11 - only 3 events for full Run2)
    if (ip == 8)
    {
    } // 22 rapidity
    if (ip == 9)
    {
    } // 16 phi
    if (ip == 10)
    {
    } // 12 DeltaRapidity
    if (ip == 11)
    {
    } // 10 DeltaPhi
    if (ip == 12)
    {
    } // 8 mass
    if (ip == 13)
    {
    } // 9 cosThetaStar
    if (ip == 14)
    {
    } // eT (bin 12 - only 3 events for full Run2)
    if (ip == 15)
    {
    } // eT (bin 12 - only 3 events for full Run2)
    if (ip == 16)
    {
    } // eT (bin 11 - only 0 events for full Run2)
    if (ip == 17)
    {
    } // eT (bin 11 - only 2 events for full Run2)
    if (ip == 18)
    {
    } // eT (bin 7 - only 1 events for full Run2)
    if (ip == 19)
    {
    } // eT (bin 7 - only 1 events for full Run2)
    if (ip == 20)
    {
    } // eT (bin 13)
    if (ip == 21)
    {
    } // eT (bin 13)
    if (ip == 22)
    {
    } // eT (bin 13)
    if (ip == 23)
    {
    } // eT (bin 13)
    if (ip == 24)
    {
    } // eT (bin 13)
    if (ip == 25)
    {
    } // eT (bin 13)

    cout << "ni = " << ni << endl;
    cout << "nb = " << nb << endl;
    cout << endl;

    double effentries_standard[5] = {}, effentries_sherpa16[5] = {};
    double entries_standard[5] = {}, entries_sherpa16[5] = {};
    //
    entries_sherpa16[0] = hh_sherpa16[ip]->GetEntries();
    effentries_sherpa16[0] = hh_sherpa16[ip]->GetEffectiveEntries();
    //
    entries_standard[0] = hh_standard[ip]->GetEntries();
    effentries_standard[0] = hh_standard[ip]->GetEffectiveEntries();

    cout << " >> ENTRIES: " << endl;
    cout << endl;
    cout << " entries_sherpa16[0] = " << entries_sherpa16[0] << endl;
    cout << " effentries_sherpa16[0] = " << effentries_sherpa16[0] << endl;
    cout << endl;
    cout << " entries_standard[0] = " << entries_standard[0] << endl;
    cout << " effentries_standard[0] = " << effentries_standard[0] << endl;
    cout << endl;

    ////// EW corrections ME+PS
    // 'MUR1_MUF1_PDF303200_ASSEW' : 322 ,
    // 'MUR1_MUF1_PDF303200_ASSEWLO1' : 328 ,
    // 'MUR1_MUF1_PDF303200_ASSEWLO1LO2' : 334 ,
    // 'MUR1_MUF1_PDF303200_ASSEWLO1LO2LO3' : 340 ,
    // 'MUR1_MUF1_PDF303200_MULTIASSEW' : 324 ,
    // 'MUR1_MUF1_PDF303200_MULTIASSEWLO1' : 330 ,
    // 'MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2' : 336 ,
    // 'MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2LO3' : 342 ,
    // 'MUR1_MUF1_PDF303200_EXPASSEW' : 326 ,
    // 'MUR1_MUF1_PDF303200_EXPASSEWLO1' : 332 ,
    // 'MUR1_MUF1_PDF303200_EXPASSEWLO1LO2' : 338 ,
    // 'MUR1_MUF1_PDF303200_EXPASSEWLO1LO2LO3' : 344 ,

    int ns = 0;
    int i = 0;
    for (int j = ni; j <= nb; j++)
    {

      i = ns;
      ns += 1;

      xbins[i] = hh_sherpa16[ip]->GetBinCenter(j);
      ex[i] = hh_sherpa16[ip]->GetBinWidth(j);
      exx[i] = 0.0000001;

      // MC sherpa16 2.2.11
      mc_sherpa16[i] = hh_sherpa16[ip]->GetBinContent(j);
      emc_sherpa16[i] = hh_sherpa16[ip]->GetBinError(j);
      mc_sherpa16[i] /= ex[i];
      emc_sherpa16[i] /= ex[i];
      // EW CORRECTED - ADDITIVE
      mc_sherpa16_wwad[i] = hh_sherpa16_ww[322]->GetBinContent(j);
      emc_sherpa16_wwad[i] = hh_sherpa16_ww[322]->GetBinError(j);
      mc_sherpa16_wwad[i] /= ex[i];
      emc_sherpa16_wwad[i] /= ex[i];
      // EW CORRECTED - MULTIPLICATIVE
      mc_sherpa16_wwmul[i] = hh_sherpa16_ww[324]->GetBinContent(j);
      emc_sherpa16_wwmul[i] = hh_sherpa16_ww[324]->GetBinError(j);
      mc_sherpa16_wwmul[i] /= ex[i];
      emc_sherpa16_wwmul[i] /= ex[i];
      // EW CORRECTED - EXPONENTIAL
      mc_sherpa16_wwexp[i] = hh_sherpa16_ww[326]->GetBinContent(j);
      emc_sherpa16_wwexp[i] = hh_sherpa16_ww[326]->GetBinError(j);
      mc_sherpa16_wwexp[i] /= ex[i];
      emc_sherpa16_wwexp[i] /= ex[i];

      // MC STANDARD 2.2.2
      mc_standard[i] = hh_standard[ip]->GetBinContent(j);
      emc_standard[i] = hh_standard[ip]->GetBinError(j);
      //
      mc_standard[i] /= ex[i];
      emc_standard[i] /= ex[i];
    }

    hh_sherpa16[ip]->Reset();
    hh_sherpa16_ww[322]->Reset();
    hh_sherpa16_ww[324]->Reset();
    hh_sherpa16_ww[326]->Reset();
    hh_standard[ip]->Reset();

    ns = 0;
    i = 0;
    for (unsigned int j = ni; j <= nb; j++)
    {

      i = ns;
      ns += 1;

      // sherpa16
      hh_sherpa16[ip]->SetBinContent(j, mc_sherpa16[i]);
      hh_sherpa16[ip]->SetBinError(j, emc_sherpa16[i]);
      // sherpa16 - EWADD
      hh_sherpa16_ww[322]->SetBinContent(j, mc_sherpa16_wwad[i]);
      hh_sherpa16_ww[322]->SetBinError(j, emc_sherpa16_wwad[i]);
      // sherpa16 - EWMUL
      hh_sherpa16_ww[324]->SetBinContent(j, mc_sherpa16_wwmul[i]);
      hh_sherpa16_ww[324]->SetBinError(j, emc_sherpa16_wwmul[i]);
      // sherpa16 - EWXP
      hh_sherpa16_ww[326]->SetBinContent(j, mc_sherpa16_wwexp[i]);
      hh_sherpa16_ww[326]->SetBinError(j, emc_sherpa16_wwexp[i]);

      // STANDARD
      hh_standard[ip]->SetBinContent(j, mc_standard[i]);
      hh_standard[ip]->SetBinError(j, emc_standard[i]);
    }

    // Normalisation [from pb-1 to nb-1]
    hh_sherpa16[ip]->Scale(1 / 1000.);
    hh_sherpa16_ww[322]->Scale(1 / 1000.);
    hh_sherpa16_ww[324]->Scale(1 / 1000.);
    hh_sherpa16_ww[326]->Scale(1 / 1000.);
    hh_standard[ip]->Scale(1 / 1000.);

    ////// Ratio and error of the ratio

    double rat_standard[500] = {}, erat_standard[500] = {};
    double rat_sherpa16[500] = {}, erat_sherpa16[500] = {};
    //
    double rat_sherpa16_wwad[500] = {}, erat_sherpa16_wwad[500] = {};
    double rat_sherpa16_wwmul[500] = {}, erat_sherpa16_wwmul[500] = {};
    double rat_sherpa16_wwexp[500] = {}, erat_sherpa16_wwexp[500] = {};

    ns = 0;
    i = 0;
    for (unsigned int j = ni; j <= nb; j++)
    {

      i = ns;
      ns += 1;

      // RATIO 1,2,3:
      rat_sherpa16[i] = 0;
      erat_sherpa16[i] = 0;
      rat_standard[i] = 0;
      erat_standard[i] = 0;
      if (mc_standard[i] > 0)
      {
        rat_sherpa16[i] = mc_sherpa16[i] / mc_standard[i];
        // erat_sherpa16[i]  = emc_sherpa16[i] / mc_standard[i];
        erat_sherpa16[i] = rat_sherpa16[i] * sqrt(pow(emc_sherpa16[i] / mc_sherpa16[i], 2) + pow(emc_standard[i] / mc_standard[i], 2));        
        //
        rat_standard[i] = mc_standard[i] / mc_standard[i];
        erat_standard[i] = emc_standard[i] / mc_standard[i];
      }
      hhr_sherpa16[ip]->SetBinContent(j, rat_sherpa16[i]);
      hhr_sherpa16[ip]->SetBinError(j, erat_sherpa16[i]);
      //
      hhr_standard[ip]->SetBinContent(j, rat_standard[i]);
      hhr_standard[ip]->SetBinError(j, erat_standard[i]);

      // RATIO 4,5,6:
      rat_sherpa16_wwad[i] = 0;
      erat_sherpa16_wwad[i] = 0;
      rat_sherpa16_wwmul[i] = 0;
      erat_sherpa16_wwmul[i] = 0;
      rat_sherpa16_wwexp[i] = 0;
      erat_sherpa16_wwexp[i] = 0;
      if (mc_sherpa16[i] > 0)
      {
        rat_sherpa16_wwad[i] = mc_sherpa16_wwad[i] / mc_sherpa16[i];
        // erat_sherpa16_wwad[i]  = emc_sherpa16_wwad[i] / mc_sherpa16[i];
        // erat_sherpa16_wwad[i] = rat_sherpa16_wwad[i] * sqrt( pow(emc_sherpa16_wwad[i]/mc_sherpa16_wwad[i],2) + pow(emc_sherpa16[i]/mc_sherpa16[i],2) );
        erat_sherpa16_wwad[i] = (1 / mc_sherpa16[i]) * sqrt(pow(emc_sherpa16_wwad[i], 2) + pow(rat_sherpa16_wwad[i] * emc_sherpa16[i], 2) - rat_sherpa16_wwad[i] * (emc_sherpa16_wwad[i]) * (emc_sherpa16[i]));
        //
        rat_sherpa16_wwmul[i] = mc_sherpa16_wwmul[i] / mc_sherpa16[i];
        // erat_sherpa16_wwmul[i]  = emc_sherpa16_wwmul[i] / mc_sherpa16[i];
        // erat_sherpa16_wwmul[i] = rat_sherpa16_wwmul[i] * sqrt( pow(emc_sherpa16_wwmul[i]/mc_sherpa16_wwmul[i],2) + pow(emc_sherpa16[i]/mc_sherpa16[i],2) );
        erat_sherpa16_wwmul[i] = (1 / mc_sherpa16[i]) * sqrt(pow(emc_sherpa16_wwmul[i], 2) + pow(rat_sherpa16_wwmul[i] * emc_sherpa16[i], 2) - rat_sherpa16_wwmul[i] * (emc_sherpa16_wwmul[i]) * (emc_sherpa16[i]));
        //
        rat_sherpa16_wwexp[i] = mc_sherpa16_wwexp[i] / mc_sherpa16[i];
        // erat_sherpa16_wwexp[i]  = emc_sherpa16_wwexp[i] / mc_sherpa16[i];
        // erat_sherpa16_wwexp[i] = rat_sherpa16_wwexp[i] * sqrt( pow(emc_sherpa16_wwexp[i]/mc_sherpa16_wwexp[i],2) + pow(emc_sherpa16[i]/mc_sherpa16[i],2) );
        erat_sherpa16_wwexp[i] = (1 / mc_sherpa16[i]) * sqrt(pow(emc_sherpa16_wwexp[i], 2) + pow(rat_sherpa16_wwexp[i] * emc_sherpa16[i], 2) - rat_sherpa16_wwexp[i] * (emc_sherpa16_wwexp[i]) * (emc_sherpa16[i]));
      }
      hhr_sherpa16_ww[322]->SetBinContent(j, rat_sherpa16_wwad[i]);
      hhr_sherpa16_ww[322]->SetBinError(j, erat_sherpa16_wwad[i]);
      //
      hhr_sherpa16_ww[324]->SetBinContent(j, rat_sherpa16_wwmul[i]);
      // hhr_sherpa16_ww[324]->SetBinError(j,erat_sherpa16_wwmul[i]);
      hhr_sherpa16_ww[324]->SetBinError(j, 0);
      //
      hhr_sherpa16_ww[326]->SetBinContent(j, rat_sherpa16_wwexp[i]);
      // hhr_sherpa16_ww[326]->SetBinError(j,erat_sherpa16_wwexp[i]);
      hhr_sherpa16_ww[326]->SetBinError(j, 0);
    }

    double bl = hh_sherpa16[ip]->GetBinCenter(ni) - hh_sherpa16[ip]->GetBinWidth(ni) / 2.;
    double bu = hh_sherpa16[ip]->GetBinCenter(nb) + hh_sherpa16[ip]->GetBinWidth(nb) / 2.;

    cout << " Limits: bl = " << bl << "; bu = " << bu << ";" << endl;

    TLine ll(bl, 1., bu, 1.);
    ll.SetLineWidth(2);
    ll.SetLineStyle(2);

    TLine llup1(bl, 1., bu, 1.);
    llup1.SetLineWidth(1);
    llup1.SetLineStyle(2);
    TLine llup2(bl, 1., bu, 1.);
    llup2.SetLineWidth(1);
    llup2.SetLineStyle(2);

    TLine lldown1(bl, 1., bu, 1.);
    lldown1.SetLineWidth(1);
    lldown1.SetLineStyle(2);
    TLine lldown2(bl, 1., bu, 1.);
    lldown2.SetLineWidth(1);
    lldown2.SetLineStyle(2);

    //
    // Plot
    //

    for (unsigned int ratn = 1; ratn <= 2; ratn++)
    {

      double w = 650;
      double h = 650;

      // Creation of 1 canvas
      TCanvas *canvas = new TCanvas("canvas", "canvas", 0, 0, w, h);
      canvas->SetWindowSize(w + (w - canvas->GetWw()), h + (h - canvas->GetWh()));
      canvas->cd();

      // Creation of two pads contained in the canvas
      TPad *canvas_1 = new TPad("canvas_1", "canvas_1", 0.0, 0.0, 1.0, 1.0);

      canvas_1->SetFillStyle(4000);
      canvas_1->Draw();

      double maxr = hh_sherpa16[ip]->GetMaximum();
      double minr = hh_sherpa16[ip]->GetMinimum();
      canvas_1->cd();

      // x-log scale
      if (ip == 1 or ip == 4 or ip == 7 or ip == 12 or (ip >= 14 and ip <= 19) or (ip >= 20 and ip <= 25))
      {
        canvas_1->SetLogx();
      }

      // Other fixes
      if (ip == 1 or ip == 4 or ip == 7 or (ip >= 20 and ip <= 25))
      {
        bu = 2500;
      }
      else if (ip == 2 or ip == 5)
      {
      }
      else if (ip == 3 or ip == 6 or ip == 9)
      {
      }
      else if (ip == 8)
      {
      }
      else if (ip == 10)
      { // Delta Y
      }
      else if (ip == 11)
      { // Delta Phi
      }
      else if (ip == 12)
      { // Invariant mass
        bu = 7200;
      }
      else if (ip == 13)
      { // cos theta*
      }
      else if (ip >= 14 and ip <= 19)
      {
        bu = 2500;
      }
      else if (ip == 0)
      { // Isolation distribution
        bl = -10;
        bu = 50;
      }

      TH1F *h1;

      if (ratn == 1)
        h1 = canvas_1->DrawFrame(bl, 0.5, bu, 1.5);
      if (ratn == 2 or ratn == 3)
        h1 = canvas_1->DrawFrame(bl, 0.7, bu, 1.3);

      ////// Axes configuration

      histo.str("");
      histo << xt[id[ip]];
      h1->SetXTitle(histo.str().c_str());
      h1->GetXaxis()->SetTitleSize(0.05);
      h1->GetXaxis()->SetTitleOffset(1.5);
      h1->GetXaxis()->SetLabelSize(0.045);
      h1->GetXaxis()->SetLabelOffset(0.005);

      histo.str("");
      if (ratn == 1)
        histo << "Ratio to SHERPA 222";
      if (ratn == 2 or ratn == 3)
        histo << "Ratio to nominal prediction";

      // histo.str(""); histo << yt[id[ip]];
      h1->SetYTitle(histo.str().c_str());
      h1->GetYaxis()->SetTitleSize(0.05);
      h1->GetYaxis()->SetTitleOffset(1.5);
      h1->GetYaxis()->SetLabelSize(0.045);
      h1->GetYaxis()->SetLabelOffset(0.005);

      TAxis *axis_x_c1 = h1->GetXaxis();
      axis_x_c1->SetNdivisions(510);
      axis_x_c1->SetMoreLogLabels(1);
      axis_x_c1->SetNoExponent(1);

      TAxis *axis_y_c1 = h1->GetYaxis();
      axis_y_c1->SetNdivisions(510);

      h1->Draw();

      histo.str("");
      histo << wt[1];
      myText(0.23, 0.89, 1, histo.str().c_str(), 0.035);

      if (ratn == 1)
      {

        histo.str("");
        histo << "SHERPA 2.2.16";
        myMarkerText(0.23, 0.85, kRed, 24, histo.str().c_str(), 1.3, 0.03, 0.04);        

        histo.str("");
        histo << "SHERPA 2.2.2";
        myMarkerText(0.23, 0.80, kGreen + 2, 20, histo.str().c_str(), 1.0, 0.03, 0.04);
      }
      else if (ratn == 2)
      {

        histo.str("");
        histo << "SHERPA 2.2.16 - ASSEW";
        myMarkerText(0.23, 0.85, kBlack, 20, histo.str().c_str(), 1.2, 0.03, 0.04);

        histo.str("");
        histo << "SHERPA 2.2.16 - MULTIASSEW";
        myLine(0.23, 0.81, 0.03, kCyan + 1, 1, histo.str().c_str(), 0.03, 0.04);

        histo.str("");
        histo << "SHERPA 2.2.16 - EXPASSEW";
        myLine(0.23, 0.77, 0.03, kRed, 2, histo.str().c_str(), 0.03, 0.04);
      }

      // Extra labels
      zt[1] = "|#eta^{#gamma}| < 1.37 & 1.52 < |#eta^{#gamma}| < 2.37;";
      zt[2] = "E_{T}^{#gamma} > 17 GeV;";
      zt[3] = "|#eta^{#gamma}| < 1.37 & 1.52 < |#eta^{#gamma}| < 2.37; E_{T}^{#gamma} > 17 GeV;";
      zt[4] = "|y^{jet}| < 4.4; p_{T}^{jet} > 10 GeV;";
      zt[5] = "|#eta^{#gamma} + y^{jet}| < 2.37; m^{#gamma-jet} > 70 GeV; |cos #theta*| < 0.83;";
      zt[14] = "#eta^{#gamma}*y^{jet} #geq 0; |y^{jet}| < 1.2;";
      zt[15] = "#eta^{#gamma}*y^{jet} < 0; |y^{jet}| < 1.2;";
      zt[16] = "#eta^{#gamma}*y^{jet} #geq 0; 1.2 #leq |y^{jet}| < 2.8;";
      zt[17] = "#eta^{#gamma}*y^{jet} < 0; 1.2 #leq |y^{jet}| < 2.8;";
      zt[18] = "#eta^{#gamma}*y^{jet} #geq 0; 2.8 #leq |y^{jet}| < 4.4;";
      zt[19] = "#eta^{#gamma}*y^{jet} < 0; 2.8 #leq |y^{jet}| < 4.4;";
      zt[20] = "|#eta^{#gamma}| < 0.6";
      zt[21] = "0.6 < |#eta^{#gamma}| < 0.8";
      zt[22] = "0.8 < |#eta^{#gamma}| < 1.37";
      zt[23] = "1.52 < |#eta^{#gamma}| < 1.81";
      zt[24] = "1.81 < |#eta^{#gamma}| < 2.01";
      zt[25] = "2.01 < |#eta^{#gamma}| < 2.37";

      if (ip == 0 or ip == 1 or ip == 2 or ip == 3)
      {

        histo.str("");
        histo << anal[id[ip]];
        myText(0.20, 0.26, 1, histo.str().c_str(), 0.03);

        histo.str("");
        histo << zt[3];
        myText(0.20, 0.21, 1, histo.str().c_str(), 0.03);
      }
      else if (ip == 4 or ip == 5 or ip == 6 or ip == 7 or ip == 8 or ip == 9 or ip == 10 or ip == 11)
      {

        histo.str("");
        histo << anal[id[ip]];
        myText(0.20, 0.31, 1, histo.str().c_str(), 0.03);

        histo.str("");
        histo << zt[3];
        myText(0.20, 0.26, 1, histo.str().c_str(), 0.03);

        histo.str("");
        histo << zt[4];
        myText(0.20, 0.21, 1, histo.str().c_str(), 0.03);
      }
      else if (ip == 12 or ip == 13)
      {

        histo.str("");
        histo << anal[id[ip]];
        myText(0.20, 0.37, 1, histo.str().c_str(), 0.03);

        histo.str("");
        histo << zt[3];
        myText(0.20, 0.31, 1, histo.str().c_str(), 0.03);

        histo.str("");
        histo << zt[4];
        myText(0.20, 0.26, 1, histo.str().c_str(), 0.03);

        histo.str("");
        histo << zt[5];
        myText(0.20, 0.21, 1, histo.str().c_str(), 0.03);
      }
      else if (ip >= 20 and ip <= 25)
      {

        histo.str("");
        histo << anal[id[ip]];
        myText(0.20, 0.26, 1, histo.str().c_str(), 0.03);

        histo.str("");
        histo << zt[ip];
        myText(0.20, 0.21, 1, histo.str().c_str(), 0.03);
      }
      else
      {

        histo.str("");
        histo << anal[id[ip]];
        myText(0.20, 0.37, 1, histo.str().c_str(), 0.03);

        histo.str("");
        histo << zt[3];
        myText(0.20, 0.31, 1, histo.str().c_str(), 0.03);

        histo.str("");
        histo << zt[4];
        myText(0.20, 0.26, 1, histo.str().c_str(), 0.03);

        histo.str("");
        histo << zt[ip];
        myText(0.20, 0.21, 1, histo.str().c_str(), 0.03);
      }

      if (ratn == 1)
      {
        myhhdate(hhr_sherpa16[ip], "esamex0", 1.3, kRed, 24, 2., 1, kRed, 1, 1);
        myhhdate(hhr_standard[ip], "esamex0", 1.0, kGreen + 2, 20, 2., 2, kGreen + 2, 1, 1);
      }
      else if (ratn == 2)
      {
        myhhdate(hhr_sherpa16_ww[322], "esamex0", 1.2, kBlack, 20, 2., 1, kBlack, 1, 1);
        myhhdate(hhr_sherpa16_ww[324], "esamex0", 0, 0, 0, 3., 1, kCyan + 1, 1, 1);
        myhhdate(hhr_sherpa16_ww[326], "esamex0", 0, 0, 0, 3., 2, kRed, 1, 1);
      }

      if (ratn == 1 or ratn == 2)
      {
        ll.DrawLine(bl, 1., bu, 1.);
        llup1.DrawLine(bl, 1.10, bu, 1.10);
        lldown1.DrawLine(bl, 0.90, bu, 0.90);
        if (ratn == 1)
        {
          llup2.DrawLine(bl, 1.20, bu, 1.20);
          lldown2.DrawLine(bl, 0.80, bu, 0.80);
        }
      }

      gPad->RedrawAxis();

      file.str("");
      file << "./plots-phjet_04_ewcor/phjet_04_ewcor_" << data_mode;
      file << "_ratn";
      file << ratn;
      file << "_";
      if (ip <= 9)
        file << "0";
      file << ip;
      file << ".";
      file << epp;
      histo.str("");
      histo << epp;

      myepsfile(canvas, file.str().c_str(), histo.str().c_str());

      delete canvas;

    } // loop over different ratios

    snlo_sherpa16->Close();
    snlo_standard->Close();

    cout << endl;
    cout << " THE END " << endl;
    cout << endl;

  } // Loop over observables

} // phjet_04_ewcor.C

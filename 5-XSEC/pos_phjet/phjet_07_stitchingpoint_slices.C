///////////////////////////
// Check stitching point //
///////////////////////////

void phjet_07_stitchingpoint_slices()
{

  string data_mode = "run2";

  int stitching = 6;
  int slice_1 = 999;
  int slice_2 = 999;
  if (stitching == 1)
  {
    slice_1 = 17;
    slice_2 = 35;
  }
  else if (stitching == 2)
  {
    slice_1 = 35;
    slice_2 = 70;
  }
  else if (stitching == 3)
  {
    slice_1 = 70;
    slice_2 = 140;
  }
  else if (stitching == 4)
  {
    slice_1 = 140;
    slice_2 = 280;
  }
  else if (stitching == 5)
  {
    slice_1 = 280;
    slice_2 = 500;
  }
  else if (stitching == 6)
  {
    slice_1 = 500;
    slice_2 = 1000;
  }

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
  xtt[0] = "E_{T}^{iso} [pb/GeV]";

  // Inclusive photon histograms
  xt[1] = "E_{T}^{#gamma} [GeV]";
  id[1] = 1;
  xt[2] = "|#eta^{#gamma}|";
  id[2] = 2;
  xt[3] = "#phi^{#gamma} [rad]";
  id[3] = 3;
  //
  xtt[1] = "E_{T}^{#gamma} [pb/GeV]";
  xtt[2] = "|#eta^{#gamma}| [pb]";
  xtt[3] = "#phi^{#gamma} [pb/rad]";

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
  xtt[11] = "E_{T}^{#gamma} [pb/GeV]";
  xtt[12] = "|#eta^{#gamma}| [pb]";
  xtt[13] = "#phi^{#gamma} [pb/rad]";
  xtt[14] = "p_{T}^{jet} [pb/GeV]";
  xtt[15] = "|y^{jet}| [pb]";
  xtt[16] = "#phi^{jet} [pb/rad]";
  xtt[17] = "|#Deltay^{#gamma-jet}| [pb]";
  xtt[18] = "#Delta#phi^{#gamma-jet} [pb/rad]";
  xtt[19] = "m^{#gamma-jet} [pb/GeV]";
  xtt[20] = "|cos #theta*| [pb]";

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
  xtt[21] = "E_{T}^{#gamma} [pb/GeV]";
  xtt[22] = "E_{T}^{#gamma} [pb/GeV]";
  xtt[23] = "E_{T}^{#gamma} [pb/GeV]";
  xtt[24] = "E_{T}^{#gamma} [pb/GeV]";
  xtt[25] = "E_{T}^{#gamma} [pb/GeV]";
  xtt[26] = "E_{T}^{#gamma} [pb/GeV]";

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
  xtt[31] = "E_{T}^{#gamma} [pb/GeV]";
  xtt[32] = "E_{T}^{#gamma} [pb/GeV]";
  xtt[33] = "E_{T}^{#gamma} [pb/GeV]";
  xtt[34] = "E_{T}^{#gamma} [pb/GeV]";
  xtt[35] = "E_{T}^{#gamma} [pb/GeV]";
  xtt[36] = "E_{T}^{#gamma} [pb/GeV]";

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
  string tag = "a";

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

  if (tag == "a")
  {
    lum = lum1516;
    elum = elum1516;
  }
  if (tag == "d")
  {
    lum = lum17;
    elum = elum17;
  }
  if (tag == "e")
  {
    lum = lum18;
    elum = elum18;
  }
  if (tag == "run2")
  {
    lum = lumR2;
    elum = elumR2;
  }

  double maxi[200] = {0};
  double mini[200] = {0};

  // MC
  TH1 *hh_mc0[30]; // This is supposed to be the standard
  TH1 *hh_mc1[30];
  TH1 *hh_mc1_slice1[30];
  TH1 *hh_mc1_slice2[30];
  TH1 *hh_mc2[30];

  // Ratios
  TH1 *hhr_mc0[30]; // This is supposed to be the standard
  TH1 *hhr_mc1[30];
  TH1 *hhr_mc1_slice1[30];
  TH1 *hhr_mc1_slice2[30];
  TH1 *hhr_mc2[30];

  // TFile for each of the inputs
  TFile *snlo_mc0;
  TFile *snlo_mc1;
  TFile *snlo_mc1_slice1;
  TFile *snlo_mc1_slice2;
  TFile *snlo_mc2;

  int ik = 0;
  int ij = 0;

  // for (int ip=0; ip<=25; ip++){
  for (int ip = 1; ip <= 1; ip++)
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

    // int k = 500 + id[ip];
    int k = 541;

    // SNLO 2.2.16 MC
    histo.str("");
    histo << "/Users/danielcamarero/PostDoc/PMG/MCJobOptionsDevelopment/4-NTUPLES/MC_phjet/pos/ph_validation_" << data_mode << "_sherpa2216_r2_wSyes_wRno_wSFno_01.root";
    snlo_mc2 = new TFile(histo.str().c_str(), "read");

    for (int ij = 2; ij <= 2; ij++)
    {
      histo.str("");
      histo << "TH1_h_" << k << "_" << ik << "_" << ij;
      hh_mc0[ip] = (TH1 *)snlo_mc2->Get(histo.str().c_str());

      hh_mc1[ip] = (TH1 *)hh_mc0[ip]->Clone(histo.str().c_str());
      hh_mc2[ip] = (TH1 *)hh_mc0[ip]->Clone(histo.str().c_str());
    }

    // SNLO 2.2.16 MC slice 1
    histo.str("");
    histo << "/Users/danielcamarero/PostDoc/PMG/MCJobOptionsDevelopment/4-NTUPLES/MC_phjet/pos/r2_" << data_mode << "/";
    histo << "ph_validation_" << data_mode << "_sherpa2216_pt"<<slice_1<<"_r2_wSyes_wRno_wSFno_01.root";
    snlo_mc1_slice1 = new TFile(histo.str().c_str(), "read");

    for (int ij = 2; ij <= 2; ij++)
    {
      histo.str("");
      histo << "TH1_h_" << k << "_" << ik << "_" << ij;
      hh_mc1_slice1[ip] = (TH1 *)snlo_mc1_slice1->Get(histo.str().c_str());
    }

    // SNLO 2.2.16 MC slice 2
    histo.str("");
    histo << "/Users/danielcamarero/PostDoc/PMG/MCJobOptionsDevelopment/4-NTUPLES/MC_phjet/pos/r2_" << data_mode << "/";
    histo << "ph_validation_" << data_mode << "_sherpa2216_pt"<<slice_2<<"_r2_wSyes_wRno_wSFno_01.root";
    snlo_mc1_slice2 = new TFile(histo.str().c_str(), "read");

    for (int ij = 2; ij <= 2; ij++)
    {
      histo.str("");
      histo << "TH1_h_" << k << "_" << ik << "_" << ij;
      hh_mc1_slice2[ip] = (TH1 *)snlo_mc1_slice2->Get(histo.str().c_str());
    }

    // Ratios
    hhr_mc1[ip] = (TH1 *)hh_mc1[ip]->Clone(histo.str().c_str());
    hhr_mc1[ip]->Reset();
    hhr_mc1_slice1[ip] = (TH1 *)hh_mc1[ip]->Clone(histo.str().c_str());
    hhr_mc1_slice1[ip]->Reset();
    hhr_mc1_slice2[ip] = (TH1 *)hh_mc1[ip]->Clone(histo.str().c_str());
    hhr_mc1_slice2[ip]->Reset();
    hhr_mc2[ip] = (TH1 *)hh_mc2[ip]->Clone(histo.str().c_str());
    hhr_mc2[ip]->Reset();
    hhr_mc0[ip] = (TH1 *)hh_mc0[ip]->Clone(histo.str().c_str());
    hhr_mc0[ip]->Reset();

    // variables definition
    double xbins[5000] = {}, ex[5000] = {}, exx[5000] = {};
    //
    double mc_mc0[5000] = {}, emc_mc0[5000] = {};
    double mc_mc1[5000] = {}, emc_mc1[5000] = {};
    double mc_mc1_slice1[5000] = {}, emc_mc1_slice1[5000] = {};
    double mc_mc1_slice2[5000] = {}, emc_mc1_slice2[5000] = {};
    double mc_mc2[5000] = {}, emc_mc2[5000] = {};
    //
    double rat_mc0[5000] = {}, erat_mc0[5000] = {};
    double rat_mc1[5000] = {}, erat_mc1[5000] = {};
    double rat_mc1_slice1[5000] = {}, erat_mc1_slice1[5000] = {};
    double rat_mc1_slice2[5000] = {}, erat_mc1_slice2[5000] = {};
    double rat_mc2[5000] = {}, erat_mc2[5000] = {};

    int nb = 0, ni = 1;
    nb = hh_mc1[ip]->GetNbinsX();

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
    } // eT (bin 12)
    if (ip == 15)
    {
    } // eT (bin 12)
    if (ip == 16)
    {
    } // eT (bin 11)
    if (ip == 17)
    {
    } // eT (bin 11)
    if (ip == 18)
    {
    } // eT (bin 7)
    if (ip == 19)
    {
    } // eT (bin 7)
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

    double effentries_mc0[5] = {}, effentries_mc1[5] = {}, effentries_mc1_slice1[5] = {}, effentries_mc1_slice2[5] = {}, effentries_mc2[5] = {};
    double entries_mc0[5] = {}, entries_mc1[5] = {}, entries_mc1_slice1[5] = {}, entries_mc1_slice2[5] = {}, entries_mc2[5] = {};
    //
    entries_mc0[0] = hh_mc0[ip]->GetEntries();
    effentries_mc0[0] = hh_mc0[ip]->GetEffectiveEntries();
    //
    entries_mc1[0] = hh_mc1[ip]->GetEntries();
    effentries_mc1[0] = hh_mc1[ip]->GetEffectiveEntries();
    //
    entries_mc1_slice1[0] = hh_mc1_slice1[ip]->GetEntries();
    effentries_mc1_slice1[0] = hh_mc1_slice1[ip]->GetEffectiveEntries();
    //
    entries_mc1_slice2[0] = hh_mc1_slice2[ip]->GetEntries();
    effentries_mc1_slice2[0] = hh_mc1_slice2[ip]->GetEffectiveEntries();
    //
    entries_mc2[0] = hh_mc2[ip]->GetEntries();
    effentries_mc2[0] = hh_mc2[ip]->GetEffectiveEntries();

    cout << " >> ENTRIES: " << endl;
    cout << endl;
    cout << " entries_mc0[0]    = " << entries_mc0[0] << endl;
    cout << " effentries_mc0[0] = " << effentries_mc0[0] << endl;
    cout << endl;
    /*
      cout << " entries_mc1[0]    = " <<entries_mc1[0]<< endl;
      cout << " effentries_mc1[0] = " <<effentries_mc1[0]<< endl;
      cout << endl;
      cout << " entries_mc2[0]    = " <<entries_mc2[0]<< endl;
      cout << " effentries_mc2[0] = " <<effentries_mc2[0]<< endl;
      cout << endl;
    */

    int ns = 0;
    int i = 0;
    for (int j = ni; j <= nb; j++)
    {

      i = ns;
      ns += 1;

      xbins[i] = hh_mc1[ip]->GetBinCenter(j);
      ex[i] = hh_mc1[ip]->GetBinWidth(j) / 2.;
      exx[i] = 1e-12;

      ////// MC MC1
      mc_mc1[i] = hh_mc1[ip]->GetBinContent(j);
      emc_mc1[i] = hh_mc1[ip]->GetBinError(j);
      //
      mc_mc1[i] = mc_mc1[i] / (2 * ex[i]);
      emc_mc1[i] = emc_mc1[i] / (2 * ex[i]);

      // Slice 1
      mc_mc1_slice1[i] = hh_mc1_slice1[ip]->GetBinContent(j);
      emc_mc1_slice1[i] = hh_mc1_slice1[ip]->GetBinError(j);
      //
      mc_mc1_slice1[i] = mc_mc1_slice1[i] / (2 * ex[i]);
      emc_mc1_slice1[i] = emc_mc1_slice1[i] / (2 * ex[i]);

      // Slice 2
      mc_mc1_slice2[i] = hh_mc1_slice2[ip]->GetBinContent(j);
      emc_mc1_slice2[i] = hh_mc1_slice2[ip]->GetBinError(j);
      //
      mc_mc1_slice2[i] = mc_mc1_slice2[i] / (2 * ex[i]);
      emc_mc1_slice2[i] = emc_mc1_slice2[i] / (2 * ex[i]);

      ////// MC MC2
      mc_mc2[i] = hh_mc2[ip]->GetBinContent(j);
      emc_mc2[i] = hh_mc2[ip]->GetBinError(j);
      //
      mc_mc2[i] = mc_mc2[i] / (2 * ex[i]);
      emc_mc2[i] = emc_mc2[i] / (2 * ex[i]);

      ////// MC MC0
      mc_mc0[i] = hh_mc0[ip]->GetBinContent(j);
      emc_mc0[i] = hh_mc0[ip]->GetBinError(j);
      //
      mc_mc0[i] = mc_mc0[i] / (2 * ex[i]);
      emc_mc0[i] = emc_mc0[i] / (2 * ex[i]);
    }

    hh_mc0[ip]->Reset();
    hh_mc1[ip]->Reset();
    hh_mc1_slice1[ip]->Reset();
    hh_mc1_slice2[ip]->Reset();
    hh_mc2[ip]->Reset();

    ns = 0;
    i = 0;
    for (int j = ni; j <= nb; j++)
    {

      i = ns;
      ns += 1;

      hh_mc0[ip]->SetBinContent(j, mc_mc0[i]);
      hh_mc0[ip]->SetBinError(j, emc_mc0[i]);

      hh_mc1[ip]->SetBinContent(j, mc_mc1[i]);
      hh_mc1[ip]->SetBinError(j, emc_mc1[i]);

      hh_mc1_slice1[ip]->SetBinContent(j, mc_mc1_slice1[i]);
      hh_mc1_slice1[ip]->SetBinError(j, emc_mc1_slice1[i]);

      hh_mc1_slice2[ip]->SetBinContent(j, mc_mc1_slice2[i]);
      hh_mc1_slice2[ip]->SetBinError(j, emc_mc1_slice2[i]);

      hh_mc2[ip]->SetBinContent(j, mc_mc2[i]);
      hh_mc2[ip]->SetBinError(j, emc_mc2[i]);
    }

    // Normalisation [from pb-1 to nb-1]
    // hh_mc0[ip]->Scale(1/1000.);
    // hh_mc1[ip]->Scale(1/1000.);
    // hh_mc2[ip]->Scale(1/1000.);

    // Ratio and error of the ratio
    ns = 0;
    i = 0;
    for (int j = ni; j <= nb; j++)
    {

      i = ns;
      ns += 1;

      // Read again the info
      mc_mc0[i] = hh_mc0[ip]->GetBinContent(j);
      emc_mc0[i] = hh_mc0[ip]->GetBinError(j);
      //
      mc_mc1[i] = hh_mc1[ip]->GetBinContent(j);
      emc_mc1[i] = hh_mc1[ip]->GetBinError(j);
      //
      mc_mc2[i] = hh_mc2[ip]->GetBinContent(j);
      emc_mc2[i] = hh_mc2[ip]->GetBinError(j);

      // RATIO 2 mc1 / mc0
      rat_mc1[i] = 0;
      erat_mc1[i] = 0;
      //
      if (mc_mc0[i] > 0)
      {
        rat_mc1[i] = mc_mc1[i] / mc_mc0[i];
        // erat_mc1[i]  = emc_mc1[i] / mc_mc0[i];
        erat_mc1[i] = rat_mc1[i] * sqrt(pow(emc_mc1[i] / mc_mc1[i], 2) + pow(emc_mc0[i] / mc_mc0[i], 2));
      }
      //
      hhr_mc1[ip]->SetBinContent(j, rat_mc1[i]);
      hhr_mc1[ip]->SetBinError(j, erat_mc1[i]);

      // RATIO 3 htptv2 / mc0
      rat_mc2[i] = 0;
      erat_mc2[i] = 0;
      //
      if (mc_mc0[i] > 0)
      {
        rat_mc2[i] = mc_mc2[i] / mc_mc0[i];
        // erat_mc2[i]  = emc_mc2[i] / mc_mc0[i];
        erat_mc2[i] = rat_mc2[i] * sqrt(pow(emc_mc2[i] / mc_mc2[i], 2) + pow(emc_mc0[i] / mc_mc0[i], 2));
      }
      //
      hhr_mc2[ip]->SetBinContent(j, rat_mc2[i]);
      hhr_mc2[ip]->SetBinError(j, erat_mc2[i]);

      // RATIO 1 mc0 / mc0
      rat_mc0[i] = 0;
      erat_mc0[i] = 0;
      //
      if (mc_mc0[i] > 0)
      {
        rat_mc0[i] = mc_mc0[i] / mc_mc0[i];
        erat_mc0[i] = emc_mc0[i] / mc_mc0[i];
      }
      //
      hhr_mc0[ip]->SetBinContent(j, rat_mc0[i]);
      hhr_mc0[ip]->SetBinError(j, erat_mc0[i]);
    }

    double bl = hh_mc1[ip]->GetBinCenter(ni) - hh_mc1[ip]->GetBinWidth(ni) / 2.;
    double bu = hh_mc1[ip]->GetBinCenter(nb) + hh_mc1[ip]->GetBinWidth(nb) / 2.;

    cout << " Limits: bl = " << bl << "; bu = " << bu << ";" << endl;

    // For MC
    TGraphErrors *gmc_mc1;
    TGraphErrors *gmcrat_mc1;
    TGraphErrors *gmc_mc1_slice1;
    TGraphErrors *gmcrat_mc1_slice1;
    TGraphErrors *gmc_mc1_slice2;
    TGraphErrors *gmcrat_mc1_slice2;
    TGraphErrors *gmc_mc2;
    TGraphErrors *gmcrat_mc2;
    TGraphErrors *gmc_mc0;
    TGraphErrors *gmcrat_mc0;

    gmc_mc0 = new TGraphErrors(ns, xbins, mc_mc0, ex, emc_mc0);
    gmcrat_mc0 = new TGraphErrors(ns, xbins, rat_mc0, ex, erat_mc0);

    gmc_mc1 = new TGraphErrors(ns, xbins, mc_mc1, ex, emc_mc1);
    gmcrat_mc1 = new TGraphErrors(ns, xbins, rat_mc1, ex, erat_mc1);

    gmc_mc1_slice1 = new TGraphErrors(ns, xbins, mc_mc1_slice1, ex, emc_mc1_slice1);
    gmcrat_mc1_slice1 = new TGraphErrors(ns, xbins, rat_mc1_slice1, ex, erat_mc1_slice1);

    gmc_mc1_slice2 = new TGraphErrors(ns, xbins, mc_mc1_slice2, ex, emc_mc1_slice2);
    gmcrat_mc1_slice2 = new TGraphErrors(ns, xbins, rat_mc1_slice2, ex, erat_mc1_slice2);

    gmc_mc2 = new TGraphErrors(ns, xbins, mc_mc2, ex, emc_mc2);
    gmcrat_mc2 = new TGraphErrors(ns, xbins, rat_mc2, ex, erat_mc2);

    TLine ll(140, 1, 140, 20);
    ll.SetLineWidth(1.);
    ll.SetLineStyle(2.);
    ll.SetLineColor(kRed);

    //
    // Plot
    //

    for (unsigned int ratn = 1; ratn <= 1; ratn++)
    {

      double w = 650;
      double h = 650;

      // Creation of 1 canvas
      TCanvas *canvas = new TCanvas("canvas", "canvas", 0, 0, w, h);
      canvas->SetWindowSize(w + (w - canvas->GetWw()), h + (h - canvas->GetWh()));
      canvas->cd();

      // Creation of two pads contained in the canvas
      TPad *canvas_1 = new TPad("canvas_1", "canvas_1", 0.0, 0.0, 0.99, 0.99);

      canvas_1->SetFillStyle(4000);
      canvas_1->Draw();

      double maxr = hh_mc1[ip]->GetMaximum();
      double minr = hh_mc1[ip]->GetMinimum();
      canvas_1->cd();

      // x-log scale
      if (ip == 1 or ip == 4 or ip == 7 or ip == 12 or (ip >= 14 and ip <= 19) or (ip >= 20 and ip <= 25))
      {
        // canvas_1->SetLogx(); // WIP
      }

      // y-log scale
      if (ip == 1 or ip == 4 or ip == 7)
      {
        canvas_1->SetLogy(); // WIP
        maxi[ip] = 5e+07;
        mini[ip] = 1e-11;
        bu = 2500;
      }
      else if (ip == 2 or ip == 5)
      {
        if (ratn == 1)
          maxi[ip] = maxr * 2;
        mini[ip] = 0.5;
      }
      else if (ip == 3 or ip == 6 or ip == 9)
      {
        if (ratn == 1)
          maxi[ip] = maxr * 2;
        mini[ip] = 0.5;
      }
      else if (ip == 8)
      {
        if (ratn == 1)
          maxi[ip] = maxr * 1.5;
        mini[ip] = 0.5;
      }
      else if (ip == 10)
      { // Delta Y
        canvas_1->SetLogy();
        if (ratn == 1)
          maxi[ip] = 2e+02;
        mini[ip] = 5;
      }
      else if (ip == 11)
      { // Delta Phi
        canvas_1->SetLogy();
        if (ratn == 1)
          maxi[ip] = maxr * 50;
        mini[ip] = 1;
      }
      else if (ip == 12)
      { // Invariant mass
        canvas_1->SetLogy();
        maxi[ip] = 1e+03;
        mini[ip] = 1e-14;
        bu = 7200;
      }
      else if (ip == 13)
      { // cos theta*
        canvas_1->SetLogy();
        if (ratn == 1)
          maxi[ip] = maxr * 10;
        mini[ip] = 1;
      }
      else if (ip >= 14 and ip <= 19)
      {
        canvas_1->SetLogy();
        maxi[ip] = 5e+03;
        mini[ip] = 1e-11;
        bu = 2500;
      }
      else if (ip >= 20 and ip <= 25)
      {
        canvas_1->SetLogy();
        maxi[ip] = 5e+03;
        mini[ip] = 1e-12;
        bu = 2500;
      }
      else if (ip == 0)
      { // Isolation distribution
        canvas_1->SetLogy();
        maxi[ip] = 1e+05;
        mini[ip] = 1e-5;
        bl = -10;
        bu = 50;
      }

      // TH1F *h1 = canvas_1->DrawFrame(bl,mini[ip],bu,maxi[ip]);
      double xup = slice_2 + 15;
      double xlow = slice_2 - 15;
      double yup = 1E+02;
      double ylow = 1;
      if (stitching == 1)
      {
        yup /= 1E-06;
        ylow /= 1;
      }
      if (stitching == 2)
      {
        yup /= 1E-03;
        ylow /= 1;
      }
      else if (stitching == 4)
      {
        yup /= 1;
        ylow /= 1E+03;
      }
      else if (stitching == 5)
      {
        yup /= 1;
        ylow /= 1E+06;
      }
      else if (stitching == 6)
      {
        yup /= 1;
        ylow /= 1E+09;
      }      

      TH1F *h1 = canvas_1->DrawFrame(xlow, ylow, xup, yup); // WIP

      // Axes configuration
      histo.str("");
      histo << xt[id[ip]];
      h1->SetXTitle(histo.str().c_str());
      histo.str("");
      histo << yt[id[ip]];
      h1->SetYTitle(histo.str().c_str());
      //
      h1->GetXaxis()->SetTitleSize(0.05);
      h1->GetXaxis()->SetTitleOffset(1.5);
      h1->GetXaxis()->SetLabelSize(0.045);
      h1->GetXaxis()->SetLabelOffset(0.005);
      //
      h1->GetYaxis()->SetTitleSize(0.05);
      h1->GetYaxis()->SetTitleOffset(1.5);
      h1->GetYaxis()->SetLabelSize(0.045);
      h1->GetYaxis()->SetLabelOffset(0.005);

      TAxis *axis_x_c1 = h1->GetXaxis();
      axis_x_c1->SetNdivisions(505);
      // axis_x_c1->SetMoreLogLabels(1);
      // axis_x_c1->SetNoExponent(1);

      TAxis *axis_y_c1 = h1->GetYaxis();
      axis_y_c1->SetNdivisions(505);

      h1->Draw();

      // Print Pythia, Sherpa and data
      if (ratn == 1)
      {

        // myhhdate(hh_mc1[ip],"esamex0",1.3,kRed,21,2.,2,kRed,1,1);
        // myggdate(gmc_mc1,"z",0,kRed,0,2.,1,kRed);

        // myhhdate(hh_mc2[ip],"esamex0",1.0,kBlue,22,2.,3,kBlue,1,1);
        // myggdate(gmc_mc2,"z",0,kBlue,0,2.,1,kBlue);

        // myhhdate(hh_mc0[ip],"esamex0",1.0,kGreen+2,20,2.,1,kGreen+2,1,1);
        myggdate(gmc_mc1_slice1, "z", 0, kBlue, 0, 1., 1, kBlue);
        myggdate(gmc_mc1_slice2, "z", 0, kRed, 0, 1., 1, kRed);
        myggdate(gmc_mc0, "z", 0, kBlack, 0, 1., 2, kBlack);
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

      histo.str("");
      histo << wt[1] << "; Inclusive photon";
      myText(0.24, 0.89, 1, histo.str().c_str(), 0.03);

      histo.str("");
      histo << zt[1];
      myText(0.24, 0.85, 1, histo.str().c_str(), 0.03);

      histo.str("");
      histo << "SHERPA 2.2.16 (pTy_slices)";
      myLine(0.24, 0.81, 0.03, kBlack, 2, histo.str().c_str(), 0.03, 0.04);

      histo.str("");
      histo << "slice " << slice_1;
      myLine(0.24, 0.77, 0.03, kBlue, 1, histo.str().c_str(), 0.03, 0.04);

      histo.str("");
      histo << "slice " << slice_2;
      myLine(0.24, 0.73, 0.03, kRed, 1, histo.str().c_str(), 0.03, 0.04);

      histo.str("");
      histo << "#Delta E_{T}^{#gamma} = 1 GeV";
      myText(0.24, 0.68, kBlack, histo.str().c_str(), 0.03);

      histo.str("");
      histo << "Slices cut";
      myLine(0.24, 0.65, 0.03, kRed, 2, histo.str().c_str(), 0.03, 0.04);

      ll.Draw();
      // ll2.Draw();

      gPad->RedrawAxis();

      file.str("");
      file << "./plots-phjet_07_stitchingpoint_slices/phjet_07_" << data_mode << "_stich_" << slice_2 << "_";
      if (ip <= 9)
        file << "0";
      file << ip << "." << epp;
      histo.str("");
      histo << epp;

      myepsfile(canvas, file.str().c_str(), histo.str().c_str());

      delete canvas;

    } // loop over different ratios

    cout << "\n THE END \n"
         << endl;

  } // Loop over observables

} // phjet_07_stitchingpoint.C

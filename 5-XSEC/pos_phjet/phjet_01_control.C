///////////////////
// Control plots //
///////////////////

void phjet_01_control()
{

  // std::cout << std::scientific;

  string data_mode = "2015+2016";
  string tag = "a";
  // string data_mode = "2017"; string tag = "d";
  // string data_mode = "2018"; string tag = "e";
  // string data_mode = "run2"; string tag = "run2";

  string mc_alt1 = "", mc_alt2 = "", mc_base = "sherpa222";
  mc_alt1 = "run2_sherpa2216";
  mc_alt2 = "run3_sherpa2216";

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

  if (data_mode == "2015+2016")
  {
    wt[1] = "#sqrt{s} = 13 TeV";
    mmc[0] = "Data 2015+2016";
    mmc[1] = "PYTHIA";
    mmc[2] = "SHERPA";
    mmc[3] = "SHERPA NLO";
  }
  else if (data_mode == "2017")
  {
    wt[1] = "#sqrt{s} = 13 TeV";
    mmc[0] = "Data 2017";
    mmc[1] = "PYTHIA";
    mmc[2] = "SHERPA";
    mmc[3] = "SHERPA NLO";
  }
  else if (data_mode == "2018")
  {
    wt[1] = "#sqrt{s} = 13 TeV";
    mmc[0] = "Data 2018";
    mmc[1] = "PYTHIA";
    mmc[2] = "SHERPA";
    mmc[3] = "SHERPA NLO";
  }
  else if (data_mode == "run2")
  {
    wt[1] = "#sqrt{s} = 13 TeV";
    mmc[0] = "Data 2015-2018";
    mmc[1] = "PYTHIA";
    mmc[2] = "SHERPA";
    mmc[3] = "SHERPA NLO";
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
  TH1 *hh_mc2[30];

  // Ratios
  TH1 *hhr_mc0[30]; // This is supposed to be the standard
  TH1 *hhr_mc1[30];
  TH1 *hhr_mc2[30];

  // TFile for each of the inputs
  TFile *snlo_mc0;
  TFile *snlo_mc1;
  TFile *snlo_mc2;

  int ik = 0;
  int ij = 0;

  // for (int ip=0; ip<=25; ip++){
  for (int ip = 0; ip <= 13; ip++)
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

    // SNLO 2.2.16 MC Run 2

    histo.str("");
    histo << "/Users/danielcamarero/PostDoc/PMG/MCJobOptionsDevelopment/4-NTUPLES/MC_phjet/pos/";
    if (mc_alt1 == "run2_sherpa2216")
    {
      histo << "ph_validation_run2_sherpa2216_r2_wSyes_wRno_wSFno_01.root";
    }
    snlo_mc1 = new TFile(histo.str().c_str(), "read");

    for (int ij = 2; ij <= 2; ij++)
    {
      histo.str("");
      histo << "TH1_h_" << k << "_" << ik << "_" << ij;
      hh_mc1[ip] = (TH1 *)snlo_mc1->Get(histo.str().c_str());
    }

    // SNLO 2.2.16 MC Run 3

    histo.str("");
    histo << "/Users/danielcamarero/PostDoc/PMG/MCJobOptionsDevelopment/4-NTUPLES/MC_phjet/pos/";
    if (mc_alt2 == "run3_sherpa2216")
    {
      histo << "ph_validation_run3_sherpa2216_r2_wSyes_wRno_wSFno_01.root";
    }
    snlo_mc2 = new TFile(histo.str().c_str(), "read");

    for (int ij = 2; ij <= 2; ij++)
    {
      histo.str("");
      histo << "TH1_h_" << k << "_" << ik << "_" << ij;
      hh_mc2[ip] = (TH1 *)snlo_mc2->Get(histo.str().c_str());
    }

    // SNLO 2.2.2 MC

    histo.str("");
    histo << "/Users/danielcamarero/PostDoc/PMG/MCJobOptionsDevelopment/4-NTUPLES/MC_phjet/SAMPLES/";
    if (mc_base == "sherpa222")
    {
      histo << "sherpa222/ph_validation_sherpa222_TRUTH1_r2_wSyes_wRno_wSFno_01.root";
    }
    snlo_mc0 = new TFile(histo.str().c_str(), "read");

    for (int ij = 2; ij <= 2; ij++)
    {
      histo.str("");
      histo << "TH1_h_" << k << "_" << ik << "_" << ij;
      hh_mc0[ip] = (TH1 *)snlo_mc0->Get(histo.str().c_str());
    }

    // Ratios
    hhr_mc1[ip] = (TH1 *)hh_mc1[ip]->Clone(histo.str().c_str());
    hhr_mc1[ip]->Reset();
    hhr_mc2[ip] = (TH1 *)hh_mc2[ip]->Clone(histo.str().c_str());
    hhr_mc2[ip]->Reset();
    hhr_mc0[ip] = (TH1 *)hh_mc0[ip]->Clone(histo.str().c_str());
    hhr_mc0[ip]->Reset();

    // variables definition
    double xbins[5000] = {}, ex[5000] = {}, exx[5000] = {};
    //
    double mc_mc0[5000] = {}, emc_mc0[5000] = {};
    double mc_mc1[5000] = {}, emc_mc1[5000] = {};
    double mc_mc2[5000] = {}, emc_mc2[5000] = {};
    //
    double rat_mc0[5000] = {}, erat_mc0[5000] = {};
    double rat_mc1[5000] = {}, erat_mc1[5000] = {};
    double rat_mc2[5000] = {}, erat_mc2[5000] = {};

    int nb = 0, ni = 1;
    nb = hh_mc0[ip]->GetNbinsX();

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

    double effentries_mc0[5] = {}, effentries_mc1[5] = {}, effentries_mc2[5] = {};
    double entries_mc0[5] = {}, entries_mc1[5] = {}, entries_mc2[5] = {};
    //
    entries_mc0[0] = hh_mc0[ip]->GetEntries();
    effentries_mc0[0] = hh_mc0[ip]->GetEffectiveEntries();
    //
    entries_mc1[0] = hh_mc1[ip]->GetEntries();
    effentries_mc1[0] = hh_mc1[ip]->GetEffectiveEntries();
    //
    entries_mc2[0] = hh_mc2[ip]->GetEntries();
    effentries_mc2[0] = hh_mc2[ip]->GetEffectiveEntries();

    cout << " >> ENTRIES: " << endl;
    cout << endl;
    cout << " entries_mc0[0]    = " << entries_mc0[0] << endl;
    cout << " effentries_mc0[0] = " << effentries_mc0[0] << endl;
    cout << endl;
    cout << " entries_mc1[0]    = " << entries_mc1[0] << endl;
    cout << " effentries_mc1[0] = " << effentries_mc1[0] << endl;
    cout << endl;
    cout << " entries_mc2[0]    = " << entries_mc2[0] << endl;
    cout << " effentries_mc2[0] = " << effentries_mc2[0] << endl;
    cout << endl;

    int ns = 0;
    int i = 0;
    for (int j = ni; j <= nb; j++)
    {

      i = ns;
      ns += 1;

      xbins[i] = hh_mc1[ip]->GetBinCenter(j);
      ex[i] = hh_mc1[ip]->GetBinWidth(j) / 2.;
      exx[i] = 1e-12;

      // MC MC1
      mc_mc1[i] = hh_mc1[ip]->GetBinContent(j);
      emc_mc1[i] = hh_mc1[ip]->GetBinError(j);
      //
      mc_mc1[i] = mc_mc1[i] / (2 * ex[i]);
      emc_mc1[i] = emc_mc1[i] / (2 * ex[i]);

      // MC MC2
      mc_mc2[i] = hh_mc2[ip]->GetBinContent(j);
      emc_mc2[i] = hh_mc2[ip]->GetBinError(j);
      //
      mc_mc2[i] = mc_mc2[i] / (2 * ex[i]);
      emc_mc2[i] = emc_mc2[i] / (2 * ex[i]);

      // MC MC0
      mc_mc0[i] = hh_mc0[ip]->GetBinContent(j);
      emc_mc0[i] = hh_mc0[ip]->GetBinError(j);
      //
      mc_mc0[i] = mc_mc0[i] / (2 * ex[i]);
      emc_mc0[i] = emc_mc0[i] / (2 * ex[i]);
    }

    hh_mc0[ip]->Reset();
    hh_mc1[ip]->Reset();
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

      hh_mc2[ip]->SetBinContent(j, mc_mc2[i]);
      hh_mc2[ip]->SetBinError(j, emc_mc2[i]);
    }

    // Normalisation [from pb-1 to nb-1]
    hh_mc0[ip]->Scale(1 / 1000.);
    hh_mc1[ip]->Scale(1 / 1000.);
    hh_mc2[ip]->Scale(1 / 1000.);

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

    double bl = hh_mc0[ip]->GetBinCenter(ni) - hh_mc0[ip]->GetBinWidth(ni) / 2.;
    double bu = hh_mc0[ip]->GetBinCenter(nb) + hh_mc0[ip]->GetBinWidth(nb) / 2.;

    cout << " Limits: bl = " << bl << "; bu = " << bu << ";" << endl;

    // For MC
    TGraphErrors *gmc_mc1;
    TGraphErrors *gmcrat_mc1;
    TGraphErrors *gmc_mc2;
    TGraphErrors *gmcrat_mc2;
    TGraphErrors *gmc_mc0;
    TGraphErrors *gmcrat_mc0;

    gmc_mc0 = new TGraphErrors(ns, xbins, mc_mc0, ex, emc_mc0);
    gmcrat_mc0 = new TGraphErrors(ns, xbins, rat_mc0, ex, erat_mc0);

    gmc_mc1 = new TGraphErrors(ns, xbins, mc_mc1, ex, emc_mc1);
    gmcrat_mc1 = new TGraphErrors(ns, xbins, rat_mc1, ex, erat_mc1);

    gmc_mc2 = new TGraphErrors(ns, xbins, mc_mc2, ex, emc_mc2);
    gmcrat_mc2 = new TGraphErrors(ns, xbins, rat_mc2, ex, erat_mc2);

    TLine ll(bl, 1., bu, 1.);
    ll.SetLineWidth(2.);
    ll.SetLineStyle(2.);

    TLine llu(bl, 1.20, bu, 1.20);
    llu.SetLineWidth(1.);
    llu.SetLineStyle(2.);

    TLine lld(bl, 0.80, bu, 0.80);
    lld.SetLineWidth(1.);
    lld.SetLineStyle(2.);

    //
    // Plot
    //

    double w = 650;
    double h = 650;

    // Creation of 1 canvas
    TCanvas *canvas = new TCanvas("canvas", "canvas", 0, 0, w, h);
    canvas->SetWindowSize(w + (w - canvas->GetWw()), h + (h - canvas->GetWh()));
    canvas->cd();

    // Creation of two pads contained in the canvas
    TPad *canvas_1 = new TPad("canvas_1", "canvas_1", 0.0, 0.29, 0.9, 0.99);
    TPad *canvas_2 = new TPad("canvas_2", "canvas_2", 0.0, 0.10, 0.9, 0.41);

    canvas_1->SetFillStyle(4000);
    canvas_1->Draw();
    canvas_2->SetFillStyle(4000);
    canvas_2->Draw();

    double maxr = hh_mc0[ip]->GetMaximum();
    double minr = hh_mc0[ip]->GetMinimum();
    canvas_1->cd();

    // x-log scale
    if (ip == 1 or ip == 4 or ip == 7 or ip == 12 or (ip >= 14 and ip <= 19) or (ip >= 20 and ip <= 25))
    {
      canvas_1->SetLogx();
    }

    // y-log scale
    if (ip == 1 or ip == 4 or ip == 7)
    {
      canvas_1->SetLogy();
      maxi[ip] = 5e+03;
      mini[ip] = 1e-11;
      bu = 2500;
    }
    else if (ip == 2 or ip == 5)
    {
      maxi[ip] = maxr * 2;
      mini[ip] = 0.5;
    }
    else if (ip == 3 or ip == 6 or ip == 9)
    {
      maxi[ip] = maxr * 2;
      mini[ip] = 0.5;
    }
    else if (ip == 8)
    {
      maxi[ip] = maxr * 1.5;
      mini[ip] = 0.5;
    }
    else if (ip == 10)
    { // Delta Y
      canvas_1->SetLogy();
      maxi[ip] = 2e+02;
      mini[ip] = 5;
    }
    else if (ip == 11)
    { // Delta Phi
      canvas_1->SetLogy();
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

    TH1F *h1 = canvas_1->DrawFrame(bl, mini[ip], bu, maxi[ip]);

    // Axes configuration
    histo.str("");
    histo << yt[id[ip]];
    h1->SetYTitle(histo.str().c_str());
    //
    h1->GetXaxis()->SetTitleSize(0.09);
    h1->GetXaxis()->SetTitleOffset(0.9);
    h1->GetXaxis()->SetLabelSize(0.09);
    h1->GetXaxis()->SetLabelOffset(200);
    //
    h1->GetYaxis()->SetTitleSize(0.05);
    h1->GetYaxis()->SetTitleOffset(1.5);
    h1->GetYaxis()->SetLabelSize(0.045);
    h1->GetYaxis()->SetLabelOffset(0.005);

    TAxis *axis_x_c1 = h1->GetXaxis();
    axis_x_c1->SetNdivisions(510);
    axis_x_c1->SetMoreLogLabels(1);
    axis_x_c1->SetNoExponent(1);

    TAxis *axis_y_c1 = h1->GetYaxis();
    axis_y_c1->SetNdivisions(505);

    h1->Draw();

    // myhhdate(hh_mc1[ip],"esamex0",1.3,kRed,21,2.,2,kRed,1,1);
    // myhhdate(hh_mc2[ip],"esamex0",1.0,kBlue,22,2.,3,kBlue,1,1);
    // myhhdate(hh_mc0[ip],"esamex0",1.0,kGreen+2,20,2.,1,kGreen+2,1,1);

    myggdate(gmc_mc1, "z", 0, kOrange + 2, 0, 2., 1, kOrange + 2);
    myggdate(gmc_mc2, "z", 0, kCyan, 0, 2., 1, kCyan);
    myggdate(gmc_mc0, "z", 0, kGreen + 2, 0, 2., 1, kGreen + 2);

    histo.str("");
    histo << wt[1];
    myText(0.55, 0.89, 1, histo.str().c_str(), 0.035);

    // myMarkerText(0.55,0.85,kRed,21,histo.str().c_str(),1.0,0.03,0.04);
    // myMarkerText(0.55,0.81,kBlue,22,histo.str().c_str(),1.0,0.03,0.04);
    // myMarkerText(0.55,0.73,kGreen+2,20,histo.str().c_str(),1.0,0.03,0.04);

    histo.str("");
    histo << "SHERPA 2.2.16 (Run 2)";
    myLine(0.55, 0.85, 0.03, kOrange + 2, 1, histo.str().c_str(), 0.03, 0.04);

    histo.str("");
    histo << "SHERPA 2.2.16 (Run 3)";
    myLine(0.55, 0.81, 0.03, kCyan, 1, histo.str().c_str(), 0.03, 0.04);

    histo.str("");
    histo << "SHERPA 2.2.2";
    myLine(0.55, 0.77, 0.03, kGreen + 2, 1, histo.str().c_str(), 0.03, 0.04);

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

    // ATLAS_LABEL_NN(0.20,0.875,1,"int",false);

    gPad->RedrawAxis();

    if (ip == 1 or ip == 4 or ip == 7 or ip == 12 or (ip >= 14 and ip <= 19) or (ip >= 20 and ip <= 25))
    {
      canvas_2->SetLogx();
    }
    canvas_2->cd();
    canvas_2->SetBottomMargin(0.30);

    double blim = 0.901;
    double ulim = 1.099;

    blim = 0.501;
    ulim = 1.499;
    if (ip == 0)
    {
      blim = 0.201;
      ulim = 1.799;
    }
    if (ip == 7)
    {
      blim = 0.001;
      ulim = 1.999;
    }

    TH1F *h2 = canvas_2->DrawFrame(bl, blim, bu, ulim);

    // h2->SetYTitle("1 / pTV^{2}");
    h2->SetYTitle("1 / SHERPA 2.2.2");
    histo.str("");
    histo << xt[id[ip]];
    h2->SetXTitle(histo.str().c_str());
    //
    h2->GetXaxis()->SetTitleSize(0.11);
    h2->GetXaxis()->SetTitleOffset(1.2);
    h2->GetXaxis()->SetLabelSize(0.09);
    h2->GetXaxis()->SetLabelOffset(0.02);
    //
    h2->GetYaxis()->CenterTitle();
    h2->GetYaxis()->SetTitleSize(0.1);
    h2->GetYaxis()->SetTitleOffset(0.63);
    h2->GetYaxis()->SetLabelSize(0.09);
    h2->GetYaxis()->SetLabelOffset(0.005);

    TAxis *axis_x = h2->GetXaxis();
    axis_x->SetNdivisions(510);
    axis_x->SetMoreLogLabels(1);
    axis_x->SetNoExponent(1);

    TAxis *axis_y = h2->GetYaxis();
    axis_y->SetNdivisions(505);

    h2->Draw();

    //
    // Print ratio Pythia and Sherpa
    //

    // myhhdate(hhr_mc2[ip],"esamex0",1.0,kBlue,22,2.,3,kBlue,1,1);
    myggdate(gmcrat_mc2, "z", 0, kCyan, 0, 2., 1, kCyan);

    // myhhdate(hhr_mc1[ip],"esamex0",1.0,kRed,21,2.,2,kRed,1,1);
    myggdate(gmcrat_mc1, "z", 0, kOrange + 2, 0, 2., 1, kOrange + 2);

    // myhhdate(hhr_mc0[ip],"esamex0",1.0,kGreen+2,20,2.,1,kGreen+2,1,1);
    myggdate(gmcrat_mc0, "z", 0, kGreen + 2, 0, 2., 1, kGreen + 2);

    ll.DrawLine(bl, 1., bu, 1.);
    llu.DrawLine(bl, 1.20, bu, 1.20);
    lld.DrawLine(bl, 0.80, bu, 0.80);

    gPad->RedrawAxis();

    file.str("");
    file << "./plots-phjet_01_control/phjet_01_";
    if (ip <= 9)
      file << "0";
    file << ip << "." << epp;
    histo.str("");
    histo << epp;

    myepsfile(canvas, file.str().c_str(), histo.str().c_str());

    delete canvas;

    cout << "\n THE END \n"
         << endl;

  } // Loop over observables

} // phjet_01_control.C

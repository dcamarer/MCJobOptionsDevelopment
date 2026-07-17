// MyxAODAnalysis.cxx  -> ntuples
/*
  Photon + jet - Run 2 analysis:
  - Last check: 17/07/2026
  - Author: Daniel Camarero Muñoz (daniel.camarero.munoz@cern.ch)
*/

//////////////
// Includes //
//////////////

#include <vector> // vector constructor
#include <string> // string constructor
// ifstream constructors
#include <iostream> // std::cout
#include <fstream>  // std::ifstream
#include <sstream>  // std::stringstream
// libraries
#include <cstdlib> // C standard general utilities library
#include <cmath>   // C mathematical library
// root constructors
#include <TH1.h>            // one-dimensional histogram constructor
#include <TH2.h>            // two-dimensional histogram constructor
#include <TTree.h>          // a TTree object is a list of TBranch - TTree constructor
#include <TChain.h>         // a collection of files containing TTree objects -- TChain constructor
#include <TFile.h>          // file default constructor
#include <TLorentzVector.h> // general four-vector class - uses: (x,y,z,t) or (px,py,pz,E)

// Functions
double get_deltar(double, double, double, double);
double get_deltaphi(double, double);
double get_phijet(double);

// Namespaces
using namespace std;

// Output stream class to operate on strings
static ostringstream histo;
static ofstream outfile;

// cutFlow
static const int msi = 100;
static const int msj = 5;
static const int msk = 500;
static const int msl = 5;
static unsigned m_cutFlow[msi][msj][msk][msl] = {};

// Mathematical constants
static const double m_deg = 180. / (4. * atan(1.));
static const double m_pi = TMath::Pi();
static const double GeV = 1000.;

// Av.num. of interactions
static double m_mufactor = 1.03;
static double m_mufactor2 = 0.94;
static double m_mufactor3 = 1.12;
static double m_mufactor4 = 1.20;
static double m_mufactor5 = 1.37;

// Selection cuts
static const double m_phptcut = 17;
static const double m_phetacut1 = 1.37;
static const double m_phetacut2 = 1.52;
static const double m_phetacut3 = 2.37;
static const double m_jetptcut = 10;
static const double m_jetptleadcut = 10;
static const double m_jetptsubleadcut = 10;
// other phase-space cuts
static const double m_jetycut = 4.4;
static const double m_jetycut_1 = 1.2;
static const double m_jetycut_2 = 2.8;
// jet variables
static const double cc = 0.83;
static const double ce = 2.37;
static const double mcut = 70;

// 2D-Sideband cuts
static double m_etisocut = 5.;
static double m_regioncut = 5.;

// Counters
static const double m_count_events = 0.5;
static const int m_var = 1;
static string m_hist[50];

// photon variables
int m_ph_r1 = 0;
double photr[50][50] = {};
int m_ph_g1 = 0;
double photg[50] = {};
int m_RT[50][10] = {};

// jet variables
int m_jet_r1 = 0;
double jetr[50][50] = {};
double mpjr[50][50] = {};
int m_jet_g1 = 0;
double jetg[50][50] = {};
double mpjg[50][50] = {};
int ipjt = 0;

// variables used for MU rew.
double weightc_t[50][150] = {};
double weightc_r[50][150] = {};

bool flag_t1 = false, flag_t2 = false, flag_t3 = false, flag_t4 = false;
bool flag_r1 = false, flag_r2 = false, flag_r3 = false, flag_r4 = false, flag_r5 = false;

//
// int main loop (argc: argument count, argv: argument vector)
//

int main(int argc, char *argv[])
{

  // Infile settins
  ifstream infile("fort.50"); // "fort.50" string representing the file to open
  string type;
  string out;
  string pos;
  string mc;
  string rew;
  string sfac;
  string swgt;
  string ptmccutbis;
  int rad;

  infile >> type;
  infile >> out;
  infile >> pos;
  infile >> mc;
  infile >> ptmccutbis;
  infile >> rad;
  infile >> rew;
  infile >> sfac;
  infile >> swgt;

  int ptmccut;
  std::istringstream iss(ptmccutbis);
  iss >> ptmccut;

  histo.str("");
  histo << out;
  ofstream outfile(histo.str().c_str());

  cout << endl;

  // MU reweighting flag
  bool reweightingflag = true;
  if (rew == "no")
  {
    reweightingflag = false;
    cout << " -> Not applying MU reweighting " << endl;
  }
  else
  {
    cout << " -> Applying MU reweighting " << endl;
  }

  // SF weighting flag
  bool SFflag = true;
  if (sfac == "no")
  {
    SFflag = false;
    cout << " -> Not applying SF weights " << endl;
  }
  else
  {
    cout << " -> Applying SF weights " << endl;
  }

  // Slice weighting flag
  bool SWGTflag = true;
  if (swgt == "no")
  {
    SWGTflag = false;
    cout << " -> Not applying SLICE weights " << endl;
  }
  else
  {
    cout << " -> Applying SLICE weights " << endl;
  }

  cout << endl;

  // Outfile check
  unsigned ts = time(NULL);
  outfile << "\n RUNNING ---> " << out << " / " << pos << "\n"
          << endl;
  outfile << " ------------------------------------------------------- " << endl;
  outfile << " Set-up info:       " << endl;
  outfile << " ------------------------------------------------------- " << endl;
  outfile << " type             = " << type << endl;
  outfile << " out              = " << out << endl;
  outfile << " pos              = " << pos << endl;
  outfile << " mc camp / period = " << mc << " / " << ptmccutbis << endl;
  outfile << " iso. cone R      = 0." << rad << endl;
  outfile << " photon pt cut    = " << m_phptcut << endl;
  outfile << " photon eta cuts  = 0 to " << m_phetacut1 << " and " << m_phetacut2 << " to " << m_phetacut3 << endl;
  outfile << " eT iso cut from  = " << 4.2e-3 * m_phptcut + 4.8 << " to " << 4.2e-3 * 2500 + 4.8 << endl;
  outfile << " jet pt cut       = " << m_jetptcut << endl;
  outfile << " jet pt lead cut  = " << m_jetptleadcut << endl;
  outfile << " jet rapidity cut = " << m_jetycut << endl;
  outfile << "\n"
          << endl;

  // Nvar
  string m_var_names[m_var] = {
      "Nominal", // 0
  };

  // Histogram bins
  // static double m_mubins[101] = {};
  // static double m_etisobins[201] = {};
  static const double m_phptbins[30] = {17., 20., 25., 35., 45., 55., 65., 75., 85., 105., 125., 150., 175., 200., 250., 300., 350., 400., 470., 550., 650., 750., 900., 1100., 1500., 2000., 2500., 3000., 3500., 4000.};
  static const double m_phptbins_bis[15] = {17., 20., 25., 30., 40., 45., 50., 55., 65., 75., 85., 105., 125., 145., 4000.};
  static const double m_phetabins[13] = {0.0, 0.2, 0.4, 0.6, 0.8, 1.0, 1.2, 1.37, 1.52, 1.8, 2.0, 2.2, 2.37};
  // jet pT bins
  static const double m_jetptbins[25] = {10., 15., 20., 25., 35., 45., 55., 65., 75., 85., 105., 125., 150., 175., 200., 250., 300., 400., 500., 600., 800., 1000., 1500., 2000., 2500.};
  static const double m_massbins[23] = {mcut, 100., 140., 180., 220., 270., 320., 380., 440., 520., 600., 700., 800., 900., 1000., 1200., 1400., 1600., 1800., 2400., 3200., 4200, 7200.};
  static const double m_costhetabins[9] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, cc};

  // Study the weights
  static const double m_mcweigths[33] = {-1E+15, -1E+14, -1E+13, -1E+12, -1E+11, -1E+10, -1E+09, -1E+08, -1E+07, -1E+06, -1E+05, -1E+04, -1E+03, -1E+02, -1E+01, -1, 0, 1, 1E+01, 1E+02, 1E+03, 1E+04, 1E+05, 1E+06, 1E+07, 1E+08, 1E+09, 1E+10, 1E+11, 1E+12, 1E+13, 1E+14, 1E+15};
  static const double m_mcweigths_positive[17] = {0, 1, 1E+01, 1E+02, 1E+03, 1E+04, 1E+05, 1E+06, 1E+07, 1E+08, 1E+09, 1E+10, 1E+11, 1E+12, 1E+13, 1E+14, 1E+15};
  static const double m_mcweigths_negative[17] = {-1E+15, -1E+14, -1E+13, -1E+12, -1E+11, -1E+10, -1E+09, -1E+08, -1E+07, -1E+06, -1E+05, -1E+04, -1E+03, -1E+02, -1E+01, -1, 0};

  cout << " >> Histograms bins defined" << endl;

  // mubins definition
  double mubins[101] = {};
  mubins[0] = 0.;
  for (unsigned int i = 1; i < 101; i++)
  {
    mubins[i] = mubins[i - 1] + 100 / 100.;
  }
  double weightc[101] = {};

  // etisobins definition
  double etisobins[201] = {};
  etisobins[0] = -25.;
  // cout << " etisobins[0] = " << etisobins[0] << endl;
  for (unsigned int i = 1; i <= 125; i++)
  {
    etisobins[i] = etisobins[i - 1] + 1;
    // cout << "etisobins[" << i << "] = " << etisobins[i] << endl;
  }

  // Ntuple configuration
  Int_t nfile = 0;
  int nfileold = -1;
  // opens the ntuple and creates a tree chain
  TChain *fChain = new TChain("analysis");
#include "files.txt"
#include "mc_validation.h"

  cout << " >> Creating tree" << endl;

  ////////////////////////
  // Histograms factory //
  ////////////////////////

  int k = 0;
  int k2 = 0; // Different studies

  TH1 *m_TH1_m[1000][3] = {};       // General parameters
  TH1 *m_TH1_h[1000][50][3] = {};   // General histograms
  TH1 *m_TH1_hf[100][3] = {};       // General histograms
  TH1 *m_TH1_hsnlo[1000][350] = {}; // Snlo theoretical predictions
  TH1 *m_TH1_g[350][3] = {};        // Sherpa NLO weights

  TH2 *m_TH2_h[100][50][3] = {}; // General histograms

  // [1]:brem [2]:hard
  for (unsigned int id = 2; id <= 2; id++)
  {

    for (unsigned int i = 0; i <= 10; i++)
    {
      histo.str("");
      histo << "TH1_m_" << i << "_" << id;
      if (i == 1)
      {
        m_TH1_m[i][id] = new TH1D(histo.str().c_str(), "events", 1, 0, 1);
      }
      else if (i >= 8)
      {
        m_TH1_m[i][id] = new TH1D(histo.str().c_str(), "events", 32, m_mcweigths);
      }
      else if (i == 9)
      {
        m_TH1_m[i][id] = new TH1D(histo.str().c_str(), "events", 16, m_mcweigths_positive);
      }
      else if (i == 10)
      {
        m_TH1_m[i][id] = new TH1D(histo.str().c_str(), "events", 16, m_mcweigths_positive);
      }
      else
      {
        m_TH1_m[i][id] = new TH1D(histo.str().c_str(), "events", 1, 0.5, 1.5);
      }

      m_TH1_m[i][id]->Sumw2();
    }

    // Histograms for general parameters
    k = 100;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "<mu>", 100, 0., 100.); // 1.00
    m_TH1_m[k][id]->Sumw2();
    k = 101;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "<mu>/mufactor", 100, 0., 100.); // 1.03
    m_TH1_m[k][id]->Sumw2();
    k = 102;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "<mu>/mufactord", 100, 0., 100.); // 0.94
    m_TH1_m[k][id]->Sumw2();
    k = 103;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "<mu>/mufactoru", 100, 0., 100.); // 1.12
    m_TH1_m[k][id]->Sumw2();
    k = 104;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "<mu>/mufactoru2", 100, 0., 100.); // 1.20
    m_TH1_m[k][id]->Sumw2();
    k = 105;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "<mu>/mufactoru3", 100, 0., 100.); // 1.37
    m_TH1_m[k][id]->Sumw2();
    k = 110;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "NPV", 50, -0.5, 49.5);
    m_TH1_m[k][id]->Sumw2();
    k = 111;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "ntr_PV0", 100, -0.5, 99.5);
    m_TH1_m[k][id]->Sumw2();
    k = 112;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "z-Vertex", 50, -250., 250.);
    m_TH1_m[k][id]->Sumw2();
    k = 113;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "Delta R truth-reco", 100, 0., 1.);
    m_TH1_m[k][id]->Sumw2();
    k = 114;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "Scale factors", 100, 0.900, 1.100);
    m_TH1_m[k][id]->Sumw2();
    k = 115;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "Scale factors + unc.", 100, 0.900, 1.100);
    m_TH1_m[k][id]->Sumw2();
    k = 116;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "Scale factors - unc.", 100, 0.900, 1.100);
    m_TH1_m[k][id]->Sumw2();
    k = 201;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "Rho - central", 100, 0., 25.);
    m_TH1_m[k][id]->Sumw2();
    k = 202;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "Rho - central low mu", 100, 0., 25.);
    m_TH1_m[k][id]->Sumw2();
    k = 203;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "Rho - central high mu", 100, 0., 25.);
    m_TH1_m[k][id]->Sumw2();
    k = 204;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "Rho - central sigma", 100, 0., 25.);
    m_TH1_m[k][id]->Sumw2();
    k = 205;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "Rho - forward", 100, 0., 25.);
    m_TH1_m[k][id]->Sumw2();
    k = 206;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "Rho - forward low mu", 100, 0., 25.);
    m_TH1_m[k][id]->Sumw2();
    k = 207;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "Rho - forward high mu", 100, 0., 25.);
    m_TH1_m[k][id]->Sumw2();
    k = 208;
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "Rho - forward sigma", 100, 0., 25.);
    m_TH1_m[k][id]->Sumw2();

    k = 301; // Inclusive eTgamma region
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "PartonTruthLabelID - Reco", 44, -22, 22);
    m_TH1_m[k][id]->Sumw2();
    k = 302; // Inclusive eTgamma region
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "PartonTruthLabelID - Truth", 44, -22, 22);
    m_TH1_m[k][id]->Sumw2();
    k = 303; // central SS reco
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "PartonTruthLabelID - Reco - central SS", 44, -22, 22);
    m_TH1_m[k][id]->Sumw2();
    k = 304; // central SS truth
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "PartonTruthLabelID - Truth - central SS", 44, -22, 22);
    m_TH1_m[k][id]->Sumw2();
    k = 305; // central OS reco
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "PartonTruthLabelID - Reco - central OS", 44, -22, 22);
    m_TH1_m[k][id]->Sumw2();
    k = 306; // central OS truth
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "PartonTruthLabelID - Truth - central OS", 44, -22, 22);
    m_TH1_m[k][id]->Sumw2();
    k = 307; // forward SS - reco
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "PartonTruthLabelID - Reco - forward SS", 44, -22, 22);
    m_TH1_m[k][id]->Sumw2();
    k = 308; // forward SS - truth
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "PartonTruthLabelID - Truth - forward SS", 44, -22, 22);
    m_TH1_m[k][id]->Sumw2();
    k = 309; // forward OS - reco
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "PartonTruthLabelID - Reco - forward OS", 44, -22, 22);
    m_TH1_m[k][id]->Sumw2();
    k = 310; // forward OS - truth
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "PartonTruthLabelID - Truth - forward OS", 44, -22, 22);
    m_TH1_m[k][id]->Sumw2();
    k = 311; // very forward SS - reco
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "PartonTruthLabelID - Reco - very forward SS", 44, -22, 22);
    m_TH1_m[k][id]->Sumw2();
    k = 312; // very forward SS - truth
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "PartonTruthLabelID - Truth - very forward SS", 44, -22, 22);
    m_TH1_m[k][id]->Sumw2();
    k = 313; // very forward OS - reco
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "PartonTruthLabelID - Reco - very forward OS", 44, -22, 22);
    m_TH1_m[k][id]->Sumw2();
    k = 314; // very forward OS - truth
    histo.str("");
    histo << "TH1_m_" << k << "_" << id;
    m_TH1_m[k][id] = new TH1D(histo.str().c_str(), "PartonTruthLabelID - Truth - very forward OS", 44, -22, 22);
    m_TH1_m[k][id]->Sumw2();

    // Histograms for Sherpa NLO weights
    for (unsigned int i = 0; i < 350; i++)
    {
      histo.str("");
      histo << "TH1_g_" << i << "_" << id;
      m_TH1_g[i][id] = new TH1D(histo.str().c_str(), "events", 1, 0.5, 1.5);
      m_TH1_g[i][id]->Sumw2();
    }

    // Histograms for weights spread
    k = 1;
    histo.str("");
    histo << "TH2_h_" << k << "_" << 0 << "_" << id;
    m_TH2_h[k][0][id] = new TH2D(histo.str().c_str(), "Weights 1", 100, 25, 2500, 400, -20, 20); // log vs max
    m_TH2_h[k][0][id]->Sumw2();
    k = 2;
    histo.str("");
    histo << "TH2_h_" << k << "_" << 0 << "_" << id;
    m_TH2_h[k][0][id] = new TH2D(histo.str().c_str(), "Weights 2", 100, 25, 2500, 400, -20, 20); // log vs pTgamma
    m_TH2_h[k][0][id]->Sumw2();
    k = 3;
    histo.str("");
    histo << "TH2_h_" << k << "_" << 0 << "_" << id;
    m_TH2_h[k][0][id] = new TH2D(histo.str().c_str(), "Weights 3", 100, 25, 2500, 400, -20, 20); // log vs pTjet
    m_TH2_h[k][0][id]->Sumw2();

    // Histograms for weights spread (without weights)
    k = 11;
    histo.str("");
    histo << "TH2_h_" << k << "_" << 0 << "_" << id;
    m_TH2_h[k][0][id] = new TH2D(histo.str().c_str(), "Weights 1", 100, 25, 2500, 400, -20, 20); // log vs max
    m_TH2_h[k][0][id]->Sumw2();
    k = 12;
    histo.str("");
    histo << "TH2_h_" << k << "_" << 0 << "_" << id;
    m_TH2_h[k][0][id] = new TH2D(histo.str().c_str(), "Weights 2", 100, 25, 2500, 400, -20, 20); // log vs pTgamma
    m_TH2_h[k][0][id]->Sumw2();
    k = 13;
    histo.str("");
    histo << "TH2_h_" << k << "_" << 0 << "_" << id;
    m_TH2_h[k][0][id] = new TH2D(histo.str().c_str(), "Weights 3", 100, 25, 2500, 400, -20, 20); // log vs pTjet
    m_TH2_h[k][0][id]->Sumw2();

    // Histograms to study the correlation between HT and PT
    for (unsigned int kl = 21; kl <= 24; kl++)
    {
      histo.str("");
      histo << "TH2_h_" << kl << "_" << 0 << "_" << id;
      m_TH2_h[kl][0][id] = new TH2D(histo.str().c_str(), "Correlation_htpt", 496, 20, 2500, 496, 20, 2500); // log vs HT
      m_TH2_h[kl][0][id]->Sumw2();
    }

    // With no weights
    k = 551;
    histo.str("");
    histo << "TH1_h_" << k << "_" << 0 << "_" << id;
    m_TH1_h[k][0][id] = new TH1D(histo.str().c_str(), "HT", 496, 20, 2500);
    m_TH1_h[k][0][id]->Sumw2();
    k = 552;
    histo.str("");
    histo << "TH1_h_" << k << "_" << 0 << "_" << id;
    m_TH1_h[k][0][id] = new TH1D(histo.str().c_str(), "PT", 496, 20, 2500);
    m_TH1_h[k][0][id]->Sumw2();
    // With weights
    k = 553;
    histo.str("");
    histo << "TH1_h_" << k << "_" << 0 << "_" << id;
    m_TH1_h[k][0][id] = new TH1D(histo.str().c_str(), "HT", 496, 20, 2500);
    m_TH1_h[k][0][id]->Sumw2();
    k = 554;
    histo.str("");
    histo << "TH1_h_" << k << "_" << 0 << "_" << id;
    m_TH1_h[k][0][id] = new TH1D(histo.str().c_str(), "PT", 496, 20, 2500);
    m_TH1_h[k][0][id]->Sumw2();

    // Variations
    for (unsigned int ik = 0; ik < m_var; ik++)
    {

      // histograms for inclusive photons in control regions
      for (unsigned int i = 0; i <= 4; i++)
      {

        // Inclusive histograms

        k = 100 * i + 100;
        histo.str("");
        histo << "TH1_h_" << k << "_" << ik << "_" << id;
        m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "inclusive photon eTiso", 125, -25, 100);
        m_TH1_h[k][ik][id]->Sumw2();

        // Etgamma info for luminosity studies
        k = 100 * i + 140;
        histo.str("");
        histo << "TH1_h_" << k << "_" << ik << "_" << id;
        m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "inclusive photon pT - luminosity", 14, m_phptbins_bis);
        m_TH1_h[k][ik][id]->Sumw2();

        // Etgamma for stitching studies
        k = 100 * i + 141;
        histo.str("");
        histo << "TH1_h_" << k << "_" << ik << "_" << id;
        m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "inclusive photon pT - stitching", 3983, 17, 4000);
        m_TH1_h[k][ik][id]->Sumw2();

        k = 100 * i + 101;
        histo.str("");
        histo << "TH1_h_" << k << "_" << ik << "_" << id;
        m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "inclusive photon pT", 29, m_phptbins);
        m_TH1_h[k][ik][id]->Sumw2();
        // Theoretical variations for SNLO
        if (ik == 0 and i == 4 and id == 2)
        {
          for (unsigned int iv = 0; iv <= 350; iv++)
          {
            histo.str("");
            histo << "TH1_h_snlo" << k << "_" << iv << "_" << ik;
            m_TH1_hsnlo[k][iv] = new TH1D(histo.str().c_str(), "SNLO variations", 29, m_phptbins);
            m_TH1_hsnlo[k][iv]->Sumw2();
          }
        }

        // Etagamma regions
        for (unsigned int il = 1; il <= 6; il++)
        {
          k = 100 * i + 130 + il;
          histo.str("");
          histo << "TH1_h_" << k << "_" << ik << "_" << id;
          m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "inclusive photon pT", 29, m_phptbins);
          m_TH1_h[k][ik][id]->Sumw2();
          // Theoretical variations for SNLO
          if (ik == 0 and i == 4 and id == 2)
          {
            for (unsigned int iv = 0; iv <= 350; iv++)
            {
              histo.str("");
              histo << "TH1_h_snlo" << k << "_" << iv << "_" << ik;
              m_TH1_hsnlo[k][iv] = new TH1D(histo.str().c_str(), "SNLO variations", 29, m_phptbins);
              m_TH1_hsnlo[k][iv]->Sumw2();
            }
          }
        }

        k = 100 * i + 102;
        histo.str("");
        histo << "TH1_h_" << k << "_" << ik << "_" << id;
        m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "inclusive photon eta", 12, m_phetabins);
        m_TH1_h[k][ik][id]->Sumw2();
        // Theoretical variations for SNLO
        if (ik == 0 and i == 4 and id == 2)
        {
          for (unsigned int iv = 0; iv <= 350; iv++)
          {
            histo.str("");
            histo << "TH1_h_snlo" << k << "_" << iv << "_" << ik;
            m_TH1_hsnlo[k][iv] = new TH1D(histo.str().c_str(), "SNLO variations", 12, m_phetabins);
            m_TH1_hsnlo[k][iv]->Sumw2();
          }
        }

        // NEW plots Julio study
        k = 1 + i;
        histo.str("");
        histo << "TH1_hf_" << k << "_" << 0 << "_" << id;
        if (i == 0)
        {
          m_TH1_hf[k][id] = new TH1D(histo.str().c_str(), "inclusive photon eta", 24, -2.37, 2.37);
        }
        if (i == 1)
        {
          m_TH1_hf[k][id] = new TH1D(histo.str().c_str(), "inclusive photon eta", 48, -2.37, 2.37);
        }
        if (i == 2)
        {
          m_TH1_hf[k][id] = new TH1D(histo.str().c_str(), "inclusive photon eta", 96, -2.37, 2.37);
        }
        if (i == 3)
        {
          m_TH1_hf[k][id] = new TH1D(histo.str().c_str(), "inclusive photon eta", 192, -2.37, 2.37);
        }
        if (i == 4)
        {
          m_TH1_hf[k][id] = new TH1D(histo.str().c_str(), "inclusive photon eta", 384, -2.37, 2.37);
        }
        m_TH1_hf[k][id]->Sumw2();

        k = 100 * i + 103;
        histo.str("");
        histo << "TH1_h_" << k << "_" << ik << "_" << id;
        m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "inclusive photon phi", 16, -m_pi, m_pi);
        m_TH1_h[k][ik][id]->Sumw2();
        // Theoretical variations for SNLO
        if (ik == 0 and i == 4 and id == 2)
        {
          for (unsigned int iv = 0; iv <= 350; iv++)
          {
            histo.str("");
            histo << "TH1_h_snlo" << k << "_" << iv << "_" << ik;
            m_TH1_hsnlo[k][iv] = new TH1D(histo.str().c_str(), "SNLO variations", 16, -m_pi, m_pi);
            m_TH1_hsnlo[k][iv]->Sumw2();
          }
        }

        // NEW plots Julio study
        k = 11 + i;
        histo.str("");
        histo << "TH1_hf_" << k << "_" << 0 << "_" << id;
        if (i == 0)
        {
          m_TH1_hf[k][id] = new TH1D(histo.str().c_str(), "inclusive photon phi", 16, -m_pi, m_pi);
        }
        if (i == 1)
        {
          m_TH1_hf[k][id] = new TH1D(histo.str().c_str(), "inclusive photon phi", 32, -m_pi, m_pi);
        }
        if (i == 2)
        {
          m_TH1_hf[k][id] = new TH1D(histo.str().c_str(), "inclusive photon phi", 64, -m_pi, m_pi);
        }
        if (i == 3)
        {
          m_TH1_hf[k][id] = new TH1D(histo.str().c_str(), "inclusive photon phi", 128, -m_pi, m_pi);
        }
        if (i == 4)
        {
          m_TH1_hf[k][id] = new TH1D(histo.str().c_str(), "inclusive photon phi", 256, -m_pi, m_pi);
        }
        m_TH1_hf[k][id]->Sumw2();

        // Photon + jet histograms

        // Etgamma for stitching studies
        k = 100 * i + 142;
        histo.str("");
        histo << "TH1_h_" << k << "_" << ik << "_" << id;
        m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "photon+jet photon pT - stitching", 3983, 17, 4000);
        m_TH1_h[k][ik][id]->Sumw2();

        k = 100 * i + 111;
        histo.str("");
        histo << "TH1_h_" << k << "_" << ik << "_" << id;
        m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "photon+jet photon pT", 29, m_phptbins);
        m_TH1_h[k][ik][id]->Sumw2();
        // Theoretical variations for SNLO
        if (ik == 0 and i == 4 and id == 2)
        {
          for (unsigned int iv = 0; iv <= 350; iv++)
          {
            histo.str("");
            histo << "TH1_h_snlo" << k << "_" << iv << "_" << ik;
            m_TH1_hsnlo[k][iv] = new TH1D(histo.str().c_str(), "SNLO variations", 29, m_phptbins);
            m_TH1_hsnlo[k][iv]->Sumw2();
          }
        }

        k = 100 * i + 112;
        histo.str("");
        histo << "TH1_h_" << k << "_" << ik << "_" << id;
        m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "photon+jet photon eta", 12, m_phetabins);
        m_TH1_h[k][ik][id]->Sumw2();
        // Theoretical variations for SNLO
        if (ik == 0 and i == 4 and id == 2)
        {
          for (unsigned int iv = 0; iv <= 350; iv++)
          {
            histo.str("");
            histo << "TH1_h_snlo" << k << "_" << iv << "_" << ik;
            m_TH1_hsnlo[k][iv] = new TH1D(histo.str().c_str(), "SNLO variations", 12, m_phetabins);
            m_TH1_hsnlo[k][iv]->Sumw2();
          }
        }

        k = 100 * i + 113;
        histo.str("");
        histo << "TH1_h_" << k << "_" << ik << "_" << id;
        m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "photon+jet photon phi", 16, -m_pi, m_pi);
        m_TH1_h[k][ik][id]->Sumw2();
        // Theoretical variations for SNLO
        if (ik == 0 and i == 4 and id == 2)
        {
          for (unsigned int iv = 0; iv <= 350; iv++)
          {
            histo.str("");
            histo << "TH1_h_snlo" << k << "_" << iv << "_" << ik;
            m_TH1_hsnlo[k][iv] = new TH1D(histo.str().c_str(), "SNLO variations", 16, -m_pi, m_pi);
            m_TH1_hsnlo[k][iv]->Sumw2();
          }
        }

        // jet multiplicity
        k2 = 10 * i + 801;
        histo.str("");
        histo << "TH1_h_" << k2 << "_" << ik << "_" << id;
        m_TH1_h[k2][ik][id] = new TH1D(histo.str().c_str(), "photon+jet multiplicity", 20, 0., 20);
        m_TH1_h[k2][ik][id]->Sumw2();

        // Jet histograms

        // jets: jet pT
        k = 100 * i + 114;
        histo.str("");
        histo << "TH1_h_" << k << "_" << ik << "_" << id;
        m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "photon+jet jet pT", 24, m_jetptbins);
        m_TH1_h[k][ik][id]->Sumw2();
        // Theoretical variations for SNLO
        if (ik == 0 and i == 4 and id == 2)
        {
          for (unsigned int iv = 0; iv <= 350; iv++)
          {
            histo.str("");
            histo << "TH1_h_snlo" << k << "_" << iv << "_" << ik;
            m_TH1_hsnlo[k][iv] = new TH1D(histo.str().c_str(), "SNLO variations", 24, m_jetptbins);
            m_TH1_hsnlo[k][iv]->Sumw2();
          }
        }

        // jets: rapidity jet
        k = 100 * i + 115;
        histo.str("");
        histo << "TH1_h_" << k << "_" << ik << "_" << id;
        m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "photon+jet jet |y|", 22, 0., 4.4);
        m_TH1_h[k][ik][id]->Sumw2();
        // Theoretical variations for SNLO
        if (ik == 0 and i == 4 and id == 2)
        {
          for (unsigned int iv = 0; iv <= 350; iv++)
          {
            histo.str("");
            histo << "TH1_h_snlo" << k << "_" << iv << "_" << ik;
            m_TH1_hsnlo[k][iv] = new TH1D(histo.str().c_str(), "SNLO variations", 22, 0., 4.4);
            m_TH1_hsnlo[k][iv]->Sumw2();
          }
        }

        // jets: phi jet
        k = 100 * i + 116;
        histo.str("");
        histo << "TH1_h_" << k << "_" << ik << "_" << id;
        m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "photon+jet jet phi", 16, -m_pi, m_pi);
        m_TH1_h[k][ik][id]->Sumw2();
        // Theoretical variations for SNLO
        if (ik == 0 and i == 4 and id == 2)
        {
          for (unsigned int iv = 0; iv <= 350; iv++)
          {
            histo.str("");
            histo << "TH1_h_snlo" << k << "_" << iv << "_" << ik;
            m_TH1_hsnlo[k][iv] = new TH1D(histo.str().c_str(), "SNLO variations", 16, -m_pi, m_pi);
            m_TH1_hsnlo[k][iv]->Sumw2();
          }
        }

        // jets: DeltaRapidity
        k = 100 * i + 117;
        histo.str("");
        histo << "TH1_h_" << k << "_" << ik << "_" << id;
        m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "photon+jet DeltaY", 12, 0, 4.8);
        m_TH1_h[k][ik][id]->Sumw2();
        // Theoretical variations for SNLO
        if (ik == 0 and i == 4 and id == 2)
        {
          for (unsigned int iv = 0; iv <= 350; iv++)
          {
            histo.str("");
            histo << "TH1_h_snlo" << k << "_" << iv << "_" << ik;
            m_TH1_hsnlo[k][iv] = new TH1D(histo.str().c_str(), "SNLO variations", 12, 0, 4.8);
            m_TH1_hsnlo[k][iv]->Sumw2();
          }
        }

        // jets: DeltaPhi
        k = 100 * i + 118;
        histo.str("");
        histo << "TH1_h_" << k << "_" << ik << "_" << id;
        m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "photon+jet DeltaPhi", 5, m_pi / 2., m_pi);
        m_TH1_h[k][ik][id]->Sumw2();
        // Theoretical variations for SNLO
        if (ik == 0 and i == 4 and id == 2)
        {
          for (unsigned int iv = 0; iv <= 350; iv++)
          {
            histo.str("");
            histo << "TH1_h_snlo" << k << "_" << iv << "_" << ik;
            m_TH1_hsnlo[k][iv] = new TH1D(histo.str().c_str(), "SNLO variations", 5, m_pi / 2., m_pi);
            m_TH1_hsnlo[k][iv]->Sumw2();
          }
        }

        // jets: m_gammajet
        k = 100 * i + 119;
        histo.str("");
        histo << "TH1_h_" << k << "_" << ik << "_" << id;
        m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "photon+jet m_gj", 22, m_massbins);
        m_TH1_h[k][ik][id]->Sumw2();
        // Theoretical variations for SNLO
        if (ik == 0 and i == 4 and id == 2)
        {
          for (unsigned int iv = 0; iv <= 350; iv++)
          {
            histo.str("");
            histo << "TH1_h_snlo" << k << "_" << iv << "_" << ik;
            m_TH1_hsnlo[k][iv] = new TH1D(histo.str().c_str(), "SNLO variations", 22, m_massbins);
            m_TH1_hsnlo[k][iv]->Sumw2();
          }
        }

        // jets: cosThetaStar
        k = 100 * i + 120;
        histo.str("");
        histo << "TH1_h_" << k << "_" << ik << "_" << id;
        m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "photon+jet cosThetaStar", 8, m_costhetabins);
        m_TH1_h[k][ik][id]->Sumw2();
        // Theoretical variations for SNLO
        if (ik == 0 and i == 4 and id == 2)
        {
          for (unsigned int iv = 0; iv <= 350; iv++)
          {
            histo.str("");
            histo << "TH1_h_snlo" << k << "_" << iv << "_" << ik;
            m_TH1_hsnlo[k][iv] = new TH1D(histo.str().c_str(), "SNLO variations", 8, m_costhetabins);
            m_TH1_hsnlo[k][iv]->Sumw2();
          }
        }

        // Photon + jet in different configurations
        for (unsigned int il = 1; il <= 6; il++)
        {

          k = 100 * i + 120 + il;
          histo.str("");
          histo << "TH1_h_" << k << "_" << ik << "_" << id;
          m_TH1_h[k][ik][id] = new TH1D(histo.str().c_str(), "photon+jet photon pt", 29, m_phptbins);
          m_TH1_h[k][ik][id]->Sumw2();
          // Theoretical variations for SNLO
          if (ik == 0 and i == 4 and id == 2)
          {
            for (unsigned int iv = 0; iv <= 350; iv++)
            {
              histo.str("");
              histo << "TH1_h_snlo" << k << "_" << iv << "_" << ik;
              m_TH1_hsnlo[k][iv] = new TH1D(histo.str().c_str(), "SNLO variations", 29, m_phptbins);
              m_TH1_hsnlo[k][iv]->Sumw2();
            }
          }

          // jet multiplicity
          k2 = 10 * i + 801 + il;
          histo.str("");
          histo << "TH1_h_" << k2 << "_" << ik << "_" << id;
          m_TH1_h[k2][ik][id] = new TH1D(histo.str().c_str(), "photon+jet multiplicity", 20, 0., 20);
          m_TH1_h[k2][ik][id]->Sumw2();
        }

      } // four control regions

    } // loop over systematic variations

  } // Hard or Brem loop

  cout << " >> Histograms defined" << endl;
  outfile << " - Histograms defined \n"
          << endl;

  // Number of entries
  unsigned int nentries = fChain->GetEntries();

  // Checking purposes
  // nentries = 100000;
  bool debug = false;

  outfile << " ************************* " << endl;
  outfile << " Number of entries = " << nentries << endl;
  outfile << " ************************* " << endl;

  cout << " >> Loop over entries " << endl;

  // Loop over entries
  for (unsigned int jentry = 0; jentry < nentries; ++jentry)
  {

    // load the event
    fChain->GetEntry(jentry);

    // Event information
    nfile = fChain->GetTreeNumber() + 1;
    if (nfile != nfileold)
    {
      nfileold = nfile;
      outfile << " nfile = " << nfile << " jentry = " << jentry << endl;
      outfile << " ------------------------------------- " << endl;
    }

    long int run_number = RunNumber;         // run number
    long int event_number = EventNumber;     // event number
    long int channel_number = ChannelNumber; // channel number (DSID of the slice)

    // cout << " run_number: " << run_number << "; event_number: " << event_number << endl;
    // cout << event_number << endl;

    // DATA/MC check (many tools are applied either to data or MC)
    // not included in the ntuples

    // Total number of events
    m_cutFlow[0][0][0][0] += 1;
    m_TH1_m[0][2]->Fill(m_count_events);

    ////////////////
    // LUMINOSITY //
    ////////////////

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

    double scale_factor_d1516 = lum1516 / lumR2;
    double scale_factor_d17 = lum17 / lumR2;
    double scale_factor_d18 = lum18 / lumR2;

    /////////////
    // WEIGHTS //
    /////////////

    double ww = 1.0;       // EVENT weight
    double ww_slice = 1.0; // SLICE weight
    double wVAR[350] = {}; // weights for theoretical variations

    /*
      Double_t        weightmc;     // weight of mc event
      vector<double>  *weightmcVAR; // weights for variations of SHERPA NLO
    */

    ww = weightmc;

    // for different slices
    double weightpythia[50] = {};
    double weightsherpalo[50] = {};
    double weightsherpanlo[50] = {};
    double samplexsec = 1;
    double filtereff = 1;
    double sow = 1;
    double nevents = 1;

    if (debug)
      cout << endl;
    if (debug)
      cout << " Slice weights " << endl;

    if (SWGTflag == true)
    {

      // Assigning weights:

      if (mc == "sherpa222")
      {
        if (ptmccut == 17)
        {
          samplexsec = 4.1548E+02;
          filtereff = 1;
          sow = 17928844.;
          nevents = 34984000;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
        else if (ptmccut == 35)
        {
          samplexsec = 4.3976E+01;
          filtereff = 1;
          sow = 19179839.;
          nevents = 34977000;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
        else if (ptmccut == 70)
        {
          samplexsec = 4.5265E+00;
          filtereff = 1;
          sow = 25993602.;
          nevents = 43234000;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
        else if (ptmccut == 140)
        {
          samplexsec = 3.7605E-01;
          filtereff = 1;
          sow = 28013604.;
          nevents = 43223800;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
        else if (ptmccut == 280)
        {
          samplexsec = 2.1851E-02;
          filtereff = 1;
          sow = 8670886.3;
          nevents = 12965400;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
        else if (ptmccut == 500)
        {
          samplexsec = 1.4637E-03;
          filtereff = 1;
          sow = 5670074.8;
          nevents = 8320100;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
        else if (ptmccut == 1000)
        {
          samplexsec = 2.9867E-05;
          filtereff = 1;
          sow = 4274294.2;
          nevents = 6138020;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
      }
      else if (mc == "run2_sherpa2216")
      {
        if (ptmccut == 17)
        {
          samplexsec = 296.1161446776;
          filtereff = 1;
          sow = 5.5197207e+15;
          nevents = 300000;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
        else if (ptmccut == 35)
        {
          samplexsec = 33.5378645278883;
          filtereff = 1;
          sow = 3.5580971e+14;
          nevents = 230000;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
        else if (ptmccut == 70)
        {
          samplexsec = 3.575765450338;
          filtereff = 1;
          sow = 6.6317324e+13;
          nevents = 300000;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
        else if (ptmccut == 140)
        {
          samplexsec = 0.29805978056574;
          filtereff = 1;
          sow = 4.9664862e+12;
          nevents = 150000;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
        else if (ptmccut == 280)
        {
          samplexsec = 0.0173283436938171;
          filtereff = 1;
          sow = 1.2293309e+11;
          nevents = 35000;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
        else if (ptmccut == 500)
        {
          samplexsec = 0.00111853366340933;
          filtereff = 1;
          sow = 8.4008953e+09;
          nevents = 30000;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
        else if (ptmccut == 1000)
        {
          samplexsec = 2.08355533615433e-05;
          filtereff = 1;
          sow = 2.0933516e+08;
          nevents = 12000;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
      }
      else if (mc == "run3_sherpa2216")
      {
        if (ptmccut == 17)
        {
          samplexsec = 310.32386595705;
          filtereff = 1;
          sow = 4.5326852e+15;
          nevents = 300000;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
        else if (ptmccut == 35)
        {
          samplexsec = 35.423878046302;
          filtereff = 1;
          sow = 5.0174638e+14;
          nevents = 230000;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
        else if (ptmccut == 70)
        {
          samplexsec = 3.79918676603325;
          filtereff = 1;
          sow = 8.1171275e+13;
          nevents = 300000;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
        else if (ptmccut == 140)
        {
          samplexsec = 0.32366425630798;
          filtereff = 1;
          sow = 3.8816069e+12;
          nevents = 150000;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
        else if (ptmccut == 280)
        {
          samplexsec = 0.0185982042850464;
          filtereff = 1;
          sow = 9.7788403e+10;
          nevents = 35000;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
        else if (ptmccut == 500)
        {
          samplexsec = 0.001278100925494;
          filtereff = 1;
          sow = 1.3447262e+10;
          nevents = 30000;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
        else if (ptmccut == 1000)
        {
          samplexsec = 2.7071366785235e-05;
          filtereff = 1;
          sow = 3.6156054e+08;
          nevents = 12000;
          ww_slice = samplexsec * filtereff * 1000 / sow;
          //ww_slice = samplexsec * filtereff * 1000 / nevents;
        }
      }

    } // Slice weighting flag

    // cout << " ww = " <<ww<< " ww_slice = " <<ww_slice<< endl;

    m_TH1_m[1][2]->Fill(ww_slice, ww);

    /////////////////////
    // WEIGHT ANALYSIS //
    /////////////////////

    // sum of weight before the sum
    m_TH1_m[2][2]->Fill(m_count_events, ww);
    if (fabs(weightmc) <= 100)
    {
      m_TH1_m[3][2]->Fill(m_count_events, ww);
    }
    if (fabs(weightmc) > 100)
    {
      m_TH1_m[4][2]->Fill(m_count_events, ww);
    }
    // Negative weights
    if (weightmc < 0)
    {
      m_TH1_m[7][2]->Fill(m_count_events, ww);
    }

    // large weight cut
    if (mc == "sherpa222" and fabs(weightmc) > 100)
      ww = 0;

    for (unsigned int i = 0; i < weightmcVAR->size(); i++)
    {
      wVAR[i] = weightmcVAR->at(i);
      // cout << "wVAR[" <<i<< "] = " <<wVAR[i]<< endl;
    }

    // Theory uncertainties
    // [From 0 to 317]
    for (unsigned int i = 0; i < weightmcVAR->size(); i++)
    {

      if (mc == "sherpa222")
      {
        if (fabs(wVAR[i]) <= 100)
        {
          m_TH1_g[i][2]->Fill(m_count_events, double(wVAR[i]));
        }
        else
        {
          wVAR[i] = 0;
        }
      }
      else
      {
        m_TH1_g[i][2]->Fill(m_count_events, double(wVAR[i]));
      }
    }

    m_TH1_m[5][2]->Fill(m_count_events, ww);

    ////// Define nominal weight
    const double weightmc_only_0 = ww;
    const double weightmc_0 = ww * ww_slice;
    // cout << " wfinal = " <<weightmc_0<< "; ww = " <<ww<< "; ww_slice = " <<ww_slice<< endl;
    ww = weightmc_0;

    m_TH1_m[6][2]->Fill(m_count_events, ww);

    // Check MC weights
    m_TH1_m[8][2]->Fill(weightmc_only_0, 1);
    if (weightmc_only_0 > 0)
    {
      m_TH1_m[9][2]->Fill(weightmc_only_0, 1);
    }
    else
    {
      m_TH1_m[10][2]->Fill(fabs(weightmc_only_0), 1);
    }

    // Average number of interactions
    double m_mu = 0.;
    // m_mu = MU;

    /////////////////
    // Truth level //
    /////////////////

    if (debug)
      cout << " Truth level " << endl;

    // get leading photon
    m_ph_g1 = ph_g1;
    if (m_ph_g1 == 1)
    {

      // get leading photon properties
      photg[7] = PhotgET;   // ntuple photg[7] -> MeV
      photg[6] = PhotgPHI;  // phi
      photg[10] = PhotgETA; // eta

      photg[5] = 2. * atan(exp(-photg[10]));               // theta
      photg[4] = photg[7] / sin(photg[5]);                 // energy
      photg[1] = photg[4] * sin(photg[5]) * cos(photg[6]); // px
      photg[2] = photg[4] * sin(photg[5]) * sin(photg[6]); // py
      photg[3] = photg[4] * cos(photg[5]);                 // pz
      if (rad == 4)
      {
        photg[11] = double(PhotgETISO_40); // Etiso
      }
      else if (rad == 2)
      {
        photg[11] = double(PhotgETISO_20); // Etiso
      }
    }
    else if (m_ph_g1 != 1)
    {
      cout << " WARNING: no truth photon! = " << " m_ph_g1 = " << m_ph_g1 << endl;
      continue;
    }

    m_cutFlow[1][0][0][0] += 1;

    // Check-point PYTHIA slices
    // m_cutFlow[2][0][0][0] += 1;

    // Classification according to hard/brem for leading truth photon
    int idn = 0;
    idn = ID_hardbrem;
    if (idn == 0)
    {
      continue;
    }
    m_cutFlow[3][0][0][0] += 1;
    m_cutFlow[3][0][0][idn] += 1;

    ////////////////////////////
    // Truth photon selection //
    ////////////////////////////

    // pT cut
    flag_t1 = false;
    // Eta cut
    flag_t2 = false;
    // Isolation cut
    flag_t3 = false;
    // At least one jet
    flag_t4 = false;
    ipjt = 0;

    if (debug)
      cout << " Truth photons " << endl;

    // Truth pt cut
    if (photg[7] > m_phptcut)
    {
      flag_t1 = true;
      m_cutFlow[4][0][0][0] += 1;
      m_cutFlow[4][0][0][idn] += 1;
    }
    else
    {
      // cout << " REJECTED CANDIDATE: " << " photg[7] = " <<photg[7]<< " photg[10] = " <<photg[10]<< endl;
    }

    if (flag_t1 == true)
    {

      if (debug)
        cout << " Truth photons -> pT cut" << endl;

      // truth eta cut
      double fabs_eta = fabs(photg[10]);
      if (fabs_eta < m_phetacut1 or (fabs_eta > m_phetacut2 and fabs_eta < m_phetacut3))
      {
        flag_t2 = true;
        m_cutFlow[5][0][0][0] += 1;
        m_cutFlow[5][0][0][idn] += 1;
      }

      // Isolation cut
      flag_t3 = false;
      if (flag_t2 == true)
      {

        if (debug)
          cout << " Truth photons -> eta cut" << endl;

        // Isolation distribution histogram
        m_TH1_h[500][0][idn]->Fill(photg[11], ww); // eTiso
        m_TH1_h[400][0][idn]->Fill(photg[11], 1);  // eTiso

        // truth eTiso
        m_etisocut = 4.2e-3 * photg[7] + 4.8;
        if (photg[11] < m_etisocut)
        {

          if (debug)
            cout << " Truth photons -> isolation cut" << endl;

          flag_t3 = true;
          m_cutFlow[6][0][0][0] += 1;
          m_cutFlow[6][0][0][idn] += 1;

          //////////////////////////////////////
          // Histograms for truth photons (I) //
          //////////////////////////////////////

          // Luminosity study
          m_TH1_h[540][0][idn]->Fill(photg[7], ww);              // pt for lumi study
          m_TH1_h[440][0][idn]->Fill(photg[7], weightmc_only_0); // pt for lumi study
          m_TH1_h[340][0][idn]->Fill(photg[7], 1);               // pt for lumi study
          //
          // Stitching points study (I)
          m_TH1_h[541][0][idn]->Fill(photg[7], ww);              // pt for stitching study
          m_TH1_h[441][0][idn]->Fill(photg[7], weightmc_only_0); // pt for stitching study
          m_TH1_h[341][0][idn]->Fill(photg[7], 1);               // pt for stitching study
          //
          m_TH1_h[500 + 1][0][idn]->Fill(photg[7], ww);        // pt
          m_TH1_h[400 + 1][0][idn]->Fill(photg[7], 1);         // pt
          m_TH1_h[500 + 2][0][idn]->Fill(fabs(photg[10]), ww); // eta
          m_TH1_h[400 + 2][0][idn]->Fill(fabs(photg[10]), 1);  // eta
          //
          m_TH1_hf[1][idn]->Fill(photg[10], ww);
          m_TH1_hf[2][idn]->Fill(photg[10], ww);
          m_TH1_hf[3][idn]->Fill(photg[10], ww);
          m_TH1_hf[4][idn]->Fill(photg[10], ww);
          m_TH1_hf[5][idn]->Fill(photg[10], ww);
          //
          m_TH1_h[500 + 3][0][idn]->Fill(photg[6], ww); // phi
          m_TH1_h[400 + 3][0][idn]->Fill(photg[6], 1);  // phi
          //
          m_TH1_hf[11][idn]->Fill(photg[6], ww);
          m_TH1_hf[12][idn]->Fill(photg[6], ww);
          m_TH1_hf[13][idn]->Fill(photg[6], ww);
          m_TH1_hf[14][idn]->Fill(photg[6], ww);
          m_TH1_hf[15][idn]->Fill(photg[6], ww);

          // Histograms for theoretical variations
          for (unsigned int i = 0; i < weightmcVAR->size(); i++)
          {
            m_TH1_hsnlo[501][i]->Fill(photg[7], double(wVAR[i] * ww_slice));
            m_TH1_hsnlo[502][i]->Fill(fabs(photg[10]), double(wVAR[i] * ww_slice));
            m_TH1_hsnlo[503][i]->Fill(photg[6], double(wVAR[i] * ww_slice));
          }

          ////// Histograms in etagamma regions
          if (fabs(photg[10]) > 0.0 and fabs(photg[10]) <= 0.6)
          {
            m_TH1_h[530 + 1][0][idn]->Fill(photg[7], ww); // pt
            m_TH1_h[430 + 1][0][idn]->Fill(photg[7], 1);  // pt
            for (unsigned int i = 0; i < weightmcVAR->size(); i++)
            {
              m_TH1_hsnlo[530 + 1][i]->Fill(photg[7], double(wVAR[i] * ww_slice));
            }
          }
          if (fabs(photg[10]) > 0.6 and fabs(photg[10]) <= 0.8)
          {
            m_TH1_h[530 + 2][0][idn]->Fill(photg[7], ww); // pt
            m_TH1_h[430 + 2][0][idn]->Fill(photg[7], 1);  // pt
            for (unsigned int i = 0; i < weightmcVAR->size(); i++)
            {
              m_TH1_hsnlo[530 + 2][i]->Fill(photg[7], double(wVAR[i] * ww_slice));
            }
          }
          if (fabs(photg[10]) > 0.8 and fabs(photg[10]) <= 1.37)
          {
            m_TH1_h[530 + 3][0][idn]->Fill(photg[7], ww); // pt
            m_TH1_h[430 + 3][0][idn]->Fill(photg[7], 1);  // pt
            for (unsigned int i = 0; i < weightmcVAR->size(); i++)
            {
              m_TH1_hsnlo[530 + 3][i]->Fill(photg[7], double(wVAR[i] * ww_slice));
            }
          }
          if (fabs(photg[10]) > 1.52 and fabs(photg[10]) <= 1.81)
          {
            m_TH1_h[530 + 4][0][idn]->Fill(photg[7], ww); // pt
            m_TH1_h[430 + 4][0][idn]->Fill(photg[7], 1);  // pt
            for (unsigned int i = 0; i < weightmcVAR->size(); i++)
            {
              m_TH1_hsnlo[530 + 4][i]->Fill(photg[7], double(wVAR[i] * ww_slice));
            }
          }
          if (fabs(photg[10]) > 1.81 and fabs(photg[10]) <= 2.01)
          {
            m_TH1_h[530 + 5][0][idn]->Fill(photg[7], ww); // pt
            m_TH1_h[430 + 5][0][idn]->Fill(photg[7], 1);  // pt
            for (unsigned int i = 0; i < weightmcVAR->size(); i++)
            {
              m_TH1_hsnlo[530 + 5][i]->Fill(photg[7], double(wVAR[i] * ww_slice));
            }
          }
          if (fabs(photg[10]) > 2.01 and fabs(photg[10]) <= 2.37)
          {
            m_TH1_h[530 + 6][0][idn]->Fill(photg[7], ww); // pt
            m_TH1_h[430 + 6][0][idn]->Fill(photg[7], 1);  // pt
            for (unsigned int i = 0; i < weightmcVAR->size(); i++)
            {
              m_TH1_hsnlo[530 + 6][i]->Fill(photg[7], double(wVAR[i] * ww_slice));
            }
          }

          ////////////////
          // Truth jets //
          ////////////////

          if (debug)
            cout << " Truth jets " << endl;

          // At least one jet
          // jet_truth_n -> would give us the total number of truth jets before the selection
          int m_jet_truth_n = JettPT->size();

          if (m_jet_truth_n < 1)
          {
            // cout << " WARNING: no truth jet! = " << " m_jet_truth_n (m_jet_g1) = " <<m_jet_truth_n<<" ("<<m_jet_g1<<")"<< endl;
            // continue;
          }
          m_cutFlow[7][0][0][0] += 1;
          m_cutFlow[7][0][0][idn] += 1;

          // loop over truth jets
          m_jet_g1 = 0;
          for (unsigned int i = 0; i < m_jet_truth_n; i++)
          {

            // leading jet pT cut
            if (double(JettPT->at(i)) < m_jetptleadcut)
              continue;
            m_cutFlow[8][0][0][0] += 1;
            m_cutFlow[8][0][0][idn] += 1;

            // jet rapidity cut
            if (fabs(double(JettRAP->at(i))) > m_jetycut)
              continue;
            m_cutFlow[9][0][0][0] += 1;
            m_cutFlow[9][0][0][idn] += 1;

            // deltaR cut
            double dR_phjet = get_deltar(double(JettETA->at(i)), double(JettPHI->at(i)), photg[10], photg[6]);
            if (dR_phjet < 0.8)
              continue;
            m_cutFlow[10][0][0][0] += 1;
            m_cutFlow[10][0][0][idn] += 1;

            // cout << " i: " << i << " dR_phjet = " << dR_phjet << endl;

            m_jet_g1 += 1;

            jetg[7][m_jet_g1] = double(JettPT->at(i));
            jetg[4][m_jet_g1] = double(JettE->at(i));
            jetg[10][m_jet_g1] = double(JettETA->at(i));
            jetg[8][m_jet_g1] = double(JettRAP->at(i));
            jetg[6][m_jet_g1] = get_phijet(JettPHI->at(i));
            jetg[9][m_jet_g1] = double(JettM->at(i));

            // jetg[1][m_jet_g1]  = double(JettPX->at(i));
            // jetg[2][m_jet_g1]  = double(JettPY->at(i));
            // jetg[3][m_jet_g1]  = double(JettPZ->at(i));
            TLorentzVector jet;
            jet.SetPtEtaPhiE(jetg[7][m_jet_g1], jetg[10][m_jet_g1],
                             jetg[6][m_jet_g1], jetg[4][m_jet_g1]);
            jetg[5][m_jet_g1] = jet.Theta();
            jetg[1][m_jet_g1] = jet.Px();
            jetg[2][m_jet_g1] = jet.Py();
            jetg[3][m_jet_g1] = jet.Pz();

            jetg[11][m_jet_g1] = int(JettLABELID->at(i));
          }

          // leading jet
          ipjt = 0;
          double maxdump = -999.;

          for (unsigned int i = 1; i <= m_jet_g1; i++)
          {

            if (jetg[7][i] > maxdump)
            {
              maxdump = jetg[7][i];
              ipjt = i;
            }
          }

          // Requiring at least one jet at truth level in the final state
          if (ipjt > 0)
          {
            flag_t4 = true;
          }

          if (flag_t4 == true)
          {

            m_cutFlow[11][0][0][0] += 1;
            m_cutFlow[11][0][0][idn] += 1;

            // GET RHO ED at truth level
            double m_rho_truth_isocentral = 0., m_rho_truth_isoforward = 0.;
            double m_rho_truth_isocentral_sigma = 0., m_rho_truth_isoforward_sigma = 0.;

            m_rho_truth_isocentral = rho_truth_isocentral;
            m_rho_truth_isoforward = rho_truth_isoforward;
            m_rho_truth_isocentral_sigma = rho_truth_isocentral_sigma;
            m_rho_truth_isoforward_sigma = rho_truth_isoforward_sigma;

            ///////////////////////////////
            // Histograms for truth jets //
            ///////////////////////////////

            // Stitching points study (II)
            m_TH1_h[542][0][idn]->Fill(photg[7], ww);              // pt for stitching study
            m_TH1_h[442][0][idn]->Fill(photg[7], weightmc_only_0); // pt for stitching study
            m_TH1_h[342][0][idn]->Fill(photg[7], 1);               // pt for stitching study

            // histograms photon + jet
            m_TH1_h[500 + 10 + 1][0][idn]->Fill(photg[7], ww);        // pt
            m_TH1_h[400 + 10 + 1][0][idn]->Fill(photg[7], 1);         // pt
            m_TH1_h[500 + 10 + 2][0][idn]->Fill(fabs(photg[10]), ww); // eta
            m_TH1_h[400 + 10 + 2][0][idn]->Fill(fabs(photg[10]), 1);  // eta
            m_TH1_h[500 + 10 + 3][0][idn]->Fill(photg[6], ww);        // phi
            m_TH1_h[400 + 10 + 3][0][idn]->Fill(photg[6], 1);         // phi

            // Histograms for theoretical variations
            for (unsigned int i = 0; i < weightmcVAR->size(); i++)
            {
              m_TH1_hsnlo[500 + 10 + 1][i]->Fill(photg[7], double(wVAR[i] * ww_slice));
              m_TH1_hsnlo[500 + 10 + 2][i]->Fill(fabs(photg[10]), double(wVAR[i] * ww_slice));
              m_TH1_hsnlo[500 + 10 + 3][i]->Fill(photg[6], double(wVAR[i] * ww_slice));
            }

            // histograms jet
            m_TH1_h[500 + 10 + 4][0][idn]->Fill(jetg[7][ipjt], ww);       // pt
            m_TH1_h[400 + 10 + 4][0][idn]->Fill(jetg[7][ipjt], 1);        // pt
            m_TH1_h[500 + 10 + 5][0][idn]->Fill(fabs(jetg[8][ipjt]), ww); // rapidity
            m_TH1_h[400 + 10 + 5][0][idn]->Fill(fabs(jetg[8][ipjt]), 1);  // rapidity
            m_TH1_h[500 + 10 + 6][0][idn]->Fill(jetg[6][ipjt], ww);       // phi
            m_TH1_h[400 + 10 + 6][0][idn]->Fill(jetg[6][ipjt], 1);        // phi
            // Histograms for theoretical variations
            for (unsigned int i = 0; i < weightmcVAR->size(); i++)
            {
              m_TH1_hsnlo[500 + 10 + 4][i]->Fill(jetg[7][ipjt], double(wVAR[i] * ww_slice));
              m_TH1_hsnlo[500 + 10 + 5][i]->Fill(fabs(jetg[8][ipjt]), double(wVAR[i] * ww_slice));
              m_TH1_hsnlo[500 + 10 + 6][i]->Fill(jetg[6][ipjt], double(wVAR[i] * ww_slice));
            }

            ///////////////////////////////
            ////// Enhancing performance //
            ///////////////////////////////

            double varlog = log10((fabs(weightmc_only_0) * samplexsec) / (sow));
            double varlog_eff = log10((fabs(weightmc_only_0) * samplexsec * filtereff) / (sow));
            double htsum = MEParton_htsum;
            double maxptht = max(MEParton_htsum, photg[7]);

            // cout << " photg[7] = " <<photg[7]<< " htsum = " <<htsum<< " maxptht = " <<maxptht<< " varlog = " <<varlog<< endl;

            m_TH2_h[1][0][idn]->Fill(maxptht, varlog_eff, ww);
            m_TH2_h[2][0][idn]->Fill(photg[7], varlog_eff, ww);
            // m_TH2_h[3][0][idn]->Fill(htsum,varlog,ww);
            m_TH2_h[3][0][idn]->Fill(jetg[7][ipjt], varlog_eff, ww);

            // With no weight for the spread of weights
            m_TH2_h[11][0][idn]->Fill(maxptht, varlog_eff, 1);
            m_TH2_h[12][0][idn]->Fill(photg[7], varlog_eff, 1);
            // m_TH2_h[13][0][idn]->Fill(htsum,varlog_eff,1);
            m_TH2_h[13][0][idn]->Fill(jetg[7][ipjt], varlog_eff, 1);

            // TH2 matrices for the correlation between HT and PT
            m_TH2_h[21][0][idn]->Fill(htsum, photg[7], ww);
            m_TH2_h[22][0][idn]->Fill(photg[7], htsum, ww);
            m_TH2_h[23][0][idn]->Fill(htsum, photg[7], 1);
            m_TH2_h[24][0][idn]->Fill(photg[7], htsum, 1);
            //
            m_TH1_h[551][0][idn]->Fill(htsum, 1);     // HT
            m_TH1_h[552][0][idn]->Fill(photg[7], 1);  // PT
            m_TH1_h[553][0][idn]->Fill(htsum, ww);    // HT
            m_TH1_h[554][0][idn]->Fill(photg[7], ww); // PT

            ////// New histograms

            // DeltaRapidity_gammajet
            double DeltaRapidity = fabs(photg[10] - jetg[8][ipjt]);
            mpjg[11][ipjt] = DeltaRapidity;

            // m_gammajet
            for (unsigned int i = 1; i <= 4; i++)
            {
              mpjg[i][ipjt] = photg[i] + jetg[i][ipjt]; // 4-vector components
            }
            mpjg[7][ipjt] = fabs(photg[10] + jetg[8][ipjt]);                                                                     // eta sum
            mpjg[9][ipjt] = sqrt(mpjg[1][ipjt] * mpjg[1][ipjt] + mpjg[2][ipjt] * mpjg[2][ipjt] + mpjg[3][ipjt] * mpjg[3][ipjt]); // |p|
            mpjg[10][ipjt] = sqrt(mpjg[4][ipjt] * mpjg[4][ipjt] - mpjg[9][ipjt] * mpjg[9][ipjt]);                                // mass = sqrt(m^2 - |p|^2)

            // DeltaPhi_gammajet
            double DeltaPhi = get_deltaphi(photg[6], jetg[6][ipjt]);
            mpjg[12][ipjt] = DeltaPhi;

            // cos(theta*)
            double cosThetaStar = fabs(tanh((photg[10] - jetg[8][ipjt]) / 2.)); // cost
            mpjg[13][ipjt] = cosThetaStar;

            m_TH1_h[500 + 10 + 7][0][idn]->Fill(mpjg[11][ipjt], ww); // DeltaRapidity_gammajet
            m_TH1_h[400 + 10 + 7][0][idn]->Fill(mpjg[11][ipjt], 1);  // DeltaRapidity_gammajet
            // Histograms for theoretical variations
            for (unsigned int i = 0; i < weightmcVAR->size(); i++)
            {
              m_TH1_hsnlo[500 + 10 + 7][i]->Fill(mpjg[11][ipjt], double(wVAR[i] * ww_slice));
            }

            if (m_pi / 2. < DeltaPhi and DeltaPhi < m_pi)
            {
              m_TH1_h[500 + 10 + 8][0][idn]->Fill(mpjg[12][ipjt], ww); // DeltaPhi_gammajet
              m_TH1_h[400 + 10 + 8][0][idn]->Fill(mpjg[12][ipjt], 1);  // DeltaPhi_gammajet
              // Histograms for theoretical variations
              for (unsigned int i = 0; i < weightmcVAR->size(); i++)
              {
                m_TH1_hsnlo[500 + 10 + 8][i]->Fill(mpjg[12][ipjt], double(wVAR[i] * ww_slice));
              }
            }

            if (mpjg[10][ipjt] > mcut and mpjg[13][ipjt] < cc and mpjg[7][ipjt] < ce)
            {
              m_TH1_h[500 + 10 + 9][0][idn]->Fill(mpjg[10][ipjt], ww);  // m_gammajet
              m_TH1_h[400 + 10 + 9][0][idn]->Fill(mpjg[10][ipjt], 1);   // m_gammajet
              m_TH1_h[500 + 10 + 10][0][idn]->Fill(mpjg[13][ipjt], ww); // cos(theta*)
              m_TH1_h[400 + 10 + 10][0][idn]->Fill(mpjg[13][ipjt], 1);  // cos(theta*)
              // Histograms for theoretical variations
              for (unsigned int i = 0; i < weightmcVAR->size(); i++)
              {
                m_TH1_hsnlo[500 + 10 + 9][i]->Fill(mpjg[10][ipjt], double(wVAR[i] * ww_slice));
                m_TH1_hsnlo[500 + 10 + 10][i]->Fill(mpjg[13][ipjt], double(wVAR[i] * ww_slice));
              }
            }

            // histograms in the jet central region
            if (fabs(jetg[8][ipjt]) < 1.2)
            {

              // histograms in the Same Side (SS) configuration
              if (jetg[8][ipjt] * photg[10] > 0)
              {
                m_TH1_h[500 + 20 + 1][0][idn]->Fill(photg[7], ww); // pt
                m_TH1_h[400 + 20 + 1][0][idn]->Fill(photg[7], 1);  // pt
                // Histograms for theoretical variations
                for (unsigned int i = 0; i < weightmcVAR->size(); i++)
                {
                  m_TH1_hsnlo[500 + 20 + 1][i]->Fill(photg[7], double(wVAR[i] * ww_slice));
                }
              }

              // histograms in the Opposite Side (OS) configuration
              if (jetg[8][ipjt] * photg[10] < 0)
              {
                m_TH1_h[500 + 20 + 2][0][idn]->Fill(photg[7], ww); // pt
                m_TH1_h[400 + 20 + 2][0][idn]->Fill(photg[7], 1);  // pt
                // Histograms for theoretical variations
                for (unsigned int i = 0; i < weightmcVAR->size(); i++)
                {
                  m_TH1_hsnlo[500 + 20 + 2][i]->Fill(photg[7], double(wVAR[i] * ww_slice));
                }
              }
            }

            // histograms in the jet forward region
            if (fabs(jetg[8][ipjt]) >= 1.2 and fabs(jetg[8][ipjt]) < 2.8)
            {

              // histograms in the Same Side (SS) configuration
              if (jetg[8][ipjt] * photg[10] > 0)
              {
                m_TH1_h[500 + 20 + 3][0][idn]->Fill(photg[7], ww); // pt
                m_TH1_h[400 + 20 + 3][0][idn]->Fill(photg[7], 1);  // pt
                // Histograms for theoretical variations
                for (unsigned int i = 0; i < weightmcVAR->size(); i++)
                {
                  m_TH1_hsnlo[500 + 20 + 3][i]->Fill(photg[7], double(wVAR[i] * ww_slice));
                }
              }

              // histograms in the Opposite Side (OS) configuration
              if (jetg[8][ipjt] * photg[10] < 0)
              {
                m_TH1_h[500 + 20 + 4][0][idn]->Fill(photg[7], ww); // pt
                m_TH1_h[400 + 20 + 4][0][idn]->Fill(photg[7], 1);  // pt
                // Histograms for theoretical variations
                for (unsigned int i = 0; i < weightmcVAR->size(); i++)
                {
                  m_TH1_hsnlo[500 + 20 + 4][i]->Fill(photg[7], double(wVAR[i] * ww_slice));
                }
              }
            }

            // histograms in the jet most-forward region
            if (fabs(jetg[8][ipjt]) >= 2.8 and fabs(jetg[8][ipjt]) < 4.4)
            {

              // histograms in the Same Side (SS) configuration
              if (jetg[8][ipjt] * photg[10] > 0)
              {
                m_TH1_h[500 + 20 + 5][0][idn]->Fill(photg[7], ww); // pt
                m_TH1_h[400 + 20 + 5][0][idn]->Fill(photg[7], 1);  // pt
                // Histograms for theoretical variations
                for (unsigned int i = 0; i < weightmcVAR->size(); i++)
                {
                  m_TH1_hsnlo[500 + 20 + 5][i]->Fill(photg[7], double(wVAR[i] * ww_slice));
                }
              }

              // histograms in the Opposite Side (OS) configuration
              if (jetg[8][ipjt] * photg[10] < 0)
              {
                m_TH1_h[500 + 20 + 6][0][idn]->Fill(photg[7], ww); // pt
                m_TH1_h[400 + 20 + 6][0][idn]->Fill(photg[7], 1);  // pt
                // Histograms for theoretical variations
                for (unsigned int i = 0; i < weightmcVAR->size(); i++)
                {
                  m_TH1_hsnlo[500 + 20 + 6][i]->Fill(photg[7], double(wVAR[i] * ww_slice));
                }
              }
            }

          } // flag_t4 - at least one jet

        } // flag_t3 - Isolation cut

      } // flag_t2 - Eta cut

    } // flag_t1 - pT cut

  } // End of loop over entries

  /////////////
  // cutFlow //
  /////////////

  outfile << " " << endl;
  outfile << "******************** cutFlow ********************" << endl;
  outfile << " " << endl;

  outfile << "Total number of events         : " << m_cutFlow[0][0][0][0] << endl;
  outfile << "Truth photons                  : " << m_cutFlow[1][0][0][0] << endl;
  // outfile << "Pythia slices                  : "<< m_cutFlow[2][0][0][0] << endl;
  outfile << "Total - [1] Brem / [2] Hard    : " << m_cutFlow[3][0][0][0] << " - " << " [1]: " << m_cutFlow[3][0][0][1] << " [2]: " << m_cutFlow[3][0][0][2] << endl;

  outfile << endl;

  outfile << "Truth level photon: " << endl;
  outfile << "TPhoton presel: pt cut         : " << m_cutFlow[4][0][0][0] << " - " << " [1]: " << m_cutFlow[4][0][0][1] << " [2]: " << m_cutFlow[4][0][0][2] << endl;
  outfile << "TPhoton presel: eta cut        : " << m_cutFlow[5][0][0][0] << " - " << " [1]: " << m_cutFlow[5][0][0][1] << " [2]: " << m_cutFlow[5][0][0][2] << endl;
  outfile << "TPhoton presel: etiso cut      : " << m_cutFlow[6][0][0][0] << " - " << " [1]: " << m_cutFlow[6][0][0][1] << " [2]: " << m_cutFlow[6][0][0][2] << endl;

  outfile << endl;

  outfile << "Truth level jet: " << endl;
  outfile << "TJet presel: one jet           : " << m_cutFlow[7][0][0][0] << " - " << " [1]: " << m_cutFlow[7][0][0][1] << " [2]: " << m_cutFlow[7][0][0][2] << endl;
  outfile << "TJet presel loop: pt cut       : " << m_cutFlow[8][0][0][0] << " - " << " [1]: " << m_cutFlow[8][0][0][1] << " [2]: " << m_cutFlow[8][0][0][2] << endl;
  outfile << "TJet presel loop: eta cut      : " << m_cutFlow[9][0][0][0] << " - " << " [1]: " << m_cutFlow[9][0][0][1] << " [2]: " << m_cutFlow[9][0][0][2] << endl;
  outfile << "TJet presel loop: DeltaR cut   : " << m_cutFlow[10][0][0][0] << " - " << " [1]: " << m_cutFlow[10][0][0][1] << " [2]: " << m_cutFlow[10][0][0][2] << endl;
  outfile << "TJet presel: LeadJet cut       : " << m_cutFlow[11][0][0][0] << " - " << " [1]: " << m_cutFlow[11][0][0][1] << " [2]: " << m_cutFlow[11][0][0][2] << endl;

  outfile << endl;
  outfile << "******************** cutFlow ********************" << endl;
  outfile << endl;

  ////////////////////////
  // Writing histograms //
  ////////////////////////

  histo.str("");
  histo << pos;
  TFile f(histo.str().c_str(), "recreate");

  // m_TH1_m[1000][3]
  for (unsigned int i = 0; i <= 2; i++)
  {
    for (unsigned int k = 0; k < 1000; k++)
    {
      if (m_TH1_m[k][i])
      {
        m_TH1_m[k][i]->Write();
      }
    }
  }

  // m_TH1_h[1000][50][3]
  for (unsigned int i = 0; i <= 2; i++)
  {
    for (unsigned int k = 0; k < 1000; k++)
    {
      for (unsigned int j = 0; j < 50; j++)
      {
        if (m_TH1_h[k][j][i])
        {
          m_TH1_h[k][j][i]->Write();
        }
      }
    }
  }

  // m_TH1_hf[100][3]
  for (unsigned int i = 0; i <= 2; i++)
  {
    for (unsigned int k = 1; k < 15; k++)
    {
      if (k >= 6 and k <= 10)
        continue;
      if (m_TH1_hf[k][i])
      {
        m_TH1_hf[k][i]->Write();
      }
    }
  }

  // m_TH1_hsnlo[1000][50]
  for (unsigned int k = 0; k < 1000; k++)
  {
    for (unsigned int j = 0; j < 350; j++)
    {
      if (m_TH1_hsnlo[k][j])
      {
        m_TH1_hsnlo[k][j]->Write();
      }
    }
  }

  // m_TH1_g[1000][3]
  for (unsigned int i = 0; i <= 2; i++)
  {
    for (unsigned int k = 0; k < 350; k++)
    {
      if (m_TH1_g[k][i])
      {
        m_TH1_g[k][i]->Write();
      }
    }
  }

  // m_TH2_h[1000][50][3]
  for (unsigned int i = 0; i <= 2; i++)
  {
    for (unsigned int k = 0; k < 100; k++)
    {
      for (unsigned int j = 0; j < 50; j++)
      {
        if (m_TH2_h[k][j][i])
        {
          m_TH2_h[k][j][i]->Write();
        }
      }
    }
  }

  // CPU time
  unsigned td = time(NULL) - ts;
  outfile << " ------------------------------------------------------- " << endl;
  outfile << " CPU time required: " << td << "s " << endl;
  outfile << " ------------------------------------------------------- " << endl;
  outfile << endl;

  return 1;
}

//////////////////////////
// Additional functions //
//////////////////////////

//
// jet function "get_deltar"
//
double get_deltar(double eta1, double phi1, double eta2, double phi2)
{
  double deg = 180. / (4. * atan(1.));
  double reta = eta1 - eta2;
  double rphi = abs(phi1 - phi2) * deg;
  if (rphi >= 180.)
    rphi = 360. - rphi;
  // if (abs(rphi)>=180.) cout << " rphi >= 180 " << rphi << endl;
  rphi = rphi / deg;
  double detar = sqrt(reta * reta + rphi * rphi);
  return detar;
}

//
// distance phi between lead-ph and lead-jet
//
double get_deltaphi(double phi1, double phi2)
{
  double deg = 180. / (4. * atan(1.));
  double rphi = abs(phi1 - phi2) * deg;
  if (rphi >= 180.)
    rphi = 360. - rphi;
  rphi = rphi / deg;
  double deltaphi = rphi;
  return deltaphi;
}

//
// Convert phi angle for the handmade jets
//
double get_phijet(double phijet)
{
  if (phijet > m_pi)
  {
    phijet = phijet - 2 * m_pi;
  }
  return phijet;
}

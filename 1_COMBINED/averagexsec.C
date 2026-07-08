#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <iomanip>

struct SampleInfo {
  double xsec_nb = -1.0;
  long long nevt = -1;
  bool foundXsec = false;
  bool foundNevt = false;
};

SampleInfo parseLogFile(const std::string& filename) {
  SampleInfo info;
  std::ifstream infile(filename);
  if (!infile.is_open()) {
    std::cerr << "ERROR: cannot open file " << filename << std::endl;
    return info;
  }

  std::string line;
  std::regex xsec_re(R"(cross-section \(nb\)=\s*([0-9eE+.\-]+))");
  std::regex nevt_re(R"(Number of events processed:\s*([0-9]+))");
  std::smatch match;

  while (std::getline(infile, line)) {
    if (!info.foundXsec && std::regex_search(line, match, xsec_re)) {
      info.xsec_nb = std::stod(match[1]);
      info.foundXsec = true;
    }

    if (!info.foundNevt && std::regex_search(line, match, nevt_re)) {
      info.nevt = std::stoll(match[1]);
      info.foundNevt = true;
    }

    if (info.foundXsec && info.foundNevt) break;
  }

  return info;
}

void weighted_xsec() {

  const std::string inputfolder = "./eos/home-d/dcamarer/PostDoc/PMG/SherpaNLO2216/13TeV/PROD_sherpaTarCreator/900007_merging/";

  const std::string file1 = inputfolder + "log.generate_part01";
  const std::string file2 = inputfolder + "log.generate_part02";

  SampleInfo s1 = parseLogFile(file1);
  SampleInfo s2 = parseLogFile(file2);

  if (!s1.foundXsec || !s1.foundNevt) {
    std::cerr << "ERROR: missing cross-section or event count in " << file1 << std::endl;
    return;
  }
  if (!s2.foundXsec || !s2.foundNevt) {
    std::cerr << "ERROR: missing cross-section or event count in " << file2 << std::endl;
    return;
  }

  long long totalEvents = s1.nevt + s2.nevt;
  if (totalEvents <= 0) {
    std::cerr << "ERROR: total number of events is <= 0" << std::endl;
    return;
  }

  double weightedXsec =
    (s1.nevt * s1.xsec_nb + s2.nevt * s2.xsec_nb) / double(totalEvents);

  std::cout << std::setprecision(15);
  std::cout << "File 1: " << file1 << "\n"
            << "  xsec (nb) = " << s1.xsec_nb << "\n"
            << "  nevt      = " << s1.nevt << "\n";

  std::cout << "File 2: " << file2 << "\n"
            << "  xsec (nb) = " << s2.xsec_nb << "\n"
            << "  nevt      = " << s2.nevt << "\n";

  std::cout << "Total events = " << totalEvents << "\n";
  std::cout << "Weighted cross-section (nb) = " << weightedXsec << std::endl;
}

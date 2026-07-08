#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <iomanip>
#include <sstream>

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
    std::cerr << "WARNING: cannot open file " << filename << std::endl;
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

void averagexsec(std::string inputfolder = ".", int nFiles = 2) {
  if (!inputfolder.empty() && inputfolder.back() != '/')
    inputfolder += "/";

  double weightedSum = 0.0;
  long long totalEvents = 0;
  int nValidFiles = 0;

  std::cout << std::endl;
  std::cout << std::setprecision(15);
  std::cout << "Reading files from: " << inputfolder << std::endl;
  std::cout << std::endl;
  std::cout << "--------------------------------------------------" << std::endl;

  for (int i = 1; i <= nFiles; ++i) {
    std::ostringstream fname;
    fname << inputfolder << "log.generate_part"
          << std::setw(2) << std::setfill('0') << i;

    SampleInfo s = parseLogFile(fname.str());

    if (!s.foundXsec || !s.foundNevt) {
      std::cerr << "WARNING: missing info in " << fname.str()
                << "  (xsec found=" << s.foundXsec
                << ", nevt found=" << s.foundNevt << ")" << std::endl;
      continue;
    }

    std::cout << fname.str() << "\n"
              << "  xsec (nb) = " << s.xsec_nb << "\n"
              << "  nevt      = " << s.nevt << "\n";

    weightedSum += s.xsec_nb * s.nevt;
    totalEvents += s.nevt;
    ++nValidFiles;
  }

  std::cout << "--------------------------------------------------" << std::endl;
  std::cout << std::endl;
  std::cout << "Valid files   = " << nValidFiles << " / " << nFiles << std::endl;
  std::cout << "Total events  = " << totalEvents << std::endl;

  if (totalEvents <= 0) {
    std::cerr << "ERROR: total number of events is <= 0" << std::endl;
    return;
  }

  double finalXsec = weightedSum / double(totalEvents);
  std::cout << "Weighted cross-section (nb) = " << finalXsec << std::endl;
  std::cout << std::endl;
}

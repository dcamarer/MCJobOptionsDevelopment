#include "AtlasStyle.C"

void rootlogon()
{
  // Load ATLAS style
  //gROOT->LoadMacro("AtlasStyle.C");
  SetAtlasStyle();
  gROOT->LoadMacro("myAtlasUtils.C");
}

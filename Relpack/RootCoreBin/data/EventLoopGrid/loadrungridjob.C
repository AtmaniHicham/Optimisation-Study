#ifndef __CINT__
#include <EventLoopGrid/GridJobLoader.h>
#include <TROOT.h>
#include <iostream>
#include <string>
#endif

void loadrungridjob(const std::string& sampleName)
{
  std::cout << "Running with ROOT version " << gROOT->GetVersion();
  std::cout << " (" << gROOT->GetVersionDate() << ")\n";
  std::cout << "Loading RootCore packages\n";

  cout << "Loading EventLoop grid job\n";

  EL::GridJobLoader gjl;
  gjl.Run(sampleName);
}

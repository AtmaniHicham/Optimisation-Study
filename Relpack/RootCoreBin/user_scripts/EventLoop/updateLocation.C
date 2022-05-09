void updateLocation (const char *location)
{
  // load the libraries for all packages
  gROOT->ProcessLine(".x $ROOTCOREDIR/scripts/load_packages.C");

  // do the actual updateLocation
  EL::Driver::updateLocation (location);
}

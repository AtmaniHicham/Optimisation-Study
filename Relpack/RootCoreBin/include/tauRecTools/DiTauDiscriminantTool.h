// Dear emacs, this is -*- c++ -*-
#ifndef  TAURECTOOLS_DITAUDISRIMINANTTOOL_H
#define  TAURECTOOLS_DITAUDISRIMINANTTOOL_H

/**
 * @brief Implementation of boosted di-tau ID.
 * 
 * @author David Kirchmeier (david.kirchmeier@cern.ch)
 *                                                                              
 */

// Framework include(s):
#include "AsgTools/AsgTool.h"

// Core include(s):

// EDM include(s):
#include "xAODTau/DiTauJetContainer.h"

// Local include(s):
#include "tauRecTools/IDiTauDiscriminantTool.h"

// ROOT includes
#include "TMVA/Reader.h"

#include <string>
#include <map>


namespace tauRecTools
{


class DiTauDiscriminantTool
  : public tauRecTools::IDiTauDiscriminantTool
  , public asg::AsgTool
{
  /// Create a proper constructor for Athena
  ASG_TOOL_CLASS( DiTauDiscriminantTool,
                  tauRecTools::IDiTauDiscriminantTool )

public:

  DiTauDiscriminantTool( const std::string& name );

  virtual ~DiTauDiscriminantTool();

  // initialize the tool
  virtual StatusCode initialize();

  // set pointer to event
  virtual StatusCode initializeEvent();

  // get ID score
  virtual double getJetBDTScore(const xAOD::DiTauJet& xDiTau);

private:

  void parseWeightsFile();

  void setIDVariables(const xAOD::DiTauJet& xDiTau);

  const xAOD::DiTauJetContainer* m_xDiTauContainer;

  // bool m_bIsInitialized;
  // steering variables
  std::string m_sWeightsFile;

  TMVA::Reader* m_rReader; //!

  std::map<std::string, float> m_mIDVariables; //!
  std::map<std::string, float> m_mIDSpectators; //!


  std::vector<std::string> m_vVarNames;
private:
  double GeV = 1000.;
  
}; // class DiTauDiscriminantTool

}
#endif // TAURECTOOLS_DITAUDISRIMINANTTOOL_H

#ifndef TAURECTOOLSDEV_MVATESEVALUATOR_H
#define TAURECTOOLSDEV_MVATESEVALUATOR_H

// tauRecTools include(s)
#include "tauRecTools/TauRecToolBase.h"

// xAOD include(s)
#include "xAODEventInfo/EventInfo.h"

// TMVA include(s)
#if not defined(__CINT__) || defined(__MAKECINT__)
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#endif

class MvaTESEvaluator
: public TauRecToolBase
{
 public:
  ASG_TOOL_CLASS2(MvaTESEvaluator, TauRecToolBase, ITauToolBase)
    
  MvaTESEvaluator(const std::string& name="MvaTESEvaluator");
  virtual ~MvaTESEvaluator();
    
  StatusCode initialize();
  StatusCode eventInitialize();
  StatusCode execute(xAOD::TauJet& xTau);
  StatusCode eventFinalize();
  StatusCode finalize() { delete reader; return StatusCode::SUCCESS;}
  
 private:
  const xAOD::EventInfo* m_xEventInfo;  //!
  const xAOD::VertexContainer* m_xVertexContainer; //!
  float m_mu; //!
  int   m_nVtxPU; //!
   
  // Configurable properties
  std::string m_sWeightFileName;

  // TMVA reader
  TMVA::Reader *reader; //!
    
  // TMVA input variables (provide all variables in float)
  float mu; //!
  float nVtxPU; //!
    
  float CenterLambda; //!
  float FirstEngDens; //!
  float SecondLambda; //!
  float PresamplerFrac; //!
  float EMProbability; //!
    
  float interpolPt; //!
  float LC_D_interpolPt; //!
  float pantau_D_interpolPt;//!
  float etaPanTauCellBased; //!
    
  float nPi0s; //!
  float PFOEngRelDiff; //!
  float nTracks; //!
    
  // Spectators
  float truthPtVis; //!
  float ptTauEtaCalib; //!
  float ptPanTauCellBased; //!
};

#endif // TAURECTOOLSDEV_MVATESEVALUATOR_H

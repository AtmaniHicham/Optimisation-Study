
def getMETMakerAlg(metsuffix,jetPtCut=0,jetColl="",confsuffix=""):
    from AthenaCommon import CfgMgr

    print "Generate METMaker and METMakerAlg for METAssoc_"+metsuffix
    from AthenaCommon.AppMgr import ToolSvc
    from AthenaCommon.AlgSequence import AlgSequence
    topSequence = AlgSequence()

    doPFlow = 'PFlow' in metsuffix
    doTruth = metsuffix.startswith('Truth')
    metMaker = CfgMgr.met__METMaker('METMaker_'+metsuffix+confsuffix,
                                    DoPFlow=doPFlow,
                                    DoSoftTruth=doTruth,
                                    JetSelection='Tier0'
                                    );
    ToolSvc += metMaker

    muonSel = CfgMgr.CP__MuonSelectionTool("METMuonSelectionTool"+confsuffix,
                                           MuQuality=1, # Medium
                                           MaxEta=2.4,
                                           TurnOffMomCorr=True
                                           )
    ToolSvc += muonSel

    elecSelLH = CfgMgr.AsgElectronLikelihoodTool("METEleSelLikelihood"+confsuffix,
                                                 WorkingPoint="MediumLHElectron")
    ToolSvc += elecSelLH

    photonSelIsEM = CfgMgr.AsgPhotonIsEMSelector("METPhotonSelIsEM"+confsuffix,
                                                 WorkingPoint="TightPhoton")
    ToolSvc += photonSelIsEM

    tauSel = CfgMgr.TauAnalysisTools__TauSelectionTool("METTauSelectionTool"+confsuffix)
    ToolSvc += tauSel

    if jetColl=="":
        jetColl = metsuffix+'Jets'
        if doTruth:
            jetColl = metsuffix.split('_')[1]+'Jets'
    makerAlg = CfgMgr.met__METMakerAlg('METMakerAlg_'+metsuffix+confsuffix,
                                       METMapName='METAssoc_'+metsuffix,
                                       METCoreName='MET_Core_'+metsuffix,
                                       METName='MET_Reference_'+metsuffix,
                                       InputJets=jetColl,
                                       Maker=metMaker,
                                       MuonSelectionTool=muonSel,
                                       ElectronLHSelectionTool=elecSelLH,
                                       PhotonIsEMSelectionTool=photonSelIsEM,
                                       TauSelectionTool=tauSel
                                       )
    return makerAlg

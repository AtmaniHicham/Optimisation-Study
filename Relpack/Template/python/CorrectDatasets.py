import os
path='/sps/atlas/h/hatmani/Systh_2/PreRec/'
dataPath='/sps/atlas/h/hatmani/PourHicham/nTuples/Systematics/'

# data15 = os.popen( 'ls /sps/atlas/a/aguerguichon/Calibration/DataxAOD/Data_13TeV_Zee_25ns_Lkh1_scaled/Data_*.root' ).read().split()
# dataFiles = os.popen( 'ls /sps/atlas/a/aguerguichon/Calibration/DataxAOD/Data_13TeV_Zee_25ns_Lkh1/Data_*.root' ).read().split()
# MCScaledFiles = os.popen( 'ls /sps/atlas/a/aguerguichon/Calibration/DataxAOD/MC_13TeV_Zee_25ns_Lkh1_scaled/MC_*.root' ).read().split()
# MCFiles = os.popen( 'ls /sps/atlas/a/aguerguichon/Calibration/DataxAOD/MC_13TeV_Zee_25ns_Lkh1/MC_*.root' ).read().split()
# dataCorrectedFiles = os.popen( 'ls ' + path + 'Data_*corrected.root | grep -v scaled' ).read().split()


#print ' --dataFileName '.join( dataFiles )

#command= 'MeasureScale --configFile ~/private/Calibration/Template/python/Config25_noAlpha.boost --noExtraction '
#command= 'MeasureScale  --configFile '+path+'Config/AlphaOffSummer_15_Window.boost --noExtraction '

#command= 'MeasureScale --noExtraction --correctAlphaFileName '+path+'Results/Delta/Delta_EW.root'
#command= 'MeasureScale --noExtraction --correctAlphaFileName '+path+'Results/Delta/Delta_Window.root '
#command= 'MeasureScale --noExtraction --correctAlphaFileName '+path+'Results/Delta/Delta_Threshold.root '
#command= 'MeasureScale --noExtraction --correctAlphaFileName '+path+'Results/Delta/Delta_noIsoCut.root '
#command= 'MeasureScale --noExtraction --correctAlphaFileName '+path+'Results/Delta/Delta_tightID.root '
command= 'MeasureScale --noExtraction --correctAlphaFileName '+path+'Results/Delta/Delta_fBrem.root '
#command= 'MeasureScale --noExtraction --correctAlphaFileName '+path+'Results/Delta/Delta_EW.root '


#nominal
#os.system( command
#           + ' --configFile '+path+'Config/AlphaOffSummer_15.boost'
#           + ' --dataFileName '+dataPath+'data15.root'
#           + ' --dataTreeName CollectionTree'
#           + ' --correctAlphaHistName delta_Nom'
#           )
#os.system( 'mv '+dataPath+'data15*corrected.root '+path+'Results/CorrectedData/.' )

# #EW
#os.system( command
#            + ' --configFile '+path+'Config/AlphaOffSummer_15_EW.boost'
#            + ' --dataFileName '+dataPath+'data15.root'
#            + ' --dataTreeName CollectionTree'
#            + ' --correctAlphaHistName delta_Nom'
#            )
#os.system( 'mv '+dataPath+'data15*corrected.root '+path+'Results/CorrectedData/data15_EW_corrected.root' )

# #noIsoCut
#os.system( command
#            + ' --configFile '+path+'Config/AlphaOffSummer_15_noIsoCut.boost'
#            + ' --dataFileName '+dataPath+'data15_noIsoCut.root'
#            + ' --dataTreeName CollectionTree'
#            + ' --correctAlphaHistName delta_Nom'
#            )
#os.system( 'mv '+dataPath+'data15*corrected.root '+path+'Results/CorrectedData/data15_noIsoCut_corrected.root')

# #tightID
#os.system( command
#            + ' --configFile '+path+'Config/AlphaOffSummer_15_tightID.boost'
#            + ' --dataFileName '+dataPath+'data15_tightID.root'
#            + ' --dataTreeName CollectionTree'
#            + ' --correctAlphaHistName delta_Nom'
#            )
#os.system( 'mv '+dataPath+'data15*corrected.root '+path+'Results/CorrectedData/data15_tightID_corrected.root.')

# #Threshold
#os.system( command
#            + ' --configFile '+path+'Config/AlphaOffSummer_15_Threshold.boost'
#            + ' --dataFileName '+dataPath+'data15.root'
#            + ' --dataTreeName CollectionTree'
#            + ' --correctAlphaHistName delta_Nom'
#            )
#os.system( 'mv '+dataPath+'data15_corrected.root '+path+'Results/CorrectedData/data15_Threshold_corrected.root' )

 #Window
#os.system( command
#            + ' --configFile '+path+'Config/AlphaOffSummer_15_Window.boost'
#            + ' --dataFileName '+dataPath+'data15.root'
#            + ' --dataTreeName CollectionTree'
#            + ' --correctAlphaHistName delta_Nom'
#            )
#os.system( 'mv '+dataPath+'data15_corrected.root '+path+'Results/CorrectedData/data15_Window_corrected.root' )

 #fBrem
os.system( command
            + ' --configFile '+path+'Config/AlphaOffSummer_15_fBrem50.boost'
            + ' --dataFileName '+dataPath+'data15_fBrem.root'
            + ' --dataTreeName PassSelTree'
            + ' --correctAlphaHistName delta_Nom'
            )
os.system( 'mv '+dataPath+'data15*corrected.root '+path+'Results/CorrectedData/data15_fBrem_corrected.root.' )


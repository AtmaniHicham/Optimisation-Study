import os


################################################################################################################################################################################ 

#  ------------------------------------ 2017 -- Correction of data -------------------------

#os.system('MeasureScale   --configFile   /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Release_21_V1/data_2017_21.2.35/Data17.root  --dataTreeName CollectionTree --correctAlphaFileName /sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-5Intervals-pol1.root   --correctAlphaHistName Extra --noExtraction')

#  ------------------------------------ 2017 -- Nominal ------------------------------------

#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_1bin.boost  --dataFileName /sps/atlas/h/hatmani/rel21_Calib_Pre/source_17_Low-mu/output_data17.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/rel21_Calib_Pre/source_17_Low-mu/MC16_13TeV_Low_mu.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/Nominal/Alpha_2017_24.root')

# ------------------------------------ 2017 -- 5 Intervals first bins  ----------------------------

#Interval 0 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins-firstbins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-0.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-0.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5Intervalsfirstbin/1muInterval/Alpha-24-0.root --makePlot')

#Interval 1 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins-firstbins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-1.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-1.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5Intervalsfirstbin/1muInterval/Alpha-24-1.root --makePlot')

#Interval 2 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins-firstbins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-2.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-2.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5Intervalsfirstbin/1muInterval/Alpha-24-2.root --makePlot')

#Interval 3 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins-firstbins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-3.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-3.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5Intervalsfirstbin/1muInterval/Alpha-24-3.root --makePlot')

#Interval 4 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins-firstbins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-4.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-4.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5Intervalsfirstbin/1muInterval/Alpha-24-4.root --makePlot')



# ------------------------------------ 2017 -- 5 Intervals Last bins  ----------------------------

#Interval 0 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins-Lastbins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-0.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-0.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5IntervalsLastbin/1muInterval/Alpha-24-0.root --makePlot')

#Interval 1 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins-Lastbins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-1.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-1.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5IntervalsLastbin/1muInterval/Alpha-24-1.root --makePlot')

#Interval 2 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins-Lastbins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-2.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-2.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5IntervalsLastbin/1muInterval/Alpha-24-2.root --makePlot')

#Interval 3 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins-Lastbins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-3.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-3.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5IntervalsLastbin/1muInterval/Alpha-24-3.root --makePlot')

##Interval 4 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins-Lastbins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-4.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-4.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5IntervalsLastbin/1muInterval/Alpha-24-4.root --makePlot')


# ------------------------------------ 2017 -- 5 Intervals ------------------------------------

#Interval 0 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-0.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-0.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5Intervals/Alpha-24-0.root')

#Interval 1 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-1.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-1.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5Intervals/Alpha-24-1.root')

#Interval 2 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-2.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-2.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5Intervals/Alpha-24-2.root')

#Interval 3 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-3.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-3.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5Intervals/Alpha-24-3.root')

##Interval 4 : 
os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-4.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-4.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5Intervals/Alpha-24-4.root --makePlot')

# ------------------------------------ 2017 -- 4 Intervals ------------------------------------

#Interval 0 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/4Intervals/data17-0.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/4Intervals/MC16d-0.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/4Intervals/Alpha-24-0.root')

#Interval 1 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/4Intervals/data17-1.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/4Intervals/MC16d-1.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/4Intervals/Alpha-24-1.root')

#Interval 2 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/4Intervals/data17-2.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/4Intervals/MC16d-2.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/4Intervals/Alpha-24-2.root')

#Interval 3 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/4Intervals/data17-3.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/4Intervals/MC16d-3.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/4Intervals/Alpha-24-3.root')

# ------------------------------------ 2017 -- 3 Intervals ------------------------------------

#Interval 0 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/3Intervals/data17-0.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/3Intervals/MC16d-0.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/3Intervals/Alpha-24-0.root')

#Interval 1 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/3Intervals/data17-1.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/3Intervals/MC16d-1.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/3Intervals/Alpha-24-1.root')

#Interval 2 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/3Intervals/data17-2.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/3Intervals/MC16d-2.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/3Intervals/Alpha-24-2.root')

# ------------------------------------ 2017 -- 2 Intervals ------------------------------------

#Interval 0 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/2Intervals/data17-0.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/2Intervals/MC16d-0.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/2Intervals/Alpha-24-0.root')

#Interval 1 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/2Intervals/data17-1.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/2Intervals/MC16d-1.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/2Intervals/Alpha-24-1.root')


# ------------------------------------ 2017 -- 5 - 1 Intervals en eta ------------------------------------

#Interval 0 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_1bin.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-0.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-0.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5Intervals2Binseta/Alpha-24-0.root')

#Interval 1 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_1bin.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-1.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-1.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5Intervals2Binseta/Alpha-24-1.root')

#Interval 2 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_1bin.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-2.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-2.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5Intervals2Binseta/Alpha-24-2.root')

#Interval 3 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_1bin.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-3.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-3.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5Intervals2Binseta/Alpha-24-3.root')

#Interval 3 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter17_1bin.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/data17-3.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source17/5Intervals/MC16d-3.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results17/5Intervals2Binseta/Alpha-24-4.root')







# ------------------------------------ 2018 -- 5 Intervals ------------------------------------

#Interval 0 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter18_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source18/5Intervals/data18-0.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source18/5Intervals/MC16e-0.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results18/5Intervals/Alpha-0.root')

#Interval 1 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter18_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source18/5Intervals/data18-1.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source18/5Intervals/MC16e-1.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results18/5Intervals/Alpha-1.root')

#Interval 2 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter18_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source18/5Intervals/data18-2.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source18/5Intervals/MC16e-2.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results18/5Intervals/Alpha-2.root')

#Interval 3 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter18_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source18/5Intervals/data18-3.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source18/5Intervals/MC16e-3.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results18/5Intervals/Alpha-3.root')

#Interval 4 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter18_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source18/5Intervals/data18-4.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source18/5Intervals/MC16e-4.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results18/5Intervals/Alpha-4.root')


# ------------------------------------ 2018 -- 4 Intervals ------------------------------------

#Interval 0 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter18_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source18/4Intervals/data18-0.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source18/4Intervals/MC16e-0.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results18/4Intervals/Alpha-0.root')

#Interval 1 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter18_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source18/4Intervals/data18-1.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source18/4Intervals/MC16e-1.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results18/4Intervals/Alpha-1.root')

#Interval 2 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter18_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source18/4Intervals/data18-2.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source18/4Intervals/MC16e-2.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results18/4Intervals/Alpha-2.root')

#Interval 3 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter18_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source18/4Intervals/data18-3.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source18/4Intervals/MC16e-3.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results18/4Intervals/Alpha-3.root')

# ------------------------------------ 2018 -- 3 Intervals ------------------------------------

#Interval 0 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter18_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source18/3Intervals/data18-0.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source18/3Intervals/MC16e-0.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results18/3Intervals/Alpha-0.root')

#Interval 1 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter18_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source18/3Intervals/data18-1.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source18/3Intervals/MC16e-1.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results18/3Intervals/Alpha-1.root')

#Interval 2 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter18_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source18/3Intervals/data18-2.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source18/3Intervals/MC16e-2.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results18/3Intervals/Alpha-2.root')

# ------------------------------------ 2018 -- 2 Intervals ------------------------------------

#Interval 0 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter18_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source18/2Intervals/data18-0.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source18/2Intervals/MC16e-0.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results18/2Intervals/Alpha-24-0.root')

#Interval 1 : 
#os.system('MeasureScale   --configFile /sps/atlas/h/hatmani/rel21_Calib_Pre/Template/ConfigFiles_Lowmu/AlphaOffWinter18_24Bins.boost  --dataFileName /sps/atlas/h/hatmani/Extrapolation/source18/2Intervals/data18-1.root  --dataTreeName CollectionTree --MCFileName  /sps/atlas/h/hatmani/Extrapolation/source18/2Intervals/MC16e-1.root  --MCTreeName  CollectionTree  --outFileName /sps/atlas/h/hatmani/Extrapolation/results18/2Intervals/Alpha-24-1.root')





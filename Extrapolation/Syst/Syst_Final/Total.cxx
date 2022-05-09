#include "TFile.h"
#include "TMatrixT.h"
#include "TH1.h"

using std::to_string;

using namespace std;

void Total(){

	TFile*  StatError = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-3Intervals-pol1.root");
	TH1*    HStat	  = (TH1*)StatError->Get("Extra");

	float fontSize=26;
 	float fontType=43;

	for(int i = 0 ; i<HStat->GetNbinsX() ; i++ ){
	HStat->SetBinContent(i+1, HStat->GetBinError(i+1));
	HStat->SetBinError(i+1,0);
	}


        int Nbins24 = 24;
        double bins24[25]={-2.47,-2.4,-2.1,-1.8,-1.55,-1.37,-1.2,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.37,1.55,1.8,2.1,2.4,2.47};
        //TH1*  HighpileupSystematic   = new TH1F("HighpileupSystematic","HighpileupSystematic",Nbins24,bins24);
	
        TFile* fileHighmu             = new TFile("/sps/atlas/h/hatmani/SystComb.root");
	TH1* HighpileupSystematic	      = (TH1*)fileHighmu->Get("AlphaCombSys");

	double a[24];
	/*
	a[0] = ( Highpileup->GetBinContent(1) + Highpileup->GetBinContent(2) )/2;
	a[1] = ( Highpileup->GetBinContent(3) + Highpileup->GetBinContent(4) + Highpileup->GetBinContent(5) + Highpileup->GetBinContent(6)  ) /4;
        a[2] = ( Highpileup->GetBinContent(7) + Highpileup->GetBinContent(8) + Highpileup->GetBinContent(9) + Highpileup->GetBinContent(10) ) /4;
        a[3] = ( Highpileup->GetBinContent(11) + Highpileup->GetBinContent(12) + Highpileup->GetBinContent(13) + Highpileup->GetBinContent(14) + Highpileup->GetBinContent(15) +  Highpileup->GetBinContent(16) ) / 6;
        a[4] = ( Highpileup->GetBinContent(17) + Highpileup->GetBinContent(18) + Highpileup->GetBinContent(19) + Highpileup->GetBinContent(20) ) /4;
        a[5] = ( Highpileup->GetBinContent(21) + Highpileup->GetBinContent(22) )/2;
        a[6] = ( Highpileup->GetBinContent(23) + Highpileup->GetBinContent(24) )/2;
        a[7] = ( Highpileup->GetBinContent(25) + Highpileup->GetBinContent(26) )/2;
        a[8] = ( Highpileup->GetBinContent(27) + Highpileup->GetBinContent(28) )/2;
        a[9] = ( Highpileup->GetBinContent(29) + Highpileup->GetBinContent(30) )/2;
        a[10] = ( Highpileup->GetBinContent(31) + Highpileup->GetBinContent(32) )/2;
        a[11] = ( Highpileup->GetBinContent(33) + Highpileup->GetBinContent(34) )/2;
        a[12] = ( Highpileup->GetBinContent(35) + Highpileup->GetBinContent(36) )/2;
        a[13] = ( Highpileup->GetBinContent(37) + Highpileup->GetBinContent(38) )/2;
        a[14] = ( Highpileup->GetBinContent(39) + Highpileup->GetBinContent(40) )/2;
        a[15] = ( Highpileup->GetBinContent(41) + Highpileup->GetBinContent(42) )/2;
        a[16] = ( Highpileup->GetBinContent(44) + Highpileup->GetBinContent(43) )/2;
        a[17] = ( Highpileup->GetBinContent(46) + Highpileup->GetBinContent(45) )/2;
        a[18] = ( Highpileup->GetBinContent(48) + Highpileup->GetBinContent(47) )/2;
        a[19] = ( Highpileup->GetBinContent(52) + Highpileup->GetBinContent(51) + Highpileup->GetBinContent(50) + Highpileup->GetBinContent(49) ) /4;
        a[20] = ( Highpileup->GetBinContent(58) + Highpileup->GetBinContent(57) + Highpileup->GetBinContent(56) + Highpileup->GetBinContent(55) + Highpileup->GetBinContent(54) +  Highpileup->GetBinContent(53) ) / 6;
        a[21] = ( Highpileup->GetBinContent(62) + Highpileup->GetBinContent(61) + Highpileup->GetBinContent(60) + Highpileup->GetBinContent(59)  ) /4;
        a[22] = ( Highpileup->GetBinContent(66) + Highpileup->GetBinContent(65) + Highpileup->GetBinContent(64) + Highpileup->GetBinContent(63)  ) /4;
        a[23] = ( Highpileup->GetBinContent(67) + Highpileup->GetBinContent(68) )/2;


        //for(int i=0; i<HighpileupSystematic->GetNbinsX() ; i++ ){	HighpileupSystematic->SetBinContent(i+1, a[i]  );}
	//for(int i=0; i<HighpileupSystematic->GetNbinsX() ; i++ ){	HighpileupSystematic->SetBinError(i+1,0);}
*/
        int Nbins = 3;
        double bins[4]={-2.47,-1.45,1.45,2.47};

	TH1F* TemperatureEffect      = new TH1F("TemperatureEffect","TemperatureEffect",Nbins,bins);
	TemperatureEffect->SetBinContent(1,0.001);	TemperatureEffect->SetBinError(1,0);
        TemperatureEffect->SetBinContent(2,0.0003);	TemperatureEffect->SetBinError(2,0);
        TemperatureEffect->SetBinContent(3,0.001);	TemperatureEffect->SetBinError(3,0);

	TFile* fileStat      	     = new TFile("/sps/atlas/h/hatmani/Extrapolation/Comparison/SourceOfError2017Stat.root");
	TFile* fileSystHigh  	     = new TFile("/sps/atlas/h/hatmani/Systh_2/PreRec_24/Results/resum/EnergyScaleFactorsAout.root");
	TFile* fileSystExtrapolated  = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Syst/extrapolationsys.root");
	TFile* fileThreshold	     = new TFile("/sps/atlas/h/hatmani/rel21_Calib_TCnoise/diff-stat/diff-energy/backup3/DiffTCstudy.root");

	//TH1*   HStat		     = (TH1*)fileStat->Get("Extra");			
	TH1*   HSystHigh	     = (TH1*)fileSystHigh->Get("totSyst_alpha");
	TH1*   HSystExtrapolated     = (TH1*)fileSystExtrapolated->Get("Hx3Mx1");
	TH1*   HThreshold	     = (TH1*)fileThreshold->Get("DIff");

	for(int i = 0 ; i<HThreshold->GetNbinsX() ; i++ ){
	HThreshold->SetBinContent(i+1,HThreshold->GetBinError(i+1));
	HThreshold->SetBinError(i+1,0);
	}

        TH1D* HTotal   = (TH1D*) HStat->Clone("HTotal");
        TH1D* Final    = (TH1D*) HStat->Clone("Final");

	for(int i = 0 ; i<6 ; i++ ){
	HTotal->SetBinContent(i+1,sqrt(
	pow( TemperatureEffect->GetBinContent(1) 	,2)+	pow( HSystExtrapolated->GetBinContent(i+1)      ,2)+   
	pow( HThreshold->GetBinContent(i+1) 	      	,2)+	pow( HighpileupSystematic->GetBinContent(i+1) 	,2)  ));
	HTotal->SetBinError(i+1,0);}


	for(int i = 6 ; i<17 ; i++ ){
        HTotal->SetBinContent(i+1,sqrt(
        pow( TemperatureEffect->GetBinContent(2)        ,2)+    pow( HSystExtrapolated->GetBinContent(i+1)      ,2)+
        pow( HThreshold->GetBinContent(i+1)             ,2)+    pow( HighpileupSystematic->GetBinContent(i+1)   ,2)  ));
        HTotal->SetBinError(i+1,0);}


        for(int i = 17 ; i<24 ; i++ ){
        HTotal->SetBinContent(i+1,sqrt(
        pow( TemperatureEffect->GetBinContent(1)        ,2)+    pow( HSystExtrapolated->GetBinContent(i+1)      ,2)+
        pow( HThreshold->GetBinContent(i+1)             ,2)+    pow( HighpileupSystematic->GetBinContent(i+1)   ,2)  ));
        HTotal->SetBinError(i+1,0);}


	for(int i = 0 ; i<Final->GetNbinsX() ; i++ ){
	Final->SetBinContent(i+1, sqrt( pow(HTotal->GetBinContent(i+1),2) + pow(HStat->GetBinContent(i+1),2)    ));
	Final->SetBinError(i+1,0);
	}

 	TCanvas* c1 = new TCanvas("c", "c", 800,600);
	c1->SetTickx(1);
 	c1->SetTicky(1);
 	c1->SetTitle("");
	
	TemperatureEffect->SetLineWidth(2);
	HSystExtrapolated->SetLineWidth(2);	
	HThreshold->SetLineWidth(2);
	HighpileupSystematic->SetLineWidth(2);		
	HTotal->SetLineWidth(2);
	HStat->SetLineWidth(2);
	Final->SetLineWidth(2);

	TemperatureEffect->SetLineColor(2);
	HSystExtrapolated->SetLineColor(4);
	HThreshold->SetLineColor(6);
	HighpileupSystematic->SetLineColor(3);
	HTotal->SetLineColor(2);
	HStat->SetLineColor(4);
	Final->SetLineColor(1);
	
	TemperatureEffect->SetLineStyle(2);
	HSystExtrapolated->SetLineStyle(2);
	HThreshold->SetLineStyle(2);
	HighpileupSystematic->SetLineStyle(2);

 	TemperatureEffect->GetXaxis()->SetTitle("#eta");
 	TemperatureEffect->GetXaxis()->SetTitleOffset(1.2);
 	TemperatureEffect->GetYaxis()->SetTitle("Uncertainties");
        TemperatureEffect->GetYaxis()->SetTitleSize(0.044);
 	TemperatureEffect->SetStats(0);
 	TemperatureEffect->GetYaxis()->SetRangeUser(-0.0003,0.005);
 	TemperatureEffect->SetTitle("");

        TemperatureEffect->Draw("same");		TemperatureEffect->SetTitle("");		
	TemperatureEffect->SetName("temperature_effect");
	HSystExtrapolated->Draw("same");		HSystExtrapolated->SetTitle("Extrapolation uncertainty");
	HSystExtrapolated->SetName("extrapolation_systematic");
	HThreshold->Draw("same");			HThreshold->SetTitle("Threshold correction");
	HThreshold->SetName("uncertainty_in_threshold_correction");	
	HighpileupSystematic->Draw("same");		HighpileupSystematic->SetTitle("High #mu systematics");		
	HighpileupSystematic->SetName("high-mu_alpha_systematics");
	HTotal->Draw("same");				HTotal->SetTitle("Total systematic uncertainty");
	HTotal->SetName("Total_Uncertainties");
	HStat->Draw("same");				HStat->SetTitle("Stat uncertainty from the extrapolation");
	HStat->SetName("Stat_Uncertaintie_of_extrapolation");
	Final->Draw("same");				Final->SetTitle("Total uncertainty");
	Final->SetName("Total_uncertainties");
	

	auto legend = new TLegend(0.49,0.6,0.88,0.85);
 	legend->SetBorderSize(0);
 	legend->AddEntry(TemperatureEffect,"Temperature effect");
 	legend->AddEntry(HSystExtrapolated,"Extrapolation uncertainty");
 	legend->AddEntry(HThreshold,"Threshold correction");
 	legend->AddEntry(HighpileupSystematic,"High #mu systematics");
 	legend->AddEntry(HTotal,"Total systematic uncertainty");
 	legend->AddEntry(HStat,"Stat uncertainty from the extrapolation");
 	legend->AddEntry(Final,"Total uncertainty");
 	legend->Draw("same");

	
 	TLatex l;
 	l.SetNDC();
 	l.SetTextSize(18);
 	l.SetTextFont(fontType);
 	l.SetTextColor(kBlack);
 	l.DrawLatex(0.14,0.83,"#font[42]{#scale[1.15]{#it{#bf{ATLAS}} Internal}}");
 	l.DrawLatex(0.14,0.78,"#sqrt{s}=13 TeV, Z #rightarrow ee");
 	l.DrawLatex(0.14,0.74,"High #mu (<#mu> ~ 37, 44.3 fb^{-1})");
        l.DrawLatex(0.14,0.70,"Low #mu (<#mu> ~ 2,   147 pb^{-1})");

	c1->SaveAs("Total.pdf");


	TFile* fichier = new TFile("Total.root","recreate");
	TemperatureEffect->Write();
	HSystExtrapolated->Write();
	HThreshold->Write();
	HighpileupSystematic->Write();
	HTotal->Write();
	fichier->Close();





}

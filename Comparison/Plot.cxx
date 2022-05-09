#include "iostream"
#include "TH1.h"
#include "TFile.h"
#include "TLine.h"
#include "TTree.h"
#include "TLegend.h"



using namespace std;

void SourceOfErrorSyst(){

        int Nbins = 24;
        double bins[25]={-2.47,-2.4,-2.1,-1.8,-1.55,-1.37,-1.2,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.37,1.55,1.8,2.1,2.4,2.47};

	TFile* Syst1   = new TFile("/sps/atlas/h/hatmani/Systh_2/PreRec_24/Results/Systh/Systh_win.root");
        TFile* Syst2   = new TFile("/sps/atlas/h/hatmani/Systh_2/PreRec_24/Results/Systh/Systh_fBrem.root");
        TFile* Syst3   = new TFile("/sps/atlas/h/hatmani/Systh_2/PreRec_24/Results/Systh/Systh_Threshold.root");
        TFile* Syst4   = new TFile("/sps/atlas/h/hatmani/Systh_2/PreRec_24/Results/Systh/Systh_tightID.root");
        TFile* Syst5   = new TFile("/sps/atlas/h/hatmani/Systh_2/PreRec_24/Results/Systh/Systh_recoEff.root");
        TFile* Syst6   = new TFile("/sps/atlas/h/hatmani/Systh_2/PreRec_24/Results/Systh/Systh_triggerEff.root");
        TFile* Syst7   = new TFile("/sps/atlas/h/hatmani/Systh_2/PreRec_24/Results/Systh/Systh_isoEff.root");
        TFile* Syst8   = new TFile("/sps/atlas/h/hatmani/Systh_2/PreRec_24/Results/Systh/Systh_IDEff.root");
        TFile* Syst9   = new TFile("/sps/atlas/h/hatmani/Systh_2/PreRec_24/Results/Systh/Systh_noIsoCut.root");
        TFile* Syst10  = new TFile("/sps/atlas/h/hatmani/Systh_2/PreRec_24/Results/Systh/Systh_EW.root");

	TH1D*  hSyst1  = (TH1D*)Syst1->Get("measScale_alpha");
        TH1D*  hSyst2  = (TH1D*)Syst2->Get("measScale_alpha");
        TH1D*  hSyst3  = (TH1D*)Syst3->Get("measScale_alpha");
        TH1D*  hSyst4  = (TH1D*)Syst4->Get("measScale_alpha");
        TH1D*  hSyst5  = (TH1D*)Syst5->Get("measScale_alpha");
        TH1D*  hSyst6  = (TH1D*)Syst6->Get("measScale_alpha");
        TH1D*  hSyst7  = (TH1D*)Syst7->Get("measScale_alpha");
        TH1D*  hSyst8  = (TH1D*)Syst8->Get("measScale_alpha");
        TH1D*  hSyst9  = (TH1D*)Syst9->Get("measScale_alpha");
        TH1D*  hSyst10 = (TH1D*)Syst10->Get("measScale_alpha");

	for(int j=0; j<Nbins; j++){

	double v1  = abs ( hSyst1->GetBinContent(j+1) ) ;
        double v2  = abs ( hSyst2->GetBinContent(j+1) ) ;
        double v3  = abs ( hSyst3->GetBinContent(j+1) ) ;
        double v4  = abs ( hSyst4->GetBinContent(j+1) ) ;
        double v5  = abs ( hSyst5->GetBinContent(j+1) ) ;
        double v6  = abs ( hSyst6->GetBinContent(j+1) ) ;
        double v7  = abs ( hSyst7->GetBinContent(j+1) ) ;
        double v8  = abs ( hSyst8->GetBinContent(j+1) ) ;
        double v9  = abs ( hSyst9->GetBinContent(j+1) ) ;
        double v10 = abs ( hSyst10->GetBinContent(j+1) ) ;

	cout<<" ] "<<bins[j]<<" : "<<bins[j+1]<<" ],"<<endl;
	cout<<scientific<<v1<<","<<v2<<","<<v3<<","<<v4<<","<<v5<<","<<v6<<","<<v7<<","<<v8<<","<<v9<<","<<v10<<endl;
	}

  	}

void SourceOfError2017Stat(){

        int Nbins = 24;
        double bins[25]={-2.47,-2.4,-2.1,-1.8,-1.55,-1.37,-1.2,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.37,1.55,1.8,2.1,2.4,2.47};

        TFile* flow = new TFile("/sps/atlas/h/hatmani/rel21_Calibe/resultat_low-mu/Alpha_2017-24.root");
        TH1F*  StatErroLow = (TH1F*)flow->Get("measScale_alpha");
	for(int j=0; j<Nbins; j++){StatErroLow->SetBinContent( j+1 , StatErroLow->GetBinError(j+1) ); StatErroLow->SetBinError( j+1 , 0); }

        TFile* fextra = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-5Intervals-pol1.root");
        TH1F*  StatErroExtra = (TH1F*)fextra->Get("Extra");
        for(int j=0; j<Nbins; j++){StatErroExtra->SetBinContent( j+1 , StatErroExtra->GetBinError(j+1) ); StatErroExtra->SetBinError( j+1 , 0); }

        StatErroLow->SetLineColor(2);
        StatErroExtra->SetLineColor(4);

        StatErroLow->SetTitle("statistical uncertainties-- low-mu");
        StatErroExtra->SetTitle("statistical uncertainties-- high-mu extrapolated to 0");
	
        StatErroExtra->SetLineWidth(2);
        StatErroLow->SetLineWidth(2);

        //StatErroLow->Draw("same");
        //StatErroExtra->Draw("same");
	
	TFile* Fichier1 = new TFile("SourceOfError2017Stat.root","recreate");
	StatErroLow->Write();
	StatErroExtra->Write();
	Fichier1->Close();


      }


void SourceOfError2018Stat(){

        int Nbins = 24;
        double bins[25]={-2.47,-2.4,-2.1,-1.8,-1.55,-1.37,-1.2,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.37,1.55,1.8,2.1,2.4,2.47};

        TFile* flow = new TFile("/sps/atlas/h/hatmani/rel21_Calib_Pre/resultat_low-mu/Alpha_2018-24.root");
        TH1F*  StatErroLow = (TH1F*)flow->Get("measScale_alpha");
        for(int j=0; j<Nbins; j++){StatErroLow->SetBinContent( j+1 , StatErroLow->GetBinError(j+1) ); StatErroLow->SetBinError( j+1 , 0); }

        TFile* fextra = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-5Intervals-pol1.root");
        TH1F*  StatErroExtra = (TH1F*)fextra->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra->SetBinContent( j+1 , StatErroExtra->GetBinError(j+1) ); StatErroExtra->SetBinError( j+1 , 0); }

        StatErroLow->SetLineColor(2);
        StatErroExtra->SetLineColor(4);

        StatErroLow->SetTitle("statistical uncertainties-- low-mu");
        StatErroExtra->SetTitle("statistical uncertainties-- high-mu extrapolated to 0");

        StatErroExtra->SetLineWidth(2);
        StatErroLow->SetLineWidth(2);

        TFile* Fichier2 = new TFile("SourceOfError2018Stat.root","recreate");
        StatErroLow->Write();
        StatErroExtra->Write();
        Fichier2->Close();

      }


int Plot(){

	SourceOfError2017Stat();
	//SourceOfError2018Stat();
	//SourceOfErrorSyst();
	return 0;
}

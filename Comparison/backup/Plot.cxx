#include "iostream"
#include "TH1.h"
#include "TFile.h"
#include "TLine.h"
#include "TTree.h"
#include "TLegend.h"



using namespace std;



void PileUpreweighting( int Years ){

	cout<<Years<<endl;

	TFile *f1=new TFile();
	TFile *f2=new TFile();

	if( Years == 2018){
        cout<<" Years  = "<< Years <<endl;
        f1 = new TFile("/sps/atlas/h/hatmani/Release_21_V1/MC_2018_21.2.40_Low_mu/MC18_LOWMU/MC18_Lowmu.root","read");                                
        f2 = new  TFile("/sps/atlas/h/hatmani/Release_21_V1/data_2018_21.2.40_Low_mu/run/submitDir/data-myOutput/data18_Lowmu.root","read");   
        }else{
        cout<<" Years  = "<< Years <<endl;
        f1 = new TFile("/sps/atlas/h/hatmani/rel21_Calib_Pre/source_17_Low-mu/MC16_13TeV_Low_mu.root","read");                                
        f2 = new TFile("/sps/atlas/h/hatmani/rel21_Calib_Pre/source_17_Low-mu/output_data17.root","read");                                    
        }


        TTree *tree1=(TTree *)f1->Get("CollectionTree");
        TTree *tree2=(TTree *)f2->Get("CollectionTree");

        TH1F *hist1=new TH1F("hist1","MC",5,0,5);       tree1->Project("hist1","mu_avg","weight_pileup_17");
        TH1F *hist2=new TH1F("hist2","data",5,0,5);     tree2->Project("hist2","(mu_avg/1.03)");


	Double_t norma = hist1->GetEntries();	hist1->Scale(1/norma); hist1->SetLineColor(2); hist1->SetLineWidth(2); hist1->SetTitle("MC");    hist1->SetStats(0);
	Double_t normb = hist2->GetEntries();	hist2->Scale(1/normb); hist2->SetLineColor(4); hist2->SetLineWidth(2); hist2->SetTitle("Data");  hist2->SetStats(0);

        TLegend *legendx=new TLegend(0.7,0.6,0.9,0.8);
        legendx->AddEntry(hist1," MC ","lpe")   ;
        legendx->AddEntry(hist2," Data ","lpe")   ;
        legendx->SetBorderSize(0);

	TLine *line = new TLine(0,1,5,1);

	TCanvas *canvas=new TCanvas("canvas","canvas",700,800);
	TPad *pad1 = new TPad("pad1", "pad1", 0, 0.35, 1, 1.0);
	pad1->SetBottomMargin(0);
	pad1->SetTitle("");
	pad1->Draw();
	pad1->cd();
	hist2->Draw();
	hist2->SetMarkerStyle(20);
	hist2->SetMarkerColor(4);
	hist1->Draw("same");
	hist2->SetMinimum(-0.002);
        legendx->Draw("same");

	canvas->cd();
	TPad *pad2 = new TPad("pad2", "pad2", 0, 0., 1, 0.30);
	pad2->SetTopMargin(0);
	pad2->SetBottomMargin(0.2);
	pad2->SetGridx();
	pad2->Draw();
	pad2->cd();

	TH1F *hist3 = (TH1F*)hist1->Clone("hist3");
	hist3->SetLineColor(kBlack);
	hist3->SetTitle("");
	hist3->SetMinimum(0.8);
	hist3->SetMaximum(1.2);
	hist3->SetStats(0);
	hist3->Divide(hist2);
	hist3->Sumw2();
	hist3->SetLineColor(2);
	hist3->GetXaxis()->SetLabelSize(0.09);
	hist3->GetYaxis()->SetLabelSize(0.09);
	hist3->GetXaxis()->SetTitle("mu");
	hist3->GetYaxis()->SetTitle("MC/Data");
	hist3->GetXaxis()->SetTitleSize(0.09);
	hist3->GetYaxis()->SetTitleSize(0.09);
	hist3->Draw("ep");
	line->Draw("same");
	hist3->SetLineWidth(2);
	hist3->SetMarkerSize(1.2);


}


int Diff18and18Extra(){

	int Nbins = 24;
	double bins[25]={-2.47,-2.4,-2.1,-1.8,-1.55,-1.37,-1.2,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.37,1.55,1.8,2.1,2.4,2.47};
	
	TLine *line = new TLine(-2.47,0,2.47,0);

	TFile* file17direct = new TFile("/sps/atlas/h/hatmani/rel21_Calib_Pre/resultat_low-mu/Alpha_2017-24.root");
        //TFile* file17Extra  = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24.root");
        TFile* file17Extra  = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-2Intervals.root");

	TFile* file18direct = new TFile("/sps/atlas/h/hatmani/rel21_Calib_Pre/resultat_low-mu/Alpha_2018-24.root");
        TFile* file18Extra  = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-2Intervals.root");
        //TFile* file18Extra  = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24.root");



	TH1F* Hist17Extra   = (TH1F*)file17Extra->Get("ExtraCorr");
	TH1F* Hist18Extra   = (TH1F*)file18Extra->Get("ExtraCorr");

	TH1F* Hist17Direct  = (TH1F*)file17direct->Get("measScale_alpha");
	TH1F* Hist18Direct  = (TH1F*)file18direct->Get("measScale_alpha");


	TH1F* Diff17  = new TH1F("Diff17","",Nbins,bins);       Diff17->Add(Hist17Extra,Hist17Direct,1,-1);
	TH1F* Diff18  = new TH1F("Diff18","",Nbins,bins);       Diff18->Add(Hist18Extra,Hist18Direct,1,-1);


	Diff17->SetLineWidth(2); Diff17->SetLineColor(2); Diff17->SetTitle("2017"); Diff17->SetStats(0);
	Diff18->SetLineWidth(2); Diff18->SetLineColor(4); Diff17->SetTitle("2018"); Diff18->SetStats(0);


	TLegend *legendx=new TLegend(0.4,0.2,0.6,0.4);
	legendx->AddEntry(Diff17," 2017 ","lpe")   ;
	legendx->AddEntry(Diff18," 2018 ","lpe")   ;
	legendx->SetBorderSize(0);

	Diff17->Draw(); Diff18->Draw("same"); line->SetLineStyle(2); line->Draw("same"); legendx->Draw("same");

	return 0;
}

int Chi2Test(int Year, int region){


	TFile* Flowmu;
	TFile* Fin3Pol1;
	TFile* Fin3Pol2;
	TFile* Fin2Pol1;
	TFile* Fin3Pol1AdP;
	TFile* Fin3Pol2AdP;

	if(Year == 2017){
	Flowmu      = new TFile("/sps/atlas/h/hatmani/rel21_Calibe/resultat_low-mu/Alpha_2017-24.root");
	Fin3Pol1    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-pol1.root");
	Fin3Pol2    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-pol2.root");
	Fin2Pol1    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-2Intervals-pol1.root");
	Fin3Pol1AdP = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-addionalpoint-pol1.root");
	Fin3Pol2AdP = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-addionalpoint-pol2.root");
	}else{
        Flowmu      = new TFile("/sps/atlas/h/hatmani/rel21_Calib_Pre/resultat_low-mu/Alpha_2018-24.root");
        Fin3Pol1    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-pol1.root");
        Fin3Pol2    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-pol2.root");
        Fin2Pol1    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-2Intervals-pol1.root");
        Fin3Pol1AdP = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-addionalpoint-pol1.root");
        Fin3Pol2AdP = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-addionalpoint-pol2.root");
	}	




        TH1F*  Hlowmu      = (TH1F*)Flowmu->Get("measScale_alpha");
        TH1F*  Hin3Pol1    = (TH1F*)Fin3Pol1->Get("ExtraCorr");
        TH1F*  Hin3Pol2    = (TH1F*)Fin3Pol2->Get("ExtraCorr");
        TH1F*  Hin2Pol1    = (TH1F*)Fin2Pol1->Get("ExtraCorr");
        TH1F*  Hin3Pol1AdP = (TH1F*)Fin3Pol1AdP->Get("ExtraCorr");
	TH1F*  Hin3Pol2AdP = (TH1F*)Fin3Pol2AdP->Get("ExtraCorr");
	
	double chi2n1   = 0;
	double chi2n2   = 0;
	double chi2n3   = 0;	
        double chi2n4   = 0;
        double chi2n5   = 0;

	for( int j=0; j<24; j++ ) { 
	if( region == 1 && ( j+1 == 4 || j+1 == 5 || j+1 == 6 || j+1 == 19 || j+1 == 20 || j+1 == 21 ) ) continue;
	cout<<j+1<<endl;
	chi2n1 = chi2n1 + pow(Hlowmu->GetBinContent(j+1) - Hin3Pol1->GetBinContent(j+1) , 2 ) / ( pow(Hlowmu->GetBinError(j+1),2) + pow(Hin3Pol1->GetBinError(j+1),2)); // Poly 1 + 3 intervals of mu 
        chi2n2 = chi2n2 + pow(Hlowmu->GetBinContent(j+1) - Hin3Pol2->GetBinContent(j+1) , 2 ) / ( pow(Hlowmu->GetBinError(j+1),2) + pow(Hin3Pol2->GetBinError(j+1),2)); // poly 2 + 3 intervals of mu
        chi2n3 = chi2n3 + pow(Hlowmu->GetBinContent(j+1) - Hin2Pol1->GetBinContent(j+1) , 2 ) / ( pow(Hlowmu->GetBinError(j+1),2) + pow(Hin2Pol1->GetBinError(j+1),2)); // poly 1 + 2 intervals of mu
        chi2n4 = chi2n4 + pow(Hlowmu->GetBinContent(j+1) - Hin3Pol1AdP->GetBinContent(j+1) , 2 ) / ( pow(Hlowmu->GetBinError(j+1),2) + pow(Hin3Pol1AdP->GetBinError(j+1),2)); // poly 1 + 3 intervals of mu + Additional point
        chi2n5 = chi2n5 + pow(Hlowmu->GetBinContent(j+1) - Hin3Pol2AdP->GetBinContent(j+1) , 2 ) / ( pow(Hlowmu->GetBinError(j+1),2) + pow(Hin3Pol2AdP->GetBinError(j+1),2)); // poly 2 + 3 intervals of mu + Additional point
	}

	cout<<"          			"<<Year<<"					   "<<endl;			
	cout<<"Chi-2 for the extrapolation results with Polynom of ordre 1 and 3 interval of mu  = "<<chi2n1<<endl;
	cout<<"Chi-2 for the extrapolation results with Polynom of ordre 2 and 3 interval of mu  = "<<chi2n2<<endl;
        cout<<"Chi-2 for the extrapolation results with Polynom of ordre 1 and 2 interval of mu  = "<<chi2n3<<endl;
        cout<<"Chi-2 for the extrapolation results with Polynom of ordre 1 and 3 interval of mu + using low mu results = "<<chi2n4<<endl;
        cout<<"Chi-2 for the extrapolation results with Polynom of ordre 2 and 3 interval of mu + using low mu results = "<<chi2n5<<endl;

	return 0;
}

int PullPlot(){


        TFile* Flowmu      = new TFile("/sps/atlas/h/hatmani/rel21_Calibe/resultat_low-mu/Alpha_2017-24.root");			   TH1F*  Hlowmu      = (TH1F*)Flowmu->Get("measScale_alpha");
        TFile* Fin3Pol1    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-pol1.root");		   TH1F*  Hin3Pol1    = (TH1F*)Fin3Pol1->Get("ExtraCorr");
        TFile* Fin3Pol2    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-pol2.root");		   TH1F*  Hin3Pol2    = (TH1F*)Fin3Pol2->Get("ExtraCorr");
        TFile* Fin2Pol1    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-2Intervals-pol1.root");    TH1F*  Hin2Pol1    = (TH1F*)Fin2Pol1->Get("ExtraCorr");
        TFile* Fin3Pol1AdP = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-addionalpoint-pol1.root"); TH1F*  Hin3Pol1AdP = (TH1F*)Fin3Pol1AdP->Get("ExtraCorr");
        TFile* Fin3Pol2AdP = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-addionalpoint-pol2.root"); TH1F*  Hin3Pol2AdP = (TH1F*)Fin3Pol2AdP->Get("ExtraCorr");

        int Nbins     = 24 ;	double pull   = 0  ;   double chi2n1 = 0  ;   double chi2n2 = 0  ;	double chi2n3 = 0  ;	double chi2n4 = 0  ;        double chi2n5 = 0  ;
        double bins[25]={-2.47,-2.4,-2.1,-1.8,-1.55,-1.37,-1.2,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.37,1.55,1.8,2.1,2.4,2.47};

        TH1F* Pull       = new TH1F("Pull","",Nbins,bins);	TH1F* PullFill1  = new TH1F("PullFill1","",4,-4,4);        TH1F* PullFill2  = new TH1F("PullFill2","",4,-4,4);	
	TH1F* PullFill3  = new TH1F("PullFill3","",4,-4,4);	TH1F* PullFill4  = new TH1F("PullFill4","",4,-4,4);        TH1F* PullFill5  = new TH1F("PullFill5","",4,-4,4);

	for( int j=0; j<24; j++ ) {

		chi2n1= ( Hlowmu->GetBinContent(j+1) - Hin3Pol1->GetBinContent(j+1) )    / sqrt(  pow(Hlowmu->GetBinError(j+1),2) + pow(Hin3Pol1->GetBinError(j+1),2)  );
	        chi2n2= ( Hlowmu->GetBinContent(j+1) - Hin3Pol2->GetBinContent(j+1) )    / sqrt(  pow(Hlowmu->GetBinError(j+1),2) + pow(Hin3Pol2->GetBinError(j+1),2)  );
	        chi2n3= ( Hlowmu->GetBinContent(j+1) - Hin2Pol1->GetBinContent(j+1) )    / sqrt(  pow(Hlowmu->GetBinError(j+1),2) + pow(Hin2Pol1->GetBinError(j+1),2)  );
	        chi2n4= ( Hlowmu->GetBinContent(j+1) - Hin3Pol1AdP->GetBinContent(j+1) ) / sqrt(  pow(Hlowmu->GetBinError(j+1),2) + pow(Hin3Pol1AdP->GetBinError(j+1),2)  );
	        chi2n5= ( Hlowmu->GetBinContent(j+1) - Hin3Pol2AdP->GetBinContent(j+1) ) / sqrt(  pow(Hlowmu->GetBinError(j+1),2) + pow(Hin3Pol2AdP->GetBinError(j+1),2)  );
	
		PullFill1->Fill(chi2n1);   
	        PullFill2->Fill(chi2n2);
	        PullFill3->Fill(chi2n3);
	        PullFill4->Fill(chi2n4);
	        PullFill5->Fill(chi2n5);

	}       

	PullFill1->Draw();
        PullFill2->Draw("same");
        PullFill3->Draw("same");
        PullFill4->Draw("same");
        PullFill5->Draw("same");
	
        TCanvas *c1 = new TCanvas("c1","multipads",900,700);
        
        TPad *pad1 = new TPad("pad1", "center_pad",0.0,0.0,0.48,0.3); 	pad1->Draw();
   	TPad *pad2 = new TPad("pad2", "right_pad",0.52,0.0,1.0,0.3);	pad2->Draw();
   	TPad *pad3 = new TPad("pad3", "top_pad",0.0,0.33,0.48,0.66);	pad3->Draw();
        TPad *pad4 = new TPad("pad4", "top_pad",0.52,0.33,1.,0.66);	pad4->Draw();
        TPad *pad5 = new TPad("pad5", "top_pad",0.25,0.66,0.73,0.99);	pad5->Draw();

	pad1->cd();  PullFill1->Draw();  PullFill1->GetXaxis()->SetLabelSize(0.08);PullFill1->GetYaxis()->SetLabelSize(0.08);
	pad2->cd();  PullFill2->Draw();  PullFill2->GetXaxis()->SetLabelSize(0.08);PullFill2->GetYaxis()->SetLabelSize(0.08);
        pad3->cd();  PullFill3->Draw();  PullFill3->GetXaxis()->SetLabelSize(0.08);PullFill3->GetYaxis()->SetLabelSize(0.08);
        pad4->cd();  PullFill4->Draw();  PullFill4->GetXaxis()->SetLabelSize(0.08);PullFill4->GetYaxis()->SetLabelSize(0.08);
        pad5->cd();  PullFill5->Draw();  PullFill5->GetXaxis()->SetLabelSize(0.08);PullFill5->GetYaxis()->SetLabelSize(0.08);

	}


int Table(){

  	fstream latex;

	latex << "\\begin{center}" << endl;
  	latex << "\\hline" << endl;
	latex << "\\end{tabular}" << endl;

 	latex.close();

	}

int SourceOfError2017(){

        int Nbins = 24;
        double bins[25]={-2.47,-2.4,-2.1,-1.8,-1.55,-1.37,-1.2,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.37,1.55,1.8,2.1,2.4,2.47};

        TFile* flow = new TFile("/sps/atlas/h/hatmani/rel21_Calibe/resultat_low-mu/Alpha_2017-24.root");
        TH1F*  StatErroLow = (TH1F*)flow->Get("measScale_alpha");
	for(int j=0; j<Nbins; j++){StatErroLow->SetBinContent( j+1 , StatErroLow->GetBinError(j+1) ); StatErroLow->SetBinError( j+1 , 0); }

        TFile* fextra = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-5Intervals-pol1.root");
        TH1F*  StatErroExtra = (TH1F*)fextra->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra->SetBinContent( j+1 , StatErroExtra->GetBinError(j+1) ); StatErroExtra->SetBinError( j+1 , 0); }

        TFile* fSystHigh = new TFile("/sps/atlas/h/hatmani/Plot-note/Rel21/High-mu/EnergyScaleFactors_21.root");
        TH1F*  SystHigh = (TH1F*)fSystHigh->Get("totSyst_alpha");

        TFile* fSystHigh24 = new TFile("/sps/atlas/h/hatmani/Systh_2/PreRec_Old/Results/resum/EnergyScaleFactorsAout.root");
        TH1F*  SystHigh24  = (TH1F*)fSystHigh24->Get("totSyst_alpha");


        TFile* TCStudy     = new TFile("/sps/atlas/h/hatmani/rel21_Calib_TCnoise/diff-stat/diff-energy/DiffTCstudy.root");
        TH1F*  HistTCStudy = (TH1F*)TCStudy->Get("DIff");
        for(int j=0; j<Nbins ; j++){  HistTCStudy->SetBinContent( j+1 , abs(HistTCStudy->GetBinContent(j+1)/2) ) ; HistTCStudy->SetBinError( j+1 , 0); }

        StatErroLow->SetLineColor(2);
        StatErroExtra->SetLineColor(4);
        SystHigh->SetLineColor(3);


        SystHigh->SetTitle("systematic uncertainties -- high-mu");
        StatErroLow->SetTitle("statistical uncertainties-- low-mu");
        StatErroExtra->SetTitle("statistical uncertainties-- high-mu extrapolated to 0");
        HistTCStudy->SetTitle("systematic of threshold");
	
        StatErroExtra->SetLineWidth(2);
        StatErroLow->SetLineWidth(2);
        SystHigh->SetLineWidth(2);
        HistTCStudy->SetLineWidth(2);
	SystHigh24->SetLineWidth(2);


        SystHigh->Draw("same");       
        StatErroExtra->Draw("same");
        StatErroLow->Draw("same");
        HistTCStudy->Draw("same");
	SystHigh24->Draw("same");
      }


int SourceOfError2018(){

        int Nbins = 24;
        double bins[25]={-2.47,-2.4,-2.1,-1.8,-1.55,-1.37,-1.2,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.37,1.55,1.8,2.1,2.4,2.47};

        TFile* flow = new TFile("/sps/atlas/h/hatmani/rel21_Calib_Pre/resultat_low-mu/Alpha_2018-24.root");
        TH1F*  StatErroLow = (TH1F*)flow->Get("measScale_alpha");
        for(int j=0; j<Nbins; j++){StatErroLow->SetBinContent( j+1 , StatErroLow->GetBinError(j+1) ); StatErroLow->SetBinError( j+1 , 0); }

        TFile* fextra = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-pol1.root");
        TH1F*  StatErroExtra = (TH1F*)fextra->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra->SetBinContent( j+1 , StatErroExtra->GetBinError(j+1) ); StatErroExtra->SetBinError( j+1 , 0); }

        TFile* fSystHigh = new TFile("/sps/atlas/h/hatmani/Plot-note/Rel21/High-mu/EnergyScaleFactors_21.root");
        TH1F*  SystHigh = (TH1F*)fSystHigh->Get("totSyst_alpha");

        TFile* TCStudy     = new TFile("/sps/atlas/h/hatmani/rel21_Calib_TCnoise/diff-stat/diff-energy/DiffTCstudy.root");
        TH1F*  HistTCStudy = (TH1F*)TCStudy->Get("DIff");
        for(int j=0; j<Nbins ; j++){  HistTCStudy->SetBinContent( j+1 , abs(HistTCStudy->GetBinContent(j+1)/2) ) ; HistTCStudy->SetBinError( j+1 , 0); }

        StatErroLow->SetLineColor(2);
        StatErroExtra->SetLineColor(4);
        SystHigh->SetLineColor(3);


        SystHigh->SetTitle("systematic uncertainties -- high-mu");
        StatErroLow->SetTitle("statistical uncertainties-- low-mu");
        StatErroExtra->SetTitle("statistical uncertainties-- high-mu extrapolated to 0");
        HistTCStudy->SetTitle("systematic of threshold");

        StatErroExtra->SetLineWidth(2);
        StatErroLow->SetLineWidth(2);
        SystHigh->SetLineWidth(2);
        HistTCStudy->SetLineWidth(2);


        SystHigh->Draw("same");
        StatErroExtra->Draw("same");
        StatErroLow->Draw("same");
        HistTCStudy->Draw("same");
      }

int SourceOfErrorInter2017(){

        int Nbins = 24;
        double bins[25]={-2.47,-2.4,-2.1,-1.8,-1.55,-1.37,-1.2,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.37,1.55,1.8,2.1,2.4,2.47};

        TFile* flow = new TFile("/sps/atlas/h/hatmani/rel21_Calib_Pre/resultat_low-mu/Alpha_2017-24.root");
        TH1F*  StatErroLow = (TH1F*)flow->Get("measScale_alpha");
        for(int j=0; j<Nbins; j++){StatErroLow->SetBinContent( j+1 , StatErroLow->GetBinError(j+1) ); StatErroLow->SetBinError( j+1 , 0); }

        TFile* fextra1 = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-2Intervals-pol1.root");
        TH1F*  StatErroExtra1 = (TH1F*)fextra1->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra1->SetBinContent( j+1 , StatErroExtra1->GetBinError(j+1) ); StatErroExtra1->SetBinError( j+1 , 0); }

        TFile* fextra2 = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-3Intervals-pol1.root");
        TH1F*  StatErroExtra2 = (TH1F*)fextra2->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra2->SetBinContent( j+1 , StatErroExtra2->GetBinError(j+1) ); StatErroExtra2->SetBinError( j+1 , 0); }

        TFile* fextra3 = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-4Intervals-pol1.root");
        TH1F*  StatErroExtra3 = (TH1F*)fextra3->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra3->SetBinContent( j+1 , StatErroExtra3->GetBinError(j+1) ); StatErroExtra3->SetBinError( j+1 , 0); }

        TFile* fextra4 = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-5Intervals-pol1.root");
        TH1F*  StatErroExtra4 = (TH1F*)fextra4->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra4->SetBinContent( j+1 , StatErroExtra4->GetBinError(j+1) ); StatErroExtra4->SetBinError( j+1 , 0); }

	StatErroLow->SetLineColor(1);
        StatErroExtra1->SetLineColor(2);
        StatErroExtra2->SetLineColor(3);
        StatErroExtra3->SetLineColor(4);
        StatErroExtra4->SetLineColor(6);

        StatErroLow->SetTitle("statistical uncertainties-- low-mu");
        StatErroExtra1->SetTitle("statistical uncertainties - high-mu extrapolated to 0 - 2 intervals of mu");
        StatErroExtra2->SetTitle("statistical uncertainties - high-mu extrapolated to 0 - 3 intervals of mu");
        StatErroExtra3->SetTitle("statistical uncertainties - high-mu extrapolated to 0 - 4 intervals of mu");
        StatErroExtra4->SetTitle("statistical uncertainties - high-mu extrapolated to 0 - 5 intervals of mu");

        StatErroLow->SetLineWidth(2);
        StatErroExtra1->SetLineWidth(2);
        StatErroExtra2->SetLineWidth(2);
        StatErroExtra3->SetLineWidth(2);
        StatErroExtra4->SetLineWidth(2);

        StatErroLow->Draw("same");
        StatErroExtra1->Draw("same");
        StatErroExtra2->Draw("same");
        StatErroExtra3->Draw("same");
        StatErroExtra4->Draw("same");

      }

int SourceOfErrorInter2017Addlow(){

        int Nbins = 24;
        double bins[25]={-2.47,-2.4,-2.1,-1.8,-1.55,-1.37,-1.2,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.37,1.55,1.8,2.1,2.4,2.47};

        TFile* flow = new TFile("/sps/atlas/h/hatmani/rel21_Calib_Pre/resultat_low-mu/Alpha_2017-24.root");
        TH1F*  StatErroLow = (TH1F*)flow->Get("measScale_alpha");
        for(int j=0; j<Nbins; j++){StatErroLow->SetBinContent( j+1 , StatErroLow->GetBinError(j+1) ); StatErroLow->SetBinError( j+1 , 0); }

        TFile* fextra1 = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-2Intervals-IntervaAddi.root");
        TH1F*  StatErroExtra1 = (TH1F*)fextra1->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra1->SetBinContent( j+1 , StatErroExtra1->GetBinError(j+1) ); StatErroExtra1->SetBinError( j+1 , 0); }

        TFile* fextra2 = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-3Intervals-IntervaAddi.root");
        TH1F*  StatErroExtra2 = (TH1F*)fextra2->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra2->SetBinContent( j+1 , StatErroExtra2->GetBinError(j+1) ); StatErroExtra2->SetBinError( j+1 , 0); }

        TFile* fextra3 = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-4Intervals-IntervaAddi.root");
        TH1F*  StatErroExtra3 = (TH1F*)fextra3->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra3->SetBinContent( j+1 , StatErroExtra3->GetBinError(j+1) ); StatErroExtra3->SetBinError( j+1 , 0); }

        TFile* fextra4 = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-5Intervals-IntervaAddi.root");
        TH1F*  StatErroExtra4 = (TH1F*)fextra4->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra4->SetBinContent( j+1 , StatErroExtra4->GetBinError(j+1) ); StatErroExtra4->SetBinError( j+1 , 0); }

        StatErroLow->SetLineColor(1);
        StatErroExtra1->SetLineColor(2);
        StatErroExtra2->SetLineColor(3);
        StatErroExtra3->SetLineColor(4);
        StatErroExtra4->SetLineColor(6);

        StatErroLow->SetTitle("statistical uncertainties-- low-mu");
        StatErroExtra1->SetTitle("statistical uncertainties - high-mu extrapolated to 0 - 2 intervals of mu");
        StatErroExtra2->SetTitle("statistical uncertainties - high-mu extrapolated to 0 - 3 intervals of mu");
        StatErroExtra3->SetTitle("statistical uncertainties - high-mu extrapolated to 0 - 4 intervals of mu");
        StatErroExtra4->SetTitle("statistical uncertainties - high-mu extrapolated to 0 - 5 intervals of mu");

        StatErroLow->SetLineWidth(2);
        StatErroExtra1->SetLineWidth(2);
        StatErroExtra2->SetLineWidth(2);
        StatErroExtra3->SetLineWidth(2);
        StatErroExtra4->SetLineWidth(2);

        StatErroLow->Draw("same");
        StatErroExtra1->Draw("same");
        StatErroExtra2->Draw("same");
        StatErroExtra3->Draw("same");
        StatErroExtra4->Draw("same");

      }

int SourceOfErrorInter2018(){

        int Nbins = 24;
        double bins[25]={-2.47,-2.4,-2.1,-1.8,-1.55,-1.37,-1.2,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.37,1.55,1.8,2.1,2.4,2.47};

        TFile* flow = new TFile("/sps/atlas/h/hatmani/rel21_Calib_Pre/resultat_low-mu/Alpha_2018-24.root");
        TH1F*  StatErroLow = (TH1F*)flow->Get("measScale_alpha");
        for(int j=0; j<Nbins; j++){StatErroLow->SetBinContent( j+1 , StatErroLow->GetBinError(j+1) ); StatErroLow->SetBinError( j+1 , 0); }

        TFile* fextra1 = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-2Intervals-pol1.root");
        TH1F*  StatErroExtra1 = (TH1F*)fextra1->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra1->SetBinContent( j+1 , StatErroExtra1->GetBinError(j+1) ); StatErroExtra1->SetBinError( j+1 , 0); }

        TFile* fextra2 = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-3Intervals-pol1.root");
        TH1F*  StatErroExtra2 = (TH1F*)fextra2->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra2->SetBinContent( j+1 , StatErroExtra2->GetBinError(j+1) ); StatErroExtra2->SetBinError( j+1 , 0); }

        TFile* fextra3 = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-4Intervals-pol1.root");
        TH1F*  StatErroExtra3 = (TH1F*)fextra3->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra3->SetBinContent( j+1 , StatErroExtra3->GetBinError(j+1) ); StatErroExtra3->SetBinError( j+1 , 0); }

        TFile* fextra4 = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-5Intervals-pol1.root");
        TH1F*  StatErroExtra4 = (TH1F*)fextra4->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra4->SetBinContent( j+1 , StatErroExtra4->GetBinError(j+1) ); StatErroExtra4->SetBinError( j+1 , 0); }

        StatErroLow->SetLineColor(1);
        StatErroExtra1->SetLineColor(2);
        StatErroExtra2->SetLineColor(3);
        StatErroExtra3->SetLineColor(4);
        StatErroExtra4->SetLineColor(6);

        StatErroLow->SetTitle("statistical uncertainties-- low-mu");
        StatErroExtra1->SetTitle("statistical uncertainties - high-mu extrapolated to 0 - 2 intervals of mu");
        StatErroExtra2->SetTitle("statistical uncertainties - high-mu extrapolated to 0 - 3 intervals of mu");
        StatErroExtra3->SetTitle("statistical uncertainties - high-mu extrapolated to 0 - 4 intervals of mu");
        StatErroExtra4->SetTitle("statistical uncertainties - high-mu extrapolated to 0 - 5 intervals of mu");

        StatErroLow->SetLineWidth(2);
        StatErroExtra1->SetLineWidth(2);
        StatErroExtra2->SetLineWidth(2);
        StatErroExtra3->SetLineWidth(2);
        StatErroExtra4->SetLineWidth(2);

        StatErroLow->Draw("same");
        StatErroExtra1->Draw("same");
        StatErroExtra2->Draw("same");
        StatErroExtra3->Draw("same");
        StatErroExtra4->Draw("same");

      }

int SourceOfErrorInter2018Addlow(){

        int Nbins = 24;
        double bins[25]={-2.47,-2.4,-2.1,-1.8,-1.55,-1.37,-1.2,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.37,1.55,1.8,2.1,2.4,2.47};

        TFile* flow = new TFile("/sps/atlas/h/hatmani/rel21_Calib_Pre/resultat_low-mu/Alpha_2018-24.root");
        TH1F*  StatErroLow = (TH1F*)flow->Get("measScale_alpha");
        for(int j=0; j<Nbins; j++){StatErroLow->SetBinContent( j+1 , StatErroLow->GetBinError(j+1) ); StatErroLow->SetBinError( j+1 , 0); }

        TFile* fextra1 = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-2Intervals-IntervaAddi.root");
        TH1F*  StatErroExtra1 = (TH1F*)fextra1->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra1->SetBinContent( j+1 , StatErroExtra1->GetBinError(j+1) ); StatErroExtra1->SetBinError( j+1 , 0); }

        TFile* fextra2 = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-3Intervals-IntervaAddi.root");
        TH1F*  StatErroExtra2 = (TH1F*)fextra2->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra2->SetBinContent( j+1 , StatErroExtra2->GetBinError(j+1) ); StatErroExtra2->SetBinError( j+1 , 0); }

        TFile* fextra3 = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-4Intervals-IntervaAddi.root");
        TH1F*  StatErroExtra3 = (TH1F*)fextra3->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra3->SetBinContent( j+1 , StatErroExtra3->GetBinError(j+1) ); StatErroExtra3->SetBinError( j+1 , 0); }

        TFile* fextra4 = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-5Intervals-IntervaAddi.root");
        TH1F*  StatErroExtra4 = (TH1F*)fextra4->Get("ExtraCorr");
        for(int j=0; j<Nbins; j++){StatErroExtra4->SetBinContent( j+1 , StatErroExtra4->GetBinError(j+1) ); StatErroExtra4->SetBinError( j+1 , 0); }

        StatErroLow->SetLineColor(1);
        StatErroExtra1->SetLineColor(2);
        StatErroExtra2->SetLineColor(3);
        StatErroExtra3->SetLineColor(4);
        StatErroExtra4->SetLineColor(6);

        StatErroLow->SetTitle("statistical uncertainties-- low-mu");
        StatErroExtra1->SetTitle("statistical uncertainties - high-mu extrapolated to 0 - 2 intervals of mu");
        StatErroExtra2->SetTitle("statistical uncertainties - high-mu extrapolated to 0 - 3 intervals of mu");
        StatErroExtra3->SetTitle("statistical uncertainties - high-mu extrapolated to 0 - 4 intervals of mu");
        StatErroExtra4->SetTitle("statistical uncertainties - high-mu extrapolated to 0 - 5 intervals of mu");

        StatErroLow->SetLineWidth(2);
        StatErroExtra1->SetLineWidth(2);
        StatErroExtra2->SetLineWidth(2);
        StatErroExtra3->SetLineWidth(2);
        StatErroExtra4->SetLineWidth(2);

        StatErroLow->Draw("same");
        StatErroExtra1->Draw("same");
        StatErroExtra2->Draw("same");
        StatErroExtra3->Draw("same");
        StatErroExtra4->Draw("same");

      }

int Plot(){

	//Diff18and18Extra();
	//PileUpreweighting(2017);
	//Chi2Test(2018,1);
	//PullPlot();
	SourceOfError2017();
	//SourceOfError2018();
	//SourceOfErrorInter2017();
        //SourceOfErrorInter2018();
	//SourceOfErrorInter2017Addlow();
        //SourceOfErrorInter2018Addlow();

	return 0;
}

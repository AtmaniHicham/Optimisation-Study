#include "TFile.h"
#include "TMatrixT.h"
#include "TH1.h"

using std::to_string;

using namespace std;

void SysPlot(){

        int Nbins = 24;
        double bins[25]={-2.47,-2.4,-2.1,-1.8,-1.55,-1.37,-1.2,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.37,1.55,1.8,2.1,2.4,2.47};

        //TFile* TCStudy     = new TFile("/sps/atlas/h/hatmani/rel21_Calib_TCnoise/diff-stat/diff-energy/DiffTCstudy.root");
        //TH1F*  HistTCStudy = (TH1F*)TCStudy->Get("DIff");

	//for(int i = 0 ; i<HistTCStudy->GetNbinsX() ; i++ ){
	//HistTCStudy->SetBinContent(i+1,HistTCStudy->GetBinError(i+1));    HistTCStudy->SetBinError(i+1,0);
	//}

        TFile* fileX7  = new TFile("/sps/atlas/h/hatmani/rel21_Calibe/resultat_low-mu/Alpha_2017-24.root");

        TFile* fileX1  = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-5Intervals-pol1.root");
        TFile* fileX2  = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-5Intervals-pol2.root");
        TFile* fileX3  = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-3Intervals-pol1.root");

        TFile* fileX4  = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-5Intervals-IntervaAddi-pol1.root");
        TFile* fileX5  = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-5Intervals-IntervaAddi-pol2.root");
        TFile* fileX6  = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-3Intervals-IntervaAddi-pol1.root");


        TFile* fileX8  = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-5Intervals_2IntervalEta-pol1.root");
        TFile* fileX9  = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-5Intervals_2IntervalEta-pol2.root");

        TFile* fileXS1 = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/Output-24-5Intervals_2Interval1EtaPol1.root");
        TFile* fileXS2 = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/Output-24-5Intervals_2Interval1EtaPol2.root");

//        TFile* fileX10  = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2017/output-24-5Intervals-IntervaAddi-pol1Shift.root");

        TH1F*  HistX1   = (TH1F*)fileX1->Get("Extra");			HistX1->SetName("HistX1");	HistX1->SetTitle("HistX1");
        TH1F*  HistX2   = (TH1F*)fileX2->Get("Extra");			HistX2->SetName("HistX2");      HistX2->SetTitle("HistX2");
        TH1F*  HistX3   = (TH1F*)fileX3->Get("Extra");			HistX3->SetName("HistX3");      HistX3->SetTitle("HistX3");	
        TH1F*  HistX4   = (TH1F*)fileX4->Get("Extra");			HistX4->SetName("HistX4");      HistX4->SetTitle("HistX4");	
        TH1F*  HistX5   = (TH1F*)fileX5->Get("Extra");			HistX5->SetName("HistX5");      HistX5->SetTitle("HistX5");	
        TH1F*  HistX6   = (TH1F*)fileX6->Get("Extra");			HistX6->SetName("HistX6");      HistX6->SetTitle("HistX6");
        TH1F*  HistX7   = (TH1F*)fileX7->Get("measScale_alpha");	HistX7->SetName("HistX7");      HistX7->SetTitle("HistX7");

        TH1F*  HistX11  = (TH1F*)fileX8->Get("Extra");                  HistX11->SetName("HistX11");    HistX11->SetTitle("HistX11");
        TH1F*  HistX12  = (TH1F*)fileX9->Get("Extra");                  HistX12->SetName("HistX12");    HistX12->SetTitle("HistX12");

	TH1F*  HistXS1  = (TH1F*)fileXS1->Get("Extra");                 HistXS1->SetName("HistXS1");    HistXS1->SetTitle("HistXS1");
        TH1F*  HistXS2  = (TH1F*)fileXS2->Get("Extra");                 HistXS2->SetName("HistXS2");    HistXS2->SetTitle("HistXS2");

//      TH1F*  HistX13 = (TH1F*)fileX10->Get("Extra");                  HistX13->SetName("HistX13");    HistX13->SetTitle("HistX13");
	

	TH1F*  HistX8  = (TH1F*)HistX7->Clone("HistX8");		HistX8->SetName("HistX8");      HistX8->SetTitle("HistX8");

        TH1D* Hx7Mx1   = (TH1D*) HistX7->Clone("Hx7Mx1");
        TH1D* Hx2Mx1   = (TH1D*) HistX7->Clone("Hx2Mx1");
        TH1D* Hx3Mx1   = (TH1D*) HistX7->Clone("Hx3Mx1");
        TH1D* Hx4Mx1   = (TH1D*) HistX7->Clone("Hx4Mx1");
        TH1D* Hx5Mx4   = (TH1D*) HistX7->Clone("Hx5Mx4");
        TH1D* Hx6Mx4   = (TH1D*) HistX7->Clone("Hx6Mx4");
        TH1D* HSys     = (TH1D*) HistX11->Clone("HSys");
        //TH1D* HSysThe  = (TH1D*) HistX13->Clone("HSysThe");
	TH1D* HSysOrdr = (TH1D*) HistXS1->Clone("HSysOrdr");

        HSys->Add(HistX11,HistX12,1,-1);

        for(int i = 0 ; i<Hx7Mx1->GetNbinsX() ; i++ ){
        HistX8->SetBinContent(i+1,(HistX1->GetBinContent(i+1)/pow(HistX1->GetBinError(i+1),2) + HistX7->GetBinContent(i+1)/pow(HistX7->GetBinError(i+1),2) ) / ( 1/pow(HistX1->GetBinError(i+1),2) + 1/pow(HistX7->GetBinError(i+1),2) ) );
        HistX8->SetBinError(i+1, 1 / sqrt( 1/pow(HistX1->GetBinError(i+1),2) + 1/pow(HistX7->GetBinError(i+1),2) ) );}

	// Sigma on low-mu :
	
	TH1F*  Histsigma1   = (TH1F*)HistX1->Clone("Histsigma1");	TH1F*  Histsigma1m  = (TH1F*)HistX1->Clone("Histsigma1m");
	TH1F*  Histsigma2   = (TH1F*)HistX2->Clone("Histsigma2");	TH1F*  Histsigma2m  = (TH1F*)HistX2->Clone("Histsigma2m");
	TH1F*  Histsigma3   = (TH1F*)HistX3->Clone("Histsigma3");	TH1F*  Histsigma3m  = (TH1F*)HistX3->Clone("Histsigma3m");
	TH1F*  Histsigma4   = (TH1F*)HistX4->Clone("Histsigma4");	TH1F*  Histsigma4m  = (TH1F*)HistX4->Clone("Histsigma4m");
	TH1F*  Histsigma5   = (TH1F*)HistX5->Clone("Histsigma5");	TH1F*  Histsigma5m  = (TH1F*)HistX5->Clone("Histsigma5m");
	TH1F*  Histsigma6   = (TH1F*)HistX6->Clone("Histsigma6");	TH1F*  Histsigma6m  = (TH1F*)HistX6->Clone("Histsigma6m");
	TH1F*  Histsigma7   = (TH1F*)HistX7->Clone("Histsigma7");	TH1F*  Histsigma7m  = (TH1F*)HistX7->Clone("Histsigma7m");
        TH1F*  Histsigma8   = (TH1F*)HistX8->Clone("Histsigma8");       TH1F*  Histsigma8m  = (TH1F*)HistX8->Clone("Histsigma8m");


        for(int i = 0 ; i<Hx7Mx1->GetNbinsX() ; i++ ){
        Histsigma1->SetBinContent(i+1,Histsigma1->GetBinError(i+1));    Histsigma1->SetBinError(i+1,0); Histsigma1m->SetBinContent(i+1,-(Histsigma1m->GetBinError(i+1)));    Histsigma1m->SetBinError(i+1,0);
        Histsigma2->SetBinContent(i+1,Histsigma2->GetBinError(i+1));    Histsigma2->SetBinError(i+1,0); Histsigma2m->SetBinContent(i+1,-(Histsigma2m->GetBinError(i+1)));    Histsigma2m->SetBinError(i+1,0);
        Histsigma3->SetBinContent(i+1,Histsigma3->GetBinError(i+1));    Histsigma3->SetBinError(i+1,0); Histsigma3m->SetBinContent(i+1,-(Histsigma3m->GetBinError(i+1)));    Histsigma3m->SetBinError(i+1,0);
        Histsigma4->SetBinContent(i+1,Histsigma4->GetBinError(i+1));    Histsigma4->SetBinError(i+1,0); Histsigma4m->SetBinContent(i+1,-(Histsigma4m->GetBinError(i+1)));    Histsigma4m->SetBinError(i+1,0);
        Histsigma5->SetBinContent(i+1,Histsigma5->GetBinError(i+1));    Histsigma5->SetBinError(i+1,0); Histsigma5m->SetBinContent(i+1,-(Histsigma5m->GetBinError(i+1)));    Histsigma5m->SetBinError(i+1,0);
        Histsigma6->SetBinContent(i+1,Histsigma6->GetBinError(i+1));    Histsigma6->SetBinError(i+1,0); Histsigma6m->SetBinContent(i+1,-(Histsigma6m->GetBinError(i+1)));    Histsigma6m->SetBinError(i+1,0);
        Histsigma7->SetBinContent(i+1,Histsigma7->GetBinError(i+1));    Histsigma7->SetBinError(i+1,0); Histsigma7m->SetBinContent(i+1,-(Histsigma7m->GetBinError(i+1)));    Histsigma7m->SetBinError(i+1,0);
        Histsigma8->SetBinContent(i+1,Histsigma8->GetBinError(i+1));    Histsigma8->SetBinError(i+1,0); Histsigma8m->SetBinContent(i+1,-(Histsigma8m->GetBinError(i+1)));    Histsigma8m->SetBinError(i+1,0);
	}

        Hx7Mx1->Add(HistX7,HistX1,1,-1);
        Hx2Mx1->Add(HistX2,HistX1,1,-1);
        Hx3Mx1->Add(HistX3,HistX1,1,-1);
        Hx4Mx1->Add(HistX4,HistX1,1,-1);
        Hx5Mx4->Add(HistX5,HistX4,1,-1);
        Hx6Mx4->Add(HistX6,HistX4,1,-1);
	HSysOrdr->Add(HistXS1,HistXS2,1,-1);

 	
	//Hx3Mx1->Draw();
	//HSysOrdr->Draw("same");

	for(int i = 0 ; i<Hx3Mx1->GetNbinsX() ; i++ ){
	Hx3Mx1->SetBinContent(i+1, sqrt( pow(HSysOrdr->GetBinContent(i+1) ,2) + pow(Hx3Mx1->GetBinContent(i+1),2) )  );
	Hx3Mx1->SetBinError(i+1,0);
        }


	TFile* fichier = new TFile("extrapolationsys.root","recreate");
	Hx3Mx1->Write();	
	//Hx2Mx1->Write();
	fichier->Close();
	//HSysThe->Add(HistX13,HistX4,1,-1);

	//for(int i = 0 ; i<Hx7Mx1->GetNbinsX() ; i++ ){
	//cout<<"   Bin = "<<i+1<<"     HistX7  "<<HistX7->GetBinError(i+1)<<"     HistX1  "<<HistX1->GetBinError(i+1)<<"     Hx7Mx1  "<<Hx7Mx1->GetBinError(i+1)<<endl;	
	//}

	
	// Error Plot 1
/*	
        Histsigma3->GetYaxis()->SetRangeUser(-0.004,0.004);
        Histsigma1->SetStats(0);
        Histsigma1->GetXaxis()->SetTitle("#eta");
        Histsigma1->GetYaxis()->SetTitle("Stat Uncertainties");
        Histsigma1->GetYaxis()->SetTitleOffset(1.4);	
	Histsigma1->SetTitle("");       

        Histsigma2->GetYaxis()->SetRangeUser(-0.004,0.004);
        Histsigma2->SetStats(0);
        Histsigma2->GetXaxis()->SetTitle("#eta");
        Histsigma2->GetYaxis()->SetTitle("Stat Uncertainties");
        Histsigma2->GetYaxis()->SetTitleOffset(1.4);
        Histsigma2->SetTitle("");

        auto legend1 = new TLegend(0.4,0.7,0.6,0.85);
        legend1->AddEntry(Histsigma1,"Polynomial -  Order 1 ");
        legend1->AddEntry(Histsigma2,"Polynomial -  Order 2 ");
        TLine *line1 = new TLine(-2.47,0,2.47,0);

        Histsigma1->Draw();
        Histsigma2->Draw("same");
        Histsigma1m->Draw("same");
        Histsigma2m->Draw("same");
        legend1->Draw("same");
        line1->Draw("same");

        // Error Plot 1
        Histsigma1->GetYaxis()->SetRangeUser(0,0.003);
        Histsigma1->SetStats(0);
        Histsigma1->GetXaxis()->SetTitle("#eta");
        Histsigma1->GetYaxis()->SetTitle("Uncertainties");
        Histsigma1->GetYaxis()->SetTitleOffset(1.4);
        Histsigma1->SetTitle("");
	Histsigma1->SetLineColor(2);
        Histsigma1->SetLineWidth(2);

        Histsigma3->GetYaxis()->SetRangeUser(0,0.003);
        Histsigma3->SetStats(0);
        Histsigma3->GetXaxis()->SetTitle("#eta");
        Histsigma3->GetYaxis()->SetTitle("Uncertainties");
        Histsigma3->GetYaxis()->SetTitleOffset(1.4);
        Histsigma3->SetTitle("");
        Histsigma3->SetLineColor(3);
        Histsigma3->SetLineWidth(2);

        Histsigma4->GetYaxis()->SetRangeUser(0,0.003);
        Histsigma4->SetStats(0);
        Histsigma4->GetXaxis()->SetTitle("#eta");
        Histsigma4->GetYaxis()->SetTitle("Uncertainties");
        Histsigma4->GetYaxis()->SetTitleOffset(1.4);
        Histsigma4->SetTitle("");
        Histsigma4->SetLineColor(4);
        Histsigma4->SetLineWidth(2);

        Histsigma6->GetYaxis()->SetRangeUser(0,0.003);
        Histsigma6->SetStats(0);
        Histsigma6->GetXaxis()->SetTitle("#eta");
        Histsigma6->GetYaxis()->SetTitle("Uncertainties");
        Histsigma6->GetYaxis()->SetTitleOffset(1.4);
        Histsigma6->SetTitle("");
        Histsigma6->SetLineColor(6);
        Histsigma6->SetLineWidth(2);

        auto legend5 = new TLegend(0.4,0.7,0.6,0.85);
        legend5->AddEntry(Histsigma1,"X1 Stat Error");
        legend5->AddEntry(Histsigma3,"X3 Stat Error");
        legend5->AddEntry(Histsigma4,"X4 Stat Error");
        legend5->AddEntry(Histsigma6,"X6 Stat Error");

	Histsigma1->Draw();
        Histsigma3->Draw("same");
        Histsigma4->Draw("same");
        Histsigma6->Draw("same");
	Histsigma1m->Draw("same");
        Histsigma3m->Draw("same");
        Histsigma4m->Draw("same");
        Histsigma6m->Draw("same");
	legend5->Draw("same");


 	// Plot final
        Histsigma1->GetYaxis()->SetRangeUser(-0.0006,0.0006);
        Histsigma1->SetStats(0);
        Histsigma1->GetXaxis()->SetTitle("#eta");
        Histsigma1->GetYaxis()->SetTitle("Uncertainties");
        Histsigma1->GetYaxis()->SetTitleOffset(1.4);
        Histsigma1->SetTitle("");
        Histsigma1->SetLineColor(2);
        Histsigma1->SetLineWidth(2);

        Histsigma4->GetYaxis()->SetRangeUser(-0.006,0.006);
        Histsigma4->SetStats(0);
        Histsigma4->GetXaxis()->SetTitle("#eta");
        Histsigma4->GetYaxis()->SetTitle("Uncertainties");
        Histsigma4->GetYaxis()->SetTitleOffset(1.4);
        Histsigma4->SetTitle("");
        Histsigma4->SetLineColor(4);
        Histsigma4->SetLineWidth(2);

        Histsigma8->GetYaxis()->SetRangeUser(-0.006,0.006);
        Histsigma8->SetStats(0);
        Histsigma8->GetXaxis()->SetTitle("#eta");
        Histsigma8->GetYaxis()->SetTitle("Uncertainties");
        Histsigma8->GetYaxis()->SetTitleOffset(1.4);
        Histsigma8->SetTitle("");
        Histsigma8->SetLineColor(6);
        Histsigma8->SetLineWidth(2);

        TLine *line6 = new TLine(-2.47,0,2.47,0);
        auto legend5 = new TLegend(0.4,0.7,0.6,0.85);
        legend5->AddEntry(Histsigma1,"X1 Stat Error");
        legend5->AddEntry(Histsigma4,"X4 Stat Error");
        legend5->AddEntry(Histsigma8,"X8 Stat Error");

        Histsigma1->SetLineColor(2);
        Histsigma1->SetLineWidth(2);
        Histsigma4->SetLineColor(4);
        Histsigma4->SetLineWidth(2);
        Histsigma8->SetLineColor(6);
        Histsigma8->SetLineWidth(2);

        Histsigma1m->SetLineColor(2);
        Histsigma1m->SetLineWidth(2);
        Histsigma4m->SetLineColor(4);
        Histsigma4m->SetLineWidth(2);
        Histsigma8m->SetLineColor(6);
        Histsigma8m->SetLineWidth(2);

        Histsigma1->Draw();
        Histsigma4->Draw("same");
        Histsigma8->Draw("same");
        Histsigma1m->Draw("same");
        Histsigma4m->Draw("same");
        Histsigma8m->Draw("same");
        legend5->Draw("same");
        line6->Draw("same");

	// Plot 1	
        Histsigma7->SetFillColor(86);
        Histsigma7m->SetFillColor(86);
        Histsigma7->GetYaxis()->SetRangeUser(-0.006,0.006);
        Histsigma7->SetStats(0);
        Histsigma7->GetXaxis()->SetTitle("#eta");
        Histsigma7->GetYaxis()->SetTitle("Uncertainties");
        Histsigma7->GetYaxis()->SetTitleOffset(1.4);

	Histsigma7->SetTitle("");	
	Histsigma7->SetLineWidth(0);
	Histsigma7m->SetLineWidth(0);

	Hx7Mx1->SetLineWidth(2);
	Histsigma7->Draw();
        Histsigma7m->Draw("same");
	Hx7Mx1->Draw("same");

	TLine *line1 = new TLine(-2.47,0,2.47,0);
	line1->Draw("same");

	auto legend1 = new TLegend(0.4,0.7,0.6,0.85);
 	legend1->AddEntry(Histsigma7,"Low mu Stat Error");
 	legend1->AddEntry(Hx7Mx1,"X7 - X1");
	legend1->Draw("same");

        // Plot 2      
	Histsigma7->SetFillColor(86);
        Histsigma7m->SetFillColor(86);
        Histsigma7->GetYaxis()->SetRangeUser(-0.006,0.006);
        Histsigma7->SetStats(0);
        Histsigma7->GetXaxis()->SetTitle("#eta");
        Histsigma7->GetYaxis()->SetTitle("Uncertainties");
        Histsigma7->GetYaxis()->SetTitleOffset(1.4);

        Histsigma7->SetTitle("");
        Histsigma7->SetLineWidth(0);
        Histsigma7m->SetLineWidth(0);

        Hx2Mx1->SetLineWidth(2);
        Histsigma7->Draw();
        Histsigma7m->Draw("same");
        Hx2Mx1->Draw("same");

        TLine *line2 = new TLine(-2.47,0,2.47,0);
        line2->Draw("same");

        auto legend2 = new TLegend(0.4,0.7,0.6,0.85);
        legend2->AddEntry(Histsigma7,"statistical uncertainties");
        legend2->AddEntry(Hx2Mx1,"difference between a Pol1 & Pol2");
        //legend2->AddEntry(HSysOrdr,"X2 - X1 with 1 bin in #eta ");
        legend2->Draw("same");  

	//Hx5Mx4->SetLineColor(2);
	//Hx5Mx4->SetLineWidth(2);
	HSysOrdr->SetLineColor(2);
        HSysOrdr->SetLineWidth(2);
	HSysOrdr->Draw("same");

	// Plot 3      
	Histsigma7->SetFillColor(86);
        Histsigma7m->SetFillColor(86);
        Histsigma7->GetYaxis()->SetRangeUser(-0.006,0.006);
        Histsigma7->SetStats(0);
        Histsigma7->GetXaxis()->SetTitle("#eta");
        Histsigma7->GetYaxis()->SetTitle("Uncertainties");
        Histsigma7->GetYaxis()->SetTitleOffset(1.4);

        Histsigma7->SetTitle("");
        Histsigma7->SetLineWidth(0);
        Histsigma7m->SetLineWidth(0);

        Hx3Mx1->SetLineWidth(2);
        Histsigma7->Draw();
        Histsigma7m->Draw("same");
        Hx3Mx1->Draw("same");

        TLine *line3 = new TLine(-2.47,0,2.47,0);
        line3->Draw("same");

        auto legend3 = new TLegend(0.4,0.7,0.6,0.85);
        legend3->AddEntry(Histsigma7,"Low mu Stat Error");
        legend3->AddEntry(Hx3Mx1,"X3 - X1");
  //      legend3->AddEntry(Hx6Mx4,"X6 - X4");
        legend3->Draw("same");

	Hx6Mx4->SetLineColor(2);
	Hx6Mx4->SetLineWidth(2);
//	Hx6Mx4->Draw("same");	


	// Plot 4
	Histsigma7->SetFillColor(86);
        Histsigma7m->SetFillColor(86);
        Histsigma7->GetYaxis()->SetRangeUser(-0.006,0.006);
        Histsigma7->SetStats(0);
        Histsigma7->GetXaxis()->SetTitle("#eta");
        Histsigma7->GetYaxis()->SetTitle("Uncertainties");
        Histsigma7->GetYaxis()->SetTitleOffset(1.4);

        Histsigma7->SetTitle("");
        Histsigma7->SetLineWidth(0);
        Histsigma7m->SetLineWidth(0);

        Hx5Mx4->SetLineWidth(2);
        Histsigma7->Draw();
        Histsigma7m->Draw("same");
        Hx5Mx4->Draw("same");

        TLine *line4 = new TLine(-2.47,0,2.47,0);
        line4->Draw("same");

        auto legend4 = new TLegend(0.4,0.7,0.6,0.85);
        legend4->AddEntry(Histsigma7,"Low mu Stat Error");
        legend4->AddEntry(Hx5Mx4,"X5 - X4");
        legend4->Draw("same");

	// Plot 5
	Histsigma7->SetFillColor(86);
        Histsigma7m->SetFillColor(86);
        Histsigma7->GetYaxis()->SetRangeUser(-0.006,0.006);
        Histsigma7->SetStats(0);
        Histsigma7->GetXaxis()->SetTitle("#eta");
        Histsigma7->GetYaxis()->SetTitle("Uncertainties");
        Histsigma7->GetYaxis()->SetTitleOffset(1.4);

        Histsigma7->SetTitle("");
        Histsigma7->SetLineWidth(0);
        Histsigma7m->SetLineWidth(0);

        Hx6Mx4->SetLineWidth(2);
        Histsigma7->Draw();
        Histsigma7m->Draw("same");
        Hx6Mx4->Draw("same");

        TLine *line5 = new TLine(-2.47,0,2.47,0);
        line5->Draw("same");

        auto legend5 = new TLegend(0.4,0.7,0.6,0.85);
        legend5->AddEntry(Histsigma7,"Low mu Stat Error");
        legend5->AddEntry(Hx6Mx4,"X6 - X4");
        legend5->Draw("same");

	// Plot 6
	Histsigma7->SetFillColor(86);
        Histsigma7m->SetFillColor(86);
        Histsigma7->GetYaxis()->SetRangeUser(-0.006,0.006);
        Histsigma7->SetStats(0);
        Histsigma7->GetXaxis()->SetTitle("#eta");
        Histsigma7->GetYaxis()->SetTitle("Uncertainties");
        Histsigma7->GetYaxis()->SetTitleOffset(1.4);

        Histsigma7->SetTitle("");
        Histsigma7->SetLineWidth(0);
        Histsigma7m->SetLineWidth(0);

        Hx4Mx1->SetLineWidth(2);
        Histsigma7->Draw();
        Histsigma7m->Draw("same");
        Hx4Mx1->Draw("same");

        TLine *line6 = new TLine(-2.47,0,2.47,0);
        line6->Draw("same");

        auto legend6 = new TLegend(0.4,0.7,0.6,0.85);
        legend6->AddEntry(Histsigma7,"Low mu Stat Error");
        legend6->AddEntry(Hx4Mx1,"X4 - X1");
        legend6->Draw("same");	
	
	
	// Plot 7

	TH1D* Hx2Mx1SE   = (TH1D*) Hx2Mx1->Clone("Hx2Mx1SE");
        TH1D* Hx3Mx1SE   = (TH1D*) Hx3Mx1->Clone("Hx3Mx1SE");
        TH1D* Hx4Mx1SE   = (TH1D*) Hx4Mx1->Clone("Hx4Mx1SE");
		
	for(int i = 0 ; i<Hx7Mx1->GetNbinsX() ; i++ ){
        Hx2Mx1SE->SetBinError(i+1,0);
	Hx3Mx1SE->SetBinError(i+1,0);
        Hx4Mx1SE->SetBinError(i+1,0);
	}


	Histsigma7->SetFillColor(86);
        Histsigma7m->SetFillColor(86);
        Histsigma7->GetYaxis()->SetRangeUser(-0.006,0.006);
        Histsigma7->SetStats(0);
        Histsigma7->GetXaxis()->SetTitle("#eta");
        Histsigma7->GetYaxis()->SetTitle("Uncertainties");
        Histsigma7->GetYaxis()->SetTitleOffset(1.4);

        Histsigma7->SetTitle("");
        Histsigma7->SetLineWidth(0);
        Histsigma7m->SetLineWidth(0);

	Histsigma7->Draw();
        Histsigma7m->Draw("same");
	
	Hx2Mx1SE->SetLineWidth(2);
	Hx3Mx1SE->SetLineWidth(2);
        Hx4Mx1SE->SetLineWidth(2);
	HistTCStudy->SetLineWidth(2);

	Hx2Mx1SE->SetLineColor(2);
        Hx3Mx1SE->SetLineColor(4);
        Hx4Mx1SE->SetLineColor(6);
	HistTCStudy->SetLineColor(1);

        auto legend7 = new TLegend(0.4,0.7,0.6,0.85);
        legend7->AddEntry(Histsigma7,"Low mu Stat Error");
        legend7->AddEntry(Hx2Mx1SE,"X2 - X1");
        legend7->AddEntry(Hx3Mx1SE,"X3 - X1");
        legend7->AddEntry(Hx4Mx1SE,"X4 - X1");
        legend7->AddEntry(HistTCStudy,"Error on the difference of threshold");

        TLine *line7 = new TLine(-2.47,0,2.47,0);
        line7->Draw("same");

	Hx2Mx1SE->Draw("same");		
	Hx3Mx1SE->Draw("same");
	Hx4Mx1SE->Draw("same");
	HistTCStudy->Draw("same");
        legend7->Draw("same");

*/


}

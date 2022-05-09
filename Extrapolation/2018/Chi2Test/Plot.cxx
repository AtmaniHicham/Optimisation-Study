#include "iostream"
#include "TH1.h"
#include "TFile.h"
#include "TLine.h"
#include "TTree.h"
#include "TLegend.h"



using namespace std;


int Chi2TestPol1(int region){

	cout<<"    jbjbj "<<endl;
	
	TFile* Flowmu     = new TFile("/sps/atlas/h/hatmani/rel21_Calib_Pre/resultat_low-mu/Alpha_2018-24.root");
	TFile* Fin2Pol1   = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-2Intervals-pol1.root");
	TFile* Fin3Pol1   = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-3Intervals-pol1.root");
	TFile* Fin4Pol1   = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-4Intervals-pol1.root");
	TFile* Fin5Pol1   = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-5Intervals-pol1.root");

        TH1F*  Hlowmu      = (TH1F*)Flowmu->Get("measScale_alpha");
        TH1F*  Hin2Pol1    = (TH1F*)Fin2Pol1->Get("ExtraCorr");
        TH1F*  Hin3Pol1    = (TH1F*)Fin3Pol1->Get("ExtraCorr");
        TH1F*  Hin4Pol1    = (TH1F*)Fin4Pol1->Get("ExtraCorr");
        TH1F*  Hin5Pol1    = (TH1F*)Fin5Pol1->Get("ExtraCorr");
	
	double chi2in2   = 0;
	double chi2in3   = 0;
	double chi2in4   = 0;	
        double chi2in5   = 0;

	for( int j=0; j<24; j++ ) { 

	if( region == 1 && ( j+1 == 4 || j+1 == 5 || j+1 == 6 || j+1 == 19 || j+1 == 20 || j+1 == 21 ) ) continue;

	cout<<j+1<<endl;

	chi2in2 = chi2in2 + pow(Hlowmu->GetBinContent(j+1) - Hin2Pol1->GetBinContent(j+1) , 2 ) / ( pow(Hlowmu->GetBinError(j+1),2) + pow(Hin2Pol1->GetBinError(j+1),2)); // Poly 1 + 3 intervals of mu 
        chi2in3 = chi2in3 + pow(Hlowmu->GetBinContent(j+1) - Hin3Pol1->GetBinContent(j+1) , 2 ) / ( pow(Hlowmu->GetBinError(j+1),2) + pow(Hin3Pol1->GetBinError(j+1),2)); // Poly 1 + 3 intervals of mu 
        chi2in4 = chi2in4 + pow(Hlowmu->GetBinContent(j+1) - Hin4Pol1->GetBinContent(j+1) , 2 ) / ( pow(Hlowmu->GetBinError(j+1),2) + pow(Hin4Pol1->GetBinError(j+1),2)); // Poly 1 + 3 intervals of mu 
        chi2in5 = chi2in5 + pow(Hlowmu->GetBinContent(j+1) - Hin5Pol1->GetBinContent(j+1) , 2 ) / ( pow(Hlowmu->GetBinError(j+1),2) + pow(Hin5Pol1->GetBinError(j+1),2)); // Poly 1 + 3 intervals of mu 

	}

	cout<<"Chi-2 for the extrapolation results with Polynom of ordre 1 and 2 intervals of mu  = "<<chi2in2<<endl;
	cout<<"Chi-2 for the extrapolation results with Polynom of ordre 2 and 3 intervals of mu  = "<<chi2in3<<endl;
        cout<<"Chi-2 for the extrapolation results with Polynom of ordre 1 and 4 intervals of mu  = "<<chi2in4<<endl;
        cout<<"Chi-2 for the extrapolation results with Polynom of ordre 1 and 5 intervals of mu  = "<<chi2in5<<endl;

	return 0;
}

int Chi2TestPol2(int region){

        cout<<"    jbjbj "<<endl;

        TFile* Flowmu     = new TFile("/sps/atlas/h/hatmani/rel21_Calib_Pre/resultat_low-mu/Alpha_2018-24.root");
        TFile* Fin2Pol1   = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-2Intervals-pol2.root");
        TFile* Fin3Pol1   = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-3Intervals-pol2.root");
        TFile* Fin4Pol1   = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-4Intervals-pol2.root");
        TFile* Fin5Pol1   = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-5Intervals-pol2.root");

        TH1F*  Hlowmu      = (TH1F*)Flowmu->Get("measScale_alpha");
        TH1F*  Hin2Pol1    = (TH1F*)Fin2Pol1->Get("ExtraCorr");
        TH1F*  Hin3Pol1    = (TH1F*)Fin3Pol1->Get("ExtraCorr");
        TH1F*  Hin4Pol1    = (TH1F*)Fin4Pol1->Get("ExtraCorr");
        TH1F*  Hin5Pol1    = (TH1F*)Fin5Pol1->Get("ExtraCorr");

        double chi2in2   = 0;
        double chi2in3   = 0;
        double chi2in4   = 0;
        double chi2in5   = 0;

        for( int j=0; j<24; j++ ) {

        if( region == 1 && ( j+1 == 4 || j+1 == 5 || j+1 == 6 || j+1 == 19 || j+1 == 20 || j+1 == 21 ) ) continue;

        cout<<j+1<<endl;

        chi2in2 = chi2in2 + pow(Hlowmu->GetBinContent(j+1) - Hin2Pol1->GetBinContent(j+1) , 2 ) / ( pow(Hlowmu->GetBinError(j+1),2) + pow(Hin2Pol1->GetBinError(j+1),2)); // Poly 1 + 3 intervals of mu 
        chi2in3 = chi2in3 + pow(Hlowmu->GetBinContent(j+1) - Hin3Pol1->GetBinContent(j+1) , 2 ) / ( pow(Hlowmu->GetBinError(j+1),2) + pow(Hin3Pol1->GetBinError(j+1),2)); // Poly 1 + 3 intervals of mu 
        chi2in4 = chi2in4 + pow(Hlowmu->GetBinContent(j+1) - Hin4Pol1->GetBinContent(j+1) , 2 ) / ( pow(Hlowmu->GetBinError(j+1),2) + pow(Hin4Pol1->GetBinError(j+1),2)); // Poly 1 + 3 intervals of mu 
        chi2in5 = chi2in5 + pow(Hlowmu->GetBinContent(j+1) - Hin5Pol1->GetBinContent(j+1) , 2 ) / ( pow(Hlowmu->GetBinError(j+1),2) + pow(Hin5Pol1->GetBinError(j+1),2)); // Poly 1 + 3 intervals of mu 

        }

        cout<<"Chi-2 for the extrapolation results with Polynom of ordre 1 and 2 intervals of mu  = "<<chi2in2<<endl;
        cout<<"Chi-2 for the extrapolation results with Polynom of ordre 2 and 3 intervals of mu  = "<<chi2in3<<endl;
        cout<<"Chi-2 for the extrapolation results with Polynom of ordre 1 and 4 intervals of mu  = "<<chi2in4<<endl;
        cout<<"Chi-2 for the extrapolation results with Polynom of ordre 1 and 5 intervals of mu  = "<<chi2in5<<endl;

        return 0;
}


int PullPlotPol1(){


        TFile* Flowmu      = new TFile("/sps/atlas/h/hatmani/rel21_Calib_Pre/resultat_low-mu/Alpha_2018-24.root");                    TH1F*  Hlowmu      = (TH1F*)Flowmu->Get("measScale_alpha");
        TFile* Fin2Pol1    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-2Intervals-pol1.root");    TH1F*  Hin2Pol1    = (TH1F*)Fin2Pol1->Get("ExtraCorr");
        TFile* Fin3Pol1    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-3Intervals-pol1.root");    TH1F*  Hin3Pol1    = (TH1F*)Fin3Pol1->Get("ExtraCorr");
        TFile* Fin4Pol1    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-4Intervals-pol1.root");    TH1F*  Hin4Pol1    = (TH1F*)Fin4Pol1->Get("ExtraCorr");
        TFile* Fin5Pol1    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/2018/output-24-5Intervals-pol1.root");    TH1F*  Hin5Pol1    = (TH1F*)Fin5Pol1->Get("ExtraCorr");

        double bins[25]={-2.47,-2.4,-2.1,-1.8,-1.55,-1.37,-1.2,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.37,1.55,1.8,2.1,2.4,2.47};

        cout<<"jbhb hbhb bhb"<<endl;
        int Nbins     = 24 ;
        double pull   = 0  ;
        double chi2n1 = 0  ;
        double chi2n2 = 0  ;
        double chi2n3 = 0  ;
        double chi2n4 = 0  ;

        TH1F* Pull       = new TH1F("Pull","",Nbins,bins);

        TH1F* PullFill1  = new TH1F("PullFill1","",4,-4,4);
        TH1F* PullFill2  = new TH1F("PullFill2","",4,-4,4);
        TH1F* PullFill3  = new TH1F("PullFill3","",4,-4,4);
        TH1F* PullFill4  = new TH1F("PullFill4","",4,-4,4);
        TH1F* PullFill5  = new TH1F("PullFill5","",4,-4,4);


        for( int j=0; j<24; j++ ) {

                chi2n1= ( Hlowmu->GetBinContent(j+1) - Hin2Pol1->GetBinContent(j+1) )    / sqrt(  pow(Hlowmu->GetBinError(j+1),2) + pow(Hin2Pol1->GetBinError(j+1),2)  );
                chi2n2= ( Hlowmu->GetBinContent(j+1) - Hin3Pol1->GetBinContent(j+1) )    / sqrt(  pow(Hlowmu->GetBinError(j+1),2) + pow(Hin3Pol1->GetBinError(j+1),2)  );
                chi2n3= ( Hlowmu->GetBinContent(j+1) - Hin4Pol1->GetBinContent(j+1) )    / sqrt(  pow(Hlowmu->GetBinError(j+1),2) + pow(Hin4Pol1->GetBinError(j+1),2)  );
                chi2n4= ( Hlowmu->GetBinContent(j+1) - Hin5Pol1->GetBinContent(j+1) )    / sqrt(  pow(Hlowmu->GetBinError(j+1),2) + pow(Hin5Pol1->GetBinError(j+1),2)  );

                PullFill1->Fill(chi2n1);
                PullFill2->Fill(chi2n2);
                PullFill3->Fill(chi2n3);
                PullFill4->Fill(chi2n4);

        }

        PullFill1->Draw();
        PullFill2->Draw("same");
        PullFill3->Draw("same");
        PullFill4->Draw("same");

        TCanvas *c1 = new TCanvas("c1","multipads",900,700);
        c1->Divide(2,2);
        c1->cd(1); PullFill1->Draw();
        c1->cd(2); PullFill2->Draw();
        c1->cd(3); PullFill3->Draw();
        c1->cd(4); PullFill4->Draw();

        return 0;

}

int Plot(){

//Chi2TestPol1(1);
//Chi2TestPol2(1);
PullPlotPol1();
return 0;

}

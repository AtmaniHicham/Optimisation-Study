#include "TFile.h"
#include "TMatrixT.h"
#include "TH1.h"

using std::to_string;

using namespace std;


void ErrorofThreshold(){
	
          int Nbins = 24;
          double bins[25]={-2.47,-2.4,-2.1,-1.8,-1.55,-1.37,-1.2,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.37,1.55,1.8,2.1,2.4,2.47};

          TFile* TCStudy     = new TFile("/sps/atlas/h/hatmani/rel21_Calib_TCnoise/diff-stat/diff-energy/DiffTCstudy.root");
          TH1F*  HistTCStudy = (TH1F*)TCStudy->Get("DIff");

          TFile* file0   = new TFile("/sps/atlas/h/hatmani/rel21_Calibe/resultat_low-mu/Alpha_2017-24.root");
          TFile* file1   = new TFile("/sps/atlas/h/hatmani/Extrapolation/results17/5Intervals/Alpha-24-0.root");
          TFile* file2   = new TFile("/sps/atlas/h/hatmani/Extrapolation/results17/5Intervals/Alpha-24-1.root");
          TFile* file3   = new TFile("/sps/atlas/h/hatmani/Extrapolation/results17/5Intervals/Alpha-24-2.root");
          TFile* file4   = new TFile("/sps/atlas/h/hatmani/Extrapolation/results17/5Intervals/Alpha-24-3.root");
          TFile* file5   = new TFile("/sps/atlas/h/hatmani/Extrapolation/results17/5Intervals/Alpha-24-4.root");

          vector <TH1D*>  vectHist;

          vectHist.push_back((TH1D*)file0->Get("measScale_alpha"));
          vectHist.push_back((TH1D*)file1->Get("measScale_alpha"));
          vectHist.push_back((TH1D*)file2->Get("measScale_alpha"));
          vectHist.push_back((TH1D*)file3->Get("measScale_alpha"));
          vectHist.push_back((TH1D*)file4->Get("measScale_alpha"));
          vectHist.push_back((TH1D*)file5->Get("measScale_alpha"));

          for( int j = 1 ; j < vectHist.size() ; j++){
          for( int i = 0 ; i < Nbins           ; i++){
          vectHist[j]->SetBinContent(i+1,  vectHist[j]->GetBinContent(i+1) + HistTCStudy->GetBinContent(i+1)     );
          }}

	  for( int j = 1 ; j < vectHist.size() ; j++){
          for( int i = 0 ; i < Nbins           ; i++){
          vectHist[j]->SetBinContent(i+1,  vectHist[j]->GetBinContent(i+1) + HistTCStudy->GetBinError(i+1)     );
          }}


          TH1F* Extra      = new TH1F("Extra","",Nbins,bins);
          TH1F* ExtraCorr  = new TH1F("ExtraCorr","",Nbins,bins);

          TH1F* Chi2   = new TH1F("Chi2","Chi2",Nbins,bins);

          int Numberint = 0 ;
          int Numberfin = 6 ;
          double test_value ;

          double Mat[Numberfin][Nbins];
          double MatErr[Numberfin][Nbins];

          TH2D* MAT = new TH2D("MAT","",Nbins,-2.47,2.47,6,0,6);  // 3 -> 2

          for(int k=Numberint; k<Numberfin ; k++){
                for(int j=0; j<Nbins; j++){
                Mat[k][j]=vectHist[k]->GetBinContent(j+1);
                MatErr[k][j]=vectHist[k]->GetBinError(j+1);
                cout<<Mat[k][j]<<endl;
                MAT->SetBinContent(j+1,k+1,vectHist[k]->GetBinContent(j+1));
          }}

          Double_t y[6] = {2,21.81,29.59,36.28,44.4,55.56};
          Double_t y_err[6] = {0,0,0,0,0,0};

          vector <TGraph*>  vectGraph;

          Double_t x1[Numberfin] ; Double_t x_err1[Numberfin] ;

          for( int i=0 ; i < Nbins  ; i++){
                        for( int j=Numberint ; j < Numberfin ; j++){
                        x1[j]=Mat[j][i];
                        x_err1[j]=MatErr[j][i];
                        }
          TGraph *gr1 = new TGraph(Numberfin,y,x1);
          gr1 = new TGraphErrors(Numberfin,y,x1,y_err,x_err1);
          gr1->SetMarkerColor(4);
          gr1->SetMarkerStyle(21);
          vectGraph.push_back(gr1);
          }

          TF1 f1("f1","pol1",0,80); Double_t par[8];
          int ndf=6;

          for( int i=0 ; i < Nbins  ; i++){
          vectGraph[i]->Fit("f1");
          f1.GetParameters(&par[0]);
          cout<<par[0]<<"        "<<par[1]<<endl;
          Extra->SetBinContent(i+1,par[0]+1.918*par[1]);
          Extra->SetBinError(i+1,(f1.GetParError(0)));
          Chi2->SetBinContent(i+1,f1.GetChisquare()/ndf);
          Chi2->SetBinError(i+1,0);}


          for( int i=0 ; i < Nbins  ; i++){
          string name = "/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/";
          name       += to_string(i);
          name       += ".root";
          TFile* Fichier = new TFile(name.c_str(),"recreate");
          vectGraph[i]->Write();
          Fichier->Close();
          }


          TFile* Fichier = new TFile("output-24-5Intervals-IntervaAddi-pol1Shift.root","recreate");
          MAT->Write("colz"); Chi2->Write();
          for( int i=0 ; i < Nbins  ; i++){
          vectGraph[i]->Write();}
          Extra->Write();
          ExtraCorr->Write();
          Fichier->Close();

}


void ExtractHighmu5Intervals(){

          int Nbins = 24;
          double bins[25]={-2.47,-2.4,-2.1,-1.8,-1.55,-1.37,-1.2,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.37,1.55,1.8,2.1,2.4,2.47};

          TFile* TCStudy     = new TFile("/sps/atlas/h/hatmani/rel21_Calib_TCnoise/resultat/Diff.root");
          TH1F*  HistTCStudy = (TH1F*)TCStudy->Get("Diff");

	  TFile* file0   = new TFile("/sps/atlas/h/hatmani/rel21_Calibe/resultat_low-mu/Alpha_2017-24.root");
          TFile* file1   = new TFile("/sps/atlas/h/hatmani/Extrapolation/results17/5Intervals/Alpha-24-0.root");
          TFile* file2   = new TFile("/sps/atlas/h/hatmani/Extrapolation/results17/5Intervals/Alpha-24-1.root");
          TFile* file3   = new TFile("/sps/atlas/h/hatmani/Extrapolation/results17/5Intervals/Alpha-24-2.root");
          TFile* file4   = new TFile("/sps/atlas/h/hatmani/Extrapolation/results17/5Intervals/Alpha-24-3.root");
          TFile* file5   = new TFile("/sps/atlas/h/hatmani/Extrapolation/results17/5Intervals/Alpha-24-4.root");

          vector <TH1D*>  vectHist;

          vectHist.push_back((TH1D*)file0->Get("measScale_alpha"));
          vectHist.push_back((TH1D*)file1->Get("measScale_alpha"));
          vectHist.push_back((TH1D*)file2->Get("measScale_alpha"));
          vectHist.push_back((TH1D*)file3->Get("measScale_alpha"));
          vectHist.push_back((TH1D*)file4->Get("measScale_alpha"));
          vectHist.push_back((TH1D*)file5->Get("measScale_alpha"));

          for( int j = 1 ; j < vectHist.size() ; j++){
          for( int i = 0 ; i < Nbins           ; i++){
          vectHist[j]->SetBinContent(i+1,  vectHist[j]->GetBinContent(i+1) + HistTCStudy->GetBinContent(i+1)     );
          }}

          TH1F* Extra      = new TH1F("Extra","",Nbins,bins);
          TH1F* ExtraCorr  = new TH1F("ExtraCorr","",Nbins,bins);

          TH1F* Chi2   = new TH1F("Chi2","Chi2",Nbins,bins);

          int Numberint = 0 ;
          int Numberfin = 6 ;
          double test_value ;

          double Mat[Numberfin][Nbins];
          double MatErr[Numberfin][Nbins];

          TH2D* MAT = new TH2D("MAT","",Nbins,-2.47,2.47,6,0,6);  // 3 -> 2

          for(int k=Numberint; k<Numberfin ; k++){
                for(int j=0; j<Nbins; j++){
                Mat[k][j]=vectHist[k]->GetBinContent(j+1);
                MatErr[k][j]=vectHist[k]->GetBinError(j+1);
                cout<<Mat[k][j]<<endl;
                MAT->SetBinContent(j+1,k+1,vectHist[k]->GetBinContent(j+1));
          }}

          Double_t y[6] = {2,21.81,29.59,36.28,44.4,55.56};
          Double_t y_err[6] = {0,0,0,0,0,0};

          vector <TGraph*>  vectGraph;

          Double_t x1[Numberfin] ; Double_t x_err1[Numberfin] ;

          for( int i=0 ; i < Nbins  ; i++){
                        for( int j=Numberint ; j < Numberfin ; j++){
                        x1[j]=Mat[j][i];
                        x_err1[j]=MatErr[j][i];
                        }
          TGraph *gr1 = new TGraph(Numberfin,y,x1);
          gr1 = new TGraphErrors(Numberfin,y,x1,y_err,x_err1);
          gr1->SetMarkerColor(4);
          gr1->SetMarkerStyle(21);
          vectGraph.push_back(gr1);
          }

          TF1 f1("f1","pol2",0,80); Double_t par[8];
          int ndf=6;

          for( int i=0 ; i < Nbins  ; i++){
          vectGraph[i]->Fit("f1");
          f1.GetParameters(&par[0]);
          cout<<par[0]<<"        "<<par[1]<<endl;
          Extra->SetBinContent(i+1,par[0]+1.918*par[1]);
          Extra->SetBinError(i+1,(f1.GetParError(0)));
          Chi2->SetBinContent(i+1,f1.GetChisquare()/ndf);
          Chi2->SetBinError(i+1,0);}


          for( int i=0 ; i < Nbins  ; i++){  
          string name = "/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/";
          name       += to_string(i);   
          name       += ".root";
          TFile* Fichier = new TFile(name.c_str(),"recreate");
          vectGraph[i]->Write();
          Fichier->Close();
          }


          TFile* Fichier = new TFile("output-24-5Intervals-IntervaAddi-pol2.root","recreate");
          MAT->Write("colz"); Chi2->Write();
          for( int i=0 ; i < Nbins  ; i++){
          vectGraph[i]->Write();}
          Extra->Write();
          ExtraCorr->Write();
          Fichier->Close();

          test_value =  Extra->KolmogorovTest(ExtraCorr);
          cout<<"          "<<test_value<<endl;
          test_value =  Extra->Chi2Test(ExtraCorr,"CHI2/NDF");
          cout<<"          "<<test_value<<endl;
}


void ExtractHighmu3Intervals(){

	  int Nbins = 24;
  	  double bins[25]={-2.47,-2.4,-2.1,-1.8,-1.55,-1.37,-1.2,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.37,1.55,1.8,2.1,2.4,2.47};

	  TFile* TCStudy     = new TFile("/sps/atlas/h/hatmani/rel21_Calib_TCnoise/resultat/Diff.root");
	  TH1F*  HistTCStudy = (TH1F*)TCStudy->Get("Diff"); 

          TFile* file0   = new TFile("/sps/atlas/h/hatmani/rel21_Calibe/resultat_low-mu/Alpha_2017-24.root");
	  TFile* file1   = new TFile("/sps/atlas/h/hatmani/Extrapolation/results17/3Intervals/Alpha-24-0.root");
          TFile* file2   = new TFile("/sps/atlas/h/hatmani/Extrapolation/results17/3Intervals/Alpha-24-1.root");
          TFile* file3   = new TFile("/sps/atlas/h/hatmani/Extrapolation/results17/3Intervals/Alpha-24-2.root");
	
	  vector <TH1D*>  vectHist;

          vectHist.push_back((TH1D*)file0->Get("measScale_alpha"));
	  vectHist.push_back((TH1D*)file1->Get("measScale_alpha"));
	  vectHist.push_back((TH1D*)file2->Get("measScale_alpha"));
	  vectHist.push_back((TH1D*)file3->Get("measScale_alpha"));

          for( int j = 1 ; j < vectHist.size() ; j++){
          for( int i = 0 ; i < Nbins           ; i++){
          vectHist[j]->SetBinContent(i+1,  vectHist[j]->GetBinContent(i+1) + HistTCStudy->GetBinContent(i+1)     );
          }}

	  TH1F* Extra      = new TH1F("Extra","",Nbins,bins);
	  TH1F* ExtraCorr  = new TH1F("ExtraCorr","",Nbins,bins);

	  TH1F* Chi2   = new TH1F("Chi2","Chi2",Nbins,bins);

	  int Numberint = 0 ;
	  int Numberfin = 4 ; // 3->2 
	  double test_value ;

	  double Mat[Numberfin][Nbins];
	  double MatErr[Numberfin][Nbins];

	  TH2D* MAT = new TH2D("MAT","",Nbins,-2.47,2.47,4,0,4);  // 3 -> 2

	  for(int k=Numberint; k<Numberfin ; k++){
	  	for(int j=0; j<Nbins; j++){ 
		Mat[k][j]=vectHist[k]->GetBinContent(j+1); 
		MatErr[k][j]=vectHist[k]->GetBinError(j+1); 
		cout<<Mat[k][j]<<endl;
		MAT->SetBinContent(j+1,k+1,vectHist[k]->GetBinContent(j+1));  
	  }}

	  Double_t y[4] = {2,22.47,33.96,51.32};
	  Double_t y_err[4] = {0,0,0,0};

	  vector <TGraph*>  vectGraph;

	  Double_t x1[Numberfin] ; Double_t x_err1[Numberfin] ;

	  for( int i=0 ; i < Nbins  ; i++){
                        for( int j=Numberint ; j < Numberfin ; j++){
                        x1[j]=Mat[j][i]; 
                        x_err1[j]=MatErr[j][i];  
			}
	  TGraph *gr1 = new TGraph(Numberfin,y,x1);	
	  gr1 = new TGraphErrors(Numberfin,y,x1,y_err,x_err1);	        
	  gr1->SetMarkerColor(4); 
	  gr1->SetMarkerStyle(21);
	  vectGraph.push_back(gr1);
	  }

	  TF1 f1("f1","pol1",0,80); Double_t par[8];
	  int ndf=3;  
  
	  for( int i=0 ; i < Nbins  ; i++){
	  vectGraph[i]->Fit("f1");  
	  f1.GetParameters(&par[0]);
	  cout<<par[0]<<"        "<<par[1]<<endl;
	  Extra->SetBinContent(i+1,par[0]+1.918*par[1]);
	  Extra->SetBinError(i+1,(f1.GetParError(0)));
	  Chi2->SetBinContent(i+1,f1.GetChisquare()/ndf);
	  Chi2->SetBinError(i+1,0);}
  
  
/*          for( int i=0 ; i < Nbins  ; i++){  
	  string name = "/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/";
	  name       += to_string(i);	
          name       += ".root";
	  TFile* Fichier = new TFile(name.c_str(),"recreate");
  	  vectGraph[i]->Write();
	  Fichier->Close();
	  }
*/

	  TFile* Fichier = new TFile("output-24-3Intervals-IntervaAddi.root","recreate");  
	  MAT->Write("colz"); Chi2->Write();
	  for( int i=0 ; i < Nbins  ; i++){
	  vectGraph[i]->Write();}
	  Extra->Write();
	  ExtraCorr->Write();
	  Fichier->Close();

	  test_value =  Extra->KolmogorovTest(ExtraCorr);
	  cout<<"          "<<test_value<<endl;
	  test_value =  Extra->Chi2Test(ExtraCorr,"CHI2/NDF"); 	
	  cout<<"          "<<test_value<<endl;
}




void extrapolationInter(){
//ErrorofThreshold();
//ExtractHighmu3Intervals();
ExtractHighmu5Intervals();

}


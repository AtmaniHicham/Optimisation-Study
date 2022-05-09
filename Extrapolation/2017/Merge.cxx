#include "TFile.h"
#include "TMatrixT.h"
#include "TH1.h"

using std::to_string;

using namespace std;

void Merge(){


	  int Nbins = 2;
          double bins[3]={-2.5,-2.47,2.47};
          int NbinsN = 1;
          double binsN[2]={-2.47,2.47};

          TFile* file1   = new TFile("/sps/atlas/h/hatmani/Extrapolation/results17/5Intervals2Binseta/Alpha-24-0.root");
          TFile* file2   = new TFile("/sps/atlas/h/hatmani/Extrapolation/results17/5Intervals2Binseta/Alpha-24-1.root");
          TFile* file3   = new TFile("/sps/atlas/h/hatmani/Extrapolation/results17/5Intervals2Binseta/Alpha-24-2.root");
          TFile* file4   = new TFile("/sps/atlas/h/hatmani/Extrapolation/results17/5Intervals2Binseta/Alpha-24-3.root");
          TFile* file5   = new TFile("/sps/atlas/h/hatmani/Extrapolation/results17/5Intervals2Binseta/Alpha-24-4.root");

          vector <TH1D*>  vectHist;

          TH1D* Hist1 = (TH1D*)file1->Get("measScale_alpha");		Hist1->SetName("Hist1");	Hist1->SetTitle("Hist1");
          TH1D* Hist2 = (TH1D*)file2->Get("measScale_alpha");		Hist2->SetName("Hist2");	Hist2->SetTitle("Hist2");
          TH1D* Hist3 = (TH1D*)file3->Get("measScale_alpha");           Hist3->SetName("Hist3");	Hist3->SetTitle("Hist3");
          TH1D* Hist4 = (TH1D*)file4->Get("measScale_alpha");           Hist4->SetName("Hist4");	Hist4->SetTitle("Hist4");
          TH1D* Hist5 = (TH1D*)file5->Get("measScale_alpha");           Hist5->SetName("Hist5");	Hist5->SetTitle("Hist5");


          TFile* Fichier = new TFile("OutputMerge.root","recreate");
	  Hist1->Write();
          Hist2->Write();
          Hist3->Write();
          Hist4->Write();
          Hist5->Write();

	  Fichier->Close();}

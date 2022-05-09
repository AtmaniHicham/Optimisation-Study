#include "TFile.h"
#include "TMatrixT.h"
#include "TH1.h"

using std::to_string;

using namespace std;

void Plot(){


	TFile* fileHighmu           = new TFile("Total.root");

	TH1*	TemperatureEffect    = (TH1*)fileHighmu->Get("temperature_effect");	
	TH1*    HExtrapolation       = (TH1*)fileHighmu->Get("extrapolation_systematic");
	TH1*    threshold_correc     = (TH1*)fileHighmu->Get("uncertainty_in_threshold_correction");
	TH1*	Highalpha_systematic = (TH1*)fileHighmu->Get("high-mu_alpha_systematics");

	TH1*    Total		     = (TH1*)fileHighmu->Get("temperature_effect");

	TemperatureEffect->Draw();
	HExtrapolation->Draw("same");
	threshold_correc->Draw("same");
	Highalpha_systematic->Draw("same");


	for(int i = 0 ; i<Total->GetNbinsX() ; i++ ){
	Total->SetBinContent(i+1,sqrt(
        pow( TemperatureEffect->GetBinContent(i+1)      ,2)+
    	pow( HExtrapolation->GetBinContent(i+1)      ,2)+
        pow( threshold_correc->GetBinContent(i+1)             ,2)+
        pow( Highalpha_systematic->GetBinContent(i+1)   ,2)  ));
        Total->SetBinError(i+1,0);
	}


	Total->Draw("same");

}

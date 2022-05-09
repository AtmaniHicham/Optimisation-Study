#include <iostream>
#include "TFile.h"
#include "TCanvas.h"
#include "TColor.h"
#include "header/SideFunctions.h"
#include <boost/program_options.hpp>
#include <fstream>
#include "header/AtlasStyle.h"
#include "header/AtlasUtils.h"
#include "header/AtlasLabels.h"

using std::cout;
using std::endl;
using std::vector;





int sfplot(){

    TFile* fileX7  = new TFile("/sps/atlas/h/hatmani/rel21_Calibe/resultat_low-mu/Alpha_2017-24.root");
    TH1F*  HistX1   = (TH1F*)fileX7->Get("Extra");  

    TCanvas *canvas = new TCanvas();
    TPad padUp( "padUp", "padUp", 0, 0.32, 1, 1 );
    padUp.SetBottomMargin( 0.03 );
    //padUp.Draw();
    padUp.cd();

    TH1F* dumUp = padUp.DrawFrame( -2.7, 0,2.7,0 );
    dumUp->GetYaxis()->SetTitleSize( 0.07);
    dumUp->GetYaxis()->SetTitleOffset( 0.7);
    dumUp->GetYaxis()->SetLabelSize( 0.05);
    dumUp->GetXaxis()->SetLabelSize( 0 );
    dumUp->GetYaxis()->SetTitle( "" );

    TPad padDown( "padDown", "padDown", 0, 0, 1, 0.32 );
    padDown.SetTopMargin( 0.04 );
    padDown.SetBottomMargin( 0.35 );
    canvas->cd();
    //padDown.Draw();
    padDown.cd();

    TH1F* dumDown = padDown.DrawFrame( -2.7, 0,2.7,0 );
    dumDown->GetYaxis()->SetLabelSize( 0.09 );
    dumDown->GetYaxis()->SetTitleSize( 0.15 );
    dumDown->GetYaxis()->SetTitleOffset( 0.35 );
 
    dumDown->GetXaxis()->SetTitle( "#eta" );
    dumDown->GetXaxis()->SetTitleSize( 0.15 );
    dumDown->GetXaxis()->SetLabelSize( 0.15 );
    dumDown->GetXaxis()->SetTitleOffset( 1 );
    dumDown->GetYaxis()->SetTitle( "eee" );
    dumDown->GetYaxis()->CenterTitle();

    padUp.cd();
    HistX1->Draw("same");

    //padDown.cd();
    //HistX1->Draw("same");

return 0;
}

#include "iostream"

using namespace std;

int draw(){

 TFile*   file0    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/0.root");
 TGraph*  graph0   = (TGraph*)file0->Get("Graph");
 graph0->SetTitle("Bin 1");
 graph0->GetXaxis()->SetTitle("mu");
 graph0->GetYaxis()->SetTitle("#alpha");
 
 TFile*   file1    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/1.root");
 TGraph*  graph1   = (TGraph*)file1->Get("Graph");
 graph0->SetTitle("Bin 2");
 graph1->GetXaxis()->SetTitle("mu");
 graph1->GetYaxis()->SetTitle("#alpha");

 TFile*   file2    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/2.root");
 TGraph*  graph2   = (TGraph*)file2->Get("Graph");
 graph0->SetTitle("Bin 3");
 graph2->GetXaxis()->SetTitle("mu");
 graph2->GetYaxis()->SetTitle("#alpha");

 TFile*   file3    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/3.root");
 TGraph*  graph3   = (TGraph*)file3->Get("Graph");
 graph0->SetTitle("Bin 4");
 graph3->GetXaxis()->SetTitle("mu");
 graph3->GetYaxis()->SetTitle("#alpha");

 TFile*   file4    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/4.root");
 TGraph*  graph4   = (TGraph*)file4->Get("Graph");
 graph0->SetTitle("Bin 5");
 graph4->GetXaxis()->SetTitle("mu");
 graph4->GetYaxis()->SetTitle("#alpha");

 TFile*   file5    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/5.root");
 TGraph*  graph5   = (TGraph*)file5->Get("Graph");
 graph0->SetTitle("Bin 6");
 graph5->GetXaxis()->SetTitle("mu");
 graph5->GetYaxis()->SetTitle("#alpha");

 TFile*   file6    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/6.root");
 TGraph*  graph6   = (TGraph*)file6->Get("Graph");
 graph0->SetTitle("Bin 7"); 
 graph6->GetXaxis()->SetTitle("mu");
 graph6->GetYaxis()->SetTitle("#alpha");

 TFile*   file7    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/7.root");
 TGraph*  graph7   = (TGraph*)file7->Get("Graph");
 graph0->SetTitle("Bin 8"); 
 graph7->GetXaxis()->SetTitle("mu");
 graph7->GetYaxis()->SetTitle("#alpha");

 TFile*   file8    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/8.root");
 TGraph*  graph8   = (TGraph*)file8->Get("Graph");
 graph0->SetTitle("Bin 9"); 
 graph8->GetXaxis()->SetTitle("mu");
 graph8->GetYaxis()->SetTitle("#alpha");

 TFile*   file9    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/9.root");
 TGraph*  graph9   = (TGraph*)file9->Get("Graph");
 graph0->SetTitle("Bin 10"); 
 graph9->GetXaxis()->SetTitle("mu");
 graph9->GetYaxis()->SetTitle("#alpha");

 TFile*   file10    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/10.root");
 TGraph*  graph10   = (TGraph*)file10->Get("Graph");
 graph0->SetTitle("Bin 11"); 
 graph10->GetXaxis()->SetTitle("mu");
 graph10->GetYaxis()->SetTitle("#alpha");

 TFile*   file11    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/11.root");
 TGraph*  graph11   = (TGraph*)file11->Get("Graph");
 graph0->SetTitle("Bin 12"); 
 graph11->GetXaxis()->SetTitle("mu");
 graph11->GetYaxis()->SetTitle("#alpha");

 TFile*   file12    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/12.root");
 TGraph*  graph12   = (TGraph*)file12->Get("Graph");
 graph0->SetTitle("Bin 13"); 
 graph12->GetXaxis()->SetTitle("mu");
 graph12->GetYaxis()->SetTitle("#alpha");

 TFile*   file13    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/13.root");
 TGraph*  graph13   = (TGraph*)file13->Get("Graph");
 graph0->SetTitle("Bin 14"); 
 graph13->GetXaxis()->SetTitle("mu");
 graph13->GetYaxis()->SetTitle("#alpha");

 TFile*   file14    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/14.root");
 TGraph*  graph14   = (TGraph*)file14->Get("Graph");
 graph0->SetTitle("Bin 15"); 
 graph14->GetXaxis()->SetTitle("mu");
 graph14->GetYaxis()->SetTitle("#alpha");

 TFile*   file15    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/15.root");
 TGraph*  graph15   = (TGraph*)file15->Get("Graph");
 graph0->SetTitle("Bin 16"); 
 graph15->GetXaxis()->SetTitle("mu");
 graph15->GetYaxis()->SetTitle("#alpha");

 TFile*   file16    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/16.root");
 TGraph*  graph16   = (TGraph*)file16->Get("Graph");
 graph0->SetTitle("Bin 17"); 
 graph16->GetXaxis()->SetTitle("mu");
 graph16->GetYaxis()->SetTitle("#alpha");

 TFile*   file17    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/17.root");
 TGraph*  graph17   = (TGraph*)file17->Get("Graph");
 graph0->SetTitle("Bin 18"); 
 graph17->GetXaxis()->SetTitle("mu");
 graph17->GetYaxis()->SetTitle("#alpha");

 TFile*   file18    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/18.root");
 TGraph*  graph18   = (TGraph*)file18->Get("Graph");
 graph0->SetTitle("Bin 19"); 
 graph18->GetXaxis()->SetTitle("mu");
 graph18->GetYaxis()->SetTitle("#alpha");

 TFile*   file19    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/19.root");
 TGraph*  graph19   = (TGraph*)file19->Get("Graph");
 graph0->SetTitle("Bin 20"); 
 graph19->GetXaxis()->SetTitle("mu");
 graph19->GetYaxis()->SetTitle("#alpha");

 TFile*   file20    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/20.root");
 TGraph*  graph20   = (TGraph*)file20->Get("Graph");
 graph0->SetTitle("Bin 21"); 
 graph20->GetXaxis()->SetTitle("mu");
 graph20->GetYaxis()->SetTitle("#alpha");

 TFile*   file21    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/21.root");
 TGraph*  graph21   = (TGraph*)file21->Get("Graph");
 graph0->SetTitle("Bin 22"); 
 graph21->GetXaxis()->SetTitle("mu");
 graph21->GetYaxis()->SetTitle("#alpha");

 TFile*   file22    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/22.root");
 TGraph*  graph22   = (TGraph*)file22->Get("Graph");
 graph0->SetTitle("Bin 23"); 
 graph22->GetXaxis()->SetTitle("mu");
 graph22->GetYaxis()->SetTitle("#alpha");

 TFile*   file23    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2018/23.root");
 TGraph*  graph23   = (TGraph*)file23->Get("Graph");
 graph0->SetTitle("Bin 24"); 
 graph23->GetXaxis()->SetTitle("mu");
 graph23->GetYaxis()->SetTitle("#alpha");


 TCanvas *c1 = new TCanvas("c1","multipads",900,700);
 c1->Divide(6,4);
 c1->cd(1);
 graph0->Draw();
 c1->cd(2);
 graph1->Draw();
 c1->cd(3);
 graph2->Draw();
 c1->cd(4);
 graph3->Draw();
 c1->cd(5);
 graph4->Draw();
 c1->cd(6);
 graph5->Draw();
 c1->cd(7);
 graph6->Draw();
 c1->cd(8);
 graph7->Draw();
 c1->cd(9);
 graph8->Draw();
 c1->cd(10);
 graph9->Draw();
 c1->cd(11);
 graph10->Draw();
 c1->cd(12);
 graph11->Draw();
 c1->cd(13);
 graph12->Draw();
 c1->cd(14);
 graph13->Draw();
 c1->cd(15);
 graph14->Draw();
 c1->cd(16);
 graph15->Draw();
 c1->cd(17);
 graph16->Draw();
 c1->cd(18);
 graph17->Draw();
 c1->cd(19);
 graph18->Draw();
 c1->cd(20);
 graph19->Draw();
 c1->cd(21);
 graph20->Draw();
 c1->cd(22);
 graph21->Draw();
 c1->cd(23);
 graph22->Draw();
 c1->cd(24);
 graph23->Draw();

 c1->SaveAs("1.pdf");





return 0;
}

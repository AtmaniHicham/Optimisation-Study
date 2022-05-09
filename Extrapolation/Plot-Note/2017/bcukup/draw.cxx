#include "iostream"

using namespace std;

int draw(){

  double min  = -0.016;
  double max  = 0.006;
  double Size = 0.04; 
 

 TFile*   file0    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/0.root");
 TGraph*  graph0   = (TGraph*)file0->Get("Graph");
 graph0->SetTitle("Bin 1");
 graph0->GetXaxis()->SetTitle("#mu");
 graph0->GetYaxis()->SetTitle("#alpha");
 graph0->GetYaxis()->SetRangeUser(min, max); 
 graph0->GetYaxis()->SetLabelSize(Size);
 graph0->GetXaxis()->SetLabelSize(Size);


 TFile*   file1    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/1.root");
 TGraph*  graph1   = (TGraph*)file1->Get("Graph");
 graph0->SetTitle("Bin 2");
 graph1->GetXaxis()->SetTitle("#mu");
 graph1->GetYaxis()->SetTitle("#alpha");
 graph1->GetYaxis()->SetRangeUser(min, max);
 graph1->GetYaxis()->SetLabelSize(Size);
 graph1->GetXaxis()->SetLabelSize(Size);


 TFile*   file2    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/2.root");
 TGraph*  graph2   = (TGraph*)file2->Get("Graph");
 graph0->SetTitle("Bin 3");
 graph2->GetXaxis()->SetTitle("#mu");
 graph2->GetYaxis()->SetTitle("#alpha");
 graph2->GetYaxis()->SetRangeUser(min, max);
 graph2->GetYaxis()->SetLabelSize(Size);
 graph2->GetXaxis()->SetLabelSize(Size);


 TFile*   file3    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/3.root");
 TGraph*  graph3   = (TGraph*)file3->Get("Graph");
 graph0->SetTitle("Bin 4");
 graph3->GetXaxis()->SetTitle("#mu");
 graph3->GetYaxis()->SetTitle("#alpha");
 graph3->GetYaxis()->SetRangeUser(min, max);
 graph3->GetYaxis()->SetLabelSize(Size);
 graph3->GetXaxis()->SetLabelSize(Size);

 TFile*   file4    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/4.root");
 TGraph*  graph4   = (TGraph*)file4->Get("Graph");
 graph0->SetTitle("Bin 5");
 graph4->GetXaxis()->SetTitle("#mu");
 graph4->GetYaxis()->SetTitle("#alpha");
 graph4->GetYaxis()->SetRangeUser(min, max);
 graph4->GetYaxis()->SetLabelSize(Size);
 graph4->GetXaxis()->SetLabelSize(Size);

 TFile*   file5    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/5.root");
 TGraph*  graph5   = (TGraph*)file5->Get("Graph");
 graph0->SetTitle("Bin 6");
 graph5->GetXaxis()->SetTitle("#mu");
 graph5->GetYaxis()->SetTitle("#alpha");
 graph5->GetYaxis()->SetRangeUser(min, max);
 graph5->GetYaxis()->SetLabelSize(Size);
 graph5->GetXaxis()->SetLabelSize(Size);

 TFile*   file6    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/6.root");
 TGraph*  graph6   = (TGraph*)file6->Get("Graph");
 graph0->SetTitle("Bin 7"); 
 graph6->GetXaxis()->SetTitle("#mu");
 graph6->GetYaxis()->SetTitle("#alpha");
 graph6->GetYaxis()->SetRangeUser(min, max);
 graph6->GetYaxis()->SetLabelSize(Size);
 graph5->GetXaxis()->SetLabelSize(Size);

 TFile*   file7    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/7.root");
 TGraph*  graph7   = (TGraph*)file7->Get("Graph");
 graph0->SetTitle("Bin 8"); 
 graph7->GetXaxis()->SetTitle("#mu");
 graph7->GetYaxis()->SetTitle("#alpha");
 graph7->GetYaxis()->SetRangeUser(min, max);
 graph7->GetYaxis()->SetLabelSize(Size);
 graph7->GetXaxis()->SetLabelSize(Size);

 TFile*   file8    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/8.root");
 TGraph*  graph8   = (TGraph*)file8->Get("Graph");
 graph0->SetTitle("Bin 9"); 
 graph8->GetXaxis()->SetTitle("#mu");
 graph8->GetYaxis()->SetTitle("#alpha");
 graph8->GetYaxis()->SetRangeUser(min, max);
 graph8->GetYaxis()->SetLabelSize(Size);
 graph8->GetXaxis()->SetLabelSize(Size);

 TFile*   file9    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/9.root");
 TGraph*  graph9   = (TGraph*)file9->Get("Graph");
 graph0->SetTitle("Bin 10"); 
 graph9->GetXaxis()->SetTitle("#mu");
 graph9->GetYaxis()->SetTitle("#alpha");
 graph9->GetYaxis()->SetRangeUser(min, max);
 graph9->GetYaxis()->SetLabelSize(Size);
 graph9->GetXaxis()->SetLabelSize(Size);

 TFile*   file10    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/10.root");
 TGraph*  graph10   = (TGraph*)file10->Get("Graph");
 graph0->SetTitle("Bin 11"); 
 graph10->GetXaxis()->SetTitle("#mu");
 graph10->GetYaxis()->SetTitle("#alpha");
 graph10->GetYaxis()->SetRangeUser(min, max);
 graph10->GetYaxis()->SetLabelSize(Size);
 graph10->GetXaxis()->SetLabelSize(Size);

 TFile*   file11    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/11.root");
 TGraph*  graph11   = (TGraph*)file11->Get("Graph");
 graph0->SetTitle("Bin 12"); 
 graph11->GetXaxis()->SetTitle("#mu");
 graph11->GetYaxis()->SetTitle("#alpha");
 graph11->GetYaxis()->SetRangeUser(min, max);
 graph11->GetYaxis()->SetLabelSize(Size);
 graph11->GetXaxis()->SetLabelSize(Size);

 TFile*   file12    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/12.root");
 TGraph*  graph12   = (TGraph*)file12->Get("Graph");
 graph0->SetTitle("Bin 13"); 
 graph12->GetXaxis()->SetTitle("#mu");
 graph12->GetYaxis()->SetTitle("#alpha");
 graph12->GetYaxis()->SetRangeUser(min, max);
 graph12->GetYaxis()->SetLabelSize(Size);
 graph12->GetXaxis()->SetLabelSize(Size);

 TFile*   file13    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/13.root");
 TGraph*  graph13   = (TGraph*)file13->Get("Graph");
 graph0->SetTitle("Bin 14"); 
 graph13->GetXaxis()->SetTitle("#mu");
 graph13->GetYaxis()->SetTitle("#alpha");
 graph13->GetYaxis()->SetRangeUser(min, max);
 graph13->GetYaxis()->SetLabelSize(Size);
 graph13->GetXaxis()->SetLabelSize(Size);

 TFile*   file14    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/14.root");
 TGraph*  graph14   = (TGraph*)file14->Get("Graph");
 graph0->SetTitle("Bin 15"); 
 graph14->GetXaxis()->SetTitle("#mu");
 graph14->GetYaxis()->SetTitle("#alpha");
 graph14->GetYaxis()->SetRangeUser(min, max);
 graph14->GetYaxis()->SetLabelSize(Size);
 graph14->GetXaxis()->SetLabelSize(Size);

 TFile*   file15    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/15.root");
 TGraph*  graph15   = (TGraph*)file15->Get("Graph");
 graph0->SetTitle("Bin 16"); 
 graph15->GetXaxis()->SetTitle("#mu");
 graph15->GetYaxis()->SetTitle("#alpha");
 graph15->GetYaxis()->SetRangeUser(min, max);
 graph15->GetYaxis()->SetLabelSize(Size);
 graph15->GetXaxis()->SetLabelSize(Size);

 TFile*   file16    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/16.root");
 TGraph*  graph16   = (TGraph*)file16->Get("Graph");
 graph0->SetTitle("Bin 17"); 
 graph16->GetXaxis()->SetTitle("#mu");
 graph16->GetYaxis()->SetTitle("#alpha");
 graph16->GetYaxis()->SetRangeUser(min, max);
 graph16->GetYaxis()->SetLabelSize(Size);
 graph16->GetXaxis()->SetLabelSize(Size);

 TFile*   file17    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/17.root");
 TGraph*  graph17   = (TGraph*)file17->Get("Graph");
 graph0->SetTitle("Bin 18"); 
 graph17->GetXaxis()->SetTitle("#mu");
 graph17->GetYaxis()->SetTitle("#alpha");
 graph17->GetYaxis()->SetRangeUser(min, max);
 graph17->GetYaxis()->SetLabelSize(Size);
 graph17->GetXaxis()->SetLabelSize(Size);

 TFile*   file18    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/18.root");
 TGraph*  graph18   = (TGraph*)file18->Get("Graph");
 graph0->SetTitle("Bin 19"); 
 graph18->GetXaxis()->SetTitle("#mu");
 graph18->GetYaxis()->SetTitle("#alpha");
 graph18->GetYaxis()->SetRangeUser(min, max);
 graph18->GetYaxis()->SetLabelSize(Size);
 graph18->GetXaxis()->SetLabelSize(Size);

 TFile*   file19    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/19.root");
 TGraph*  graph19   = (TGraph*)file19->Get("Graph");
 graph0->SetTitle("Bin 20"); 
 graph19->GetXaxis()->SetTitle("#mu");
 graph19->GetYaxis()->SetTitle("#alpha");
 graph19->GetYaxis()->SetRangeUser(min, max);
 graph19->GetYaxis()->SetLabelSize(Size);
 graph19->GetXaxis()->SetLabelSize(Size);

 TFile*   file20    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/20.root");
 TGraph*  graph20   = (TGraph*)file20->Get("Graph");
 graph0->SetTitle("Bin 21"); 
 graph20->GetXaxis()->SetTitle("#mu");
 graph20->GetYaxis()->SetTitle("#alpha");
 graph20->GetYaxis()->SetRangeUser(min, max);
 graph20->GetYaxis()->SetLabelSize(Size);
 graph20->GetXaxis()->SetLabelSize(Size);

 TFile*   file21    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/21.root");
 TGraph*  graph21   = (TGraph*)file21->Get("Graph");
 graph0->SetTitle("Bin 22"); 
 graph21->GetXaxis()->SetTitle("#mu");
 graph21->GetYaxis()->SetTitle("#alpha");
 graph21->GetYaxis()->SetRangeUser(min, max);
 graph21->GetYaxis()->SetLabelSize(Size);
 graph21->GetXaxis()->SetLabelSize(Size);

 TFile*   file22    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/22.root");
 TGraph*  graph22   = (TGraph*)file22->Get("Graph");
 graph0->SetTitle("Bin 23"); 
 graph22->GetXaxis()->SetTitle("#mu");
 graph22->GetYaxis()->SetTitle("#alpha");
 graph22->GetYaxis()->SetRangeUser(min, max);
 graph22->GetYaxis()->SetLabelSize(Size);
 graph22->GetXaxis()->SetLabelSize(Size);

 TFile*   file23    = new TFile("/sps/atlas/h/hatmani/Extrapolation/Extrapolation/Plot-Note/2017/23.root");
 TGraph*  graph23   = (TGraph*)file23->Get("Graph");
 graph0->SetTitle("Bin 24"); 
 graph23->GetXaxis()->SetTitle("#mu");
 graph23->GetYaxis()->SetTitle("#alpha");
 graph23->GetYaxis()->SetRangeUser(min, max);
 graph23->GetYaxis()->SetLabelSize(Size);
 graph23->GetXaxis()->SetLabelSize(Size);

 cout<<"   min "<<graph0->GetHistogram()->GetMinimum()<<"                Max  = "<<graph0->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph1->GetHistogram()->GetMinimum()<<"                Max  = "<<graph1->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph2->GetHistogram()->GetMinimum()<<"                Max  = "<<graph2->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph3->GetHistogram()->GetMinimum()<<"                Max  = "<<graph3->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph4->GetHistogram()->GetMinimum()<<"                Max  = "<<graph4->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph5->GetHistogram()->GetMinimum()<<"                Max  = "<<graph5->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph6->GetHistogram()->GetMinimum()<<"                Max  = "<<graph6->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph7->GetHistogram()->GetMinimum()<<"                Max  = "<<graph7->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph8->GetHistogram()->GetMinimum()<<"                Max  = "<<graph8->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph9->GetHistogram()->GetMinimum()<<"                Max  = "<<graph9->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph10->GetHistogram()->GetMinimum()<<"                Max  = "<<graph10->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph11->GetHistogram()->GetMinimum()<<"                Max  = "<<graph11->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph12->GetHistogram()->GetMinimum()<<"                Max  = "<<graph12->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph13->GetHistogram()->GetMinimum()<<"                Max  = "<<graph13->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph14->GetHistogram()->GetMinimum()<<"                Max  = "<<graph14->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph15->GetHistogram()->GetMinimum()<<"                Max  = "<<graph15->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph16->GetHistogram()->GetMinimum()<<"                Max  = "<<graph16->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph17->GetHistogram()->GetMinimum()<<"                Max  = "<<graph17->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph18->GetHistogram()->GetMinimum()<<"                Max  = "<<graph18->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph19->GetHistogram()->GetMinimum()<<"                Max  = "<<graph19->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph20->GetHistogram()->GetMinimum()<<"                Max  = "<<graph20->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph21->GetHistogram()->GetMinimum()<<"                Max  = "<<graph21->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph22->GetHistogram()->GetMinimum()<<"                Max  = "<<graph22->GetHistogram()->GetMaximum() <<endl;
 cout<<"   min "<<graph23->GetHistogram()->GetMinimum()<<"                Max  = "<<graph23->GetHistogram()->GetMaximum() <<endl;


/*
 TCanvas *c1 = new TCanvas("c1","multipads",900,700);
 c1->Divide(2,1);
 c1->cd(1);
 graph0->Draw();
 c1->cd(2);
 graph14->Draw();
 c1->SaveAs("1.pdf");

 TLatex latex;
 latex.SetTextSize(0.025);
 latex.SetTextAlign(13);
 latex.DrawLatex(.2,.9,"dddddddddddddddddddK_{S}");
 latex.DrawLatex(.3,.9,"K^{*0dddddddddddddddd}");
*/
 
 TCanvas *c1 = new TCanvas("c1","multipads",900,700);
 c1->Divide(4,3);
 c1->cd(1);
 graph0->Draw();
 graph23->Draw("same");
 c1->cd(2);
 graph1->Draw();
 graph22->Draw("same");
 c1->cd(3);
 graph2->Draw();
 graph21->Draw("same");
 c1->cd(4);
 graph3->Draw();
 graph20->Draw("same");
 c1->cd(5);
 graph4->Draw();
 graph19->Draw("same");
 c1->cd(6);
 graph5->Draw();
 graph18->Draw("same");
 c1->cd(7);
 graph6->Draw();
 graph17->Draw("same");
 c1->cd(8);
 graph7->Draw();
 graph16->Draw("same");
 c1->cd(9);
 graph8->Draw();
 graph15->Draw("same");
 c1->cd(10);
 graph9->Draw();
 graph14->Draw("same");
 c1->cd(11);
 graph10->Draw();
 graph13->Draw("same");
 c1->cd(12);
 graph11->Draw();
 graph12->Draw("same");
 c1->SaveAs("1.pdf");




return 0;
}

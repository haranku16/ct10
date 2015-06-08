#include <TCanvas.h>
#include <TH1.h>
#include <TImage.h>
#include <TFile.h>
void print(const char* str){
	std::cout<<str<<std::endl;
}
void plots(int ignvctr){
	int plus = ignvctr*2+99;
	int minus = ignvctr*2+100;
	ostringstream stream; TString str;
	TCanvas* c1 = new TCanvas; //c1->SetWindowSize(1362,687);
	TCanvas* c2 = new TCanvas; //c2->SetWindowSize(1362,687);
	TCanvas* c3 = new TCanvas; //c3->SetWindowSize(1362,687);
	//TCanvas* c4 = new TCanvas; //c4->SetWindowSize(1362,687);
	stream.str(""); stream<<"Endcap-Endcap Distributions for Extreme Eigenvector "<<ignvctr; str = stream.str(); THStack stack1("EE",str.Data());
	stream.str(""); stream<<"Barrel-Barrel Distributions for Extreme Eigenvector "<<ignvctr; str = stream.str(); THStack stack2("BB",str.Data());
	stream.str(""); stream<<"Barrel-Endcap Distributions for Extreme Eigenvector "<<ignvctr; str = stream.str(); THStack stack3("BE",str.Data());
	//stream.str(""); stream<<"Same-Endcap Distributions for Extreme Eigenvector "<<ignvctr; str = stream.str(); THStack stack4("SE",str.Data());
	TImage* img1 = TImage::Create();
	TImage* img2 = TImage::Create();
	TImage* img3 = TImage::Create();
	//TImage* img4 = TImage::Create();
	TFile source("../diphox_completed.root");
	TH1D eeNom = (TH1D)source.Get("EE100"); eeNom.GetXaxis()->SetTitle("Diphoton Mass (GeV/c^2)"); eeNom.GetYaxis()->SetTitle("Cross Section (pb)");
	TH1D bbNom = (TH1D)source.Get("BB100"); bbNom.GetXaxis()->SetTitle("Diphoton Mass (GeV/c^2)"); bbNom.GetYaxis()->SetTitle("Cross Section (pb)");
	TH1D beNom = (TH1D)source.Get("BE100"); beNom.GetXaxis()->SetTitle("Diphoton Mass (GeV/c^2)"); beNom.GetYaxis()->SetTitle("Cross Section (pb)");
	//TH1D seNom = (TH1D)source.Get("SE100"); seNom.GetXaxis()->SetTitle("Diphoton Mass (GeV/c^2)"); seNom.GetYaxis()->SetTitle("Cross Section (pb)");
	TH1D eePlus,bbPlus,bePlus,sePlus,eeMinus,bbMinus,beMinus,seMinus;
	stream.str(""); stream<<"EE"<<plus; str=stream.str(); eePlus=(TH1D)source.Get(str.Data());
	stream.str(""); stream<<"EE"<<minus; str=stream.str(); eeMinus=(TH1D)source.Get(str.Data());
	stream.str(""); stream<<"BB"<<plus; str=stream.str(); bbPlus=(TH1D)source.Get(str.Data());
	stream.str(""); stream<<"BB"<<minus; str=stream.str(); bbMinus=(TH1D)source.Get(str.Data());
	stream.str(""); stream<<"BE"<<plus; str=stream.str(); bePlus=(TH1D)source.Get(str.Data());
	stream.str(""); stream<<"BE"<<minus; str=stream.str(); beMinus=(TH1D)source.Get(str.Data());
	//stream.str(""); stream<<"SE"<<plus; str=stream.str(); sePlus=(TH1D)source.Get(str.Data());
	//stream.str(""); stream<<"SE"<<minus; str=stream.str(); seMinus=(TH1D)source.Get(str.Data());
	/*eeNom.SetMarkerStyle(7); bbNom.SetMarkerStyle(7); beNom.SetMarkerStyle(7); seNom.SetMarkerStyle(7);
	eePlus.SetMarkerStyle(7); eeMinus.SetMarkerStyle(7);
	bbPlus.SetMarkerStyle(7); bbMinus.SetMarkerStyle(7);
	bePlus.SetMarkerStyle(7); beMinus.SetMarkerStyle(7);
	sePlus.SetMarkerStyle(7); seMinus.SetMarkerStyle(7);
	eeNom.SetMarkerColor(kBlack); bbNom.SetMarkerColor(kBlack); beNom.SetMarkerColor(kBlack); seNom.SetMarkerColor(kBlack);
	eePlus.SetMarkerColor(kBlue); eeMinus.SetMarkerColor(kRed);
	bbPlus.SetMarkerColor(kBlue); bbMinus.SetMarkerColor(kRed);
	bePlus.SetMarkerColor(kBlue); beMinus.SetMarkerColor(kRed);
	sePlus.SetMarkerColor(kBlue); seMinus.SetMarkerColor(kRed);*/
	eeNom.SetLineColor(kBlack); bbNom.SetLineColor(kBlack); beNom.SetLineColor(kBlack); //seNom.SetLineColor(kBlack);
	eePlus.SetLineColor(kBlue); eeMinus.SetLineColor(kRed);
	bbPlus.SetLineColor(kBlue); bbMinus.SetLineColor(kRed);
	bePlus.SetLineColor(kBlue); beMinus.SetLineColor(kRed);
	//sePlus.SetLineColor(kBlue); seMinus.SetLineColor(kRed);
	gStyle->SetOptStat(0);
	c1->SetLogy(); c2->SetLogy(); c3->SetLogy(); //c4->SetLogy();
	stack1.SetHistogram((TH1D*)&eeNom); stack1.Add((TH1D*)&eeNom,"E"); stack1.Add((TH1D*)&eePlus,"E"); stack1.Add((TH1D*)&eeMinus,"E");
	stack2.SetHistogram((TH1D*)&bbNom); stack2.Add((TH1D*)&bbNom,"E"); stack2.Add((TH1D*)&bbPlus,"E"); stack2.Add((TH1D*)&bbMinus,"E");
	stack3.SetHistogram((TH1D*)&beNom); stack3.Add((TH1D*)&beNom,"E"); stack3.Add((TH1D*)&bePlus,"E"); stack3.Add((TH1D*)&beMinus,"E");
	//stack4.SetHistogram((TH1D*)&seNom); stack4.Add((TH1D*)&seNom,"E"); stack4.Add((TH1D*)&sePlus,"E"); stack4.Add((TH1D*)&seMinus,"E");
	c1->cd(); stack1.Draw(); c1->BuildLegend(); c2->cd(); stack2.Draw(); c2->BuildLegend(); c3->cd(); stack3.Draw(); c3->BuildLegend(); //c4->cd(); stack4.Draw(); c4->BuildLegend();
	//gSystem->ProcessEvents();
	c1->SetWindowSize(1362,687); c2->SetWindowSize(1362,687); c3->SetWindowSize(1362,687); //c4->SetWindowSize(1362,687);
	img1->FromPad(c1); print("From c1"); stream.str(""); stream<<"EE"<<ignvctr<<".png"; str = stream.str(); img1->WriteImage(str.Data()); //gSystem->ProcessEvents();
	img2->FromPad(c2); print("From c2"); stream.str(""); stream<<"BB"<<ignvctr<<".png"; str = stream.str(); img2->WriteImage(str.Data()); //gSystem->ProcessEvents();
	img3->FromPad(c3); print("From c3"); stream.str(""); stream<<"BE"<<ignvctr<<".png"; str = stream.str(); img3->WriteImage(str.Data()); //gSystem->ProcessEvents();
	//img4->FromPad(c4); print("From c4"); stream.str(""); stream<<"SE"<<ignvctr<<".png"; str = stream.str(); img4->WriteImage(str.Data()); //gSystem->ProcessEvents();
	c1->Close(); c2->Close(); c3->Close(); source.Close(); //c4->Close();
}

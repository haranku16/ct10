#include <TCanvas.h>
#include <TH1.h>
#include <TFile.h>
int dNum=0;
void d(){
	ostringstream stream; TString str;
	stream<<dNum; str = stream.str();
	std::cout<<str.Data()<<std::endl;
	dNum++;
}
void env2(){
	ostringstream stream; TString str;
	TCanvas* c1 = new TCanvas;
	TCanvas* c2 = new TCanvas;
	TCanvas* c3 = new TCanvas;
	d();
	int NBINS = 172;
	int NVECTORS = 52;
	TFile f("../diphox_completed.root");
	TH1D eeNom = (TH1D)f.Get("EE100"), bbNom = (TH1D)f.Get("BB100"), beNom = (TH1D)f.Get("BE100");
	TH1D* cmp;
	TH1D ee("EE","Endcap-Endcap Excursion Envelope",NBINS,0.0,8600.0), bb("BB","Barrel-Barrel Excursion Envelope",NBINS,0.0,8600.0), be("BE","Barrel-Endcap Excursion Envelope",NBINS,0.0,8600.0);
	gStyle->SetOptStat(0);
	d();
	for (int i = 0; i < NBINS; i++){
		d();
		double moveEE = 0, moveBB = 0, moveBE = 0;
		for (int j = 0; j < NVECTORS; j++){
			stream.str(""); stream<<"EE"<<j+101; str = stream.str(); cmp=(TH1D*)f.Get(str.Data());
			if (fabs(eeNom.GetBinContent(i)-cmp->GetBinContent(i))>moveEE) moveEE = fabs(eeNom.GetBinContent(i)-cmp->GetBinContent(i));
			stream.str(""); stream<<"BB"<<j+101; str = stream.str(); cmp=(TH1D*)f.Get(str.Data());
			if (fabs(bbNom.GetBinContent(i)-cmp->GetBinContent(i))>moveBB) moveBB = fabs(bbNom.GetBinContent(i)-cmp->GetBinContent(i));
			stream.str(""); stream<<"BE"<<j+101; str = stream.str(); cmp=(TH1D*)f.Get(str.Data());
			if (fabs(beNom.GetBinContent(i)-cmp->GetBinContent(i))>moveBE) moveBE = fabs(beNom.GetBinContent(i)-cmp->GetBinContent(i));
		}
		ee.AddBinContent(i,moveEE); bb.AddBinContent(i,moveBB); be.AddBinContent(i,moveBE);
	}
	d();
	ee.GetXaxis()->SetTitle("Diphoton Mass (GeV/c^2)"); bb.GetXaxis()->SetTitle("Diphoton Mass (GeV/c^2)"); be.GetXaxis()->SetTitle("Diphoton Mass (GeV/c^2)");
	ee.GetYaxis()->SetTitle("Cross Section (pb)"); bb.GetYaxis()->SetTitle("Cross Section (pb)");  be.GetYaxis()->SetTitle("Cross Section (pb)");
	c1->SetLogy(); c2->SetLogy(); c3->SetLogy();
	c1->cd(); ee.Draw(); c2->cd(); bb.Draw(); c3->cd(); be.Draw(); 
	c1->Print("excursions.pdf("); c2->Print("excursions.pdf"); c3->Print("excursions.pdf)");
}

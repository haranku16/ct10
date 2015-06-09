#include <TFile.h>
#include <TH1.h>

void reldiff(int num){
	ostringstream stream,stream2; TString str,str2;
	int NBINS = 172;
	TFile f("../diphox_completed.root");
	TFile* outp;
	TH1D bbNom,beNom,bbdiff,bediff; TH1D* bb,be;
	stream.str(""); stream<<num<<".root"; str = stream.str();
	outp = new TFile(str.Data(),"recreate");
	bbNom = (TH1D)f.Get("BB100"); beNom = (TH1D)f.Get("BE100");
	stream.str(""); stream<<"BB"<<num; str=stream.str();
	bb = (TH1D*)f.Get(str.Data());
	stream.str(""); stream<<"BE"<<num; str=stream.str();
	be = (TH1D*)f.Get(str.Data());
	stream.str(""); stream<<"BB"<<num; str = stream.str(); stream2.str(""); stream2<<"Barrel-Barrel Relative Difference for Eigenvector Set "<<num; str2 = stream.str();
	bbdiff=TH1D(str.Data(),str2.Data(),NBINS,0.0,8600.0);
	stream.str(""); stream<<"BE"<<num; str = stream.str(); stream2.str(""); stream2<<"Barrel-Endcap Relative Difference for Eigenvector Set "<<num; str2 = stream.str();
	
	bediff=TH1D(str.Data(),str2.Data(),NBINS,0.0,8600.0);
	for (int i = 0; i < NBINS; i++){
		bbdiff.AddBinContent(i,(bb->GetBinContent(i)-bbNom.GetBinContent(i))/bbNom.GetBinContent(i));
		bediff.AddBinContent(i,(be->GetBinContent(i)-beNom.GetBinContent(i))/beNom.GetBinContent(i));
	}
	outp->cd();
	bediff.Write(); bbdiff.Write();
	f.Close(); outp->Close();
}

#include <TH1.h>
#include <TFile.h>
void rebin(){
	TFile fin("diphox_1GeV.root");
	TFile fout("diphox_rebinned.root","recreate");
	double xbin[7] = {0,640,1130,1810,2610,3510,8600};
	TH1D* h;
	ostringstream stream; TString str;
	for (int i =100; i < 153; i++){
		stream.str(""); stream<<"BB"<<i; str = stream.str();
		h = (TH1D*)fin.Get(str.Data());
		h = (TH1D*)h->Clone();
		h=(TH1D*)h->Rebin(6,"",xbin);
		fout.cd(); h->Write();
		stream.str(""); stream<<"BE"<<i; str = stream.str();
		h = (TH1D*)fin.Get(str.Data());
		h = (TH1D*)h->Clone();
		h=(TH1D*)h->Rebin(6,"",xbin);
		fout.cd(); h->Write();
	}
}

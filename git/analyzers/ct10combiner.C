#include <TString.h>
#include <TFile.h>
#include <TH2.h>
void ct10combiner(){
	TFile f = TFile("diphox_completed_testcombiner.root","recreate");
	TH1D* ee;
	TH1D* bb;
	TH1D* be;
	TH1D* se;
	TFile* in;
	ifstream xs("../xs.res");
	string line;
	double cross;
	for (int i = 0; i < 53; i++){
		int num = i+100;
		ostringstream stream; TString str;
		stream<<num<<".root"; str = stream.str();
		in = new TFile(str.Data());
		stream.str(""); stream<<"EE "<<num; str = stream.str();
		ee = (TH1D*)in->Get(str.Data());
		stream.str(""); stream<<"BB "<<num; str = stream.str();
		bb = (TH1D*)in->Get(str.Data());
		stream.str(""); stream<<"BE "<<num; str = stream.str();
		be = (TH1D*)in->Get(str.Data());
		stream.str(""); stream<<"SE "<<num; str = stream.str();
		se = (TH1D*)in->Get(str.Data());
		stream.str("");
		getline(xs,line); stream<<line; str = stream.str(); cross = atof(str.Data());
		stream.str(""); stream<<"SE "<<num; str = stream.str();
		stream.str(""); stream<<"BB"<<num; str = stream.str(); bb->SetName(str.Data()); bb->Scale(cross/4000000);
		stream.str(""); stream<<"EE"<<num; str = stream.str(); ee->SetName(str.Data()); be->Scale(cross/4000000);
		stream.str(""); stream<<"BE"<<num; str = stream.str(); be->SetName(str.Data()); ee->Scale(cross/4000000);
		stream.str(""); stream<<"SE"<<num; str = stream.str(); se->SetName(str.Data()); se->Scale(cross/4000000);
		if (i == 0){
			stream.str(""); stream<<"Barrel-Barrel Nominal Diphoton Mass Distribution"; str = stream.str(); bb->SetTitle(str.Data());
			stream.str(""); stream<<"Barrel-Endcap Nominal Diphoton Mass Distribution"; str = stream.str(); be->SetTitle(str.Data());
			stream.str(""); stream<<"Endcap-Endcap Nominal Diphoton Mass Distribution"; str = stream.str(); ee->SetTitle(str.Data());
			stream.str(""); stream<<"Same-Endcap Nominal Diphoton Mass Distribution"; str = stream.str(); se->SetTitle(str.Data());
		}
		else if (i%2==0){
			stream.str(""); stream<<"Barrel-Barrel Minus Diphoton Mass Distribution for Extreme Eigenvector "<<i/2; str = stream.str(); bb->SetTitle(str.Data());
			stream.str(""); stream<<"Endcap-Endcap Minus Diphoton Mass Distribution for Extreme Eigenvector "<<i/2; str = stream.str(); ee->SetTitle(str.Data());
			stream.str(""); stream<<"Barrel-Endcap Minus Diphoton Mass Distribution for Extreme Eigenvector "<<i/2; str = stream.str(); be->SetTitle(str.Data());
			stream.str(""); stream<<"Same-Endcap Minus Diphoton Mass Distribution for Extreme Eigenvector "<<i/2; str = stream.str(); se->SetTitle(str.Data());
		}
		else{
			stream.str(""); stream<<"Barrel-Barrel Plus Diphoton Mass Distribution for Extreme Eigenvector "<<(i+1)/2; str = stream.str(); bb->SetTitle(str.Data());
			stream.str(""); stream<<"Endcap-Endcap Plus Diphoton Mass Distribution for Extreme Eigenvector "<<(i+1)/2; str = stream.str(); ee->SetTitle(str.Data());
			stream.str(""); stream<<"Barrel-Endcap Plus Diphoton Mass Distribution for Extreme Eigenvector "<<(i+1)/2; str = stream.str(); be->SetTitle(str.Data());
			stream.str(""); stream<<"Same-Endcap Plus Diphoton Mass Distribution for Extreme Eigenvector "<<(i+1)/2; str = stream.str(); se->SetTitle(str.Data());
		}
		f.cd();
		ee->Write(); bb->Write(); be->Write(); se->Write();
	}
	xs.close();
	f.Close();
}

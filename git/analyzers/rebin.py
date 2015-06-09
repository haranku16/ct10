import ROOT,numpy

xbins = [0.0,640.0,1130.0,1810.0,2610.0,3510.0]

fin = ROOT.TFile("diphox_1GeV.root")
fout = ROOT.TFile("diphox_rebinned.root","recreate")

for i in range(0,53):
	num = i + 100
	hBB = fin.Get("BB"+str(num))
	hBB = hBB.Rebin(5,"BB"+str(num),xbins)
	hBE = fin.Get("BE"+str(num))
	hBE = hBE.Rebin(5,"BE"+str(num),xbins)
	fout.cd()
	hBB.Write()
	hBE.Write()
fin.Close()
fout.Close()

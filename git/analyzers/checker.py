import ROOT

runouts = []

f = ROOT.TFile("diphox_1GeV.root")

for i in range(0,53):
	h = f.Get("BB"+str(i+100))
	low = 0
	for j in range(0,860):
		if h.GetBinContent(j)>0:
			low = j
	runouts.append(low)
	h = f.Get("BE"+str(i+100))
	low = 0
	for j in range(0,860):
		if h.GetBinContent(j)>0:
			low = j
	runouts.append(low)
	h = f.Get("EE"+str(i+100))
	low = 0
	for j in range(0,860):
		if h.GetBinContent(j)>0:
			low = j
	runouts.append(low)
print min(runouts)

I=3
while [ $I -lt 27 ]; do
	root -l "plots.C($I)" &
	let I=I+1
done

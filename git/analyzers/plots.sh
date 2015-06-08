I=1
while [ $I -lt 27 ]; do
	root -b "plots.C($I)" &
	let I=I+1
done

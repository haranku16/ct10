I=100
while [ $I -lt 153 ]; do
	root -b ggo_ct10$I.root
	root -b ggt_ct10$I.root
	let I=I+1
done

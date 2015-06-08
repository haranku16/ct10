#!/bin/bash
COUNTER=0
while [ $COUNTER -lt 53 ]; do
	root -b "ct10analyzer.C($COUNTER)" &
	let COUNTER=COUNTER+1
done

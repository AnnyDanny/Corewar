#!/bin/bash

# Specify path with your champions.
CHAMPS=$(find champs -type f -name "*.cor")
echo $CHAMPS


# Specify executable of your corewar.
MY=../corewar
# Specify executable of original corewar.
OR=./corewar

make_diff() {
	./$MY -dump 15000 $@ > file1
	./$OR -d 15000 $@ > file2
	diff file1 file2 || printf "$@ - different\n\n" >> dump
}

for i in $CHAMPS; do
	make_diff $i
	# for j in $CHAMPS; do
		# make_diff $i $j
		# for k in $CHAMPS; do
			# make_diff $i $j $k
			# for h in $CHAMPS; do
				# make_diff $i $j $k $h
			# done
		# done
	# done
done

rm -f file1 file2
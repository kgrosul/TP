#!/bin/bash

finDir=$1
finArch=$2

mkdir $finDir &> /dev/null

for fileType in $@
do
find $HOME -iname "*.$fileType" -exec cp {} ./$finDir/ \; &> /dev/null
done

tar -cf "$finArch.tar" $finDir

echo "done"

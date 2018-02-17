#!/bin/bash

finDir=$1
finArch=$2
mkdir $finDir

for fileType in $@
do
find $HOME -iname "*.$fileType" -exec cp {} ./$finDir/ \;
done

tar -cf "$finArch.tar" $finDir

echo "done"

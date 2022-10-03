#!/bin/bash

echo 'Введи адрес'
read filename

if [ ! -f $filename ]
then
    echo 'нет такого файла'
    exit 0
fi

qty=$(wc -l $filename | awk '{print $1}')
uniqfiles=$(cat $filename | awk '{print $1}' | uniq -ud | wc | awk '{print $1}')
qtyhash=$(cat $filename | awk '{print $8}' | uniq -ud | wc | awk '{print $1}')
echo "$qty $uniqfiles $qtyhash"
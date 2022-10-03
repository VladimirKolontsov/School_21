#!/bin/bash

echo 'Введи адрес'
read filename
if [ ! -f $filename ]
then 
    echo "$filename такого файла нет"
    #exit 0
fi
echo 'Что ищем?'
read stroka_na_zameny
if [ -z $stroka_na_zameny ]
then
    echo 'строка не может быть пустой'
    exit 0
fi
echo 'На что меняем?'
read na_chto_menyaem
if [ -z $na_chto_menyaem ]
then
    echo 'строка не может быть пустой'
    exit 0
fi

sed -I -e "s/$stroka_na_zameny/$na_chto_menyaem/g" $filename    

size=$(ls -l $filename | awk '{print $5}')        
data=$(date -r $filename +"%Y-%m-%d %H:%m")
sha=$(shasum -a 256 $filename | awk '{print $1}')        
 
echo "$filename - $size - $data - $sha - sha256" >> files.log
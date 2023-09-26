#!/bin/bash

# Crear archivo de entrada de prueba
echo -e "manzana\npera\nuva" > infile.txt

# Test 1: Con 3 comandos
./pipex infile.txt "sort" "uniq" "wc -l" outfile1.txt
sort infile.txt | uniq | wc -l > outfile2.txt

# Comparar archivos de salida
if cmp -s outfile1.txt outfile2.txt ; then
   echo "Test 1: El test de 3 comandos pasó"
else
   echo "Test 1: El test de 3 comandos falló"
   diff outfile1.txt outfile2.txt
fi

# Test 2: Comandos con argumentos
./pipex infile.txt "sort -r" "uniq -i" "wc -c" outfile1.txt
sort -r infile.txt | uniq -i | wc -c > outfile2.txt

# Comparar archivos de salida
if cmp -s outfile1.txt outfile2.txt ; then
   echo "Test 2: El test con argumentos pasó"
else
   echo "Test 2: El test con argumentos falló"
   diff outfile1.txt outfile2.txt
fi

# Test 3: Archivo no existente
./pipex nofile.txt "sort" "uniq" "wc -l" outfile1.txt
if [ $? -eq 1 ]; then
    echo "Test 3: El test con archivo no existente pasó (esperado fallo)"
else
    echo "Test 3: El test con archivo no existente falló (esperado fallo)"
fi

# Limpiar archivos de prueba
rm infile.txt outfile1.txt outfile2.txt

gcc -std=c11 mat-seq.c -o seqMatrixMul.out -lpthread
gcc -std=c11 mat-mult.c -o matrixMul.out -lpthread
rm matrixMul.csv

for i in 16 32 64 128 256 
do
  ./seqMatrixMul.out $i >> matrixMul.csv
  ./matrixMul.out $i >> matrixMul.csv
done

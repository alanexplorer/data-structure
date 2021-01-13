#include <cstdlib>
#include <ctime>
#include "sort.h"
#include <QDebug>

int main()
{
    Sort<int> *S = new Sort<int>();


    //Essa função gera números aleatórios para o array
    int size = 10;
    int A[size];

    srand((unsigned)time(0));

    for(int i=0; i<size; i++)
        A[i] = (rand()%100)+1;

    //Fim

    qDebug()<<"Normal";
    S->show(A, size);


        //Bubble Sort
//        S->bubbleSort(A,size);

        //InsSort
//        S->insSort(A,size);

        //selSort
//        S->selSort(A, size);

        //MegeSort
//        S->mergeSort(A, size);

        //shellSor
//        S->shellSort(A, size);

    qDebug()<<"Ordenado";
    S->show(A, size);

    return 0;
}

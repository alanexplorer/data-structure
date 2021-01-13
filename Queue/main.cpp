#include "queue.h"
#include<QDebug>


int main()
{
    Fila<int> *F = new Fila<int>();

    F->enqueue(12);
    qDebug()<<F->frontValue();
    qDebug()<<F->length();


    return 0;
}

#include "stack.h"
#include<QDebug>


int main()
{
    Pilha<int> *P = new Pilha<int>();

   // P->pop();
    P->push(1);
    qDebug()<<P->topValue();
    P->push(1);
    P->push(1);
    P->push(1);

   // qDebug()<<P->length();

    return 0;
}

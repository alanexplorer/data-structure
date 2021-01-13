#include "Heap.h"
//#include "MinHeap.h"
#include <QDebug>

int main(){

    MaxHeap<int> *H = new MaxHeap<int>(10);

    H->insert(16);
    H->insert(4);
    H->insert(10);
    H->insert(14);
    H->insert(7);
    H->insert(9);
    H->insert(3);
    H->insert(2);
    H->insert(8);
    H->insert(1);

   // H->heapfy(1);
   // H->remove(1);

    H->show();

    return 0;
}

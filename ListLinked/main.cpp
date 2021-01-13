#include <QDebug>
#include "list.h"

int main()
{
    List<int> *L = new List<int>();

    L->insert(11);
    L->insert(21);
    L->insert(31);




    qDebug()<<L->getValue();

}

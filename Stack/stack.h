#ifndef LSTACK
#define LSTACK

#include <cstddef>
#include <iostream>
#include <QDebug>
#include "stackNode.h"
#include "stackadt.h"

class TrataErro
{
public:
    TrataErro(int n);

private:
    int NLinha;
};
TrataErro::TrataErro(int n)
{
    NLinha = n;
    std::cout<<"Erro linha "<<NLinha<<": ";
}


template <typename E> class Pilha: public Stack<E> {
private:
    Link<E>* top;
    int size;

public:
    Pilha(){
        top = NULL;
        size = 0;
    }

    ~Pilha() {
        clear();
    }

    void clear() {
        while (top != NULL) {
            Link<E>* temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }

    void push(const E& it) {
        top = new Link<E>(it, top);
        size++;
    }

    E pop() {
        try{
            if(top==NULL){
                throw (TrataErro(__LINE__));
            }
            E it = top->element;
            Link<E>* ltemp = top->next;
            delete top;
            top = ltemp;
            size--;
            return it;
        }
        catch(...){
            qDebug() <<" A pilha esta vazia";
            return 0;
        }
    }

    const E& topValue() const {
        try{
            if(top==NULL){
                throw (TrataErro(__LINE__));
            }
            return top->element;
        }
        catch(...){
            qDebug() <<" Nao existe elemento no top";

        }
        return NULL;
    }

    int length() const {
        return size;
    }
};
#endif

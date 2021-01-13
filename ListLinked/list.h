//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||@|||||||||@||@@@@@@||@@@@@@@|||@@@@@@@|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||@|||||||||@||@@|||||||||@||||||@|||||@|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||@|||||||||@|||@@@|||||||@||||||@@@@@@@|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||@|||||||||@||||||@@|||||@||||||@|||||@|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||@@@@@@@|||@||@@@@@@|||||@||||||@|||||@|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||                         |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||           POR           |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||                         |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||       ALAN PEREIRA      |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||                         |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

#include "listadt.h"
#include "listnd.h"
#include<iostream>

//Envia mensagem se a condição não for satisfeita e fecha
void Assert(bool condicao, std::string s) {
    if (!condicao) {
        std::cout << "Falha: " << s << std::endl;
        exit(-1);
    }
}

template <typename E> class List: public ListADT<E> {

    NodeList<E>* Cabeca;
    NodeList<E>* Calda;
    NodeList<E>* curssor;
    int cont;

    void iniciar() {
        curssor = Calda = Cabeca = new NodeList<E>;
        cont = 0;
    }

    void reiniciar() {
        while(Cabeca != NULL) {
            curssor = Cabeca;
            Cabeca = Cabeca->proximo;
            delete curssor;
        }
    }

public:

    //Construtor
    List() {
        iniciar();
    }

    //Destrutor
    ~List() {
        reiniciar();
    }

    //Implementação do clear()
    void clear() {
        reiniciar();
        iniciar();
    }

    void insert(const E& item) {
        curssor->proximo = new NodeList<E>(item, curssor->proximo);
        if (Calda == curssor)
            Calda = curssor->proximo;
        cont++; //Atualizo o tamanho da lista
    }

    void append(const E& item) {
        Calda = Calda->proximo = new NodeList<E>(item, NULL);
        cont++;
    }

    E remove() {
        Assert(curssor->proximo != NULL, "Sem elementos para remover");

        E item = curssor->proximo->elemento;

        NodeList<E>* listTemp = curssor->proximo;

        if (Calda == curssor->proximo)
            Calda = curssor;
        curssor->proximo = curssor->proximo->proximo;

        delete listTemp;
        cont--; //atualizo o tamanho da lista
        return item;
    }

    void moveToStart(){
        curssor = Cabeca;
    }

    void moveToEnd(){
        curssor = Calda;
    }

    void prev() {
        if (curssor == Cabeca)
            return;

        NodeList<E>* temp = Cabeca;

        while (temp->proximo!=curssor)
            temp=temp->proximo;
        curssor = temp;
    }

    void next(){
        if (curssor != Calda)
            curssor = curssor->proximo;
    }

    int length() const  {
        return cont;
    }

    int currPos() const {
        NodeList<E>* temp = Cabeca;
        int i;
        for (i=0; curssor != temp; i++)
            temp = temp->proximo;
        return i;
    }

    void moveToPos(int pos) {
        Assert ((pos>=0)&&(pos<=cont), "Sem essa posicao");

        curssor = Cabeca;
        for(int i=0; i<pos; i++) curssor = curssor->proximo;
    }

    const E& getValue() const {
        Assert(curssor->proximo != NULL, "Sem esse valor");

        return curssor->proximo->elemento;

    }
};

#include "queuenode.h"
#include "queueadt.h"
#include <cstddef>

template <typename E> class Fila: public QueueADT<E> {
private:
  Node<E>* frente;
  Node<E>* traz;
  int size;

public:
  Fila(){
      frente = traz = new Node<E>();
      size = 0;
  }

  ~Fila() {
      clear(); delete frente;
  }

  void clear() {
    while(frente->next != NULL) {
      traz = frente;
      delete traz;
    }
    traz = frente;
    size = 0;
  }

  void enqueue(const E& it) {
    traz->next = new Node<E>(it, NULL);
    traz = traz->next;
    size++;
  }

  E dequeue() {

    E it = frente->next->element;
    Node<E>* ltemp = frente->next;
    frente->next = ltemp->next;
    if (traz == ltemp) traz = frente;
    delete ltemp;
    size --;
    return it;
  }

  const E& frontValue() const {

    return frente->next->element;
  }

  virtual int length() const {
      return size;
  }
};

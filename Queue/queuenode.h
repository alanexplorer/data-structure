#include <cstddef>
template <typename E> class Node {
public:
  E element;
  Node *next;

  Node(const E& elemval, Node* nextval =NULL){
      element = elemval;
      next = nextval;
  }
  Node(Node* nextval =NULL) {
      next = nextval;
  }
};

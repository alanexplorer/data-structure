#include <QString>
// Heap class
template <typename E> class HeapADT{


private:
// Helper function to put element in its correct place
public:
virtual void heapfy(int pos)  = 0;
virtual void bubble(int pos) = 0;
virtual int size() const = 0;//retorna tamanho da heap
virtual bool isLeaf(int pos) const = 0; //retorna buff se pos e folha
virtual int leftchild(int pos) const = 0;// retorna posicao do filho a esquerda
virtual int rightchild(int pos) const = 0;//retorna posicao do filho a direita
virtual int parent(int pos) const  = 0;// retorna posicao do pai
virtual void buildHeap()  = 0; // Constroi a heap de acordo com suas configuracoes
//virtual void insert(const E& it) = 0;// Insert "it" into the heap
virtual E get(int pos) const = 0;//retorna valor na seguinte pos
virtual void remove(const E& it) =  0;//remove valor em questao
//virtual QString toString() = 0;//imprimir no formato arvore
};

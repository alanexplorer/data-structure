template <typename E> class NodeList {
public:
    E elemento;
    NodeList *proximo;

    NodeList(const E& elementoValor, NodeList* proximoValor =NULL){
        elemento = elementoValor;
        proximo = proximoValor;
    }
    NodeList(NodeList* proximoValor =NULL) {
        proximo = proximoValor;
    }
};

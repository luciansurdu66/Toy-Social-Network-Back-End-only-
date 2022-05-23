#ifndef PROIEEEECT_DICTIONARYNODE_H
#define PROIEEEECT_NODE_H

template <typename  T>
class List;

template <typename T>
class Node {
public:
    T data ;
    Node<T> *next;
    Node(T data, Node<T> *next) : data(data), next(next){}
    Node(T data): data(data){next = nullptr;}
    friend class List<T>;

};
#endif //PROIEEEECT_NODE_H

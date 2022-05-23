
#ifndef PROIEEEECT_LISTNODE_H
#define PROIEEEECT_LISTNODE_H

#include <ostream>

template<class T>

class ListNode {
public:
    T data;
    ListNode<T> *next;

    ListNode(T data, ListNode<T> *next) : data(data), next(next) {}

    explicit ListNode(T data) : data(data) { next = nullptr; }

    friend std::ostream &operator<<(std::ostream &os, const ListNode<T> &node) {
        os << node.data;
        return os;
    }
};
#endif //PROIEEEECT_LISTNODE_H

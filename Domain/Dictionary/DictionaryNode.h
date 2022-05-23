#ifndef PROIEEEECT_DICTIONARYNODE_H
#define PROIEEEECT_DICTIONARYNODE_H
template <class K, class V>
class Dictionary;

template <class K, class V>
class DictionaryNode{
private:
    K key;
    V value;
    DictionaryNode<K,V>* next;
public:
    DictionaryNode(K key, V value) : key(key), value(value){
        this->next = nullptr;
    }
    friend class Dictionary<K,V>;
    K get_key(DictionaryNode<K, V> node){
        return node.key;
    }
    V get_value(DictionaryNode<K, V> node){
        return node.value;
    }
};
#endif //PROIEEEECT_DICTIONARYNODE_H

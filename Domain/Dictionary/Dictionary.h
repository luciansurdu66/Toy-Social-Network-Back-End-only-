#ifndef PROIEEEECT_DICTIONARY_H
#define PROIEEEECT_DICTIONARY_H
using namespace std;
#include <algorithm>
#include <stdexcept>
#include "DictionaryNode.h"
template <class K, class V>
class Dictionary{
private:
    DictionaryNode<K, V>* first;
    int size;
public:
    /**
     * Constructor
     */
    Dictionary(){
        this->first = nullptr;
        size = 0;
    }
    /**
     * Add an element to the dictionary
     * @param key key
     * @param value value
     */
    void put(K key, V value){
        if(first == nullptr){
            first = new DictionaryNode<K, V>(key, value);
            this->size++;
        }else{
            DictionaryNode<K, V>*p = first;
            while(p->next != nullptr && p->key != key){
                p = p->next;
            }
            if(p->key == key){
                p->value = value;
            }else{
                p->next = new DictionaryNode<K, V>(key, value);
                this->size++;
            }
        }
    }
    /**
     * Used to iterate
     * @param index index
     * @return V value
     */
    V operator[] (int index){
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }

        DictionaryNode<K, V> *current = first;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }
    /**
     * Remove an entity
     * @param index index of entity
     */
    void remove(int index){
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        DictionaryNode<K, V> *current = first;
        DictionaryNode<K, V> *prev = nullptr;
        for(int i = 0;i < index; i++){
            prev = current;
            current = current->next;
        }
        if(prev == nullptr){
            first = current->next;
        }else
        {
            prev->next = current->next;
        }

        delete current;
        size -- ;
    }

    /**
     * Get the size of the dictionary
     * @return size
     */
    int get_size(){
        return this->size;
    }
    /**
     * Destructor
     */
    ~Dictionary() = default;
};
#endif //PROIEEEECT_DICTIONARY_H

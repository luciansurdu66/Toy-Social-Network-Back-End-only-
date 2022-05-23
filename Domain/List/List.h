#ifndef PROIEEEECT_LIST_H
#define PROIEEEECT_LIST_H

#include <stdexcept>
#include "Node.h"
#include "ListNode.h"
template <class T> class List{
private:
    int capacity,size,defaultcapacity=10;
    T* entities;
    /**
     * Resize the list
     */
    void resize(){
        this->capacity = this->capacity + this->defaultcapacity;
        T* newEntities = new T[this->capacity];
        for(int i = 0; i < this->size; i++) {
            newEntities[i] = this->entities[i];
        }
        delete[] this->entities;
        this->entities = newEntities;
    }
public:
    /**
     * Constructor
     */
    List(){
        this->size = 0;
        this->capacity = defaultcapacity;
        entities = new T[this->capacity];
    }

    T& operator[](int i){
        return entities[i];
    }
    /**
     * Copy Constructor
     * @param array array
     */
    List(const List<T> &array){
        this->capacity = array.capacity;
        this->size = array.size;
        T* newEntities = new T[this->capacity];
        for(int i = 0; i < this->size; i++) {
            newEntities[i] = array[i];
        }
        this->entities = newEntities;
    }
    /**
     * Destructor
     */
    ~List() = default;
    /**
     * Get the size of the list
     * @return size of list
     */
    int getSize(){
        return this->size;
    }
    /**
     * Add an entity to the list
     * @param ent entity
     */
    void add(T ent){
        if(this->size == this->capacity) {
            resize();
        }
        this->entities[this->size++] = ent;
    }
    /**
     * Get all entities
     * @return a list with all entities
     */
    List<T> getAll(){
        return entities;
    }

    T& operator[](int i)const{
        return entities[i];
    }
    /**
     * Delete an entity
     * @param elem entity to delete
     */
    void remove(T elem) {
        bool ok = false;
        for (int i = 0; i < size; i++) {
            if(entities[i] == elem){
                ok = true;
                for(int k=i;k<size-1;k++){
                    entities[k] = entities[k+1];
                }
            }
        }
        if(ok){
            size--;
        }
    }
};
#endif //PROIEEEECT_LIST_H

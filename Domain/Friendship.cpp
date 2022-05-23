#include <sstream>
#include "Friendship.h"

Friendship::Friendship(int id, int id1, int id2) : id(id), id1(id1), id2(id2) {
    this->id = id;
    this->id1 = id1;
    this->id2 = id2;
}

int Friendship::getId() const {
    return id;
}

Friendship::~Friendship() =default;

void Friendship::setId(int id) {
    Friendship::id = id;
}

int Friendship::getId1() const {
    return id1;
}

void Friendship::setId1(int id1) {
    Friendship::id1 = id1;
}

int Friendship::getId2() const {
    return id2;
}

void Friendship::setId2(int id2) {
    Friendship::id2 = id2;
}
void Friendship::fromString(std::string args, char delimiter) {
    std::vector<std::string> elements;
    std::stringstream ss(args);
    std::string item;
    while (getline (ss, item, delimiter)) {
        elements.push_back(item);
    }
    if(elements.size() == 3) {
        std::stringstream i(elements[0]);
        i >> this->id;
        std::stringstream n(elements[1]);
        n >> this->id1;
        std::stringstream p(elements[2]);
        p >> this->id2;
    }
}
std::string Friendship::toString(char delimiter) {
    return std::to_string(this->id) + delimiter + std::to_string(this->id1) + delimiter + std::to_string(this->id2);
}

ostream &operator<<(ostream &os, const Friendship &friendship) {
    os << "id: " << friendship.id << " id sender: " << friendship.id1 << " id receiver: " << friendship.id2;
    return os;
}

Friendship::Friendship(std::string args) {
    this->fromString(args);
}
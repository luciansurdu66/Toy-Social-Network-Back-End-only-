//
// Created by lucia on 5/22/2022.
//

#ifndef PROIEEEECT_EVENT_H
#define PROIEEEECT_EVENT_H
#include "User.h"
#include "List/List.h"
#include <string>
#include <ostream>

using namespace std;

class Event {
private:
    int id;
    string name;
    User organizer;
    string description;
    List<User> attendants;
public:
    Event() = default;
    Event(int id, string name,  const User& organizer, const List<User>& attendants, string description) :
        id(id), name(move(name)), organizer(organizer), attendants(attendants), description(move(description) ){}

    bool operator==(const Event &rhs) const {
        return id == rhs.id &&
               name == rhs.name &&
               organizer == rhs.organizer &&
               description == rhs.description;
    }

    bool operator!=(const Event &rhs) const {
        return !(rhs == *this);
    }

    ~Event() = default;

    int getId() const {
        return id;
    }

    void setId(int id) {
        Event::id = id;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Event::name = name;
    }

    const User &getOrganizer() const {
        return organizer;
    }

    void setOrganizer(const User &organizer) {
        Event::organizer = organizer;
    }

    const List<User> &getAttendants() const {
        return attendants;
    }

    void setAttendants(const List<User> &attendants) {
        Event::attendants = attendants;
    }

    const string &getDescription() const {
        return description;
    }

    void setDescription(const string &description) {
        Event::description = description;
    }
};


#endif //PROIEEEECT_EVENT_H

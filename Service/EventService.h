//
// Created by lucia on 5/22/2022.
//

#ifndef PROIEEEECT_EVENTSERVICE_H
#define PROIEEEECT_EVENTSERVICE_H

#include "../Repository/EventRepository.h"
class EventService {
private:
    EventRepositry repository;
public:
    EventService() = default;

    ~EventService() = default;

    void addEvent(Event event);

    void removeEvent(Event event);

    void updateEvent(Event event);

    int getSizeEvents();

    Event getEvent(int id);

    List<Event> &getAllEvents();

    int GiveIdEvent();

    Event getEventByName(string name);

    bool verifyExistEvent(string name);
};


#endif //PROIEEEECT_EVENTSERVICE_H

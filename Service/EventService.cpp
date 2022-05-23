//
// Created by lucia on 5/22/2022.
//

#include "EventService.h"
/**
 * Add an event
 * @param event event to add
 */
void EventService::addEvent(Event event) {
    repository.add_event(event);
}
/**
 * Delete an event
 * @param event event to delete
 */
void EventService::removeEvent(Event event) {
    repository.remove_event(event);
}
/**
 * Update an event
 * @param event event to update
 */
void EventService::updateEvent(Event event) {
    repository.update_event(event);
}
/**
 * Get size of events
 * @return size
 */
int EventService::getSizeEvents() {
    return repository.get_size();
}
/**
 * Get all events
 * @return a list with all events
 */
List<Event> &EventService::getAllEvents() {
    return repository.get_all();
}
/**
 * Get event by id
 * @param id id of event
 * @return Event
 */
Event EventService::getEvent(int id) {
    return repository.get_event_by_id(id);
}
/**
 * Give id to a new event
 * @return id
 */
int EventService::GiveIdEvent() {
    int max = -1;
    for(int i = 0 ;i<getSizeEvents();i++)
        if(getAllEvents()[i].getId() > max)
            max = getAllEvents()[i].getId();
    return max+1;
}

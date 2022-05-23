#ifndef PROIEEEECT_EVENTREPOSITORY_H
#define PROIEEEECT_EVENTREPOSITORY_H
#include "../Domain/List/List.h"
#include "../Domain/Event.h"
class EventRepositry{
private:
    List<Event> events;
public:
    /**
     * Constructor
     */
    EventRepositry() = default;
    /**
     * Add an event
     * @param event the event
     */
    void add_event(Event event){
        events.add(event);
    }
    /**
     * Get index from an event
     * @param id id from an event
     * @return index of event
     */
    int get_index(int id){
        for(int i = 0 ;i<events.getSize();i++){
            if(events[i].getId() == id)
                return i;
        }
    }
    /**
     * Remove event
     * @param event event to remove
     */
    void remove_event(const Event& event){
        events.remove(event);
    }
    /**
     * Update event
     * @param event event to update
     */
    void update_event(const Event& event){
        events[get_index(event.getId())] = event;
    }
    /**
     * Get the size of repository
     * @return size
     */
    int get_size(){
        return events.getSize();
    }
    /**
     * Get event by id
     * @param id id of event
     * @return Event
     */
    Event get_event_by_id(int id){
        return events[get_index(id)];
    }
    /**
     * Get all events
     * @return a list with all events
     */
    List<Event>& get_all(){
        return events;
    }
    /**
     * Destructor
     */
    ~EventRepositry() = default;
};
#endif //PROIEEEECT_EVENTREPOSITORY_H

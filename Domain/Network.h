//
// Created by lucia on 5/22/2022.
//

#ifndef PROIEEEECT_NETWORK_H
#define PROIEEEECT_NETWORK_H
#include <fstream>
#include "../Service/UserService.h"
#include "../Service/EventService.h"
#include "../Service/MessageService.h"
#include "../Service/FriendshipService.h"

class Network {
protected:
    static Network* instance;
    UserService userService;
    FriendshipService friendshipService;
    MessageService messageService;
    EventService eventService;

    Network(): userService(), friendshipService(), messageService(), eventService(){
        string line;
        ifstream myFileUser("../Domain/TXT/Users.txt");
        while (getline(myFileUser, line)) {
            User r(line);
            userService.add_user(r);
        }
        std::ifstream myFileMessages("../Domain/TXT/Messages.txt");
        while (getline(myFileMessages, line)) {
            Message m(line);
            messageService.add_message(m);
        }
        std::ifstream myFileFriendships("../Domain/TXT/Friendships.txt");
        while (getline(myFileFriendships, line)) {
            Friendship f(line);
            friendshipService.add_friendship(f);
        }

    }
public:
    static Network *get_instance(){
        if(!instance){
            instance = new Network();
        }
        return instance;
    }
    ~Network(){
        delete instance;
    }

    void add_user(User user){
        userService.add_user(user);
    }
    void add_message(Message message){
        messageService.add_message(message);
    }
    void add_friendship(Friendship friendship){
        friendshipService.add_friendship(friendship);
    }
    void delete_user(const User& user){
        userService.delete_user(user);
    }

    void update_user(const User& user){
        userService.update_user(user);
    }

    int get_size_users(){
        return userService.get_size();
    }

    User get_user_by_id(int id){
        return userService.get_user_by_id(id);
    }

    User get_user_by_index(int index){
        return userService.get_user_by_index(index);
    }
    List<User>& get_all_users(){
        return userService.get_all();
    }
    int get_index_user(int id){
        return userService.get_index(id);
    }
    void remove_message(Message message) {
        messageService.remove_message(message);
    }

    int get_size_messages() {
        return messageService.get_size();
    }

    List<Message>& get_all_messages(){
        return messageService.get_all();
    }

    vector<Message> get_messages_from_user(User user){
        return messageService.get_messages(user);
    }

    void remove_friendship(Friendship friendship) {
        friendshipService.remove_friendship(friendship);
    }

    Friendship get_friendship_by_id(int id){
        return friendshipService.get_friendship_by_id(id);
    }

    Dictionary<int, Friendship>& get_all_friendships(){
        return friendshipService.get_all();
    }

    int get_size_friendships(){
        return friendshipService.get_size_friendhsips();
    }

    int give_id_friendship(){
        Dictionary<int, Friendship> current = get_all_friendships();
        return current.get_size()+1;
    }
    void add_event(Event event) {
        eventService.addEvent(event);
    }

    void remove_event(Event event) {
        eventService.removeEvent(event);
    }

    void update_event(Event event) {
        eventService.updateEvent(event);
    }

    int get_size_events() {
        return eventService.getSizeEvents();
    }

    List<Event> &get_all_events() {
        return eventService.getAllEvents();
    }

    Event get_event(int id) {
        return eventService.getEvent(id);
    }
    int give_id_user(){
        return userService.GiveIdUser();
    }

    User get_user_by_email(string email){
        return userService.get_user_by_email(email);
    }
};


#endif //PROIEEEECT_NETWORK_H

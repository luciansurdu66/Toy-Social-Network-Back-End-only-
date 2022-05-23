#include "MessageService.h"
#include <iostream>
/**
 * Add a message
 * @param message message to add
 */
void MessageService::add_message(Message message) {
    repository.add_message(message);
}
/**
 * Remove a message
 * @param message message to remove
 */
void MessageService::remove_message(Message message) {
    repository.delete_message(message);
}
/**
 * Get size of messages
 * @return size
 */
int MessageService::get_size() {
    return repository.get_size();
}
/**
 * Get all messages
 * @return a list with all messages
 */
List<Message>& MessageService::get_all(){
    return repository.get_all();
}
/**
 * Get all messages from an user
 * @param user User
 * @return a vector with all messages from an user
 */
vector<Message> MessageService::get_messages(User user){
    return repository.get_messages(user);
}

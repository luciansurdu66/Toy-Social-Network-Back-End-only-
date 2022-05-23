#ifndef PROIEEEECT_MESSSAGEREPOSITORY_H
#define PROIEEEECT_MESSSAGEREPOSITORY_H
#include <tuple>
#include "../Domain/List/List.h"
#include "../Domain/User.h"
#include "../Domain/Message.h"
class MessageRepository{
private:
    List<Message> messages;
public:
    /**
     * Constructor
     */
    MessageRepository() = default;
    /**
     * Add a message
     * @param message message to add
     */
    void add_message(Message message){
        messages.add(message);
    }

    int get_index(int id){
        for(int i=0;i<messages.getSize();i++){
            if(messages[i].getId() == id){
                return i;
            }
        }
    }
    /**
     * Delete a message
     * @param message message to delete
     */
    void delete_message(const Message& message){
        messages.remove(message);
    }
    /**
     * Get the size of messages
     * @return size of messages
     */
    int get_size(){
        return messages.getSize();
    }
    /**
     * Get all messages
     * @return a list with all messages
     */
    List<Message> &get_all(){
        return messages;
    }
    /**
     * Get all messages from an user
     * @param user User
     * @return a vector with messages
     */
    vector<Message> get_messages(User user){
        vector<Message> result;
        for(int i = 0; i < messages.getSize();i++){
            if(user.getId() == messages[i].getIdSender()){
                result.push_back(messages[i]);
            }
        }
        return result;
    }
    /**
     * Destructor
     */
    ~MessageRepository() = default;
};
#endif //PROIEEEECT_MESSSAGEREPOSITORY_H

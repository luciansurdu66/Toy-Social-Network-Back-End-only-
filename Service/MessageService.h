#ifndef PROIEEEECT_MESSAGESERVICE_H
#define PROIEEEECT_MESSAGESERVICE_H

#include "../Repository/MesssageRepository.h"
class MessageService {
private:
    MessageRepository repository;
public:
    MessageService() = default;

    void add_message(Message message);

    void remove_message(Message message);

    int get_size();


    ~MessageService() = default;

    List<Message>& get_all();

    vector<Message> get_messages(User user);
};


#endif //PROIEEEECT_MESSAGESERVICE_H

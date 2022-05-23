//
// Created by lucia on 5/21/2022.
//

#ifndef PROIEEEECT_MESSAGE_H
#define PROIEEEECT_MESSAGE_H
#include <string>
#include <ostream>

using namespace std;
class Message {
private:
    int id;
    int idSender;
    int idReceiver;
    string data;
public:
    ~Message();

    Message(int id, int idSender, int idReceiver, string data);

    Message(const Message &others);

    int getId() const;

    int getIdSender() const;

    int getIdReceiver() const;

    string getData();

    void setId(int id);

    void setIdSender(int idSender);

    void setIdReceiver(int idReceiver);

    void setData(string data);

    Message& operator=(const Message& message);

    bool operator==(const Message& message) const;

        void fromString(const std::string& args, char delimiter = ',');

    explicit Message(std::string args);

    std::string toString(char delimiter = ',');

    Message();

    string getMessage();

    void setMessage(string data);

    friend ostream &operator<<(ostream &os, const Message &message);
};


#endif //PROIEEEECT_MESSAGE_H

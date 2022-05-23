
#include <utility>
#include <vector>
#include <sstream>
#include "Message.h"
Message::Message(int id, int idSender, int idReceiver, string data) {
    this->id = id;
    this->idSender = idSender;
    this->idReceiver = idReceiver;
    this->data = move(data);
}

Message::Message(const Message &others) {
    this->id = others.id;
    this->idSender = others.idSender;
    this->idReceiver = others.idReceiver;
    this->data = others.data;
}

Message::~Message() = default;

int Message::getId() const {
    return this->id;
}

int Message::getIdReceiver() const {
    return this->idReceiver;
}

int Message::getIdSender() const {
    return this->idSender;
}

string Message::getMessage() {
    return this->data;
}

void Message::setId(int id) {
    this->id = id;
}

void Message::setIdSender(int idSender) {
    this->idSender = idSender;
}

void Message::setIdReceiver(int idReceiver) {
    this->idReceiver = idReceiver;
}

void Message::setMessage(string data) {
    this->data = data;
}

Message &Message::operator=(const Message &message) {
    if (this != &message) {
        this->id = message.id;
        this->idSender = message.idSender;
        this->idReceiver = message.idReceiver;
        this->data = data;
    }
    return *this;
}

bool Message::operator==(const Message &message) const {
    return this->id == message.id && this->idReceiver == message.idReceiver
           && this->idSender == message.idSender && this->data == message.data;
}


Message::Message(string args) {
    this->fromString(args);
}

std::string Message::toString(char delimiter) {
    return std::to_string(this->id) + delimiter + std::to_string(this->idSender) + delimiter + std::to_string(this->idReceiver) + delimiter + this->data;
}

void Message::fromString(const string& args, char delimiter) {
    vector<string> elements;
    stringstream ss(args);
    string item;
    while (getline(ss, item, delimiter)) {
        elements.push_back(item);
    }
    if (elements.size() == 4) {
        stringstream id(elements[0]);
        id >> this->id;
        stringstream sender(elements[1]);
        sender >> this->idSender;
        stringstream receiver(elements[2]);
        receiver >> this->idReceiver;
        stringstream message(elements[3]);
        string messages;

        getline(message, messages);
        this->setMessage(messages);

    }
}
ostream &operator<<(ostream &os, const Message &message) {
    os << "id: " << message.id << " idSender: " << message.idSender << " idReceiver: " << message.idReceiver
       << " messsage: " << message.data;
    return os;
}

Message::Message() = default;

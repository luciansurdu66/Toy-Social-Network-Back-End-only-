#include <sstream>
#include "User.h"

User::User(int id, const string &firstName, const string &lastName, const string &email,
           const string &password, const string &gender) : firstName(firstName), lastName(lastName),email(email), password(password), gender(gender) {
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->password = password;
    this->gender = gender;
}

int User::getId() const {
    return id;
}

bool User::operator==(const User &rhs) const {
    return id == rhs.id &&
           firstName == rhs.firstName &&
           lastName == rhs.lastName &&
           email == rhs.email &&
           password == rhs.password &&
           gender == rhs.gender;
}

bool User::operator!=(const User &rhs) const {
    return !(rhs == *this);
}

void User::setId(int id) {
    User::id = id;
}


const string &User::getFirstName() const {
    return firstName;
}

const string &User::getEmail() const {
    return email;
}

void User::setFirstName(const string &firstName) {
    User::firstName = firstName;
}

void User::setLastName(const string &lastName) {
    User::lastName = lastName;
}

void User::setEmail(const string &email) {
    User::email = email;
}

void User::setPassword(const string &password) {
    User::password = password;
}

void User::setGender(const string &gender) {
    User::gender = gender;
}

const string &User::getPassword() const {
    return password;
}

const string &User::getGender() const {
    return gender;
}

const string &User::getLastName() const {
    return lastName;
}

ostream &operator<<(ostream &os, const User &user) {
    os << "id: " << user.id << " firstName: " << user.firstName << " lastName: " << user.lastName << " email: "
       << user.email << " password: " << user.password << " gender: " << user.gender;
    return os;
}

User::User(std::string args) {
    this->fromString(args);
}
void User::fromString(std::string args, char delimiter) {
    vector<string> elements;
    stringstream ss(args);
    string item;
    while (getline (ss, item, delimiter)) {
        elements.push_back(item);
    }
    if(elements.size() == 6) {
        stringstream i(elements[0]);
        i >> this->id;
        stringstream n(elements[1]);
        n >> this->firstName;
        stringstream p(elements[2]);
        p >> this->lastName;
        stringstream pn(elements[3]);
        pn >> this->email;
        stringstream a(elements[4]);
        a >> this->password;
        stringstream g(elements[5]);
        g >> this->gender;
    }
}
string User::toString(char delimiter) {
    return to_string(this->id) + delimiter + this->firstName + delimiter + this->lastName + delimiter + this->email + delimiter + this->password + delimiter + this->gender;
}

User::User() = default;

User::~User() = default;

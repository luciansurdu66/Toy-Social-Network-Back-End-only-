#ifndef PROIEEEECT_USER_H
#define PROIEEEECT_USER_H
using namespace std;
#include <string>
#include <vector>
#include <ostream>
#include "List/List.h"
class User {
private:

    int id;
    string firstName;
    string lastName;
    string email;
    string password;
    string gender;
public:
    User();

    User(int id, const string &firstName, const string &lastName, const string &email,
         const string &password, const string &gender);

    virtual ~User();

    const string &getFirstName() const;

    const string &getLastName() const;

    const string &getEmail() const;

    const string &getPassword() const;

    const string &getGender() const;

    void setFirstName(const string &firstName);

    void setLastName(const string &lastName);

    void setEmail(const string &email);

    void setPassword(const string &password);

    void setGender(const string &gender);

    int getId() const;

    void setId(int id);

    bool operator==(const User &rhs) const;

    bool operator!=(const User &rhs) const;

    friend ostream &operator<<(ostream &os, const User &user);

    void fromString(string args, char delimiter = ',');

    string toString(char delimiter = ',');

    User(string args);
};


#endif //PROIEEEECT_USER_H

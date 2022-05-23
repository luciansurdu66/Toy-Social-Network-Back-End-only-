#ifndef PROIEEEECT_USERSERVICE_H
#define PROIEEEECT_USERSERVICE_H
#include "../Repository/UserRepository.h"

class UserService {
private:
    UserRepository repository;
public:
    UserService();
    ~UserService();
    void add_user(const User& user);
    void delete_user(const User& user);
    void update_user(const User& user);
    int get_size();
    User get_user_by_id(int id);
    User get_user_by_index(int index);
    List<User>& get_all();
    int get_index(int id);
    User get_user_by_email(string email);
    bool verify_registration(string email);
    User get_by_email(string email);

    int GiveIdUser();
};


#endif //PROIEEEECT_USERSERVICE_H

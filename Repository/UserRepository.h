#ifndef PROIEEEECT_USERREPOSITORY_H
#define PROIEEEECT_USERREPOSITORY_H
#include "../Domain/List/List.h"
using namespace std;
#include "../Domain/User.h"

class UserRepository{
private:
    List<User> userlist;
public:
    /**
     * Constructor
     */
    UserRepository() = default;
    /**
     * Destructor
     */
    ~UserRepository() = default;
    /**
     * Add an user
     * @param user user to add
     */
    void add_user(const User& user){
        userlist.add(user);
    }
    /**
     * Get index of user
     * @param id id of user
     * @return index
     */
    int get_index(int id){
        for(int i=0;i<userlist.getSize();i++){
            if(userlist[i].getId() == id){
                return i;
            }
        }
    }
    /**
     * Get User by id
     * @param id id of user
     * @return User
     */
    User get_user_by_id(int id){
        for(int i = 0; i< userlist.getSize(); i++){
            if(userlist[i].getId() == id){
                return userlist[i];
            }
        }
    }
    /**
     * Delete an user
     * @param user user to delete
     */
    void delete_user(const User& user){
        userlist.remove(user);
    }
    /**
     * Get all users
     * @return a list with all users
     */
    List<User>& get_all(){
        return userlist;
    };
    /**
     * Get size of the list with users
     * @return size
     */
    int get_size(){
        return userlist.getSize();
    }
    /**
     * Get user by index
     * @param index index
     * @return User
     */
    User get_user_by_index(int index){
        return userlist[index];
    }
    /**
     * Update an User
     * @param user user to update
     */
    void update_user(const User& user){
        userlist[get_index(user.getId())] = user;
    }
};
#endif //PROIEEEECT_USERREPOSITORY_H

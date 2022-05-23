#include "UserService.h"
UserService::UserService() = default;

UserService::~UserService() = default;
/**
 * Add an User
 * @param user user to add
 */
void UserService::add_user(const User& user){
    repository.add_user(user);
}
/**
 * Delete an User
 * @param user user to delete
 */
void UserService::delete_user(const User& user){
    repository.delete_user(user);
}
/**
 * Update an User
 * @param user user to update
 */
void UserService::update_user(const User& user){
    repository.update_user(user);
}
/**
 * Get size of users
 * @return size
 */
int UserService::get_size(){
    return repository.get_size();
}
/**
 * Get user by id
 * @param id id of user
 * @return User
 */
User UserService::get_user_by_id(int id){
    return repository.get_user_by_id(id);
}
/**
 * Get User by index
 * @param index index of user
 * @return User
 */
User UserService::get_user_by_index(int index){
    return repository.get_user_by_index(index);
}
/**
 * Get all users
 * @return a list with all users
 */
List<User>& UserService::get_all(){
    return repository.get_all();
}
/**
 * Get the index of an user
 * @param id id of user
 * @return index
 */
int UserService::get_index(int id){
    return repository.get_index(id);
}
/**
 * Get user by email
 * @param email email of user
 * @return User
 */
User UserService::get_user_by_email(string email){
    for(int i = 0; i<get_size();i++){
        if(get_all()[i].getEmail() == email){
            return get_all()[i];
        }
    }

}
/**
 * Give id to a new user
 * @return id
 */
int UserService::GiveIdUser() {
    int max = -1;
    for (int i = 0; i < get_size(); i++)
        if (get_all()[i].getId() > max)
            max = get_all()[i].getId();
    return max + 1;
}
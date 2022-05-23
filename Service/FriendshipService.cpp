//
// Created by lucia on 5/22/2022.
//

#include "FriendshipService.h"
/**
 * Add a friendship
 * @param friendship Friendship to add
 */
void FriendshipService::add_friendship(Friendship friendship) {
    repository.add_friendship(friendship);
}
/**
 * Delete a friendship
 * @param friendship friendship to delete
 */
void FriendshipService::remove_friendship(Friendship friendship) {
    repository.delete_friendship(friendship);
}
/**
 * Get friendship by id
 * @param id id of friendship
 * @return Friendship
 */
Friendship FriendshipService::get_friendship_by_id(int id){
    return repository.get_friendship(id);
}
/**
 * Get all friendships
 * @return a dictionary with all friendships
 */
Dictionary<int, Friendship>& FriendshipService::get_all(){
    return repository.get_all_friendships();
}
/**
 * Give id to a new friendship
 * @return id
 */
int FriendshipService::give_id_friendship(){
    Dictionary<int, Friendship> current = get_all();
    return current.get_size()+1;
}
/**
 * Get size of friendships
 * @return size
 */
int FriendshipService::get_size_friendhsips(){
    return repository.get_size_friendships();
}

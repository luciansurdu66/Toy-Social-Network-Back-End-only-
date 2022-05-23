#ifndef PROIEEEECT_FRIENDSHIPREPOSITORY_H
#define PROIEEEECT_FRIENDSHIPREPOSITORY_H
#include "../Domain/Dictionary/Dictionary.h"
#include "../Domain/List/List.h"
#include "../Domain/Friendship.h"
#include <tuple>
class FriendshipRepository{
private:
    Dictionary<int,Friendship> friendships;
public:
    /**
     * Constructor
     */
    FriendshipRepository() = default;
    /**
     * Destructor
     */
    ~FriendshipRepository() = default;
    /**
     * Add a friendship
     * @param friendship friendship to add
     */
    void add_friendship(Friendship friendship){
        friendships.put(friendship.getId(), friendship);
    }
    /**
     * Delete a friendship
     * @param friendship friendship to delete
     */
    void delete_friendship(Friendship friendship){
        friendships.remove(friendship.getId());
    }
    /**
     * Get friendship by id
     * @param id id of friendship
     * @return Friendship
     */
    Friendship get_friendship(int id){
        Friendship friendship(id, friendships[id].getId1(), friendships[id].getId2());
        return friendship;
    }
    /**
     * Get all friendships
     * @return a dictionary with all friendships
     */
    Dictionary<int,Friendship>& get_all_friendships(){
        return friendships;
    }
    /**
     * Get size of dictionary
     * @return size
     */
    int get_size_friendships(){
        return friendships.get_size();
    }
};
#endif //PROIEEEECT_FRIENDSHIPREPOSITORY_H

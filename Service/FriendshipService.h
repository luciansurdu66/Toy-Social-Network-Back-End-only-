//
// Created by lucia on 5/22/2022.
//

#ifndef PROIEEEECT_FRIENDSHIPSERVICE_H
#define PROIEEEECT_FRIENDSHIPSERVICE_H
#include "../Repository/FriendshipRepository.h"

class FriendshipService {
private:
    FriendshipRepository repository;
public:
    FriendshipService() = default;

    ~FriendshipService() = default;

    void add_friendship(Friendship friendship);

    void remove_friendship(Friendship friendship);


    Friendship get_friendship_by_id(int id);

    Dictionary<int, Friendship>& get_all();

    int give_id_friendship();

    int get_size_friendhsips();
};


#endif //PROIEEEECT_FRIENDSHIPSERVICE_H

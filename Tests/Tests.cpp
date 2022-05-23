//
// Created by lucia on 5/23/2022.
//

#include <cassert>
#include "Tests.h"
void Tests::test_all(){
    test_domain();
}
void Tests::test_domain(){
    User user(1,"Surdu","Lucian","luciansurdu66@gmail.com","123","male");
    assert(user.getId() == 1);
    assert(user.getFirstName() == "Surdu");
    assert(user.getLastName() == "Lucian");
    assert(user.getEmail() == "luciansurdu66@gmail.com");
    assert(user.getPassword() == "123");

    User user2(2,"Anton","Bianca","biancaanton@yahoo.com","123","female");
    Friendship friendship(1,1,2);
    assert(friendship.getId() == 1);
    assert(friendship.getId1() == 1);
    assert(friendship.getId2() == 2);

    Message message(1,1,2,"Ola!!");
    assert(message.getId() == 1);
    assert(message.getIdSender() == 1);
    assert(message.getIdReceiver() == 2);
    assert(message.getMessage() == "Ola!!");
}
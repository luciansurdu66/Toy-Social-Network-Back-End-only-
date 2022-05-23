cmake_minimum_required(VERSION 3.21)
project(Proieeeect)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proieeeect main.cpp Domain/User.cpp Domain/User.h Domain/List/List.h Domain/Dictionary/DictionaryNode.h Domain/Dictionary/Dictionary.h Domain/Friendship.cpp Domain/Friendship.h Domain/Message.cpp Domain/Message.h Repository/UserRepository.h Repository/FriendshipRepository.h Domain/Event.h Repository/MesssageRepository.h Service/UserService.cpp Service/UserService.h UI/MainMenu.cpp UI/MainMenu.h Service/MessageService.cpp Service/MessageService.h Repository/EventRepository.h Service/FriendshipService.cpp Service/FriendshipService.h Service/EventService.cpp Service/EventService.h Domain/List/Node.h Domain/List/ListNode.h Domain/Network.cpp Domain/Network.h Tests/Tests.cpp Tests/Tests.h)

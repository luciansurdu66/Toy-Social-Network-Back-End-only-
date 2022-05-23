#ifndef PROIEEEECT_MAINMENU_H
#define PROIEEEECT_MAINMENU_H
#include "../Domain/Network.h"
#include "../Service/UserService.h"
#include "../Service/EventService.h"
#include "../Service/MessageService.h"
#include "../Service/FriendshipService.h"
class MainMenu {
private:
    Network *network;

public:
    MainMenu();
    void handle_main_menu();
    void handle_admin_menu();
    void handle_run_main_menu();

    ~MainMenu() = default;

    void handle_admin_show_users();

    void handle_admin_show_friendships();

    void handle_run_admin_menu();

    void handle_admin_show_messages();

    void handle_user_menu();

    void handle_aplication_user_menu();

    void handle_run_user_menu();

    void handle_login_user();

    void handle_registration_user();

    void handle_run_aplication_user_menu(const string &email, const string &password);

    void handle_user_show_users(string email, string password);

    void handle_user_show_friends(string email, string password);

    void handle_user_add_friend(string email, string password);

    void handle_user_add_message(string email, string password);

    void handle_user_show_messages_friend(string email, string password);

    void handle_user_show_messages(string email, string password);

    void handle_user_delete_account(string email, string password);
};


#endif //PROIEEEECT_MAINMENU_H

#include <iostream>
#include <utility>
#include "MainMenu.h"

MainMenu::MainMenu() {
    network = Network::get_instance();
}

void MainMenu::handle_main_menu() {
    cout << "Welcome to the main menu of this Toy Social Network\n";
    cout << "Options: \n";
    cout << "1. Admin menu.\n";
    cout << "2. User menu.\n";
    cout << "x. Exit.\n";
}

void MainMenu::handle_admin_menu(){

    cout << "Options: \n";
    cout << "1. Show all users.\n";
    cout << "2. Show all friendships.\n";
    cout << "3. Show all messages.\n";
    cout << "x. Back.\n";
}

void MainMenu::handle_user_menu(){
    cout << "Options: \n";
    cout << "1. Login.\n";
    cout << "2. Registration. \n";
    cout << "x. Back\n";
}

void MainMenu::handle_aplication_user_menu(){
    cout << "Options: \n";
    cout << "1. Show other users.\n";
    cout << "2. Show your friends. \n";
    cout << "3. Add a friend.\n";
    cout << "4. Send a message.\n";
    cout << "5. Show all your messages.\n";
    cout << "6. Show all messages with a friend.\n";
    cout << "d. Delete your account.\n";
    cout << "x. Back.\n";
}
void MainMenu::handle_run_main_menu() {
    char option;
    bool ok = true;
    while(ok){
        handle_main_menu();
        cin >> option;
        switch (option) {
            case '1':
                handle_run_admin_menu();
                break;
            case '2':
                handle_run_user_menu();
                break;
            case 'x':
                ok = false;
                break;
            default: {
                cout << "Wrong option! Try again!\n";
                break;
            }
        }
    }
}

void MainMenu::handle_run_user_menu(){
    char option;
    bool ok = true;
    while(ok){
        handle_user_menu();
        cin>>option;
        switch (option) {
            case '1':
                handle_login_user();
                break;
            case '2':
                handle_registration_user();
            case 'x':
                ok = false;
                break;
            default:
                cout << "Wrong option! Try again!\n";
                break;
        }
    }

}

void MainMenu::handle_run_admin_menu(){
    char option;
    bool ok = true;
    while(ok){
        cout << "\nThis is the admin menu of this Social Network\n";
        handle_admin_menu();
        cin >> option;
        switch (option) {
            case '1':
                handle_admin_show_users();
                break;
            case '2':
                handle_admin_show_friendships();
                break;
            case '3':
                handle_admin_show_messages();
                break;
            case 'x':
                ok = false;
                break;
            default: {
                cout << "Wrong option! Try again!\n";
                break;
            }
        }
    }
}

void MainMenu::handle_run_aplication_user_menu(const string& email, const string& password){
    char option;
    bool ok = true;
    while(ok){
        cout << "\nThis is the application menu for users\n";
        handle_aplication_user_menu();
        cin >> option;
        switch (option) {
            case '1':
                handle_user_show_users(email, password);
                break;
            case '2':
                handle_user_show_friends(email, password);
                break;
            case '3':
                handle_user_add_friend(email, password);
                break;
            case '4':
                handle_user_add_message(email, password);
            case '5':
                handle_user_show_messages_friend(email, password);
                break;
            case '6':
                handle_user_show_messages(email, password);
                break;
            case 'd':
                handle_user_delete_account(email,password);
            case 'x':
                ok = false;
                handle_run_user_menu();
                break;
            default:
                cout << "Wrong option! Try again! \n";
                break;

        }
    }
}

void MainMenu::handle_admin_show_users(){
    for(int i=0;i< this->network->get_size_users();i++){
        cout << this->network->get_all_users()[i] << "\n";
    }
}

void MainMenu::handle_admin_show_friendships(){
    for(int i = 0; i < this->network->get_size_friendships();i++){
        cout << this->network->get_all_friendships()[i] << "\n";
    }
}

void MainMenu::handle_admin_show_messages(){
    for(int i = 0; i < this->network->get_size_messages();i++){
        cout << this->network->get_all_messages()[i] << this->network->get_all_messages()[i].getMessage()<<"\n";
    }
}

void MainMenu::handle_user_show_users(string email, string password){
    if(network->get_size_users()!=1){
        for(int i = 0;i< network->get_size_users();i++){
            User user = network->get_all_users()[i];
            if(email != user.getEmail()){
                cout << user.getFirstName() + " " + user.getLastName() + " with email: " + user.getEmail() + "\n";
            }
        }
    }
}

void MainMenu::handle_user_show_friends(string email, string password){
    User user = network->get_user_by_email(std::move(email));
    cout << user.getFirstName() + " " + user.getLastName() + ", you are friends with: \n";
    for(int i = 0;i < network->get_all_friendships().get_size();i++){
        Friendship friendship = network->get_all_friendships()[i];
        if(user.getId() == friendship.getId1()){
            User u = network->get_user_by_id(friendship.getId2());
            cout << u.getFirstName() + " " + u.getLastName() + "\n";
        }
        if(user.getId() == friendship.getId2()){
            User u = network->get_user_by_id(friendship.getId1());
            cout << u.getFirstName() + " " + u.getLastName() + "\n";
        }
    }
}

void MainMenu::handle_user_add_friend(string email, string password){
    User user = network->get_user_by_email(std::move(email));
    string mail;
    cout << "\nGive us the email of the user that you want to be friends with, choose wisely:)!\n";
    cin >> mail;
    bool ok = true,ok1 = true;
    for(int i = 0;i<this->network->get_size_users();i++){
        User user1 = this->network->get_all_users()[i];
        if(mail == user1.getEmail()){
            ok = false;
            break;
        }
    }
    for(int i = 0;i < network->get_all_friendships().get_size();i++){
        Friendship friendship = network->get_all_friendships()[i];
        if(user.getId() == friendship.getId1()){
            User u = network->get_user_by_id(friendship.getId2());
            if(u.getEmail() == mail){
                ok1 = false;
            }
        }
        if(user.getId() == friendship.getId2()){
            User u = network->get_user_by_id(friendship.getId1());
            if(u.getEmail() == mail){
                ok1 = false;
            }
        }
    }
    if(ok){
        cout << "It looks like this email doesn't exist in our databases!\n";
    }
    else if(!ok1){
        cout << "It looks like you already are friends with this user!\n";
    } else{
        User user1 = network->get_user_by_email(mail);
        Friendship f(network->give_id_friendship(), user.getId(), user1.getId());
        network->add_friendship(f);
        cout << "Congrats!! you are now friends with " + user1.getLastName() + user1.getFirstName() + "!\n";
    }
}

void MainMenu::handle_user_add_message(string email, string password){

    handle_user_show_friends(email, password);
    cout << "You can only message them!\n";
    string mail, message;
    cout << "\nGive us the email of the user that you want to message with, choose wisely:)!\n";
    cin >> mail;
    bool ok = true;
    for(int i = 0;i<this->network->get_size_users();i++){
        User user1 = this->network->get_all_users()[i];
        if(mail == user1.getEmail()){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << "It looks like this email doesn't exist in our databases!\n";
    }else{
        cout << "Give the message: \n";
        getline(cin, message);
        User user1 = network->get_user_by_email(email);
        User user = network->get_user_by_email(mail);
        int max = -1;
        for (int i = 0; i < network->get_size_messages(); i++)
        {
            Message m = network->get_all_messages()[i];
            if(m.getId() > max){
                max = m.getId();
            }
        }
        Message m(max + 1, user1.getId(), user.getId(), message);
    }

}

void MainMenu::handle_user_show_messages_friend(string email, string password){
    User user = network->get_user_by_email(email);
    for(int i = 0;i< network->get_size_messages();i++){
        Message message = network->get_all_messages()[i];
        if(user.getId() == message.getIdSender()){
            User user1 = network->get_user_by_id(message.getIdReceiver());
            cout << "\nYou have sent a message to "
            + user1.getFirstName() + " "
            + user1.getLastName() + ": "
            + message.getMessage() + "\n";
        }
        else if(user.getId() == message.getIdReceiver()){
            User user1 = network->get_user_by_id(message.getIdSender());
            cout << "\n You have received a message from "
            + user1.getFirstName() + " "
            + user1.getLastName() + ": "
            + message.getMessage() + "\n";
        }
    }
}

void MainMenu::handle_user_show_messages(string email, string password){
    User user = network->get_user_by_email(email);
    string mail;
    cout << "\nGive us the email of the user that you want to see the conversation with!\n";
    cin >> mail;
    bool ok = true,ok1 = true;
    for(int i = 0;i<this->network->get_size_users();i++){
        User user1 = this->network->get_all_users()[i];
        if(mail == user1.getEmail()){
            ok = false;
            break;
        }
    }
    for(int i = 0;i < network->get_all_friendships().get_size();i++){
        Friendship friendship = network->get_all_friendships()[i];
        if(user.getId() == friendship.getId1()){
            User u = network->get_user_by_id(friendship.getId2());
            if(u.getEmail() == mail){
                ok1 = false;
            }
        }
        if(user.getId() == friendship.getId2()){
            User u = network->get_user_by_id(friendship.getId1());
            if(u.getEmail() == mail){
                ok1 = false;
            }
        }
    }
    if(ok){
        cout << "It looks like this email doesn't exist in our databases!\n";
    }
    else if(ok1){
        cout << "It looks like you are not friends with this user!\n";
    } else{
        User user1 = network->get_user_by_email(mail);
        for(int i = 0;i< network->get_size_messages();i++){
            Message message = network->get_all_messages()[i];
            if(user.getId() == message.getIdSender() and user1.getId() == message.getIdReceiver()){
                cout << "\nYou have sent a message to "
                        + user1.getFirstName() + " "
                        + user1.getLastName() + ": "
                        + message.getMessage() + "\n";
            }
            else if(user.getId() == message.getIdReceiver() and user1.getId() == message.getIdSender()){
                cout << "\n You have received a message from "
                        + user1.getFirstName() + " "
                        + user1.getLastName() + ": "
                        + message.getMessage() + "\n";
            }
        }
    }
}

void MainMenu::handle_user_delete_account(string email, string password){
    cout << "\n Are you sure?(Press Y/N)\n";
    string answer;
    cin >> answer;
    if(answer == "Y" or answer == "y"){
        User user = network->get_user_by_email(email);
        network->delete_user(user);
        cout << "\nYou have successfully deleted your account!\n";

    }
    else{
        cout << "\nThank you for reconsidering!\n";
    }

}

void MainMenu::handle_login_user(){
    string email, password;
    cout << "\n Enter your email: ";
    cin >> email;
    cout << "\n Enter your password: ";
    cin >> password;
    int ok;
    for(int i = 0 ;i < this->network->get_size_users(); i++){
        User user = this->network->get_all_users()[i];
        if(user.getEmail() == email and user.getPassword() == password){
            cout << "\n Succesfully logged in! \n";
            cout << "Welcome " << user.getFirstName()  +" "+ user.getLastName() << "!\n";
            handle_run_aplication_user_menu(email, password);
            break;
        }
        else
        {
            if(user.getEmail() != email and user.getPassword() == password){
                ok = 1;
            }
            else
            {
                if(user.getEmail() == email and user.getPassword() != password)
                    ok = 2;
            }
        }
    }
    if(ok == 1){
        cout << "\nWrong email! Try again! \n";
        handle_login_user();
    }else if(ok == 2){
        cout << "\nWrong password! Try again! \n";
        handle_login_user();
    }
}

void MainMenu::handle_registration_user(){
        string first_name, last_name, email, password, gender;
        cout << "\nWrite your first name: ";
        cin >> first_name;
        cout << "\nWrite your last name: ";
        cin >> last_name;
        cout << "\nWrite your email: ";
        cin >> email;
        cout << "\nWrite your password: ";
        cin >> password;
        cout << "\nWrite your gender: ";
        cin >> gender;
        bool ok = false;
        for(int i = 0 ;i < this->network->get_size_users(); i++) {
            User user = this->network->get_all_users()[i];
            if (user.getEmail() == email) {
                cout << "This email is already been used!\n";
                ok = true;
                break;
            }
        }
        cout << "Congratulations you just registered to this Social Network " + first_name + " " + last_name << "!\n";
        User user(network->give_id_user(), first_name, last_name, email, password, gender);
        network->add_user(user);
        handle_run_user_menu();
        }


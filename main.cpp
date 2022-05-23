#include "UI/MainMenu.h"
#include "Domain/Network.h"
#include "Tests/Tests.h"
Network *Network::instance;
int main() {
    Tests tests;
    tests.test_all();
    MainMenu mainMenu;
    mainMenu.handle_run_main_menu();
    return 0;
}

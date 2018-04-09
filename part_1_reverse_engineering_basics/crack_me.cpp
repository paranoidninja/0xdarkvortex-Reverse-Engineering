#include <stdio.h>
#include <iostream>
#include <string.h>

int check_pass(char* password) {
    char mypass[10] = "PASSWORD1";
    if ( strcmp(password, mypass) != 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Help:\n" << argv[0] << " <password>\n";
    }
    else {
        int reply = check_pass(argv[1]);

        if (reply == 1) {
            std::cout << "[!] InCorrect Password" << std::endl;
        }
        else {
            std::cout << "[+] Correct Password" << std::endl;
        }
    }
    return 0;
}
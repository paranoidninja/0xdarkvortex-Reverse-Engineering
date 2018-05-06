#include <stdio.h>
#include <string.h>

void CheckPass(int *XoredPassword) {
    int PArray[10] = {38, 34, 37, 55, 55, 61, 33, 51, 32, 39};

    bool is_equal = true;

    for (int i=0; i<10; i++) {
        if (XoredPassword[i] != PArray[i]) {
            is_equal = false;
            break;
        }
    }

    if (is_equal == true) {
        printf ("[+] Correct Password");
    }
    else {
        printf ("[-] Incorrect Password");
    }
}

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        printf("Help:\n%s <password 10 chars max>\n", argv[0]);
    }
    else {
    //     char toEncrypt[10] = argv[1];
        int stringLength = strlen(argv[1]);
        if (stringLength > 10) {
            printf("[-] Password must be a maximum of 10 characters. Please enter a shorter password\n");
        }
        else {
            int keyStore[10] = {85, 86, 87, 88, 89, 90, 81, 82, 83, 84};
            int XoredDecimal[stringLength] = {};

            for (int i=0; i<stringLength; i++) {
                XoredDecimal[i] = ((int)(argv[1][i]))^(keyStore[i]);
            }
            
            CheckPass(XoredDecimal);
        }
    }
    return 0;
}

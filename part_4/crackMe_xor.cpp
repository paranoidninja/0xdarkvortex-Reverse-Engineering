#include <iostream>
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

int main() {
    char toEncrypt[10] = "";
    
    printf("Enter the 10 character password: ");
    scanf("%10s", toEncrypt);
    int stringLength = strlen(toEncrypt);
    
    int keyStore[10] = {85, 86, 87, 88, 89, 90, 81, 82, 83, 84};
    int XoredDecimal[stringLength] = {};

    for (int i=0; i<stringLength; i++) {
        XoredDecimal[i] = ((int)(toEncrypt[i]))^(keyStore[i]);
    }
    
    CheckPass(XoredDecimal);
    
    return 0;
}

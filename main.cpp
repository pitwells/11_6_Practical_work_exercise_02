#include <iostream>

std::string email;
std::string symbolsLeft = "!#$%&'*+-/=?^_`{|}~.1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string symbolsRight = "-.1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

std::string separatesPartEmail (std::string email, int part) {
    std::string result, partLeft, partRight;
    partLeft = email;
    partRight = email;

    partLeft = partLeft.erase(email.find('@'));
    partRight = partRight.erase(0, email.find('@') + 1);

    return part == 1 ? result = partLeft : result = partRight;
}


std::string validatingEmail (std::string email) {
    int checkValid = 0;
    std::string partLeft, partRight;
    partLeft = separatesPartEmail(email, 1);
    partRight = separatesPartEmail(email, 2);

    if (partLeft.length() <= 64 && partLeft.length() >= 1 && partRight.length() <= 63 && partRight.length() >= 1) {
        checkValid = checkValid + 1;
    } else checkValid = 0;

    int chk = 0;

    for (int i = 0; i < partLeft.length(); i++) {
        for (int k = 0; k < symbolsLeft.length(); k++) {
            if (partLeft[i] == symbolsLeft[k]) chk +=1;
        }
    }
    if (chk == partLeft.length()) checkValid = checkValid + 1;
        else checkValid = 0;

    chk = 0;

    for (int n = 0; n < partRight.length(); n++) {
        for (int j = 0; j < symbolsRight.length(); j++) {
            if (partRight[n] == symbolsRight[j]) chk +=1;
        }
    }
    if (chk == partRight.length()) checkValid = checkValid + 1;
        else checkValid = 0;

    chk = 0;

    for (int t = 0; t < partLeft.length(); t++) {
        if (partLeft[t-1] == '.' && partLeft[t] == '.') checkValid = 0;
            else chk = 1;
    }
    if (chk == 1) checkValid = checkValid + 1;

    chk = 0;

    for (int q = 0; q < partLeft.length(); q++) {
        if (partRight[q-1] == '.' && partRight[q] == '.') checkValid = 0;
        else chk = 1;
    }
    if (chk == 1) checkValid = checkValid + 1;

    if (partLeft[0] == '.' || partLeft[partLeft.size()] == '.') checkValid = 0;
        else checkValid = checkValid + 1;

    return checkValid == 6 ? "YES" : "NO";
}


int main() {
    std::cout << "Checking the correctness of the email address!" << std::endl << std::endl;

    std::cout << "Enter email address:" << std::endl;
    std::getline(std::cin, email);

    std::cout << validatingEmail(email);
}

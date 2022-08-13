#include <iostream>

int checkEmail = 0;
bool qwer = false;
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
    std::string partLeft, partRight;
    partLeft = separatesPartEmail(email, 1);
    partRight = separatesPartEmail(email, 2);

    if (partLeft.length() < 64 && partLeft.length() > 1 && partRight.length() < 63 && partRight.length() > 1) {
        checkEmail = checkEmail + 1;
    } else checkEmail = 0;
    std::cout << checkEmail << std::endl;

    std::cout << "CHECKEMAIL " << checkEmail << std::endl;

    int chk = 0;

    for (int i = 0; i < partLeft.length(); i++) {

        //if (qwer) break;
        for (int k = 0; k < symbolsLeft.length(); k++) {
            if (partLeft[i] != symbolsLeft[k]) {
                //checkEmail = 0;
                //std::cout << symbolsLeft[k] << "|" << std::endl;
            } else {
                chk +=1 ;
                //checkEmail = checkEmail + 1;
                //qwer = true;
                //break;
                //std::cout << "***" << std::endl;
            }
        }
    std::cout << "CHK " << chk << std::endl;
    std::cout << "CHECKEMAIL " << checkEmail << std::endl;
    if (chk == partLeft.length()) checkEmail = checkEmail + 1;

        //std::cout << checkEmail << std::endl;

        if (partLeft[i] == '.' && partLeft[i+1] == '.') checkEmail = 0;
            else checkEmail = checkEmail + 1;
    }
    /*std::cout << checkEmail << std::endl;/*
    for (int i = 0; i < partRight.length(); i++) {
        if (partLeft[i] == symbolsRight[i]) checkEmail = checkEmail + 1;
            else checkEmail = 0;
        if (partRight[i] != '.' && partRight[i+1] != '.') checkEmail = checkEmail + 1;
            else checkEmail = 0;
    }
    std::cout << checkEmail << std::endl;
    if (partLeft[0] != '.' && partLeft[partLeft.length()] != '.') {
        checkEmail = checkEmail + 1;
    } else checkEmail = 0;
    std::cout << checkEmail << std::endl;
    // проверить длинну строки +
    // проверить символы +
    // проверить точку в начале и конце +
    // две точки подряд
    // проверить две собаки

    /*if (checkEmail) std::cout << "YES";
        else std::cout << "NO";*/

    return checkEmail == 3 ? "YES" : "NO";
}



int main() {
    std::cout << "Checking the correctness of the email address!" << std::endl << std::endl;

    std::cout << "Enter email address:" << std::endl;
    std::cin >> email;

    std::cout << validatingEmail(email);

    std::cout << std::endl << "END";
}

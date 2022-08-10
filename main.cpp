#include <iostream>

bool checkEmail = false;
std::string email;
std::string symbols = "!#$%&'*+-/=?^_`{|}~.1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

/*int validatingEmail (std::string qwq) {
    std::cout << "CHECK " << qwq << std::endl;
    checkEmail = true;
    return 0;
}*/

std::string separatesPartEmail_1 (std::string email) {
    std::string partEmail_1;
    std::string partEmail_2;

    for(int i = 0; i < email.length(); i++) {
        if (email[i] != '@') {
            partEmail_1 += email[i];
        } else partEmail_2 = partEmail_1;
    }
    //std::cout << "P2 " << partEmail_2;
    return (partEmail_2);
}

std::string separatesPartEmail_2 (std::string email) {
    std::string partEmail_2;

    for(int i = 0; i < email.length(); i++) {
        if (email[i] == '@') partEmail_2 += email[i+1];
    }
    return (partEmail_2);
}

int main() {
    std::cout << "Checking the correctness of the email address!" << std::endl << std::endl;



    std::cout << "Enter email address:" << std::endl;
    std::cin >> email;

    //validatingEmail(email);

    std::cout << "Part_1 " << separatesPartEmail_1(email) << std::endl;
    std::cout << "Part_2 " << separatesPartEmail_2(email);

    /*if (checkEmail) std::cout << "Yes";
        else std::cout << "No";
    return 0;*/
    std::cout << std::endl << "END";
}

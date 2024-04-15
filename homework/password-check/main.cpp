#include <iostream>
#include <string>

#include "validation.hpp"

int main() {
    std::string password;
    std::string repeated_password;
    std::cout << "Set new password: ";
    std::cin >> password;
    std::cout << "Repeat password: ";
    std::cin >> repeated_password;
    auto result = checkPassword(password, repeated_password);
    std::cout << getErrorMessage(result) << '\n';

    return 0;
}

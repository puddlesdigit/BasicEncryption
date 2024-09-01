#include <iostream>
#include <string>
#include <cctype>

std::string getMessage() {
   std::string message;
   std::cout << "Enter a message: ";
   std::cin.ignore(); // clear the input buffer
   std::getline(std::cin, message);
   return message;
}

int getShift() {
    int shift;
    std::cout << "Enter a shift value: ";
    std::cin >> shift;
    return shift;
}

char getContinueChoice() {
    char choice;
    std::cout << "Do you want to encrypt/decrypt another message? (y/n)";

    std::cin >> choice;
    return choice;
}

std::string encrypt(const std::string& text, int shift) {
    std::string result = text;
    for (char &c : result) {
        if (std::isalpha(c)) {
            char offset = std::isupper(c) ? 'A' : 'a'; // Handles upper and lower case characters
            c = (c - offset + shift) % 26 + offset;
        }
    }
    return result;
}

int main() {
    char choice;
    do {
        std::string message = getMessage();
        int shift = getShift();

        std::string encrypted = encrypt(message, shift);
        std::cout << "Encrypted Message: " << encrypted << "\n";

        choice = getContinueChoice();
    } while(choice == 'y' || choice == 'Y');

    std::cout << "Exiting program. Goodbye!" << std::endl;
    return 0;
}

#include <iostream>
#include <string>
#include <cctype>
#include <limits>

std::string getMessage() {
   std::string message;
   std::cout << "Enter a message: ";
   std::getline(std::cin >> std::ws, message); // Ensure leading whitespace is ignored
   return message;
}

int getShift() {
    int shift;
    std::cout << "Enter a shift value: ";
    while (!(std::cin >> shift)) { // Validate input to ensure it's an integer
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid input. Please enter an integer: ";
    }
    return shift;
}

char getContinueChoice() {
    char choice;
    std::cout << "Do you want to encrypt/decrypt another message? (y/n): ";
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

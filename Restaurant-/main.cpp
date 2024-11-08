#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void appendToFile(const std::string& filename, const std::string& userInput) {
    std::ofstream outFile(filename, std::ios::app); // this opens the file to allow the append to occur

    if (outFile.is_open()) {
        outFile << userInput << std::endl; // this part checks to see if file properly opened. If so, it then appends user input and gives user feeback

        outFile.close();
        std::cout << "Data successfully appended to " << filename << std::endl;
    } else {
        std::cerr << "Error opening file for appending." << std::endl;
    }
}

void reverseFileContent(const std::string& inputFilename, const std::string& outputFilename) {

    std::ifstream inFile(inputFilename);
    std::ofstream outFile(outputFilename);

    if (inFile.is_open() && outFile.is_open()) {
        std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>()); // this should read the contents of the file to the string
        std::reverse(content.begin(), content.end()); // reversing the string
        outFile << content; // writing the reversed content to a new file


        inFile.close();
        outFile.close();
        std::cout << "Reversed content successfully written to " << outputFilename << std::endl;
    } else {
        std::cerr << "Error opening files for reading/writing." << std::endl;
    }
}

int main() {
    std::string userInput;
    const std::string inputFilename = "CSC450_CT5_mod5.txt";
    const std::string outputFilename = "CSC450_mod5_reverse.txt";

    // retrieving user input
    std::cout << "Enter text to append to the file: ";
    std::getline(std::cin, userInput);

    // append input to the file
    appendToFile(inputFilename, userInput);

    // this is to reverse the file contents and then store it in another file
    reverseFileContent(inputFilename, outputFilename);

    return 0;
}





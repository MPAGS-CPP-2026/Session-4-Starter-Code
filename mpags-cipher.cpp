#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    // Exercise 4.1
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    for (const std::string& argument : cmdLineArgs) {
        std::cout << argument << std::endl;
    }

    // Exercise 4.2
    for (const std::string& argument : cmdLineArgs) {
        if (argument == "-h" || argument == "--help") {
            std::cout << "Usage: ./mpags-cipher [options]\n";
            std::cout << "Options:\n";
            std::cout << "  -h, --help      Display help information\n";
        }
    }

    // Exercise 4.3
    std::string inputFile;
    std::string outputFile;

    for (int i = 1; i < argc; ++i) {
        const std::string& argument = cmdLineArgs[i];

        if (argument == "-h" || argument == "--help") {
            std::cout << "Help message\n";
            return 0;
        }

        else if (argument == "--version") {
            std::cout << "mpags-cipher version 1.0\n";
            return 0;
        }

        else if (argument == "-i") {
            if (i + 1 >= argc) {
                std::cerr << "Error: missing input filename\n";
                return 1;
            }

            inputFile = cmdLineArgs[++i];
        }

        else if (argument == "-o") {
            if (i + 1 >= argc) {
                std::cerr << "Error: missing output filename\n";
                return 1;
            }

            outputFile = cmdLineArgs[++i];
        }

        else {
            std::cerr << "Error: unknown argument " << argument << '\n';
            return 1;
        }
    }

    if (!inputFile.empty()) {
        std::cout << "Input filename: " << inputFile << '\n';
    }

    if (!outputFile.empty()) {
        std::cout << "Output filename: " << outputFile << '\n';
    }

    // Initialise variables
    char inputChar{'x'};
    std::string inputText;

    // loop over each character from user input
    while (std::cin >> inputChar) {
        // Uppercase alphabetic characters
        if (std::isalpha(inputChar)) {
            inputText += std::toupper(inputChar);
            continue;
        }

        // Transliterate digits to English words
        switch (inputChar) {
            case '0':
                inputText += "ZERO";
                break;
            case '1':
                inputText += "ONE";
                break;
            case '2':
                inputText += "TWO";
                break;
            case '3':
                inputText += "THREE";
                break;
            case '4':
                inputText += "FOUR";
                break;
            case '5':
                inputText += "FIVE";
                break;
            case '6':
                inputText += "SIX";
                break;
            case '7':
                inputText += "SEVEN";
                break;
            case '8':
                inputText += "EIGHT";
                break;
            case '9':
                inputText += "NINE";
                break;
        }

        // If the character isn't alphabetic or numeric, DONT add it
    }

    // Print out the transliterated text
    std::cout << inputText << std::endl;

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}

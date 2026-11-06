#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    // Initialise variables
    char inputChar{'x'};
    std::string inputText{""};
    const std::vector<std::string> cmdLineArgs { argv, argv+argc };
    std::string tempFileName{""};
    std::string inputFileName{""};
    std::string outputFileName{""};
    
    // Print out command line args

    for (auto it{cmdLineArgs.begin()}; it != cmdLineArgs.end(); it++) {
        if (*it == "-h" || *it == "--help") {
            std::cout << "options:" << std::endl << "    -h --help: displays this message" << std::endl << "    -v --version: displays the version of this code" << std::endl << "    -i --input: add name of input file" << std::endl << "    -o --output: add name of output file" << std::endl;
            return 0;

        } else if (*it == "-v" || *it == "--version") {
            std::cout << "version: 0.4.0" << std::endl; //0.4.0 = session 4
            return 0;

        } else if (*it == "-i" || *it == "--input"){
            tempFileName = *std::next(it);
            if (inputFileName != "") {
                //can't put two file name args
                std::cout << "you've tried to put two input args: " << inputFileName << " and " << tempFileName << std::endl;
                return 0;
            } else if (tempFileName[0] == '-') { 
                // if you put "-i -some_other_option" it will give you an error
                std::cout << "invalid file input name: " << tempFileName << std::endl;
                return 0;
            }
            inputFileName = tempFileName;
            std::cout << inputFileName << std::endl;

        } else if (*it == "-o" || *it == "--output"){
            tempFileName = *std::next(it);
            if (outputFileName != "") {
                //can't put two file name args
                std::cout << "you've tried to put two output args: " << outputFileName << " and " << tempFileName << std::endl;
                return 0;
            } else if (tempFileName[0] == '-') { 
                // if you put "-o -some_other_option" it will give you an error
                std::cout << "invalid file input name: " << tempFileName << std::endl;
                return 0;
            }
            outputFileName = tempFileName;
            std::cout << outputFileName << std::endl;
        }
    }

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

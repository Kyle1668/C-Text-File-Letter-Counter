#include "LetterTree.h"
#include <iostream>
#include <fstream>
#include <string>

void readFromStream(std::ifstream& targetFile);
std::string getFileURL();

int main()
{
    std::string fileURL = getFileURL();
    std::ifstream targetFile;
    targetFile.open(fileURL);

    if (targetFile.is_open())
    {
        readFromStream(targetFile);
    }
    else
    {
        std::cout << "File not found or error opening file." << std::endl;
    }

    targetFile.close();

    return 0;
}

// Global Methods

std::string getFileURL()
{
    std::cout << "\nEnter URL of the file you wish to read from. : ";
    std::string fileURL;
    std::getline(std::cin, fileURL);
    return fileURL;
}

void readFromStream(std::ifstream& targetFile)
{
    LetterTree alphabet;

    while (!targetFile.eof())
    {
        char output;
        targetFile >> output;
        alphabet.addLetter(output);
    }

    alphabet.printTree();
}
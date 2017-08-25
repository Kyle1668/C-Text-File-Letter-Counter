//
// Created by Kyle O'Brien on 8/24/17.
//

#include "LetterTree.h"

LetterTree::LetterTree()
{
    rootNode = nullptr;
    numNodes = 0;
}

// Class Methods

void LetterTree::addLetter(char newLetter)
{
    if (isalpha(newLetter))
    {
        newLetter = char(toupper(newLetter));
        if (!rootNode)
        {
            rootNode = new LetterNode;
            rootNode->letter = newLetter;
            rootNode->occurrences = 1;
            numNodes++;
        }
        else if (newLetter == rootNode->letter)
        {
            rootNode->occurrences++;
        }
        else
        {
            addLetter(newLetter, rootNode);
        }
    }
}

void LetterTree::addLetter(char newLetter, LetterNode*& parentNode)
{
    if (!parentNode)
    {
        parentNode = new LetterNode;
        parentNode->letter = newLetter;
        parentNode->occurrences = 1;
        numNodes++;
    }
    else if (newLetter == parentNode->letter)
    {
        parentNode->occurrences++;
    }
    else if (parentNode->letter < newLetter)
    {
        addLetter(newLetter, parentNode->leftChild);
    }
    else
    {
        addLetter(newLetter, parentNode->rightChild);
    }
}

int LetterTree::getSize()
{
    return numNodes;
}

void LetterTree::printTree()
{
    printTree(rootNode);
}

void LetterTree::printTree(LetterNode* parentNode)
{
    if (parentNode != nullptr)
    {
        printTree(parentNode->rightChild);
        std::cout << parentNode->letter << "'s = " << parentNode->occurrences << std::endl;
        printTree(parentNode->leftChild);
    }
}
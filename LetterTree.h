//
// Created by Kyle O'Brien on 8/24/17.
//

#ifndef C_TEXT_FILE_LETTER_COUNTER_LETTERTREE_H
#define C_TEXT_FILE_LETTER_COUNTER_LETTERTREE_H

class LetterTree {
private:
    struct LetterNode
    {
        char letter;
        long int occurrences = 0;
        LetterNode* leftChild = nullptr;
        LetterNode* rightChild = nullptr;
    };

    LetterNode* rootNode;
    int numNodes;

    // Recursive Auxiliary Functions
    void printTree(LetterNode* parentNode);
    void addLetter(char newLetter, LetterNode*& parentNode);

public:
    LetterTree();
    void addLetter(char newLetter);
    void printTree();
    int getSize();

};


#endif //C_TEXT_FILE_LETTER_COUNTER_LETTERTREE_H

#include <iostream>
#include "str.h"

char strget(const char *string, int index = 0) {
    return string[index];
}
int strlength(const char *string) {
    int i = 0;
    char currentChar = strget(string);
    while(currentChar != '\0') {
        i++;
        currentChar = strget(string, i);
    }
    return i;
}

str::str() {
    length = 0;
    string = new charNode;
    string->Get(0)->character = '\0';
}

str::str(const str &old) {
    length = old.length;
    string = new charNode;

    int currentIndex = 0;
    charNode *workingNode = string;

    while(currentIndex < length) {
        workingNode->character = old.string->Get(currentIndex)->character;
        workingNode->index = currentIndex;
        workingNode->next = new charNode;
        workingNode = workingNode->next;
        currentIndex++;
    }
}

str::str(const char *word) {
    length = strlength(word);
    string = new charNode;

    int currentIndex = 0;
    charNode *workingNode = string;

    while(currentIndex < length) {
        workingNode->character = strget(word, currentIndex);
        workingNode->index = currentIndex;
        workingNode->next = new charNode;
        workingNode = workingNode->next;
        currentIndex++;
    }
}
bool str::compare(const str string2) {
    for (int i = 0; i < string2.length;i++) {
        if(this->string->Get(i)->character != string2.string->Get(i)->character) {
            return false;
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &out, const str &s) {
    charNode *workingNode = s.string;
    for (int i = 0; i < s.length;i++) {
        out << workingNode->character;
        workingNode = workingNode->next;
    }
    return out;
}
str &operator+(str &s, const char c) {
    charNode *newChar = new charNode;
    charNode *end = s.string->Get(s.length);
    newChar->character = c;
    newChar->index = s.length;
    newChar->next = end;

    if(s.length == 0) {
        s.string = newChar;
    } else {
        s.string->Get(s.length-1)->next = newChar;
    }
    s.length = s.length+1;
    end->index++;
    return s;
}

charNode::charNode() {
    character = '\0';
    index = 0;
    next = nullptr;
}

charNode *charNode::Get(int ind) {
        try {
            if(index == ind) {
                return this;
            } else {
                if(this->next == nullptr) {
                    throw(0);
                }
                return this->next->Get(ind);
            }
        } catch(int errNum) {
            switch(errNum) {
                case 0:
                    std::cout << "Index out of range. " << ind << std::endl;
                    break;
            }
            return nullptr;
        }
    }
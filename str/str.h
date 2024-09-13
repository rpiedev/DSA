#include <ostream>

struct charNode {
    char character;
    int index;
    charNode *next = nullptr;
    charNode *Get(int ind);
    charNode();
};

struct str {
    charNode *string;
    int length;
    str();
    str(const str&);
    str(const char*);
    bool compare(const str);
};

std::ostream &operator<<(std::ostream &out, const str &s);
std::istream &operator>>(std::istream &in, str &s);
str &operator+(str &s, const char c);
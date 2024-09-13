#include "./../str/str.h"
#include <iostream>

str StringReverse(str input) {
    str output = str(input);
    for (int i = 0; i < input.length/2;i++) {
        output.string->Get(i)->character = input.string->Get(input.length-1 - i)->character;
        output.string->Get(input.length-1 - i)->character = input.string->Get(i)->character;
    }
    return output;
}


bool CheckPalindrome(str input) {
    str shortened = str("");
    str reversed = str("");
    for (int i = 0; i < input.length;i++) {
        if(input.string->Get(i)->character != ' ') shortened + tolower(input.string->Get(i)->character);
    }
    return shortened.compare(StringReverse(shortened));
}

int main() {
    str input = str("Take me in and get me reversed!");
    str output = StringReverse(input);
    str isPalindrome = str(CheckPalindrome(input) == 0 ? "NOT Palindrome" : "YES Palindrome");

    std::cout << "Original: " << input << std::endl;
    std::cout << "Reversed: " << output << std::endl;
    std::cout << isPalindrome << std::endl;
}

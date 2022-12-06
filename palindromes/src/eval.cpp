#include <iostream>
#include "palindromes.h"

int main(void) {
    ListNode* end = nullptr;
    ListNode* next = end;
    for (int ii = 1; ii <= 200; ii++) {
        ListNode* ln = new ListNode(ii, next);
        // printNode(ln);
        next = ln;
    }
    // for (int ii = 199; ii >= 1; ii--) {
        // ListNode* ln = new ListNode(ii, next);
        // printNode(ln);
        // next = ln;
    // }
    bool result = Palindrome().isPalindrome(next);
    std::cout << "Palindrome? " << (result ? "true" : "false") << std::endl;
    return 0;
}
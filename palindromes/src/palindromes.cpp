#include <iostream>
#include <vector>
#include "palindromes.h"

void printNode(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr << ": ";
        std::cout << "Val: " << curr->val;
        std::cout << " -> " << curr->next << std::endl;
        if (curr == curr->next) {
            std::cout << "ERROR: Self-referencing next ptr" << std::endl;
            return;
        }
        curr = curr->next;
    }
    std::cout << "Done printing node" << std::endl;
}

bool Palindrome::isPalindrome(ListNode* head) {
    std::vector<int> runningValues {};
    while (head) {
        runningValues.push_back(head->val);
        // std::cout << head->val << ", ";
        head = head->next;
    }
    std::cout << std::endl;
    int last = runningValues.size() - 1;
    int first = 0;
    while (last > first) {
        if (runningValues[first] != runningValues[last]) {
            return false;
        }
        first++;
        last--;
    }
    return true;
}
#include <string>
#include <vector>
#include "prefix.h"

using namespace std;

string Prefix::longestCommonPrefix(vector<string>& strs) {
    // At most 200 chars in a string
    string prefix = "";
    for (int ii = 0; ii < 200; ii++) {
        char prefixCandidate = '\0';
        for (auto str: strs) {
            if (ii >= str.length()) {
                // One string is done, no further common prefix possible
                return prefix;
            } else if (prefixCandidate == '\0') {
                // Set first char of this position
                prefixCandidate = str[ii];
            } else if (prefixCandidate != str[ii]) {
                // mismatch between strings, return current common prefix
                return prefix;
            }
        }
        prefix += prefixCandidate;
    }
    return prefix;
}

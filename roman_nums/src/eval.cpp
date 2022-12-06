#include <iostream>
#include <string>
#include "Roman.h"

int main(void) {
    Roman r = Roman();
    const std::string testCases[3] = {"III", "LVIII", "MCMXCIV"};
    for (int ii = 0; ii < 3; ii++) {
        const std::string testCase = testCases[ii];
        std::cout << "Testing " << testCase << ": ";
        const int converted = r.romanToInt(testCase);
        std::cout << converted << std::endl;

    }
    return 0;
}

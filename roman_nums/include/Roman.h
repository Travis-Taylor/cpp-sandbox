#pragma once
#include <string>

class Roman {
        static const int romanValuesSize = 7;
        const char romanValues[romanValuesSize] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        const int intValues[7] = {1, 5, 10, 50, 100, 500, 1000};
        static const int decrementorsSize = 3;
        const char decrementors[decrementorsSize] = {'I', 'X', 'C'};
        const char decrementorOptions[decrementorsSize][2] = {
            {'V', 'X'},
            {'L', 'C'},
            {'D', 'M'},
        };
        int findMember(char roman, const char array[], const int arrSize);
        bool isDecrementing(char s1, char s2);
        int romanToVal(char roman);
    public:
        int romanToInt(std::string s);
};

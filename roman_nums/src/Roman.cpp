#include <string>
#include <iostream>
#include "Roman.h"
// Find index of a given roman numeral from the specified array, returning -1 if not found
int Roman::findMember(char roman, const char array[], const int arrSize) {
    for (int ii = 0; ii < arrSize; ii++) {
        if (roman == array[ii]) {
            return ii;
        } 
    }
    return -1;
}

/* Determine if a given pair of roman numerals exhibits the "decrement" behavior
e.g. IX is 10 - 1 = 9
*/
bool Roman::isDecrementing(char s1, char s2) {
    const int decrementIndex = findMember(s1, decrementors, decrementorsSize);

    if (decrementIndex >= 0) {
        // The second numeral also has to be valid given the first
        const int secondIndex = findMember(s2, decrementorOptions[decrementIndex], 2);
        return secondIndex >= 0;
    }
    return false;
}

int Roman::romanToVal(char roman) {
    const int index = findMember(roman, romanValues, romanValuesSize);
    return intValues[index];
}

int Roman::romanToInt(std::string s) {
    int runningTotal = 0;
    const int romanLen = s.length();
    for (int ii = 0; ii < romanLen; ii++) {
        // check if we're in decrement case
        const char first = s[ii];
        if (ii + 1 <= romanLen && isDecrementing(first, s[ii + 1])) {
            const char second = s[ii + 1];
            const int subtotal = romanToVal(second) - romanToVal(first);
            // skip the next index, we counted it here
            ii++;
            runningTotal += subtotal;
        } else {
            // Just add the first digit and move on to the next one
            runningTotal += romanToVal(first);
        }
    }
    return runningTotal;
}

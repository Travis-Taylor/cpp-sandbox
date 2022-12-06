#include <iostream>
#include <string>
#include <vector>
#include "prefix.h"

using namespace std;

int main(void) {
    Prefix p = Prefix();
    cout << "Testing common prefixes:" << endl; 
    const vector<string> first = {"dog", "dodge", "does"};
    const vector<string> second = {"last", "loose", "laaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
    const vector<string> third = {"nothing", "in", "common"};
    const vector<string> fourth = {"", "some" };
    const vector<string> fifth = {"same", "same" };

    const vector<vector<string>> tests = {first, second, third, fourth, fifth};
    for (auto test: tests) {
        const string result = p.longestCommonPrefix(test);
        cout << "Testing [";
        for (auto str: test) {
            cout << str << ",";
        }
        cout << "]:" << endl;
        cout << "\"" << result << "\"" << endl;
    }
    return 0;
}
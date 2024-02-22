#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool containsCode(const string& transmission, const string& code) {
    size_t foundPos = transmission.find(code);
    return foundPos != string::npos;
}

bool isMirrored(const string& str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return str == reversed;
}

pair<int, int> findLongestMirroredCode(const string& transmission) {
    pair<int, int> longestCodePos(0, 0);
    int maxLength = 0;

    for (int i = 0; i < transmission.length(); i++) {
        for (int j = i + 1; j <= transmission.length(); j++) {
            string subStr = transmission.substr(i, j - i);
            if (isMirrored(subStr) && subStr.length() > maxLength) {
                maxLength = subStr.length();
                longestCodePos = make_pair(i + 1, j);
            }
        }
    }

    return longestCodePos;
}

pair<int, int> findLongestCommonSubstring(const string& transmission1, const string& transmission2) {
    int maxLength = 0;
    pair<int, int> longestSubstringPos(0, 0);

    for (int i = 0; i < transmission1.length(); i++) {
        for (int j = 0; j < transmission2.length(); j++) {
            int length = 0;
            while (i + length < transmission1.length() && j + length < transmission2.length() &&
                   transmission1[i + length] == transmission2[j + length]) {
                length++;
            }
            if (length > maxLength) {
                maxLength = length;
                longestSubstringPos = make_pair(i + 1, i + length);
            }
        }
    }

    return longestSubstringPos;
}

int main() {
    ifstream transmission1("transmission1.txt");
    ifstream transmission2("transmission2.txt");
    ifstream mcode1("mcode1.txt");
    ifstream mcode2("mcode2.txt");
    ifstream mcode3("mcode3.txt");

    if (!transmission1.is_open() || !transmission2.is_open() || !mcode1.is_open() || !mcode2.is_open() || !mcode3.is_open()) {
        cerr << "Error opening one or more files." << endl;
        return 1;
    }

    string transmission1Data, transmission2Data, mcode1Data, mcode2Data, mcode3Data;
    string line;

    while (getline(transmission1, line)) {
        transmission1Data += line + '\n';
    }
    while (getline(transmission2, line)) {
        transmission2Data += line + '\n';
    }
    while (getline(mcode1, line)) {
        mcode1Data += line + '\n';
    }
    while (getline(mcode2, line)) {
        mcode2Data += line + '\n';
    }
    while (getline(mcode3, line)) {
        mcode3Data += line + '\n';
    }

    transmission1.close();
    transmission2.close();
    mcode1.close();
    mcode2.close();
    mcode3.close();

    cout << boolalpha;
    cout << containsCode(transmission1Data, mcode1Data) << endl;
    cout << containsCode(transmission1Data, mcode2Data) << endl;
    cout << containsCode(transmission1Data, mcode3Data) << endl;
    cout << containsCode(transmission2Data, mcode1Data) << endl;
    cout << containsCode(transmission2Data, mcode2Data) << endl;
    cout << containsCode(transmission2Data, mcode3Data) << endl;

    pair<int, int> longestCodePos1 = findLongestMirroredCode(transmission1Data);
    pair<int, int> longestCodePos2 = findLongestMirroredCode(transmission2Data);

    cout << longestCodePos1.first << " " << longestCodePos1.second << endl;
    cout << longestCodePos2.first << " " << longestCodePos2.second << endl;

    pair<int, int> longestSubstringPos = findLongestCommonSubstring(transmission1Data, transmission2Data);
    cout << longestSubstringPos.first << " " << longestSubstringPos.second << endl;

    return 0;
}

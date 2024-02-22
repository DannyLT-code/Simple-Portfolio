#include <iostream>
#include <string>

using namespace std;

string LongestCommonSubstring(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();

    int longest[m + 1][n + 1];
    int len = 0;
    int row = 0, col = 0;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                longest[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1]) {
                longest[i][j] = longest[i - 1][j - 1] + 1;
                if (len < longest[i][j]) {
                    len = longest[i][j];
                    row = i;
                    col = j;
                }
            } else
                longest[i][j] = 0;
        }
    }

    if (len == 0) {
        return "There exists no common substring";
    }

    string final_str = str1.substr(row - len, len);
    return final_str;
}

int main() {
    string str1 = "helloworld";
    string str2 = "worldbook";

    string longestCommonSubstr = LongestCommonSubstring(str1, str2);

    cout << "Longest Common Substring: " << longestCommonSubstr << endl;

    return 0;
}

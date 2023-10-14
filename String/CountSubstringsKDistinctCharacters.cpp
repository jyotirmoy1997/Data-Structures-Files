/* The Idea is to check how many unique characters can be clubbed together to form 
a substring. */

// https://www.geeksforgeeks.org/count-number-of-substrings-with-exactly-k-distinct-characters/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int countSubStrings(string s, int k) {
    int n = s.length();
    int count = 0;

    for (int left = 0; left < n; left++) {
        unordered_map<char, int> charCount;
        int uniqueCount = 0;

        for (int right = left; right < n; right++) {
            if (charCount[s[right]] == 0) {
                uniqueCount++;
            }

            charCount[s[right]]++;

            if (uniqueCount == k) {
                count++;
            } else if (uniqueCount > k) {
                break;
            }
        }
    }

    return count;
}

int main() {
    string s = "aacfssa";
    cout << countSubStrings(s, 3);

    return 0;
}

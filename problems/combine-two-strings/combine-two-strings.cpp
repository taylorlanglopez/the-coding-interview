/* # Combine Two Strings

We are given 3 strings: str1, str2, and str3. Str3 is said to be a shuffle of str1 and str2 if it can be formed by interleaving the characters of str1 and str2 in a way that maintains the left to right ordering of the characters from each string. For example, given str1="abc" and str2="def", str3="dabecf" is a valid shuffle since it preserves the character ordering of the two strings. So, given these 3 strings write a function that detects whether str3 is a valid shuffle of str1 and str2.

## Source

[http://www.ardendertat.com/2011/10/10/programming-interview-questions-6-combine-two-strings/](http://www.ardendertat.com/2011/10/10/programming-interview-questions-6-combine-two-strings/) */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

bool check_shuffle(string s, string t, string u) {
    char* s_curr = &s[0];
    char* t_curr = &t[0];
    for(auto c : u) {
        if(c != *s_curr && c != *t_curr) return false;
        else {
            if(c == *s_curr) {
                s_curr++;
                continue;
            }
            if(c == *t_curr) {
                t_curr++;
                continue;
            }
        }
    }
    return true;
}

int main() {
    cout << boolalpha << check_shuffle("abc","def","dabecf") << "\n";
    cout << boolalpha << check_shuffle("abc","def","fabecd") << "\n";
}

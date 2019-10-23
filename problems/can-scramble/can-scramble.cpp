/* # CanScramble

Write a function that returns true if one string can be formed out of another by
reordering ("scrambling") the characters.

For example:

```
can_scramble("abc", "cba") -> true
can_scramble("aab", "bba") -> false
``` */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool can_scramble(string a, string b) {
    vector < pair<char,int> > a_cont;
    vector < pair<char,int> > b_cont;
    transform(a.begin(),a.end(),a.begin(),::tolower);
    transform(b.begin(),b.end(),b.begin(),::tolower);
    for(int i = 0; i < 26; i++) {
        a_cont.push_back(make_pair(97+i,0));
        b_cont.push_back(make_pair(97+i,0));
    }
    for(auto i : a) {
        a_cont[(i  % 97)].second++; 
    }
    for(auto i : b) {
        b_cont[(i  % 97)].second++; 
    }
    return equal(a_cont.begin(),a_cont.end(),b_cont.begin());
}

int main() {
    cout << boolalpha << can_scramble("abc","cba") << endl;
    cout << boolalpha << can_scramble("aab","bba") << endl;
    return 0;
}

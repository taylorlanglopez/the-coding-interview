/* Atbash is a simple substitution cipher originally for the Hebrew alphabet, but possible with any known alphabet.
```
 Original:   abcdefghijklmnopqrstuvwxyz  
 Substitute: ZYXWVUTSRQPONMLKJIHGFEDCBA
```

So you would substitute "a" in your input text with "Z" in your output text, "b" with "Y", "c" with "X" and so forth.

A few English words also 'Atbash' into other English words: "irk"="rip", "low"="old", "hob"="sly", "hold"="slow", "holy"="slob", "horn"="slim", "glow"="told", "grog"="tilt" and "zoo"="all". Some other English words Atbash into their own reverses, e.g., "wizard" = "draziw."
(https://en.wikipedia.org/wiki/Atbash) */

#include <iostream>
#include <cstdlib>
#include <string>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map <int, int> charMap = {};

void display_map(unordered_map <int, int> cMap) {
    for(auto const pair : cMap) {
        cout << "{" << pair.first << ", " << pair.second << "}" << endl;
    }
}

void build_map(string t, string s) {
    for(int i = 0; i < t.size(); ++i) {
        charMap.insert({t[i],s[i]});
    }
    for(int j = 0; j < s.size(); ++j) {
        charMap.insert({s[j],t[j]});
    }
}

void atbash(string input) {
    string output = "";
    for(auto i : input) {
        auto search = charMap.find(i);
        if(search != charMap.end()) {
            output += search->second;
        }
    }
    cout << output << endl;
}

int main() {
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string upper = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    build_map(lower,upper);
    atbash("hello world");
    atbash("goodbye world");
    atbash(lower);
}


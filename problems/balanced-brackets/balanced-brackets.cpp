/* # Balanced Brackets

Write a function that accepts a string consisting entiring of brackets (`[](){}`) and returns whether it is balanced. Every "opening" bracket must be followed by a closing bracket of the same type. There can also be nested brackets, which adhere to the same rule.

```js
f('()[]{}(([])){[()][]}') // true
f('())[]{}') // false
f('[(])') // false
``` */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

vector <char> rightBracks = { '}', ']', ')' };
vector <char> leftBracks  =  { '(', '{', '[' };

bool testBalance(string brackets) {
    stack <char> s;
    for(auto i : brackets) {
        auto findL = find(leftBracks.begin(),leftBracks.end(),i);
        auto findR = find(rightBracks.begin(),rightBracks.end(),i);
        if(findL != leftBracks.end()) {
            s.push(i);
        }
        if(findR != rightBracks.end()) {
            if(s.empty()) return false;
            char c = s.top();
            s.pop();
            if( i == '}' && c != '{' ) return false;
            if( i == ')' && c != '(' ) return false;
            if( i == ']' && c != '[' ) return false;
        }
    }
    return true;
}

int main() {
    string bbTest = "[(])"; 
    string bbTest1 = "()[]{}(([])){[()][]}";
    string bbTest2 = "())[]{}";
    cout << boolalpha << testBalance(bbTest) << endl;
    cout << boolalpha << testBalance(bbTest1) << endl;
    cout << boolalpha << testBalance(bbTest2) << endl;
}

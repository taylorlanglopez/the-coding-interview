/* Calculate the number of "loops" in a number.
A number has a loop when it has a closed circle when you draw it, so
6 has one loop, 1 has no loop and 8 has two loops.
So 2876 has three loops */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <string>

using namespace std;

vector < pair<char, int> > loops =  {{'0',1}, {'6',1}, {'8',2}, {'9', 1}};

int count_loops(int num) {
    string x = std::to_string(num);
    int ret_val = 0;
    for(auto i : x) {
        for(auto j : loops) {
            if(j.first == i) {
                ret_val += j.second;
            }
        } 
    }
    return ret_val;
}

int main() {
    cout << count_loops(2876) << endl;
    cout << count_loops(8888) << endl;
}

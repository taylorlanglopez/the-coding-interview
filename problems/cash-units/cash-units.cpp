/* # Cash units

Write a function that returns the number of each cash-unit that fits into the given input by achieving the
smallest denomination.

Given cash units are:

* 500
* 200
* 100
* 50
* 20
* 10
* 5
* 2
* 1
* 0.5
* 0.2
* 0.1
* 0.05
* 0.02
* 0.01 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void display_vec(vector < pair<float,int> > v, float sum) {
    cout << "Total: " << sum << endl;
    for(auto i : v) {
        if(i.second > 0) {
            cout << i.first << "::" << i.second << endl;
        }
    }
    cout << endl;
}

void cash_units(float sum) {
    vector < pair<float, int> > denom_pair = {{500,0}, {200, 0}, {100,0}, {50, 0}, {20, 0}, {10, 0}, {5, 0}, {2, 0}, {0.5, 0}, {0.2, 0}, {0.1, 0}, {0.05, 0}, {0.02, 0}, {0.01, 0}};
    float copy_sum = sum;
    float s_cents = sum * 100;
    for(auto& i : denom_pair) {
        float d_cents = i.first * 100;
        int count = (s_cents/d_cents);
        i = make_pair(i.first,count);
        s_cents = s_cents - (d_cents * count);
    }
    display_vec(denom_pair, copy_sum);
}

int main() {
    cash_units(100.25);
    cash_units(1337.2501);
    cash_units(1972.78);
}

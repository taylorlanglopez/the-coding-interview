/* # Bubble Sort

Implement the [bubble sort algorithm](http://en.wikipedia.org/wiki/Bubble_sort). */
#include <climits>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>

using namespace std;

template <typename T>
std::ostream &operator <<(std::ostream &os, std::vector<T> vec) {
    os << "{";
    std::copy(vec.begin(),vec.end()-1,std::ostream_iterator<T>(os, ","));
    os << vec.back();
    os << "}" << endl;
    return os;
}

bool sorted(const vector <int> &arr) {
    int comp = INT_MIN;
    for(auto i : arr) {
        if(i < comp) {
            return false;
        } 
        comp = i;
    }
    return true;
}

void bubble_sort(vector <int> &arr) {
    while(!sorted(arr)) {
        for(int i = 0; i < arr.size()-1; i++) {
            int j = i+1;
            if(arr[i] > arr[j]) {
                swap(arr[i],arr[j]);
            }
        }
    }
}


int main() {
    vector <int> arr;
    for(int i = 0; i < 25; i++) {
       arr.push_back((rand() % (i + 1337))); 
    }
    cout << arr;
    bubble_sort(arr);
    cout << arr;
}

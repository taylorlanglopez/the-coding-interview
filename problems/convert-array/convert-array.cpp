/* # Convert Array

Given an array `[a1, a2, ..., aN, b1, b2, ..., bN, c1, c2, ..., cN]`  convert it to `[a1, b1, c1, a2, b2, c2, ..., aN, bN, cN]` in-place without using constant extra space.

## Source

[http://www.ardendertat.com/2011/10/18/programming-interview-questions-9-convert-array/](http://www.ardendertat.com/2011/10/18/programming-interview-questions-9-convert-array/) */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void merge(string arr[], int s, int m, int e) {
    int s2 = m + 1;
    if(arr[m] <= arr[s2]) return;
    while(s <= m && s2 <= e) {
        if(arr[s] <= arr[s2]) s++;
        else {
            string value = arr[s2];
            int idx = s2;

            while(idx != s) {
                arr[idx] = arr[idx-1];
                idx--;
            }
            arr[s] = value;
            s++;
            m++;
            s2++;
        }
    }
}

void mergeSort(string arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main() {
    string arr[] = { "a1", "b1", "d1", "c1", "a2", "c3", "d2" };
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,arrSize-1);
    for(int i = 0; i < arrSize - 1; ++i) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    return 0;
}

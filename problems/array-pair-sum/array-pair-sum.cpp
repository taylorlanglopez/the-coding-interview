/* # Array Pair Sum

Given an integer array, output all pairs that sum up to a specific value k. Consider the fact that the same number can add up to `k` with its duplicates in the array.

> For example the array is [1, 1, 2, 3, 4] and the desired sum is 4. Should we output the pair (1, 3) twice or just once? Also do we output the reverse of a pair, meaning both (3, 1) and (1, 3)? Let’s keep the output as short as possible and print each pair only once. So, we will output only one copy of (1, 3). Also note that we shouldn’t output (2, 2) because it’s not a pair of two distinct elements.

## Example

```
f(10, [3, 4, 5, 6, 7]) // [ [6, 4], [7, 3] ]
f(8, [3, 4, 5, 4, 4]) // [ [3, 5], [4, 4], [4, 4], [4, 4] ]
```

## Source
[http://www.ardendertat.com/2011/09/17/programming-interview-questions-1-array-pair-sum/](http://www.ardendertat.com/2011/09/17/programming-interview-questions-1-array-pair-sum/) */

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <set>
#include <array>
#include <climits>

using namespace std;

vector <int> combo;
vector <pair <int,int> > combos;

void display_set(multiset < pair <int,int> > s) {
    for(auto i : s) {
        cout << "{" << i.first << ", " << i.second << "} ";
    }
    cout << endl;
}

void add_num_with_uid(const vector <int> arr, vector < pair<int,int> >  &arr_w_uid) {
    int uid_local = 0;
    for(auto i : arr) {
        arr_w_uid.push_back(make_pair(i,uid_local++));
    }
}

void gatherCombo(vector <int> combo) {
    static int count = 0;
    pair <int,int> retval;
    for(int i = 0; i < combo.size(); ++i) {
        if(i == 0) retval.first = combo[i];
        if(i == 1) retval.second = combo[i];
    }
    combos.push_back(retval);
}

void go(int offset, int k, vector <int> uid_arr) {
    if(k == 0) {
       gatherCombo(combo);
       return;
    }
    for(int i = offset; i <= uid_arr.size() - k; ++i) {
        combo.push_back(uid_arr[i]);
        go(i+1,k-1,uid_arr);
        combo.pop_back();
    }
}

void permute_all_pairs (vector < pair<int,int> > &arr_w_uid) {
    sort(arr_w_uid.begin(),arr_w_uid.end());
    vector <int> uid_arr;
    for(auto i : arr_w_uid) {
        uid_arr.push_back(i.second); //Get uid's in sorted order
    }
    combos.clear();
    combo.clear();
    go(0,2,uid_arr);
    //display_pair_vector(combos); #debuglyfe
}

void f(const int desiredSum, vector <int> arr, multiset < pair<int,int> > &s) {
    vector < pair<int,int> > arr_w_uid = {};
    add_num_with_uid(arr,arr_w_uid);
    permute_all_pairs(arr_w_uid);
    //All pairs stored in combos, which means that we have to clear combos before we call "go" everytime
    //At this point we all all UID's saved in pairs to the combos vector
    //So now that we all all the UID's in all permuted pairs for the entire vector
    //We can simply go through each pair, see if it sums to the desired sum, 
    //and add it to a multiset then display it
    for(auto i : combos) {
        int idxL = i.first;
        int idxR = i.second;
        int idxLVal = arr_w_uid[idxL].first;
        int idxRVal = arr_w_uid[idxR].first;
        if(idxLVal + idxRVal  == desiredSum) {
            s.insert(make_pair(idxLVal,idxRVal));
        }
    }
}

int main()  {
    multiset < pair<int,int> > s1,s2,s3;
    vector <int> arr = {3,4,5,6,7};
    vector <int> arr2 = {3,4,5,4,4};
    vector <int> arr3 = {1,2,3,4,5,6,7,8,9,10};
    int ds1 = 10, ds2 = 8, ds3 = 11;
    f(ds1,  arr, s1);
    display_set(s1);
    f(ds2, arr2, s2);
    display_set(s2);
    f(ds3, arr3, s3);
    display_set(s3);
}

/* # Find Missing Element

There is an array of non-negative integers. 
A second array is formed by shuffling the elements of the first array and deleting a random element. 
Given these two arrays, find which element is missing in the second array.

## Source

[http://www.ardendertat.com/2011/09/27/programming-interview-questions-4-find-missing-element/](http://www.ardendertat.com/2011/09/27/programming-interview-questions-4-find-missing-element/)
*/

#include <iostream>
#include <cstdlib>
#include <map>
#include <random>
#include <algorithm>
#include <vector>

void find_missing_element(std::vector <int> x, std::vector <int> y) {
    std::map <int, int> m;
    for(auto i : x) {
        m.insert(std::make_pair(i,1));
    }
    for(auto i : y) {
        auto f = m.find(i);
        if(f == m.end()) {
            std::cout << "The missing element is -> " << i << std::endl;
        }
    }
}

void disp_vec(std::vector <int> arr) {
    for(int i : arr) {
        std::cout << i << " ";
    }
}

int main() {
    std::vector <int> arr1 = {1,2,3,4,5,6,7,8,9,10};
    std::vector <int> arr2 = arr1;

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(arr1.begin(),arr1.end(),g);

    arr1.erase(arr1.begin()+7); //Delete the 7th element after the shuffle
    disp_vec(arr1);
    std::cout << "<- Shuffled Array \n";
    disp_vec(arr2);
    std::cout << "<- Original Array \n";
    find_missing_element(arr1,arr2);
}
/* # Find Even Occurring Element

Given an integer array, one element occurs even number of times and all others have odd occurrences. Find the element with even occurrences.

## Source

[http://www.ardendertat.com/2011/11/29/programming-interview-questions-18-find-even-occurring-element/](http://www.ardendertat.com/2011/11/29/programming-interview-questions-18-find-even-occurring-element/)
*/

#include <map>
#include <iostream>
#include <cstdlib>
#include <utility>
#include <array>
#include <experimental/array>

//Compile with g++ -std=c++14 or greater (c++17, etc.) or gcc will be very angry about std::experimental

template <std::size_t SIZE>
void even_occuring_element(std::array <int, SIZE> arr) {
    std::map <int,int> m;
    for(auto i : arr) {
        auto f = m.find(i);
        if(f == m.end()) {
            m.insert(std::make_pair(i,1));
        } else {
            ((*f).second)++;
        }
    }
    for(auto i : m) {
        if(i.second % 2 == 0) {
            std::cout << "Element that occurs evenly is -> " << i.first << std::endl;
            std::cout << "It occurs exactly " << i.second << " times. " << std::endl;
        }
    }
} 

int main() {
    decltype(auto) arr = std::experimental::make_array(2, 3, 4, 5, 7, 7, 7, 6, 6, 6, 6, 6, 6, 11, 11, 11, 9, 9, 9, 9, 9, 12);
    even_occuring_element(arr);
}
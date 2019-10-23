/* # CSV Parsing

Write a function that accepts a string as it's only argument. 
The string consists of comma-separated values and all values are either an integer or a string. 
Return an array of the parsed input string.

```js
f('2,6,3,2,5') 
// [ 2, 6, 3, 2, 5 ]

f('"pears","apples","walnuts","grapes","cheese,cake"') 
// [ "pears", "apples", "walnuts", "grapes", "cheese,cake" ]

f('1,"Que?","Kay?",2,"Si.","Sea? Kay, sea?","No, no, no. Que... ‘what’.",234,"Kay Watt?","Si, que ‘what’.","C.K. Watt?",3,"Yes!","comma,comma, comma , :)"') // [ 1, "Que?", "Kay?", 2, "Si.", "Sea? Kay, sea?", "No, no, no. Que... ‘what’." 234, "Kay Watt?", "Si, que ‘what’.", "C.K. Watt?", 3, "Yes!", "comma,comma, comma , :)" ]
``` */

//Templates and type traits?

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <any>
#include <sstream>

template <typename T>
void print_vec(std::vector <T> v) {
    std::cout << "{";
    std::copy(v.begin(),v.end()-1,std::ostream_iterator<T>(std::cout,","));
    std::cout << v.back() << "}" << std::endl;
}

std::vector <std::string> parse_str_to_arr(std::string toParse) {
    std::stringstream ss;
    std::vector <std::string> storage;
    bool respect_quote = false;
    for(auto i : toParse) {
        if(i == '"') respect_quote = !respect_quote;
        if(i == ',' && respect_quote) {
            storage.push_back(ss.str());
            ss.str(std::string());
        } else {
            ss << i;
        }
    }
    if(!ss.str().empty()) storage.push_back(ss.str());
    return storage;
}

int main() {
    print_vec(parse_str_to_arr(std::string("2,6,3,2,5")));
    print_vec(parse_str_to_arr(std::string("\"pears\",\"cheese,cake\",\"apples\",\"walnuts\",\"grapes\"")));
}
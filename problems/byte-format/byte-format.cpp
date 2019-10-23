/* # Byte String

Convert a number to a string that represents a rounded size in bytes.

## Example

```
f(156833213) // => "149.57 MB"
f(8101)      // => "7.91 KB"
f(12331, 3)  // => "12.042 KB"
```

## Source

By [Riga](https://github.com/riga). */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector <string> count_map = { "B", "KB", "MB", "GB", "TB", "PB" };

void f(int size, int prec = 2) {
    //Size in bytes 
    int count = 0;
    float size_f = size;
    do {
        size_f /= 1024.0;
        count++;
    } while (size_f > 1024);
    
    stringstream ss;
    string breakStr = to_string(size_f);
    int prec_count = 0;
    bool plato = false;
   
    for(auto i : breakStr) {
        ss << i;
        if(plato) {
            prec_count++;
            if(prec_count == prec) break;
        }
        if(i == '.') {
            plato = true;
        }
    }
    
    ss << " " << count_map[count];
    cout << ss.str() << endl;
}


int main() {
    f(156833213);
    f(8101);
    f(12331, 3);
}

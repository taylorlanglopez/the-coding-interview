#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;


int numAnagramAppearance(string parent, string child) {
    int match_count = 0;
    std::sort(child.begin(),child.end());
    for(int c = 0; c < parent.size(); c++) {
        string captureSubStr = parent.substr(c, child.size());
        std::sort(captureSubStr.begin(),captureSubStr.end());
        if ( !captureSubStr.compare(child) ) match_count++;
    }
    return match_count;
}


int main() {
    std::cout <<  numAnagramAppearance("AdnBndAndBdaBn", "dAn") << std::endl;
    std::cout <<  numAnagramAppearance("AbrAcadAbra", "cAda") << std::endl;
}

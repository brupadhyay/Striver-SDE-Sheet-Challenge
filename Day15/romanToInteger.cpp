#include <iostream>
#include <map>
using namespace std;

/**
 * TC - O(n) { linear time complexity }
 * SC - O(1) { map is constant having 7 fixed-pairs irrespective of string s}
*/

int romanToInt(string s) {
    map<char, int> romanIntegerMap{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                    {'C', 100}, {'D', 500}, {'M', 1000}};

    int integerAnswer = romanIntegerMap[s[0]];

    for(int i = 1;i<s.size();i++){
        if(romanIntegerMap[s[i]] > romanIntegerMap[s[i-1]]){
            integerAnswer -= romanIntegerMap[s[i-1]];
            integerAnswer += romanIntegerMap[s[i]] - romanIntegerMap[s[i-1]];
        } else {
            integerAnswer += romanIntegerMap[s[i]];
        }
    }

    return integerAnswer;
}

int main(){
    string s = "LXXIX";
    cout << "integer value of "<< s << " is " << romanToInt(s) << endl;
    return 0;
}
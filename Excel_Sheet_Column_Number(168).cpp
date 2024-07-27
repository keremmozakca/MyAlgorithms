#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string alphabet[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        string result = "";

        while (columnNumber > 0) {
            int kalan = (columnNumber - 1) % 26;
            result = alphabet[kalan] + result;
            columnNumber = (columnNumber - 1) / 26;
        }

        return result;
    }
}
};

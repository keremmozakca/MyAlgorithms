#include <iostream>
using namespace std;
class Solution {
private:
int convertToInt(char letter) {
    switch (letter) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}
public:
    int romanToInt(string s) {
      int last = 1;
      int sum = 0;
      int i = s.size()-1;
      char rletter;
      while(i>=0){
        rletter = s[i];
        if(convertToInt(rletter)>last){
          last = convertToInt(rletter);
          sum+=last;
        }else if(convertToInt(rletter)==last){
          sum+=last;
        }
        else{
          sum-=convertToInt(rletter);
        }
        i--;
      }
      return sum;
    }

    
};
int main() {
    Solution sol;
    cout << sol.romanToInt("III") << endl; // Output: 3
    cout << sol.romanToInt("IV") << endl; // Output: 4
    cout << sol.romanToInt("IX") << endl; // Output: 9
    cout << sol.romanToInt("LVIII") << endl; // Output: 58
    cout << sol.romanToInt("MCMXCIV") << endl; // Output: 1994
    string a;
    cout<<"Bir Roman sayısı girin: ";
    cin>>a;
    cout<< sol.romanToInt(a)<<endl;
    return 0;
}

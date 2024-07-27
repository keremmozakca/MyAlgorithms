#include<iostream>
using namespace std;
class Solution {
public:
    long long divide(int dividend, int divisor) {
       bool minus = false;
       if(dividend<0 && divisor>0){minus=true; dividend*=-1;}
       else if(dividend>0 && divisor<0){minus=true; divisor*=-1;}
       else{minus=false;}
       if (divisor == 0) {
           return 2147483648;
       }
       if (dividend == -2147483648 && divisor == -1) {
           return 2147483648;
       }
       long long int i = 0; // changed int to long long int
       long long int tempDividend = dividend; // added tempDividend variable
       for( ;tempDividend>=divisor;i++) { // used tempDividend
            tempDividend -= divisor;
            if(tempDividend<0){
                i--;
                break;
            }
       }
       if(minus){
           return -1 * i;
       }else{
           return i;
       }
    }
};
int main(){
    Solution s;
    cout<<s.divide(10,3)<<endl; // 3
    cout<<s.divide(7,-3)<<endl; // -2
    cout<<s.divide(-2147483648,-1)<<endl; // 2147483647
}

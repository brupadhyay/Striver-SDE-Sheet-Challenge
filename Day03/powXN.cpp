/*
BRUTE FORCE - linearly traverse 1 to n and multiply
TC - O(n)
SC - O(1)
*/
#include <iostream>
using namespace std;

double myPow(double x, int n) {
    double ans = 1.0;
    long long power = n;
    if( power<0) power = -1*power;
    
    for(int i=0;i<power;i++){
        ans = ans*x;
    }
    if(n<0) return (double)(1/ans);
    return ans;
}

/*
OPTIMAL APPROACH - using binary exponentiation
TC - O(logn)
SC - O(1)
because every time we divide n by 2 and if it's odd we make it even
*/

double myPow(double x, int n) {
    double ans = 1.0;
    long nn = n;
    if(n < 0) nn = -1*nn;

    while(nn > 0){
        if(nn % 2 == 0){
            x = x*x;
            nn >>= 1;
        } else {
            ans *= x;
            nn -= 1;
        }
    }
    if(n < 0) return (double)1.0/(double)ans;
    return ans;
}

int main(){
    int n = 10;
    int x = 2;

    cout << "pow(2, 10) is "<< myPow(x, n) << endl;

    return 0;
}
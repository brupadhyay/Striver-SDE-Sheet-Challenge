#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


/*
Two variations of the same questions 
1. simple nth root
2. nth root till d decimal places
*/

// * For simple nth root
// ? TC - O(NlogM) { where logM is for binary search and N because each time we find muliple of mid N times}
// ? Sc - O(1)

int mulitplier(int num, int n){
    int ans = 1;
    for(int i = 1;i<=n;i++){
        ans = ans*num;
    }
    return ans;
}

int findNthRoot(int n, int m) {
  int low = 1, high = m;
  while(low <= high){
    int mid = (low + high)/2;
    int powerOfMid = mulitplier(mid, n);
    if(powerOfMid == m) return mid;
    else if(powerOfMid < m){
      low = mid + 1;
    } else high = mid - 1;
  }
  return -1;
}



// if asked find answer till d decimals
/*if d = 2 then 1 1.01 1.02 ... 1.99 2 so in each two numbers there are 100 numbers
if m = 27 then total search space 27*10^2 = 2700
*/
/*
TC - O(Nlog(M * 10^d))
SC - O(1)
*/
double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

void getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-2; 
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    
    cout << n <<"th root of "<< m <<" is "<< std::setprecision(2) << fixed << low<<endl; 
}


int main(){
    int n = 3;
    int m = 27;
    cout << "nth root is "<< findNthRoot(n, m)<< endl;
    getNthRoot(n, m);

    return 0;
}
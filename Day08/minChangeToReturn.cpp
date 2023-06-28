/*Find minimum number of coins
Problem Statement: Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change.*/

#include <iostream>
#include <vector>
using namespace std;

int findMinimumCoins(int amount){
    // start from maximum eventually notes will be minimum
    int notes[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int coinsRequired = 0;
    int currNote = 0;
    vector<pair<int,int>> change;
    while(amount){
        int coin = notes[currNote];
        int freq = amount / coin;
        if(freq > 0){
            change.push_back({coin, freq});
        }
        coinsRequired += freq;
        amount = amount%notes[currNote];
        currNote++;
    }

    cout << "The notes which we return are as follows\n";

    for(auto it: change){
        cout << "Rs "<< it.first << ", freq: " << it.second << "\n";
    }

    return coinsRequired;
}

int main(){
    int V = 49;
    cout << "The minimum exhange coins are "<< findMinimumCoins(V) << endl;

    return 0;
}


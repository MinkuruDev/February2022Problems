#include <bits/stdc++.h>

using namespace std;

bool prime[1000001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // eratosthenes sieve
    for(int i = 2; i<=1000000; i++){
        if(!prime[i]){
            for(int j = i*i; j<=1000000; j+=i){
                prime[j] = true;
            }
        }
    }
    return 0;
}
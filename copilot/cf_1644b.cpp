#include <bits/stdc++.h>

using namespace std;
int a[50];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testCase;
    cin >> testCase;
    while(testCase--){
        int n;
        cin >> n;
        for(int i = 0; i<n; i++){
            a[i] = n - i;
        }

        int _n = n;
            do{
                bool antiFibonacci = true;
                for(int i = 2; i<n; i++){
                    if(a[i] == a[i-1] + a[i-2]){
                        antiFibonacci = false;
                        break;
                    }
                }

                if(antiFibonacci){
                    for(int i = 0; i<n; i++){
                        cout << a[i] << " ";
                    }
                    cout << endl;
                    _n--;
                }
            }while (prev_permutation(a, a+n) && _n);
        
    }
    return 0;
}
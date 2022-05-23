/***************************************************\
*                                                   *
*   000   000       111        00000       11111    *
*   0000 0000      11 11       00  00     11        *
*   00 000 00     11   11      00000       11111    *
*   00     00    111111111     00  00          11   *
*   00     00   11       11    00   00     11111    *
*                                                   *
\***************************************************/

#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fow(i,a,b) for(auto i = a; i<b; i++)
#define rep(i,a,b) for(auto i = a; i<=b; i++)
#define red(i,a,b) for(auto i = a; i>=b; i--)
#define repa(i,a) for(auto i: a)
#define db(x) cout << #x << " = " << x << endl
#define el cout << endl
#define getBit(n,i) ((n>>i)&1)
#define mod 1000000007
#define MAX 100000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/// Global variable and input, init ///
void inputAndInit(){

}

/// Process ///
void solve(int testIndex){
    int pre,n,temp;
    vector<int> a, cnt(101,0);
    cin >> n;
    cin >> pre;
    a.push_back(pre);
    fow(i,1,n){
        cin >> temp;
        if(temp != pre){
            a.push_back(temp);
            pre = temp;
        }
    }
    //fill_n(cnt, 100, 0);
    repa(i, a){
        cnt[i]++;
    }
    int max_i = 0;
    fow(i,1,101){
        if(cnt[i] > cnt[max_i]) max_i = i;
    }
    int total = 1;
    fow(i,0,101){
        if(i != max_i) total += cnt[i];
    }

    cout << "Case " << testIndex+1 << ": " << total << endl;
}

void test(){

}

int main(){
    fast_io;
    inputAndInit();
    //test();
    int testCase = 0;
    if(testCase == 0) cin >> testCase;
    fow(i,0,testCase)
        solve(i);
    return 0;
}

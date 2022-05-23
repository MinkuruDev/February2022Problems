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
#define MAX 100005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int a[MAX], b[MAX];
/// Global variable and input, init ///

void inputAndInit(){

}

/// Process ///
void solve(int n){
    rep(i,1,n){
        cin >> a[i];
        b[a[i]] = i;
    }
    bool flag = true;
    rep(i,1,n){
        if(a[i] != b[i]){
            flag = false;
            break;
        }
    }

    cout << (flag?"":"not ") << "ambiguous" << endl;
}

void test(){

}

int main(){
    fast_io;
    inputAndInit();
    //test();
    int n;
    while(true){
        cin >> n;
        if(n) solve(n);
        else break;
    }
    return 0;
}

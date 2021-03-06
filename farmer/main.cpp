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
#define MAX 10000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/// Global variable and input, init ///

void inputAndInit(){

}

/// Process ///
void solve(ll d, ll f, ll b, ll m){
    ll s = (f*f+f+2)/2;
    d -= s*b;
    if(d<m){
        cout << "The firm is trying to bankrupt Farmer Cream by " << m - d << " Bsf." << endl;
    }else{
        cout << "Farmer Cream will have " << d << " Bsf to spend." << endl;
    }
}

void test(){

}

int main(){
    fast_io;
    inputAndInit();
    //test();
    int testCase = 1;
    ll d,f,b,m;
    while(true){
        cin >> d >> f >> b >> m;
        if(d+f+b+m == 0) break;
        solve(d,f,b,m);
    }
    return 0;
}

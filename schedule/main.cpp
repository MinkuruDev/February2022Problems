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
void solve(int na, int nb, int ns){
    vector<int> a,b;
    int hh,mm,ss;
    string s;
    fow(j,0,na){
        cin >> s;
        string st = "";
        int i = 0;
        while(s[i] != ':')
            st += s[i++];
        hh = stoi(st);
        i++; st = "";
        while(s[i] != ':')
            st += s[i++];
        mm = stoi(st);
        i++; st = "";
        while(i < s.size())
            st += s[i++];

        ss = stoi(st);

        a.push_back(hh*3600 + mm*60 + ss);
    }
    fow(j,0,nb){
        cin >> s;
        string st = "";
        int i = 0;
        while(s[i] != ':')
            st += s[i++];
        hh = stoi(st);
        i++; st = "";
        while(s[i] != ':')
            st += s[i++];
        mm = stoi(st);
        i++; st = "";
        while(i < s.size())
            st += s[i++];

        ss = stoi(st);

        b.push_back(hh*3600 + mm*60 + ss);
    }
    /*
    repa(i,a){
        cout << i << " ";
    }
    el;
    repa(i,b){
        cout << i << " ";
    }
    el;
    */

    int as = a.size(), bs = b.size();
    vector<int> checka(as,-1), checkb(bs,-1);
    int matches = 0;
    fow(i,0,as){
        fow(j,0,bs){
            int diff = abs(a[i] - b[j]);
            if(diff <= ns){
                if(checkb[j] < 0){
                    checka[i] = j;
                    checkb[j] = i;
                    //db(i); db(j);
                }else{
                    int _i = checkb[j];
                    if(diff < abs(a[_i] - b[j])){
                        checka[i] = j;
                        checkb[j] = i;
                        checka[_i] = -1;
                        //db(i); db(j);
                    }
                }
            }
        }
    }

    double sum = 0;
    fow(i,0,as){
        int j = checka[i];
        if(j>=0){
            matches++;
            sum += abs(a[i] - b[j]);
        }
    }
    if(matches == 0){
        cout << "No matches" << endl;
    }else{
        sum /= matches;
        cout << matches << " ";
        cout << fixed << setprecision(1) << sum << endl;
    }

}

void test(){

}

int main(){
    fast_io;
    inputAndInit();
    //test();
    int na,nb,ns;
    while(1){
        cin >> na >> nb >> ns;
        if(na == 0 && nb == 0 && ns == 0)
            break;
        solve(na,nb,ns);
    }
    return 0;
}

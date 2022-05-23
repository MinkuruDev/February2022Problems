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

bool comp(const vector<int> a, const vector<int> b){
    return a.size() > b.size();
}

struct Node{
    vector<int> child;

    bool operator<(const Node other){
        return child.size() < other.child.size();
    }
};

/// Global variable and input, init ///
int n,k;
Node node[MAX];
vector<vector<int>> t;
vector<int> vtm;
bool vis[MAX];
void inputAndInit(){
    cin >> n >> k;
    int temp;
    vis[1] = false;
    rep(i,2,n){
        cin >> temp;
        node[temp].child.push_back(i);
        vis[i] = false;
    }

}

void surf(int focus, vector<int> vt){
    vt.push_back(focus);
    if(node[focus].child.size() == 0){
        if(vt.size() > vtm.size()) vtm = vt;
        return;
    }

    repa(i, node[focus].child){
        surf(i,vt);
    }

}

/// Process ///
void solve(int testIndex){
    /*rep(i,1,n){
        cout << "node " << i << ":";
        repa(j,node[i].child){
            cout << " " << j;
        }
        el;
    }*/

    int total = 0;
    vector<int> subtree;
    subtree.push_back(1);
    while(k--){
        vtm.clear();
        repa(i, subtree){
            vector<int> vt;
            surf(i,vt);
        }

        reverse(vtm.begin(), vtm.end());
        total += vtm.size();
        repa(i,vtm){
            vis[i] = true;
            //cout << i << " ";
            repa(j,node[i].child){
                if(!vis[j]) subtree.push_back(j);
                //db(j);
            }
        }
        //el;

        for(auto it = subtree.begin(); it<subtree.end(); it++){
            if(*it == vtm.back()){
                subtree.erase(it);
                break;
            }
        }
    }

    cout << total << endl;
}

void test(){

}

int main(){
    fast_io;
    inputAndInit();
    //test();
    int testCase = 1;
    if(testCase == 0) cin >> testCase;
    fow(i,0,testCase)
        solve(i);
    return 0;
}

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

struct Point{
    int x,y;
    Point(){
        x = 0;
        y = 0;
    }
    Point(int _x, int _y){
        x = _x;
        y = _y;
    }
};

/// Global variable and input, init ///
int dx[] = {1,0,0,-1}, dy[] = {0,1,-1,0};
void inputAndInit(){

}

/// Process ///
void solve(int testIndex){
    int n,m;
    vector<string> g;
    cin >> m >> n;
    Point start, fin;
    bool vis[100][100];
    int dis[100][100];
    fow(i,0,m){
        string s;
        cin >> s;
        g.push_back(s);
        fow(j,0,n){
            dis[i][j] = 0;
            if(s[j] == 'O'){
                vis[i][j] = false;
            }else if(s[j] == '*'){
                vis[i][j] = true;
            }else if(s[j]=='$'){
                vis[i][j] = true;
                start = Point(i,j);
            }else{
                fin = Point(i,j);
                vis[i][j] = false;
            }
        }
    }

    int distances = -1;
    queue<Point> q;
    q.push(start);
    while(!q.empty()){
        Point v = q.front();
        q.pop();
        fow(i,0,4){
            int nx = v.x + dx[i];
            int ny = v.y + dy[i];

            if(nx == fin.x && ny == fin.y){
                distances = dis[v.x][v.y]+1;
                queue<Point> emp;
                swap(q,emp);
                break;
            }else if(nx>=0 && nx < m && ny >=0 && ny < n){
                if(vis[nx][ny]) continue;
                dis[nx][ny] = dis[v.x][v.y]+1;
                vis[nx][ny] = true;
                q.push(Point(nx,ny));
            }
        }
    }

    cout << distances << endl;
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

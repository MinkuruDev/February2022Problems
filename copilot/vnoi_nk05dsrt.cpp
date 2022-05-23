#include <bits/stdc++.h>

using namespace std;

#define inf 100000
#define MAXN 101
#define dbg(x) cout << #x << " = " << x << endl

int g[MAXN][MAXN];
int n, m, c;
bool vis[MAXN];
int trace[MAXN], dis[MAXN];

void init(){
    for(int i = 0; i<MAXN; i++){
        for(int j = 0; j<MAXN; j++){
            g[i][j] = 0;
        }
        vis[i] = false;
        trace[i] = -1;
        dis[i] = inf;
    }
}

// dijkstra
void dijkstra(int start){
    dis[start] = 0;

    for(int i = 1; i<=n; i++){
        int uBest = -1;
        int max = inf + 1;
        for(int j = 1; j<=n; j++){
            if(!vis[j] && dis[j] < max){
                max = dis[j];
                uBest = j;
            }
        }

        //if(uBest == -1) break;
        vis[uBest] = true;

        for(int j = 1; j<=n; j++){
            if(!vis[j] && g[uBest][j] != 0 && dis[uBest] + g[uBest][j] < dis[j]){
                dis[j] = dis[uBest] + g[uBest][j];
                trace[j] = uBest;
            }
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        init();
        cin >> n >> m >> c;
        for(int i = 0; i<m; i++){
            int u,v,w;
            cin >> u >> v >> w;
            g[u][v] = w;
            g[v][u] = w;
        }
        dijkstra(1);

        vector<int> ans;
        int u = n;
        while(u != -1){
            ans.push_back(u);
            u = trace[u];
        }
        int size = ans.size();

        int total = 0;
        for(int i = 0; i<size-1; i++){
            if(g[ans[i]][ans[i+1]] > c){
                cout << -1 << endl;
                return 0;
            }

            
            if(total + g[ans[i]][ans[i+1]] > c){
                int temp = total;
                total = 0;
                do{
                    temp -= c - 2 * g[ans[i]][ans[i+1]];
                    total += c;
                }while(temp + g[ans[i]][ans[i+1]] > c);
                total += temp + g[ans[i]][ans[i+1]];

            }else{
                total += g[ans[i]][ans[i+1]];
            }
        }

        cout << total << endl;
    }

    return 0;
}
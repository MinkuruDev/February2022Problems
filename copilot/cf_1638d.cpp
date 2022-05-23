#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}

    Point() : x(0), y(0) {}
};


struct Operation{
    int x,y,op;

    Operation(int x, int y, int op){
        this->x = x;
        this->y = y;
        this->op = op;
    }

    Operation(){}

    friend ostream &operator<<(ostream &os, const Operation &op){
        os  << op.x << " " << op.y << " " << op.op;
        return os;
    }
};

int a[1000][1000];
int n, m;
int dx[] = {-1, -1, 0, 0}, dy[] = {-1, 0, -1, 0};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; i<m; j++){
            cin >> a[i][j];
        }
    }
    stack<Operation> st;
    queue<Point> q;

    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<m-1; j++){
            if(a[i][j] != 0 && a[i][j] == a[i][j+1] && a[i][j] == a[i+i][j] && a[i][j] == a[i+1][j+1]){
                st.push(Operation(i,j,a[i][j]));
                q.push(Point(i,j));
                q.push(Point(i,j+1));
                q.push(Point(i+1,j));
                q.push(Point(i+1,j+1));
                a[i][j] = 0;
                a[i][j+1] = 0;
                a[i+1][j] = 0;
                a[i+1][j+1] = 0;
            }
        }
    }

    while(!q.empty()){
        Point p = q.front();
        q.pop();
        
        for(int i = 0; i<4; i++){
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if(nx >= 0 && ny >=0 && nx < n-1 && ny < m-1){
                if(a[nx][ny] == 0) continue;

                
            }
        }
    }

    return 0;
}
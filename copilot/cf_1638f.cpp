#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Panel{
    ll value;
    int index;

    bool operator<(const Panel& p) const{
        if(value == p.value){
            return index < p.index;
        }
        return value < p.value;
    }
};

ll a[10000];
//Panel b[10000];
int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    ll maxArea = 0;
    ll height = 0;
    int left = 0, right = n-1;
    for(int i = 0; i<n; i++){
        ll area = 0;
        int _i = i;
        int j = i;

        while(j<n){
            if(a[j] >= a[_i]){
                area += a[_i];
            }else{
                if(area > maxArea){
                    maxArea = area;
                    height = a[_i];
                    left = _i;
                    right = j - 1;
                    area = 0;
                    _i = j;
                }
            }
            j++;
        }

        if(area > maxArea){
            maxArea = area;
            height = a[_i];
            left = _i;
            right = j - 1;
        }
    }

    for(int i = left; i<=right; i++){
        a[i] -= height;
    }

    ll maxArea2 = 0;
    ll height2 = 0;
    int left2 = 0, right2 = n-1;
    for(int i = 0; i<n; i++){
        ll area = 0;
        int _i = i;
        int j = i;

        while(j<n){
            if(a[j] >= a[_i]){
                area += a[_i];
            }else{
                if(area > maxArea2){
                    maxArea2 = area;
                    height2 = a[_i];
                    left2 = _i;
                    right2 = j - 1;
                    area = 0;
                    _i = j;
                }
            }
            j++;
        }

        if(area > maxArea2){
            maxArea2 = area;
            height2 = a[_i];
            left2 = _i;
            right2 = j - 1;
        }
    }

    ll totalArea = maxArea + maxArea2;
    cout << totalArea << '\n';

    return 0;
}
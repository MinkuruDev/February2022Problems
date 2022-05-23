#include <bits/stdc++.h>

using namespace std;

string key = "rgb";
string door = "RGB";

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testCase;
    cin >> testCase;
    while(testCase--){
        string s;
        cin >> s;
        bool flag = true;
        for(int i = 0; i<3; i++){
            if(s.find(key[i]) > s.find(door[i])){
                flag = false;
                break;
            }
        }

        cout << (flag?"YES":"NO") << endl;
    }
    return 0;
}
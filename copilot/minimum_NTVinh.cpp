#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool prime[] = {0,0,1,1,0,1,0,1,0,0};

string div(string a, int b){
    string ans = "";
    int i = 0;
    string temp = "";
    while(i < a.size()){
        temp += a[i];
        int j = stoi(temp);
        ans += to_string(j/b);
        temp = "";
        temp += to_string(j%b);
        i++;
    }
    i = 0;
    while(i < ans.size()){
        if(ans[i] != '0'){
            break;
        }
        i++;
    }
    return ans.substr(i);
}

bool is_divisible_by_3(string a){
    int sum = 0;
    for(auto c : a){
        sum += c - '0';
    }

    return sum % 3 == 0;
}

bool is_divisible_by_9(string a){
    int sum = 0;
    for(auto c : a){
        sum += c - '0';
    }

    return sum % 9 == 0;
}

vector<int> nomalize(string num){
    vector<int> ans = {0,0,0,0}; // count 2,3,5,7
    while (num[num.size()-1]%2 == 0){
        ans[0]++;
        num = div(num,2);
    }

    while(is_divisible_by_3(num)){
        ans[1]++;
        num = div(num,3);
    }

    while (num[num.size()-1] == '5'){
        ans[2]++;
        num = div(num,5);
    }
    
    while (num.size() > 1){
        ans[3]++;
        num = div(num,7);
    }

    if(num == "7"){
        ans[3]++;
    }
    
    return ans;
}

string sol1(string s, int k){
    vector<int> ans = nomalize(s);
    string result = "";
    while (ans[1] >= 2){
        ans[1] -= 2;
        result += '9';
    }
    while (ans[0] >= 3){
        ans[0] -= 3;
        result = '8' + result;
    }
    while (ans[3] > 0){
        ans[3]--;
        result = '7' + result;
    }
    while(ans[1] > 0 && ans[0] > 0){
        ans[1]--;
        ans[0]--;
        result = '6' + result;
    }
    while (ans[2] > 0){
        ans[2]--;
        result = '5' + result;
    }
    while (ans[0] >= 2){
        ans[0] -= 2;
        result = '4' + result;
    }
    while (ans[1] > 0){
        ans[1]--;
        result = '3' + result;
    }
    while (ans[0] > 0){
        ans[0]--;
        result = '2' + result;
    }
    k -= result.size();
    while (k > 0){
        result = '1' + result;
        k--;
    }

    return result;
}

string sol2(string s, int k){
    string result = sol1(s,k);
    if(is_divisible_by_9(result)){
        return result;
    }
    
    vector<int> ans = nomalize(s);
    
}

void sol1(int n){
    while (n--){
        string s;
        int k;
        cin >> s >> k;
        cout << sol1(s,k) << endl;
    }
    
}

void sol2(int n){
    while (n--){
        string s;
        int k;
        cin >> s >> k;
        string result = sol1(s,k);
        if(is_divisible_by_9(result)){
            cout << result << endl;
        }else{
            cout << "No solution" << endl;
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, type;
    cin >> n >> type;
    if(type == 1) sol1(n);
    else sol2(n);

    return 0;
}
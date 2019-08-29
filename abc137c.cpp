#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

//アナグラム->辞書式ソート

string sort_string(string str){
    vector<char> v;
    rep(i,10){
        v.emplace_back(str[i]);
    }
    sort(v.begin(), v.end());
    string ans = "";
    rep(i,10){
        ans += v[i];
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    string v[n+10];
    rep(i,n){
        cin >> v[i];
    }

    //ハッシュ連想配列
    unordered_map<string, long long> mp;
    long long count=0;
    for(int i=0; i<n; i++){
        string str = sort_string(v[i]);
        if(mp.find(str) == mp.end()){
            mp[str] = 1;
        }
        else{
            count += mp[str];
            mp[str]++;
        }
    }
    cout << count << endl;

}


int main(){
  solve();
  return 0;
}
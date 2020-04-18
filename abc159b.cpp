#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

bool isp(string s){
    int n = s.length();
    bool b=true;
    rep(i,n){
        if(s[i]!=s[n-i-1]) b=false;
    }
    return b;
}

void solve(){

    string s;
    cin >> s;
    //cout << isp("asdsdka") << endl;
    string ans = "Yes";

    if(!isp(s)) ans = "No";

    string tmp = s.substr(0,(s.length()-1)/2);

    if(!isp(tmp)) ans = "No";

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

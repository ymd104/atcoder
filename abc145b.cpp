#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;



void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool b = true;
    if(n%2==1) b = false;
    else{
        rep(i,n/2){
            if(s[i]!=s[i+n/2]) b = false;
        }
    }
    if(b) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

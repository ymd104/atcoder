#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


void solve(){

    int n;
    string s;
    cin >> n;
    cin >> s;
    int count=0;
    rep(i,n-2){
        if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){
            count++;
        }
    }
    cout << count << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

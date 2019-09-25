#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

/*
*/

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int ans1,ans2;
    ans1=-1;
    ans2=-1;
    for(int i=1; i<n; i++){
        if(s[i-1]==s[i]) {
            ans1=i;
            ans2=i+1;
        }
    }
    for(int i=2; i<n; i++){
        if(s[i-2]==s[i]){
            ans1=i-1;
            ans2=i+1;
        }
    }
    cout << ans1 << " " << ans2 << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}


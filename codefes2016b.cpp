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
    int a[n+10];
    int count=0;
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        if(a[a[i]-1]==i+1) count++;
    }
    cout << count/2 << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;



void solve(){
    int n,k,q;
    cin >> n >> k >> q;
    int a[q+5];
    int ans[n+10];
    int x[n+10];
    rep(i,n){
      ans[i] = 0;
    }
    rep(i,q){
      cin >> a[i];
      ans[a[i]-1]++;
    }
    //それぞれの参加者が正解した回数をベクトルで保持

    rep(i,n){
      x[i] = k - q + ans[i];
    }
    rep(i,n){
      if(x[i]>0) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

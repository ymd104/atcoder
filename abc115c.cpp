#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;


void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> h;
    rep(i,n){
        int tmp;
        cin >> tmp;
        h.emplace_back(tmp);
    }
    sort(h.begin(),h.end());
    /*
    h[n-1], h[n-2], ..., h[n-k]
    h[n-2], h[n-3], ..., h[n-k-1]
    ...
    h[k-1], h[k-2], ..., h[0]
    */
    int ans = h[n-1] - h[n-k];
    rep(i,n-k+1){
        ans = min(ans, h[n-1-i]- h[n-k-i]);
    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

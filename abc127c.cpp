#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;


void solve(){
    int n,m;
    cin >> n >> m;
    int mi,ma;
    mi = 0;
    ma = n;
    rep(i,m){
        int l,r;
        cin >> l >> r;
        mi = max(mi,l);
        ma = min(ma,r);
    }
    cout << max(0,ma-mi+1) << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
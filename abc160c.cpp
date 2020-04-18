#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int a[200010];
int b[200010];

void solve(){

    ll k,n;
    cin >> k >> n;
    rep(i,n){
        cin >> a[i];
    }
    a[n]=a[0]+k;
    rep(i,n){
        b[i]=a[i+1]-a[i];
    }
    ll m = 0;
    rep(i,n){
        m=max(ll(m), ll(b[i]));
    }
    cout << k-m << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

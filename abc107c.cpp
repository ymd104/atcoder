#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

/*
一番近いろうそくに火を付ける？
-1 100 101 102
-101 -100 -1 99 100

一番狭い区間に火を付ける？
10 13 16 100 101 102

いずれにせよ、連続したk個のろうそくに火を付けるので、
連続したk個のろうそくに火を付ける為に必要なコストを計算する
区間が0を含んでいなければ、最も遠いろうそくまでの距離
0を含んでいれば、[-p,0][0,q]とし、
min(2*p+q,p+2*q)
*/

void solve(){
    ll n;
    ll k;
    cin >> n >> k;
    ll x[n+10];
    rep(i,n){
        cin >> x[i];
    }
    ll ans = INF;
    for(ll i=k-1; i<n; i++){
        ll cost=0;
        //区間 x[i-k+1], x[i-k+2], ..., x[i]
        if(x[i]<=0){
            cost = -x[i-k+1];
        }
        else if(x[i-k+1]>=0){
            cost = x[i];
        }
        else{
            ll p=-x[i-k+1];
            ll q=x[i];
            cost = min(2*p+q, p+2*q);
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}


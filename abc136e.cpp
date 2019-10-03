#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
総和に変わりはない. そのため、操作後のAを割り切る値の候補は総和の約数.
約数を大きいものから順に走査.
*/

vector<ll> divisor(ll n) {
  vector<ll> ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

void solve(){
  ll n,k;
  cin >> n >> k;
  ll a[n+10];
  ll sum=0;
  rep(i,n){
    cin >> a[i];
    sum += a[i];
  }
  vector<ll> v = divisor(sum);
  reverse(v.begin(),v.end());
  for(ll d:v){
    ll r[n+10];
    rep(i,n){
      r[i] = a[i]%d;
    }
    sort(r,r+n);
    ll sum1 = 0;
    rep(i,n){
      sum1 += d-r[i];
    }
    ll sum2=0;

    if(max(sum1,sum2)<=k) {
      cout << d << endl;
      break;
    }

    bool br=false;
    for(ll i=0; i<n; i++){
      sum1 = sum1 - (d-r[i]);
      sum2 = sum2 + r[i];
      if(max(sum1,sum2)<=k) {
      cout << d << endl;
      br = true;
      break;
      }
    }

    if(br) break;

  }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
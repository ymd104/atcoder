#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

ll a[2020];
bool moved[2020];

void solve(){

    ll n;
    cin >> n;  
    rep(i,n){
        cin >> a[i];
    }
    rep(i,2020){
        moved[i]=false;
    }
    ll l=0;
    ll r=n-1;
    ll ans = 0;
    
    while(r-l>=0){
        ll tmp = 0;
        ll pointer = 0;
        rep(i,n){
            if(moved[i]) continue;
            if(tmp <= a[i]*max(ll(abs(ll(i-l))),ll(abs(ll(r-i))))){
                tmp = a[i]*max(ll(abs(ll(i-l))),ll(abs(ll(r-i))));
                pointer = i;
            }
        }
        //cout << "p" << pointer << endl;
        //cout << a[pointer]*max(pointer-l,r-pointer) << endl;
        ans += a[pointer]*max(ll(abs(ll(pointer-l))),ll(abs(ll(r-pointer))));
        moved[pointer]=true;
        if(abs(pointer-l) < abs(r-pointer)) r--;
        else l++;
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

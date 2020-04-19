#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll b[65];
void t(ll x){
    ll tmp = x;
    ll count=0;
    while(count<=65){
        
        if(x%2==1) {
            b[count] = true;
        }
        else{
            b[count] = false;
        }
        x /= 2;
        count++;
    }
    
}

ll sum[65];

void solve(){

    rep(i,65){
        sum[i]=0;
    }

    ll n;
    cin >> n;
    rep(i,n){
        ll tmp;
        cin >> tmp;
        t(tmp);
        /*
        rep(i,65){
            cout << b[i];
        }
        cout << endl;
        */
        rep(j,65){
            if(b[j]==1) sum[j]++;
        }
    }
    ll ans = 0;
    ll s = 1;
    rep(i,65){
        
        ans = (ans + ((sum[i]*(n-sum[i]))%MOD*((s)%MOD))%MOD)%MOD;
        s = (s * 2)%MOD;

    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

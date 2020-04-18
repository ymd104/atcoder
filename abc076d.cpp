#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

typedef long double ld;
ld t[110];
ld v[110];
ld nextv = 0;

ld distance(ld v0, ld v, ld vn, ld t){
    if(v0>v) {
        cout << "error" << endl;
        return 0;
    }
    if(v<=vn){
        if(v-v0<t) {
            nextv = v;            
            return v*t-(v-v0)*(v-v0)/2;
        }
        else {
            nextv = v0+t;
            return v0*t+t*t/2;
        }
    }
    else if(v>vn){
        nextv = vn;
        if(2*v-v0-vn <= t) return v*t - (v-v0)*(v-v0)/2 - (v-vn)*(v-vn)/2;
        else {
            ld x = (vn-v0+t)/2;
            if(0<=x&&x<=t){
                return v0*x+x*x/2+(t-x)*vn+(t-x)*(t-x)/2;
            }
            else{
                return v0*t+t*t/2;
            }
            
        }
    }
    else {
        cout << "error2" << endl;
        return 0;
    }

}

void solve(){
    ll n;
    cin >> n;
    rep(i,n){
        cin >> t[i] >> v[i];
    }
    ld ans = 0;
    nextv=0;
    for(ll i=0; i<n-1; i++){
        ans += distance(nextv,v[i],v[i+1],t[i]);
    }
    ans += distance(nextv,v[n-1],0,t[n-1]);

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

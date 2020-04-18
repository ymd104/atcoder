#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll a[100010];

void solve(){

    ll n;
    cin >> n;
    rep(i,n){
        cin >> a[i];
    }
    vector<ll> v;
    bool is = true;
    rep(i,n){
        if(a[i]==0){
            v.emplace_back(0);
            if(v.size()>=4){
                is = false;
                break;
            }
        }
        else{
            if(v.size()==0){
                is=false;
                break;
            }
            if(v[0]==a[i]-1){
                v[0]++;
                continue;
            }
            else if(v.size()==1){
                is=false;
                break;
            }
            else if(v[1]==a[i]-1){
                v[1]++;
                continue;
            }
            else if(v.size()==2){
                is=false;
                break;
            }
            else if(v[2]==a[i]-1){
                v[2]++;
                continue;
            }
            else{
                is=false;
                break;
            }
        }
    }

    if(!is) {
        cout << 0 << endl;
        return;
    }

    ll numof0 = 0;
    vector<ll> v2;
    ll ans = 1;

    rep(i,n){
        if(i==0) {
            v2.emplace_back(a[0]);
            numof0++;
            continue;
        }
        if(a[i]==0){
            v2.emplace_back(a[i]);
            numof0++;
            continue;
        }
        int count = 0;
        rep(j,v2.size()){
            if(v2[j]==a[i]-1) count++;
        }
        ans = (ans * count) % MOD;
        rep(j,v2.size()){
            if(v2[j]==a[i]-1){
                v2[j]++;
                break;
            }
        }
    }

    if(numof0>=2){
        ans = (ans * 3*2) % MOD;
    }
    else{
        ans = (ans * 3) % MOD;
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

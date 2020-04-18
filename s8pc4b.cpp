#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll a[20];
ll p[20];

void solve(){

    ll n,k;
    cin >> n >> k;
    
    
    rep(i,n){
        cin >> a[i];
        if(i!=0) p[i]=max(a[i],p[i-1]);
        else p[0]=a[0];
    }
    /*
    rep(i,n){
        cout << p[i] << " ";
    }
    cout << endl;
    */

    ll ans = 10000000000000;

    for(ll bit=0; bit<(1<<n); bit++){

        ll tmp=bit;
        vector<ll> c;
        for(ll i=0; i<n; i++){
            if(tmp%2==1) {
                c.emplace_back(i);
            }
            tmp = tmp/2;
        }

        /*
        rep(i,c.size()){
            cout << a[c[i]] << " ";
        }
        cout << endl;
        */

        if(c.size()<k) continue;
        ll count=0;
        count += p[c[0]]-a[c[0]];
        //cout << c[0] << ": " << count << " ";
        rep(i,c.size()-1){
            ll x = c[i];
            if(p[x]>=p[c[i+1]]){
                p[c[i+1]]=p[x]+1;
                count += p[x]+1-a[c[i+1]];
                //cout << x+1 << ": " << p[x]+1-a[c[i+1]] << " ";
            }
        }
        //cout << endl;

        /*
        rep(i,c.size()){
            cout << "result: " << p[c[i]] << " ";
        }
        cout << count << endl;
        */

        //cout << count << endl;

        ans = min(ans, count);

        rep(i,n){
        if(i!=0) p[i]=max(a[i],p[i-1]);
        else p[0]=a[0];
    }

    }

    cout << ans << endl;

    

    

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

ll a[55];
ll b[55];
ll c[55];
ll d[55];


ll n,m,q_;

ll ans_s;

ll x[12];

ll ans(ll at, ll bt, ll ct, ll dt){
    ll tmp=0;
    if(x[bt-1]-x[at-1]==ct) tmp+=dt;
    return tmp;
}



// p以上の数の数列をx[q]より右に生成.
void dfs(ll p, ll q){
    if(q>=n){
        /*
        rep(i,n){
            cout << x[i];
        }
        */
        
        ll ans_all = 0;
        rep(i,q_){
            ans_all += ans(a[i],b[i],c[i],d[i]);
            //cout << " " << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << " " << ans(a[i],b[i],c[i],d[i]);
        }
        //cout << " " << ans_all << endl;
        ans_s = max(ans_s, ans_all);
        return;
    }
    else{
        for(ll i=p; i<=m; i++){
            x[q]=i;
            dfs(i,q+1);
        }
    }
}



void solve(){

    cin >> n >> m >> q_;

    rep(i,q_){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    ans_s=0;

    dfs(1,0);

    cout << ans_s << endl;


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

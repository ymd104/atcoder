#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

ll x[12];



// p以上の数の数列をx[q]より右に生成.
void dfs(ll p, ll q){
    if(q>=n){
        /*
        rep(i,n){
            cout << x[i];
        }
        */
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

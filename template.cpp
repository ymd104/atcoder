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

pair<ll,ll> adj[12][12];

pair<ll,ll> ans[12];


void solve(){

    ll n,m,q;
    cin >> n >> m >> q;

    rep(i,12){
        rep(j,12){
            adj[i][j]=make_pair(0,0);
        }
    }
    rep(i,12){
        ans[i]=make_pair(0,0);
    }
    vector< pair<pair<ll,ll>, pair<ll,ll> >> px;
    rep(i,q){
        ll p,q,r,s;
        cin >> p >> q >> r >> s;
        px.emplace_back(make_pair(make_pair(p,q), make_pair(r,s)));
    }

    sort(px.begin(), px.end());

    rep(i,q){
        a[i] = px[i].first.first;
        b[i] = px[i].first.second;
        c[i] = px[i].second.first;
        d[i] = px[i].second.second;

        a[i]--;
        b[i]--;

        cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << endl;

        if(adj[a[i]][b[i]].second < d[i]){
            adj[a[i]][b[i]] = make_pair(c[i],d[i]);
        }


        if(ans[b[i]].first==ans[a[i]].first+c[i]){
            ans[b[i]].second += (ans[a[i]].first+d[i]);
        } 
        else if(ans[b[i]].second < ans[a[i]].second + d[i]){
            ans[b[i]] = make_pair( ans[a[i]].first + c[i], ans[b[i]].second + d[i] );
        }

    }

    rep(i,n){
        cout << ans[i].second << " ";
    }
    cout << endl;



}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

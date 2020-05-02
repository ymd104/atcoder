#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

vector<ll> adj[100010];
bool visited[100010];
ll dist[100010];
ll dist2[100010];


void solve(){

    ll n;
    cin >> n;
    ll u,v;
    cin >> u >> v;
    u--;
    v--;
    rep(i,n-1){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    rep(i,100010){
        visited[i]=false;
        dist[i]=0;
    }

    stack<ll> st;
    st.push(v);
    visited[v]=true;
    while(!st.empty()){
        ll x = st.top();
        st.pop();
        for(auto e: adj[x]){
            if(visited[e]==true) continue;
            dist[e]=dist[x]+1;
            st.push(e);
            visited[e]=true;
        }
    }

    /*
    rep(i,n){
        cout << dist[i] << " ";
    }
    cout << endl;
    */

    rep(i,100010){
        visited[i]=false;
        dist2[i]=0;
    }

    stack<ll> st2;
    st2.push(u);
    visited[u]=true;
    while(!st2.empty()){
        ll x = st2.top();
        st2.pop();
        for(auto e: adj[x]){
            if(visited[e]==true) continue;
            dist2[e]=dist2[x]+1;
            st2.push(e);
            visited[e]=true;
        }
    }

    /*
    rep(i,n){
        cout << dist2[i] << " ";
    }
    cout << endl;
    */

    ll ans = 0;
    rep(i,n){
        if(dist[i]>dist2[i]) ans = max(ans, dist[i]-1);
    }

    if(ans!=0) cout << ans << endl;
    else cout << (dist[u])/2 << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

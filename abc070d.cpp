#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

void solve(){

    int n;
    cin >> n;
    vector<pair<int,int>> ad[n];
    rep(i,n-1){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        ad[a].emplace_back(make_pair(b,c));
        ad[b].emplace_back(make_pair(a,c));
    }
    bool visited[n];
    ll dis[n];
    rep(i,n){
        visited[i]=false;
        dis[i]=0;
    }
    int Q,K;
    cin >> Q >> K;
    K--;
    
    queue<int> q;
    q.push(K);
    visited[K]=true;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        auto vec=ad[t];
        for(auto &e:vec){
            ll node=e.first;
            ll d=e.second;
            if(!visited[node]) {
                dis[node]=dis[t]+d;
                visited[node]=true;
                q.push(node);
            }
        }
    }

    int xi[Q];
    int yi[Q];
    rep(i,Q){
        cin >> xi[i] >> yi[i];
    }

    /*
    rep(i,n){
        cout << dis[i] << endl;
    }
    */

    rep(i,Q){
        int x,y;
        x=xi[i];
        y=yi[i];
        x--;
        y--;
        cout << dis[x]+dis[y] << endl;
    }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

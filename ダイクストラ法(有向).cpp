#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

vector<pair<int,int>> adj[100010];
int dis[100010];
bool visit[100010];

void solve(){

    int v,e,r;
    cin >> v >> e >> r;
    rep(i,e){
        int x,y,z;
        cin >> x >> y >> z;
        adj[x].emplace_back(make_pair(y,z));
        //adj[y].emplace_back(make_pair(x,z));
    }

    rep(i,v){
        dis[i]=INF;
        visit[i]=false;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push(make_pair(0,r));
    visit[r]=true;
    dis[r]=0;
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        int d = p.first;
        int node = p.second;
        if(dis[node]!=d) continue;
        visit[node] = true;
        for(auto e: adj[node]){
            if(!visit[e.first]){
                int x = e.first;
                int distance = e.second;
                dis[x]=min(dis[x],dis[node]+distance);
                q.push(make_pair(dis[x],x));
            }
        }
    }
    
    rep(i,v){
        if(dis[i]!=INF) cout << dis[i] << endl;
        else cout << "INF" << endl;
    }

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

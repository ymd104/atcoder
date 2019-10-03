#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
*/

struct edge{
    int p;
    int c;
    int w;
};

void solve(){
    int n,m,p;
    cin >> n >> m >> p;
    vector<edge> v;
    vector<pair<int,int>> g[n+10];
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        v.emplace_back(edge{a,b,p-c});
        g[a].emplace_back(make_pair(b,p-c));
    }
    int cost[n+10];
    fill(cost,cost+n+10,INF);
    cost[1]=0;
    rep(i,n){
        for(int j=1; j<=n ;j++){
            for(auto e:g[j]){
                if(cost[e.first]==INF&&cost[j]==INF) cost[e.first] = INF;
                else cost[e.first] = min(cost[e.first], cost[j]+e.second);
            }  
        }
        //rep(j,n) cout << "cost[" << j+1 << "]:" <<  cost[j+1] << endl;
    }
    int tmp = cost[n];

    bool negative[n+10];
    fill(negative,negative+n+10,false);
    rep(i,n){
        for(int j=1; j<=n ;j++){
            for(auto e:g[j]){
                int tmp=cost[e.first];
                if(cost[e.first]==INF&&cost[j]==INF) cost[e.first] = INF;
                else cost[e.first] = min(cost[e.first], cost[j]+e.second);
                if(tmp!=cost[e.first]) negative[e.first] = true;
                if(negative[j]==true) negative[e.first] = true;
            }  
        }
        //rep(j,n) cout << "cost[" << j+1 << "]:" <<  cost[j+1] << endl;
    }
    

    
    if(negative[n]) {
        cout << -1 << endl;
        return;
    }
    cout << max(-cost[n],0) << endl;


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
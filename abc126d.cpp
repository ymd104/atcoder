#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;

/*
ある頂点からの距離が偶数であるものは白、奇数であるものは黒とすれば、
同色の任意の頂点について距離が偶数になる。
根からの距離を計算する関数が必要。
*/

/*
グラフ：
Edge 結んでいる頂点とその重みのペア
Graph Edgeの配列の配列
*/
vector<vector<pair<int,int>>> g;

/*
頂点u、uの親頂点v, uの頂点からの距離を表すdが与えられる
uと繋がっている頂点がvと等しい時、スキップ
*/
vector<ll> dist;
void dfs(int u, int v, ll d){
    dist[u] = d;
    
    for(auto e : g[u]){
        if(e.first != v) dfs(e.first, u, d+e.second);
    }
    
    /*
    int siz = g[u].size();
    rep(i,siz){
        pair<int,int> e;
        e = g[u][i];
        if(e.first != v) dfs(e.first, u, d+e.second);
    }
    */
}

void solve(){
    int n;
    cin >> n;
    //assign:同じ値で要素を埋める
    g.assign(n,vector<pair<int,int>>());
    dist.assign(n,0);
    rep(i,n-1){
        int u,v,w;
        cin >> u >> v >> w;
        //頂点番号を0始まりにする
        u--;
        v--;
        g[u].emplace_back(make_pair(v,w));
        g[v].emplace_back(make_pair(u,w));
    }
    dfs(0,-1,0);
    rep(i,n){
        cout << dist[i]%2 << endl;
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
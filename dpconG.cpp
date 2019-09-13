#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;

/*
トポロジカルソートをし、頂点を順に見ていけばOK。
*/

void solve(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> v;
    vector<int> e[n+5];//e[i]:頂点i+1から辺が伸びている頂点の集合
    vector<int> e2[n+5];//e2[i]:頂点i+1へ伸びている頂点の集合
    int g[n+5];//頂点iへ入っていく辺の数
    rep(i,n){
        g[i]=0;
    }
    rep(i,m){
        int x,y;
        cin >> x >> y;
        v.emplace_back(make_pair(x-1,y-1));
        e[x-1].emplace_back(y-1);
        e2[y-1].emplace_back(x-1);
        g[y-1]++;
    }
    vector<int> sorted;
    //トポロジカルソート。各頂点の入次数を管理。
    //gが0の頂点を取り出し、キューに追加。見た頂点について、辺が入っていく方の頂点の次数を-1。
    queue<int> q;
    
    rep(i,n){
        if(g[i]==0) q.push(i);
    }
    while(q.size()!=0){
        int tmp = q.front();
        q.pop();
        sorted.emplace_back(tmp);
        for(auto j:e[tmp]){
            g[j]--;
            if(g[j]==0) q.push(j);
        }
    }

    //rep(i,n-4){
        //cout << g[0] << endl;
    //}
    
    int dp[n+5];
    rep(i,n){
        
        int tmp = sorted[i];//セグフォ
        
        if(e2[tmp].size()==0) dp[tmp]=0;
        else{
            int m = 0;
            for(auto j:e2[tmp]){
                m = max(m, dp[j]);
            }
            dp[tmp] = m+1;
        }
        
        
    }
    
    int ma = 0;
    rep(i,n){
        ma = max(ma, dp[i]);
    }
    cout << ma << endl;
    
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

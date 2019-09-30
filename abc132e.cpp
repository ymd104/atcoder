#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
sからtへの3の倍数の経路のうち最小のものを出力する

1 -> 2 を
1 -> 5
2 -> 6
3 -> 4

深さ優先探索
進められる辺がなくなるまで、以下を繰り返す
1. スタート地点から伸びる辺を選択し、sを訪問済みにセットして、辺の先の頂点をスタックに追加
2. 以後、スタックの上にある頂点が未到達なら到達済みに変更した上で辺の先の頂点をスタックに追加
なお、未到達の管理は配列に整数値を格納することで行う. デフォルトでは-1、到達したら最短距離を格納
*/

void solve(){
    ll n,m;
    cin >> n >> m;
    vector<ll> g[n*3+10];
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        g[3*a-2].emplace_back(3*b-1);
        g[3*a-1].emplace_back(3*b);
        g[3*a].emplace_back(3*b-2);
    }
    ll s,t;
    cin >> s >> t;

    ll visited[3*n+10];
    rep(i,3*n+1){
        visited[i]=-1;
    }
    /*
    stack<ll> st;
    st.push(s*3-2);
    visited[s*3-2]=0;
    while(!st.empty()){
        ll tmp = st.top();
        st.pop();
        for(auto i:g[tmp]){
            if(visited[i]==-1){
                visited[i]=visited[tmp]+1;
                st.push(i);
            }
        }
    }
    */
    //DFSだとWAが生える
    queue<ll> q;
    q.push(s*3-2);
    visited[s*3-2]=0;
    while(!q.empty()){
        ll tmp = q.front();
        q.pop();
        for(auto i:g[tmp]){
            if(visited[i]==-1){
                visited[i]=visited[tmp]+1;
                q.push(i);
            }
        }
    }
    
    if(visited[t*3-2]!=-1) cout << visited[t*3-2]/3 << endl;
    else cout << -1 << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
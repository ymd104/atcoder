#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
橋判定はO(N+M)でできるらしいが、面倒
*/

bool b[60];
vector<int> vec[60];
//vec[i]:頂点i(+1)の隣接頂点
void dfs(int v){
    b[v]=true;
    for(int i:vec[v]){
        if(!b[i]) dfs(i);
    }
    return;
}


void solve(){
    int n, m;
    cin>> n >> m;
    vector<pair<int,int>> vp;
    rep(i,m){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        vp.emplace_back(make_pair(tmp1-1,tmp2-1));
        //vec[tmp1-1].emplace_back(tmp2-1);
    }
    int ans = 0;
    rep(i,m){
        rep(j,m){
            if(i!=j){
                int t1,t2;
                t1 = vp[j].first;
                t2 = vp[j].second;
                vec[t1].emplace_back(t2);
                vec[t2].emplace_back(t1);
            }
        }
        rep(i,n){
            b[i]=false;
        }
        dfs(0);
        bool allvisited=true;
        rep(i,n){
            if(b[i]==false) allvisited = false; 
        }
        if(!allvisited) ans++;
        allvisited = true;


        rep(k,n){
            vec[k].clear();
        }
        
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}


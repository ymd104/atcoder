#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int ad_num[110];
vector<int> ad[110];
int t=0;
int d[110];
int f[110];

void dfs(int v){
    t++;
    if(d[v]==-1) d[v]=t;
    //if(ad_num[v]==0) return;
    for(auto e: ad[v]){
        //t++;
        if(d[e]==-1) dfs(e);
    }
    t++;
    if(f[v]==-1) f[v]=t;
}

void solve(){

    int n;
    cin >> n;
    rep(i,n){
        int trash;
        cin >> trash;
        cin >> ad_num[i];
        rep(j,ad_num[i]){
            int tmp;
            cin >> tmp;
            tmp--;
            ad[i].emplace_back(tmp);
        }
    }
    rep(i,n){
        d[i]=-1;
        f[i]=-1;
    }
    dfs(0);
    rep(i,n){
        if(d[i]==-1) dfs(i);
    }

    rep(i,n){
        cout << i+1 << " " << d[i] << " " << f[i] << endl;
    }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

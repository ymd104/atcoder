#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int s[100010];
int t[100010];
int c[100010];
int sum[100010];
vector<pair<int,int>> v[35];

void solve(){

    int N,C;
    cin >> N >> C;
    rep(i,N){
        cin >> s[i] >> t[i] >> c[i];
        c[i]--;
        v[c[i]].emplace_back(make_pair(s[i],t[i]));
    }
    rep(i,C){
        sort(v[i].begin(), v[i].end());
        rep(j, v[i].size()){
            if(j==v[i].size()-1) continue;
            if(v[i][j].second==v[i][j+1].first){
                v[i][j]={0,0};
                v[i][j+1].first=v[i][j].first-1;
            }
        }
        
    }
    rep(i,100005){
        sum[i]=0;
    }
    /*
    rep(i,N){
        sum[max(s[i]-1,0)]++;
        sum[t[i]]--;
    }
    */
    rep(i,C){
        rep(j,v[i].size()){
            auto e=v[i][j];
            //cout << e.first << " " << e.second << endl;
            sum[max(e.first-1,0)]++;
            sum[e.second]--;
        }
    }
    
    /*
    rep(i,4){
        cout << i << ":" << sum[i] << endl;
    }
    */
    
    rep(i,100005){
        if(i==0) continue;
        sum[i]=sum[i-1]+sum[i];
    }
    int ans = 1;
    rep(i,100005){
        ans = max(ans,sum[i]);
    }
    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

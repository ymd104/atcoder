#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

map<pair<int,int>,bool> mp;

void solve(){


    int m;
    cin >> m;
    vector<pair<int,int>> vs;
    rep(i,m){
        int x,y;
        cin >> x >> y;
        vs.emplace_back(make_pair(x,y));
    }
    int n;
    cin >> n;
    vector<pair<int,int>> va;
    rep(i,n){
        int x,y;
        cin >> x >> y;
        va.emplace_back(make_pair(x,y));
        mp[make_pair(x,y)] = true;
    }

    rep(i,va.size()){
        int x,y;
        x = va[i].first;
        y = va[i].second;
        bool isok=true;
        for(int j=1; j<m; j++){
            int dx, dy;
            dx = vs[j].first-vs[0].first;
            dy = vs[j].second-vs[0].second;
            if(1-mp.count(make_pair(x+dx,y+dy))){
                isok=false;
                break;
            }
        }
        if(isok){
            cout << x-vs[0].first << " " << y-vs[0].second << endl;
            break;
        }
    }


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

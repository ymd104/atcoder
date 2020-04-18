#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

bool b[10010][10010];

void solve(){

    int n;
    cin >> n;
    vector<pair<int,int>> v;
    rep(i,5010){
        rep(j,5010){
            b[i][j]=false;
        }
    }
    rep(i,n){
        int x,y;
        cin >> x >> y;
        v.emplace_back(make_pair(x,y));
        b[x][y]=true;
    }

    ll ans = 0;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int x1,x2,y1,y2;
            x1=v[i].first;
            y1=v[i].second;
            x2=v[j].first;
            y2=v[j].second;
            int x3,x4,y3,y4;
            x3 = x2+y1-y2;
            y3 = y2+x2-x1;
            x4 = x1+y1-y2;
            y4 = y1+x2-x1;
            if(x3>=0&&x4>=0&&y3>=0&&y4>=0){
                if(b[x3][y3]&&b[x4][y4]){
                    ans=(max(ans, ll((y1-y2)*(y1-y2)+(x1-x2)*(x1-x2))));
                }
            }
            

            x3 = x2-y1+y2;
            y3 = y2-x2+x1;
            x4 = x1-y1+y2;
            y4 = y1-x2+x1;
            if(x3>=0&&x4>=0&&y3>=0&&y4>=0){
                if(b[x3][y3]&&b[x4][y4]){
                    ans=(max(ans, ll((y1-y2)*(y1-y2)+(x1-x2)*(x1-x2))));
                }
            }

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

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

bool b[12];
bool isfriend[12][12];

void solve(){

    int n,m;
    cin >> n >> m;
    rep(i,n){
        rep(j,n){
            isfriend[i][j]=false;
        }
    }
    rep(i,m){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        isfriend[x][y]=true;
    }
    int maxh=0;
    for (int bit = 0; bit < (1<<n); ++bit) {
        int tmp=bit;
        vector<int> v;
        for(int j=0; j<n; j++){
            if(tmp%2==1) {
                b[j]=true;
                v.emplace_back(j);
            }
            else{
                b[j]=false;
            }
            tmp = tmp/2;
        }

        bool t = true;

        for(int i=0; i<v.size(); i++){
            for(int j=i+1; j<v.size(); j++){
                if(!isfriend[v[i]][v[j]]) t=false;
            }
        }

        /*
        rep(i,v.size()){
            cout << v[i]+1 << " ";
        }
        cout << (t? "true": "false");
        cout << endl;
        */

        if(t) maxh=max(int(maxh),int(v.size()));

    }

    cout << maxh << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

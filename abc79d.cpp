#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

/*
c[i][j]:iをjに変えるのに必要な魔力
c[i][j]を、iをkに変えてからjに変えるのに必要な魔力の最小値として再計算
kは0~9全ての値で良い
10回繰り返す

どうやらこの手法(グラフ内の全ペアの最短経路をO(V^3)で計算するアルゴリズム)を
ワーシャルフロイド法というらしい
*/

void solve(){
    int h,w;
    cin >> h >> w;
    int c[11][11];
    rep(i,10){
        rep(j,10){
            cin >> c[i][j];
        }
    }
    int a[h+10][w+10];
    vector<int> x;
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
            x.emplace_back(a[i][j]);
        }
    }
    rep(notused, 10){
    rep(i,10){
        rep(j,10){
            rep(k,10){
                c[i][j]=min(c[i][j], c[i][k]+c[k][j]);
            }
        }
    }
    }

    int sum=0;
    rep(i,x.size()){
        if(x[i]!=-1) sum += c[x[i]][1];
    }
    cout << sum << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}


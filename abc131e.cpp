#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
こういう問題は実装より証明の方が大事なので、証明を追います

N頂点連結グラフには少なくともN-1本の辺が存在する(最低でも木なので).
これらの辺は距離1で頂点を結ぶため、最短距離が1である頂点対がN-1存在する.
頂点対は多くともNC2=N(N-1)/2で、そのうち最低でもN-1が最短距離1の頂点対であるから、
N(N-1)/2-(N-1) = (N-1)(N-2)/2 < K であるような場合、グラフは構成できない.

逆に (N-1)(N-2)/2 >= K であるような場合、そのようなグラフを常に構成できる.
１つの頂点とそれ以外の頂点のみを結ぶグラフを考えると、このグラフの頂点対で距離が2のものは (N-1)(N-2)/2.
(N-1)(N-2)/2 のうちから、頂点対同士を結んでいくことでデクリメントができる.
この操作を K - (N-1)(N-2)/2 回繰り返せばいい.
*/

void solve(){
    int n,k;
    cin >> n >> k;
    int thr = (n-1)*(n-2)/2;
    if(thr < k) cout << -1 << endl;
    else{
        cout << n-1+thr-k << endl;
        rep(i,n-1){
            cout << 1 << " " << i+2 << endl;
        }
        /*
        2 3  2 4  2 5  ...  2 n  3 4  3 5 ... ... n-1 n
        */
        vector<pair<int,int>> vp;
        for(int p=2; p<n; p++){
            for(int q=p+1; q<=n; q++){
                vp.emplace_back(make_pair(p,q));
            }
        }
        int pointer = 0;
        rep(i,thr-k){
            cout << vp[i].first << " " << vp[i].second << endl;
            pointer++;
        }
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
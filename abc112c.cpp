#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;

/*
hi = h - |xi - cx| - |yi - cy|
の式N個から、h, cx, cyを計算する

cx、cyを全探索し、hがすべて同じになるような場合を答えとする
計算量は1000000程度なのでいけそう
*/

void solve(){
    int n;
    cin >> n;
    vector<int> x;
    vector<int> y;
    vector<int> h;
    rep(i,n){
        int a,b,c;
        cin >> a >> b >> c;
        x.emplace_back(a);
        y.emplace_back(b);
        h.emplace_back(c);
    }
    bool ans = true;
    int a1,a2,a3;
    rep(cx,101){
        rep(cy,101){
            ans = true;
            int tmp=0;
            while(h[tmp]==0){
                tmp++;
            }
            int cons = h[tmp] + abs(x[tmp]-cx) + abs(y[tmp]-cy);
            for(int i=0; i<n; i++){
                if(h[i] != max(cons - abs(x[i]-cx) - abs(y[i]-cy),(ll)0)){
                    ans = false;
                }
            }
            if(ans) {
                a1 = cx;
                a2 = cy;
                a3 = cons;
            }
        }
    }
    cout << a1 << " " << a2 << " " << a3 << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

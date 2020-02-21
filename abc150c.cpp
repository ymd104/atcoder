#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


void solve(){

    int n;
    cin >> n;
    const int t = n;
    vector<int> v(t);
    iota(v.begin(), v.end(), 1);       // v に 1, 2, ... N を設定
    int count = 0;
    vector<vector<int>> ve;
    do {
        vector<int> c;
        for(auto x : v) {
            c.emplace_back(x);
            //cout << x << " "; cout << "\n";    // v の要素を表示
        }
        ve.emplace_back(c);
    } while( next_permutation(v.begin(), v.end()) );     // 次の順列を生成
    rep(i,10){
        rep(j,n){
            //cout << ve[i][j];
        }
        //cout << endl;
    }

    vector<int> p;
    rep(i,n){
        int x;
        cin >> x;
        p.emplace_back(x);
    }
    int pi=0;
    rep(i,ve.size()){
        bool b=true;
        rep(j,n){
            if(ve[i][j]!=p[j]) b=false;
        }
        if(b){
            pi=i;
            break;
        }
        else{
            b=true;
        }
    }

    vector<int> q;
    rep(i,n){
        int x;
        cin >> x;
        q.emplace_back(x);
    }
    int qi=0;
    rep(i,ve.size()){
        bool b=true;
        rep(j,n){
            if(ve[i][j]!=q[j]) b=false;
        }
        if(b){
            qi=i;
            break;
        }
        else{
            b=true;
        }
    }

    cout << abs(pi-qi) << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

void solve(){

    ll n;
    cin >> n;
    if(n==1){
        cout << "Yes" << endl;
        cout << 2 << endl;
        cout << "1  1" << endl;
        cout << "1  1" << endl;
        return;
    }
    ll tmp=3;
    ll count=3;
    vector<vector<ll>> v;
    vector<ll> x;
    x.emplace_back(1);
    x.emplace_back(2);
    v.emplace_back(x);
    x.clear();
    x.emplace_back(1);
    x.emplace_back(3);
    v.emplace_back(x);
    x.clear();
    x.emplace_back(2);
    x.emplace_back(3);
    v.emplace_back(x);
    x.clear();
    while(n>tmp){
        rep(i,count){
            v[i].emplace_back(tmp+1+i);
        }
        vector<ll> y;
        rep(i,count){
            y.emplace_back(tmp+1+i);
        }
        v.emplace_back(y);
        tmp = tmp + count;
        count++;

    }
    if(n!=tmp) cout << "No" << endl;
    else{
        cout << "Yes" << endl;
        cout << v.size() << endl;
        rep(i, v.size()){
            auto t = v[i];
            cout << t.size() << " ";
            rep(j,t.size()){
                cout << t[j] << " ";
            }
            cout << endl;
        }
    }


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

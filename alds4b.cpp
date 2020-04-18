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
    vector<int> s;
    rep(i,n){
        int tmp;
        cin >> tmp;
        s.emplace_back(tmp);
    }
    int q;
    cin >> q;
    vector<int> t;
    rep(i,q){
        int tmp;
        cin >> tmp;
        t.emplace_back(tmp);
    }

    int count=0;
    rep(i,q){
        if(binary_search(s.begin(), s.end(), t[i])) count++;
    }

    cout << count << endl;


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

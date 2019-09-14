#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;


void solve(){
    int n;
    cin >> n;
    vector<int> p;
    rep(i,n){
        int tmp;
        cin >> tmp;
        p.emplace_back(tmp);
    }
    sort(p.begin(),p.end());
    int sum = 0;
    rep(i,n){
        sum += p[i];
    }
    sum -= (p[n-1]/2);
    cout << sum << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

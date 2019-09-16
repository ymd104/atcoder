#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;


void solve(){
    int n;
    cin >> n;
    string s[n+10];
    rep(i,n){
        cin >> s[i];
    }

    int m;
    cin >> m;
    string t[m+10];
    rep(i,m){
        cin >> t[i];
    }
    int count=0;
    int ma = 0;
    rep(i,n){
        count = 0;
        rep(j,n){
            if(s[i]==s[j]) count++;
        }
        //count--;
        rep(j,m){
            if(s[i]==t[j]) count--;
        }
        ma = max(ma, count);
    }
    cout << ma << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

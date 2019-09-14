#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;



void solve(){
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    if(s1.back()==s2.front()&&s2.back()==s3.front()) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;

/*
最初の得点がxの時、x*2^m>=kなる最小のmを求めれば良い
x*2^(m-1)<k     2^m<2*(k/x)
x*2^m>=k        2^m>=k/x

*/

void solve(){
    int n,k;
    cin >> n >> k;
    double ans = 0;
    rep(i,n){
        int score = i+1;
        double denominator = 1;
        while(1<=score&&score<k){
            denominator *= 2;
            score *= 2;
        }
        ans += 1/(denominator*n);
    }
    cout << setprecision(12) << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
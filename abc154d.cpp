#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

double p[200010];
double psum[200010];

void solve(){

    int n,k;
    cin >> n >> k;
    rep(i,n){
        cin >> p[i];
        p[i] = (p[i]+1)/2;
    }
    //期待値は出る目の最大値をcとして、(1+2+...+c)/c=(c+1)/2

    //psum[i]:p[i]からp[i+k-1]までの合計
    psum[0]=0;
    rep(i,k){
        psum[0] += p[i];
    }
    for(int i=1; i<n-k+1; i++){
        psum[i]=psum[i-1]-p[i-1]+p[i+k-1];
    }

    double ans = 0;
    rep(i,n-k+1){
        ans = max(ans, psum[i]);
        //cout << psum[i] << " ";
    }
    //cout << endl;

    cout << std::setprecision(12) << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

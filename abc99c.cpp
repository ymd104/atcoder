#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

/*
DPで解きます
*/

int unover(int a, int b){
    int tmp = 1;
    while(a>=pow(b,tmp)){
        tmp++;
    }
    return tmp-1;
}

int m3(int a, int b, int c){
    return max(a,max(b,c));
}

int dp[100010];

int ans(int i){
    if(dp[i]!=-1) return dp[i];
    else{
        if(i==0) {
            dp[i]=0;
            return 0;
        }
        else{
        int m = INF;
        m = min(m,ans(i-1)+1);
        rep(j,unover(i,6)){
            m = min(ans(i-pow(6,j+1))+1,m);
        }
        rep(j,unover(i,9)){
            m = min(ans(i-pow(9,j+1))+1,m);
        }
        dp[i]=m;
        return m;
        }
    }

}


void solve(){
    int n;
    cin >> n;
    rep(i,n+1){
        dp[i] = -1;
    }    
    dp[0] = 0;

    cout << ans(n) << endl;
    /*
    rep(i,n+1){
        cout << "dp[" << i << "]:" << dp[i] << endl;
    }
    */
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int f[190];
int dp1[1000100];
int dp2[1000100];


void solve(){

    int n=182;
    vector<int> v;

    while(true){
        int x;
        cin >> x;
        if(x==0) break;
        v.emplace_back(x);
    }


    rep(i,190){
        f[i]=i*(i+1)*(i+2)/6;
    }

    rep(i,1000100){
        dp1[i]=i;
        dp2[i]=i;
    }


    for(int k=1; k<=1000100; k++){
        rep(i,n){
            if(k>=f[i]) dp1[k]=min(dp1[k-f[i]]+1, dp1[k]);
            if(f[i]%2==1){
                if(k>=f[i]) dp2[k]=min(dp2[k-f[i]]+1, dp2[k]);
            }
        }
        /*
        rep(i,100){
            if(k>=fodd[i]) dp2[k]=min(dp2[k-fodd[i]]+1, dp2[k]);
        }
        */
    }


    rep(i,v.size()){
        cout << dp1[v[i]] << " " << dp2[v[i]] << endl;
    }


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

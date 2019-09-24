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
    int a[n+10];
    rep(i,n){
        cin >> a[i];
    }
    /*
    int count=0;
    rep(i,n){
        if(a[i]>=2){
            count += a[i]/2;
            a[i]=a[i]%2;
        }
    }
    for(int i=1; i<n; i++){
        if(a[i-1]==1&&a[i]==1){
            count++;
            a[i-1]=0;
            a[i]=0;
        }
    }
    cout << count << endl;
    */

    //上の解法だと、1 2 3の時にミスる
    //0がなければ、結局１枚だけ残してあとは全部回収することが可能

    ll ans=0;
    ll tmp=0;
    rep(i,n){
        if(a[i]==0){
            ans+=tmp/2;
            tmp=0;
        }
        else{
            tmp+=a[i];
        }
    }
    ans += tmp/2;
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

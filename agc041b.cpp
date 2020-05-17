#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

ll a[100010];
ll sum[100010];
//sum[i]:a[i-1]までの総和

void solve(){

    ll n,m,v,p;
    cin >> n >> m >> v >> p;
    //p--;
    sum[0]=0;
    rep(i,n){
        cin >> a[i];
        sum[i+1]=sum[i]+a[i];
    }
    sort(a,a+n,greater<int>());
    ll l=0;
    ll r=n;
    ll i;
    while(r-l>1){
        i=(l+r)/2;
        //cout << "i:" << i; 
        if(p-1>=i) l=i;
        else if(v<=p-1+n-i){
            if(a[p-1]<=a[i]+m){
                l=i;
                //cout << " " << "1,OK" << endl;
            }
            else{
                r=i;
                //cout << " " << "1,NG" << endl;
            }
        }
        else{
            if(  (a[i]+m)*(i-(p-1))-(sum[i]-sum[p-2]) > (v-(p-1+n-i))*m  ){
                l=i;
                //cout << " " << "2,OK" << endl;
            }
            else{
                r=i;
                //cout << " " << "2,NG" << endl;
            }
        }
    }

    cout << r << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

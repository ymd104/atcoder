#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll a[200010];
ll sum[200010];
//0~i-1までの総和
//a[i]~a[j]までの総和はsum[j+1]-sum[i]と計算できる

void solve(){

    rep(i,200010){
        sum[i]=0;
    }

    ll n;
    cin >> n;
    rep(i,n){
        cin >> a[i];
        sum[i+1]=sum[i]+a[i];
    }
    ll m = INF;
    ll anstmp=0;
    for(ll i=1; i<n-2; i++){
        //iの右で区切る
        ll left = sum[i+1]-sum[0];
        ll right = sum[n]-sum[i+1];
        if(m>abs(left-right)) {
            anstmp = i;
            m = abs(left-right);
        }
    }
    m = INF;
    ll ansleft = 0;
    for(ll i=0; i<anstmp; i++){
        ll left = sum[i+1]-sum[0];
        ll right = sum[anstmp]-sum[i+1];
        if(m>abs(left-right)) {
            ansleft = i;
            m = abs(left-right);
        }
    }
    m = INF;
    ll ansright = 0;
    for(ll i=anstmp+1; i<n-1; i++){
        ll left = sum[i+1]-sum[anstmp];
        ll right = sum[n]-sum[i+1];
        if(m>abs(left-right)) {
            ansright = i;
            m = abs(left-right);
        }
    }
    cout << ansleft << " " << anstmp << " " << ansright << endl;
    ll s1,s2,s3,s4;
    s1 = sum[ansleft+1]-sum[0];
    s2 = sum[anstmp+1]-sum[ansleft+1];
    s3 = sum[ansright+1]-sum[anstmp+1];
    s4 = sum[n]-sum[ansright+1];
    cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
    ll ma = max(max(s1,s2),max(s3,s4));
    ll mi = min(min(s1,s2),min(s3,s4));
    cout << ma-mi << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

void solve(){
    ll n;
    cin >> n;
    ll a[n+10];
    rep(i,n){
        cin >> a[i];
        a[i] = a[i] - i - 1;
    }
    /*
    long double avg;
    long double sum=0;
    rep(i,n){
        sum+=(long double)a[i];
    }
    avg = sum/n;
    ll t = ceil(avg);
    */
    //最初は平均値でやっていたが、どうやら平均値でなく中央値でやるのが最適らしい
    /*
    1 1 1 97
    avg=25 24*3+72=144
    med=1 96

    0 -1 -2 -3 -3 -3 -3
    */

    sort(a,a+n);
    int med;
    if(n%2==0){
        med = (a[n/2-1]+a[n/2])/2;
    }
    else{
        med = a[n/2];
    }

    ll s1,s2;
    s1=0;
    s2=0;
    rep(i,n){
        s1 += abs(a[i]-med);
    }
    rep(i,n){
        s2 += abs(a[i]-med+1);
    }

    cout << min(s1,s2) << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

/*

*/

void solve(){
    ll n,len;
    cin >> n >> len;
    ll a[n+10];
    rep(i,n){
        cin >> a[i];
    }
    ll l=0;
    ll r=n-1;
    //a[l]+...+a[r]を計算する必要がある
    //s[i]:a[0]+...+a[i]
    ll s[n+10];
    s[0]=a[0];
    for(ll i=1; i<n; i++){
        s[i]=s[i-1]+a[i];
    }
    //a[l]+...+a[r]=s[r]-a[l-1]
    //ただしl=0ならs[r]
    //番兵の配置が面倒なので

    string ans = "Possible";
    vector<ll> answer;
    while(r-l>0){
        ll sum;
        if(l==0) sum = s[r];
        else sum = s[r]-s[l-1];

        if(sum<len){
            ans = "Impossible";
            cout << ans << endl;
            return;
        }
        else{
            if(a[l]+a[l+1]>a[r]+a[r-1]){
                answer.emplace_back(r-1);
                r--;
            }
            else{
                answer.emplace_back(l);
                l++;
            }
        }
    }
    cout << ans << endl;
    rep(i,answer.size()){
        cout << answer[i]+1 << endl;
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}


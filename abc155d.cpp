#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
二分探索.
*/

ll n,k;
vector<ll> p,m,z;

bool judge_m(ll mid){
  ll sum = 0;
  for (ll i = 0; i < (ll)p.size(); i++) {
        ll d = (mid - p[i] + 1) / p[i];
        sum += upper_bound(m.begin(), m.end(), d) - m.begin();
    }
    return sum >= k;
}


bool judge_p(ll mid) {
    ll sum = 0;
    for (int i = 0; i < (int)p.size(); i++) {  // 正と正の積
        ll d = mid / p[i];
        ll tmp = upper_bound(p.begin(), p.end(), d) - p.begin();
        if (i < tmp) tmp--;  // 自身を除く
        sum += tmp;
    }
    for (int i = 0; i < (int)m.size(); i++) {  // 負と負の積
        ll d = mid / m[i];
        ll tmp = upper_bound(m.begin(), m.end(), d) - m.begin();
        if (i < tmp) tmp--;  // 自身を除く
        sum += tmp;
    }
    sum /= 2;
    return sum >= k;
}


ll a[200010];

void solve(){

    cin >> n >> k;

    ll numn = 0;
    ll num0 = 0;
    ll nump = 0;
    rep(i,n){
        cin >> a[i];
        if(a[i]<0) {
            numn++;
            m.eb(a[i]);
        }
        if(a[i]==0) {
            num0++;
            z.eb(a[i]);
        }
        if(a[i]>0) {
            nump++;
            p.eb(a[i]);
        }
    }

    sort(a,a+n);
    
    /*
    for(auto e:p){
       cout << e << " ";
    }
    cout << endl;
    */

    if(numn*nump>=k){
        sort(m.begin(), m.end());
        sort(p.begin(), p.end());
        //負*正の数がkより大きいので、小さい方からk個取ろうとすると負のものになるはず
        //
        ll l = -1e18 - 1;
        ll r = -1;  // 二分探索: (l,u]に答えがある
        while (r - l > 1) {
            ll mid = (r + l) / 2;
            if (judge_m(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << r << endl;
    }
    else if(numn*nump + num0 >= k){
      cout << 0 << endl;
    }
    else{
        k -= (numn+num0);
        sort(m.begin(), m.end());
        rep(i,m.size()){
          m[i]= -m[i];
        }
        sort(p.begin(), p.end());
        ll l=-1;
        ll r=1e18+1;
        while(r-l>1){
          ll mid = (l+r)/2;
          if(judge_p(mid)){
            r=mid;
          }
          else{
            l=mid;
          }
        }
        cout << r << endl;
    }


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

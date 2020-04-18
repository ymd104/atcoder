#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int a[100010];

void solve(){

    int n;
    cin >> n;
    vector<int> v;
    rep(i,n){
        cin >> a[i];
    }
    int m = a[0];
    int d = 0;
    rep(i,n){
        a[i]=(a[i]+i%2)%2;
    }
    rep(i,n){
        if(a[i]==m) d++;
        else{
            v.emplace_back(d);
            d=1;
            m=a[i];
        }
    }
    v.emplace_back(d);

    /*
    for(auto e:v){
        cout << e << endl;
    }
    */

    int ans = 0;
    if(v.size()==1){
        cout << v[0] << endl;
        return;
    }
    if(v.size()==2){
        cout << v[0]+v[1] << endl;
        return;
    }
    for(int i=1; i<=v.size()-2; i++){
        ans = max(ans, v[i-1]+v[i]+v[i+1]);
    }
    cout << ans << endl;


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

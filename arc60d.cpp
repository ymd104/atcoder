#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

ll sum(ll p, ll q){
    // qをp進法表示した時の桁の和
    if(q<p) return q;
    else{
        return sum(p,(q/p))+(q%p);
    }
}



void solve(){

    ll n,s;
    cin >> n >> s;
    /*
    if(s>(n+2)/2){
        cout << -1 << endl;
        return;
    }
    */

    if(s==n) {
        cout << s+1 << endl;
        return;
    }

    ll root = ll(sqrt(n))+1;
    for(ll i=2; i<=root; i++){
        if(sum(i,n)==s){
            cout << i << endl;
            return;
        }
    }
    
    for(ll x=root; x>=1; x--){
        if((n-s)%x==0){
            ll y = s-x;
            ll b = (n-s)/x + 1;
            //cout << x << " " << y << " " << b << endl;
            if(1<=x&&x<b&&0<=y&&y<b){
                cout << b << endl;
                //cout << "x:" << x << " n-s:" << n-s << endl;
                return;
            }
        }
    }

    cout << -1 << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

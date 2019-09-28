#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
各iについて、
x=h*iとして、残りの面積はh%2==0ならh/2*(w-i)が２つ
h%2!=0ならh/2*(w-i)と(h/2+1)*(w-i)
wについても同じことをやる
*/

void solve(){
    ll h,w;
    cin >> h >> w;
    ll ans = INF;
    for(ll i=1; i<w; i++){
        ll x,y,z;
        x=h*i;
        if(h%2==0) {
            y = h/2 * (w-i);
            z = y;
        }
        else{
            y = h/2 * (w-i);
            z = (h+1)/2 * (w-i);
        }
        ll tmp, tmp2;
        tmp = min(x,min(y,z));
        tmp2 = max(x,max(y,z));
        ans = min(ans,tmp2-tmp);
        //cout << i << " " << x << " " << y << " " << z << endl;
    }
    for(ll i=1; i<h; i++){
        ll x,y,z;
        x=w*i;
        if(w%2==0) {
            y = w/2 * (h-i);
            z = y;
        }
        else{
            y = w/2 * (h-i);
            z = (w+1)/2 * (h-i);
        }
        ll tmp, tmp2;
        tmp = min(x,min(y,z));
        tmp2 = max(x,max(y,z));
        ans = min(ans,tmp2-tmp);
        //cout << i << " " << x << " " << y << " " << z << endl;
    }
    //cout << h%3*w << endl;
    //cout << w%3*h << endl;

    ans = min(ans,h%3*w);
    ans = min(ans,w%3*h);
    ans = min(ans,(3-h%3)*w);
    ans = min(ans,(3-w%3)*h);
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}


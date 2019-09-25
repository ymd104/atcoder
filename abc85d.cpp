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
    int n,h;
    cin >> n >> h;
    int a[n+10];
    int b[n+10];
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    sort(a,a+n,greater<int>());
    sort(b,b+n,greater<int>());
    int ans=0;
    int pointer=0;
    while(h>0){
        if(b[pointer]>a[0]&&pointer<n){
            h = h - b[pointer];
            pointer++;
            ans++;
        }
        else{
            if(h%a[0]==0){
                ans += h/a[0];
                h=0;
            }
            else{
                ans += h/a[0]+1;
                h=0;
            }
        }
    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}


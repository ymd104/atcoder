#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

void solve(){

    int n;
    string s;
    cin >> n >> s;
    int ans = 0;

    rep(i,1000){
        int p = 0;
        
        int abc[3];
        abc[0] = i/100;
        abc[1] = (i/10)%10;
        abc[2] = i%10;

        int tmp=0;
        int count=0;
        bool b=false;
        while(p<n){
            if((s[p]-'0')==abc[tmp]){
                count++;
                tmp++;
            }
            p++;
            if(tmp==3){
                b = true;
                break;
            }
        }
        if(b) ans++;
        //if(b) cout << i << endl;

    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

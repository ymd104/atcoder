#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll sumr[4010];
ll sumg[4010];
ll sumb[4010];

void solve(){

    ll n;
    cin >> n;
    string s;
    cin >> s;
    rep(i,4010){
        sumr[i]=0;
        sumg[i]=0;
        sumb[i]=0;
    }
    rep(i,n){
        sumr[i+1]=sumr[i];
        sumg[i+1]=sumg[i];
        sumb[i+1]=sumb[i];
        if(s[i]=='R') sumr[i+1]++;
        if(s[i]=='G') sumg[i+1]++;
        if(s[i]=='B') sumb[i+1]++;
    }

    ll ans = 0;
    for(ll i=0; i<n; i++){
        for(ll j=i+1; j<n; j++){
            char p = s[i];
            char q = s[j];
            char r;
            if(p=='R'&&q=='G'||p=='G'&&q=='R') r='B';
            else if(p=='R'&&q=='B'||p=='B'&&q=='R') r='G';
            else if(p=='B'&&q=='G'||p=='G'&&q=='B') r='R';
            else continue;
            ll k = 2*j-i;

            if(r=='R'){
                if(s[k]=='R') ans--;
                ans += sumr[n]-sumr[j+1];
            }
            if(r=='G'){
                if(s[k]=='G') ans--;
                ans += sumg[n]-sumg[j+1];
            }
            if(r=='B'){
                if(s[k]=='B') ans--;
                ans += sumb[n]-sumb[j+1];
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

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

long double v[60];

ll COM[60][60];

void COMinit(void){
    rep(i,60){
        rep(j,60){
            if(i<j) {
                COM[i][j]=0;
                continue;
            }
            if(i==0) {
                COM[i][j]=0;
                continue;
            }
            if(j==0) {
                COM[i][j]=1;
                continue;
            }
            if(i==j){
                COM[i][j]=1;
                continue;
            }
            COM[i][j]=COM[i-1][j-1]+COM[i-1][j];
        }
    }
}


void solve(){

    COMinit();

    ll n,a,b;
    cin >> n >> a >> b;
    rep(i,n){
        cin >> v[i];
    }
    sort(v,v+n, greater<long double>());
    long double avg=0;
    rep(i,a){
        avg += v[i];
    }
    avg /= a;
    cout << setprecision(18) << avg << endl;

    if(v[0]!=v[a-1]){
        ll x=0;
        ll y=0;
        rep(i,n){
            if(v[i]==v[a-1]){
                if(i<=a-1) x++;
                else y++;
            }
        }
        cout << COM[x+y][x] << endl;
    }

    else{
        ll count = 0;
        rep(i,n){
            if(v[i]==v[0]) count++;
        }

        ll ans=0;
        if(count>=b){
            for(ll t=a; t<=b; t++){
                ans += COM[count][t];
                //cout << "count:" << count << " t:" << t << " C:" <<  COM[count][t] << endl;
            }
        }
        else{
            for(ll t=a; t<=count; t++){
                ans += COM[count][t];
            }
        }
        //cout << count << endl;

        cout << setprecision(20) << ans << endl;
    }
    

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

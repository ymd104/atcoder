#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll p[10];
ll p2[10];

bool run(ll x){
    ll tmp=x;
    ll i=0;
    while(tmp>0){
        p[i] = tmp%10;
        tmp = tmp / 10;
        i++;
    }
    //桁数i
    for(ll j=1; j<i; j++){
        if(abs(p[j]-p[j-1])>1) return false;
    }
    return true;
}

ll ch(ll x){
    ll tmp=x;
    ll i=0;
    while(tmp>0){
        p2[i] = tmp%10;
        tmp = tmp / 10;
        i++;
    }
    bool aaa = false;
    for(ll j=1; j<i; j++){
        if(p2[j]-p2[j-1]>=2){
            p2[j]--;
            p2[j-1]++;
            aaa = true;
            break;
        }
        if(aaa) break;
    }
    ll m = 1;
    rep(t,i){
        m = m*10+p2[t];
    }
    return m;
}

ll dp[11][25];

void solve(){

    //cout << ch(96) << endl;

    ll k;
    cin >> k;
    rep(i,11){
        rep(j,25){
            dp[i][j]=0;
        }
    }

    rep(i,10){
        dp[i][1]=1;
    }

    for(ll j=2; j<25; j++){
        rep(i,10){
            if(i!=0&&i!=9){
                dp[i][j]=dp[i-1][j-1]+dp[i][j-1]+dp[i+1][j-1];
            }
            if(i==0){
                dp[i][j]=dp[0][j-1]+dp[1][j-1];
            }
            if(i==9){
                dp[i][j]=dp[8][j-1]+dp[9][j-1];
            }
        }
    }

    /*
    rep(i,10){
        rep(j,4){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */

    ll s = 0;
    ll x,y;
    ll p,q;
    bool b=false;
    rep(j,25){
        rep(i,9){
            s+=dp[i+1][j];
            if(s>=k){
                x = i+1;
                y = j;
                b=true;
                s-=dp[i+1][j];
                break;
            }
            else{
                p = i+1;
                q = j;
            }
        }
        if(b) break;
    }
    /*

    cout << x << " " << y << endl;
    cout << p << " " << q << endl;
    cout << s << endl;
    */

    //k番目のものはxで始まるy桁のルンルン数

    ll tmp = ll(pow(10,y-1)*x);
    ll t2= ll(pow(10,y-1));
    //cout << tmp << "  " << t2 << endl;
    ll c = k-s;
    ll count = 0;
    ll ans=0;
    for(ll i=tmp; i<=tmp+t2; i++){
        ans = i;
        if(run(i)){
            count++;
        }
        if(count>=c){
           
            break;
        }
        ll tm = i;
        string st = to_string(tm);
        ll leng = st.length();
        if(st[2]-st[1]>=2){
            i = ((st[1]-'0')+1+10*(st[0]-'0'))*pow(10,leng-2)-1;
            //cout << i << endl;
        }
        if(st[3]-st[2]>=2){
            i = ((st[2]-'0')+1+100*(st[0]-'0') + 10*(st[1]-'0'))*pow(10,leng-3)-1;
            //cout << i << endl;
        }
        if(st[4]-st[3]>=2){
            i = ((st[3]-'0')+1+1000*(st[0]-'0') + 100*(st[1]-'0') + 10*(st[2]-'0'))*pow(10,leng-4)-1;
            //cout << i << endl;
        }
        if(st[5]-st[4]>=2){
            i = ((st[4]-'0')+1+10000*(st[0]-'0') + 1000*(st[1]-'0') + 100*(st[2]-'0') + 10*(st[3]-'0'))*pow(10,leng-5)-1;
            //cout << i << endl;
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

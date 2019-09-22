#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

ll digit(ll x){
    ll count = 1;
    while(x>=10){
        count++;
        x=x/10;
    }
    return count;
}
/*
int a[11];

void base2(int x, int d){
    rep(i,d){
        a[i] = x%2;
        x = x/2;
    }
}
*/

ll d;

string base2(ll x){
    string s="";
    while(x!=0){
        if(x%2==1){
            s = '1'+s;
        }
        else{
            s = '0'+s;
        }
        x=x/2;
    }
    ll siz = s.size();
    while(d-1!=siz){
        s = '0' + s;
        siz++;
    }
    return s;
}


void solve(){
    ll s;
    cin >> s;
    ll count = 0;
    d = digit(s);
    rep(i,pow(2,d-1)){
        string t = base2(i);
        //cout << "i:" << i << " t:" << t << endl;
        t = t + '2';
        /*2進法表記
        例えばs=12345, 1011なら、1+23+4+5
        t[0]=1なのでs[0]を足す
        t[1]=0なのでtmp=s[1]
        t[2]=1なのでtmp*10+s[2]を足す
        t[3]=1なのでs[3]を足す
        */
        ll tmp=0;
        rep(j,t.size()+1){
            string st = to_string(s);
            char c=st[j];
            ll x = c-'0';
            tmp += x;
            if(t[j]=='1') {
                count += tmp;
                //cout << tmp << endl;
                tmp=0;
            }
            else if(t[j]=='2'){
                count += tmp;
                //cout << tmp << endl;
                tmp=0;
            }
            else {
                tmp = tmp*10;
            }
            //cout << tmp << endl;
        }

    }

    cout << count << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

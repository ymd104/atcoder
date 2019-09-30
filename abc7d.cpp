#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;



void solve(){
    ll a,b;
    cin >> a >> b;
    string s,t;
    s = to_string(a-1);
    t = to_string(b);

    unordered_map<char,ll> mp;
    mp['0']=0;
    mp['1']=1;
    mp['2']=2;
    mp['3']=3;
    mp['4']=4;
    mp['5']=4;
    mp['6']=5;
    mp['7']=6;
    mp['8']=7;
    mp['9']=8;

    ll sans=0;
    bool b1=true;
    rep(i,s.size()){
        if(i==0||(s[i-1]!='4'&&s[i-1]!='9')) sans += mp[s[i]]*(ll)pow(8,s.size()-i-1);
        else {
            b1=false;
            break;
        }
    }
    if (b1&&s.back()!='4'&&s.back()!='9') sans++;
    sans = a-1-sans;
    //cout << sans << endl;

    ll sant=0;
    bool b2 =true;
    rep(i,t.size()){
        if(i==0||(t[i-1]!='4'&&t[i-1]!='9')) sant += mp[t[i]]*(ll)pow(8,t.size()-i-1);
        else {
            b2=false;
            break;
        }
    }
    if (b2&&t.back()!='4'&&t.back()!='9') sant++;
    sant = b-sant;
    //cout << sant << endl;

    cout << sant-sans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
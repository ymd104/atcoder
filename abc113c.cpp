#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;

/*
識別番号の配列num[m]
市の数を数える配列check[n]
配列<年数、<県、市の番号>>をソート
check[p]を調べ、取り出した数をnumに格納。１を足してcheckに代入
*/

int digitnumber(int a){
    int tmp=1;
    while(a/10!=0) {
        tmp++;
        a = a/10;
    }
    return tmp;
}

string number(int a, int b){
    string s="";
    string t="";
    rep(i, 6-digitnumber(a)){
        s = "0" + s;
    }
    s = s + to_string(a);
    rep(i, 6-digitnumber(b)){
        t = "0" + t;
    }
    t = t + to_string(b);
    return s + t;
}

void solve(){
    int n,m;
    cin >> n >> m;
    string num[m+10];
    rep(i,m){
        num[i] = "";
    }
    int check[n+10];
    rep(i,n){
        check[i]=0;
    }
    vector<pair<int, pair<int,int>>> v;
    rep(i,m){
        int p,y;
        cin >> p >> y;
        v.emplace_back(make_pair(y, make_pair(p,i)));
    }

    sort(v.begin(), v.end());
    rep(i,m){
        int pnum = (v[i].second).first;
        int tmp = check[pnum-1];
        int nu = (v[i].second).second;
        num[nu] = number(pnum, tmp+1);
        check[pnum-1]++;
    }

    rep(i,m){
        cout << num[i] << endl;
    }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

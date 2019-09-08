#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;

vector<ll> v;
ll l;

bool num753(ll i){
    bool n7=false;
    bool n5=false;
    bool n3=false;
    while(i!=0){
        ll j;
        j = i%10;
        if(j==7) n7=true;
        if(j==5) n5=true;
        if(j==3) n3=true;
        i /= 10;
    }
    return n7&&n5&&n3;
}

void dfs(ll t){
    ll x = t*10+3;
    //cout << t << endl;
    if(x<=l){
        if(num753(x)) {v.emplace_back(x);}
        dfs(x);
    }
    if(x+2<=l){
        if(num753(x+2)) {v.emplace_back(x+2);}
        dfs(x+2);
    }
    if(x+4<=l){
        if(num753(x+4)) {v.emplace_back(x+4);}
        dfs(x+4);
    }
}

void solve(){
    ll n;
    cin >> n;
    //753数を列挙。
    l = n;
    dfs(0);
    ll count = 0;
    for(auto x:v){
        if(num753(x)){
            count++;
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

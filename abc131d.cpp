#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;


/*
締め切りが近いものから順に貪欲で処理？
*/


void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        v.emplace_back(make_pair(b,a));
    }

    sort(v.begin(), v.end());
    string s = "Yes";
    int time = 0;
    rep(i,n){
        time += v.at(i).second;
        if(time > v.at(i).first){
            s = "No";
            break;
        }
    }
    cout << s << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
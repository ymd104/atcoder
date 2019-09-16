#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;


bool judge(int x){
    vector<int> v;
    while(x!=0){
        v.emplace_back(x%10);
        x = x/10;
    }
    vector<int> w = v;
    reverse(w.begin(), w.end());
    bool b=true;
    int s = v.size();
    rep(i,s){
        if(v[i]!=w[i]) {
            b=false;
            break;
        }
    }
    return b;
}


void solve(){
    int a,b;
    cin >> a >> b;
    int count = 0;
    for(int i=a; i<=b; i++){
        if(judge(i)) count++;
    }
    cout << count << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

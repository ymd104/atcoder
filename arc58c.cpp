#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;


int t;
vector<int> d;
bool judge(int x){
    bool b=true;
    while(x!=0){
        for(auto p:d){
            //cout << p << " " << x%10 << endl;
            if(p==x%10) b=false;
        }
        x = x/10;
    }
    return b;
}


void solve(){
    int n,k;
    cin >> n >> k;
    rep(i,k){
        int tmp;
        cin >> tmp;
        d.emplace_back(tmp);
    }

    int i = n;
    while(!judge(i)){
        //cout << i << endl;
        i++;
    }
    cout << i << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

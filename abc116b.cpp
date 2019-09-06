#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;


void solve(){
    int s;
    cin >> s;
    vector<int> newint;
    int a;
    int count = 0;
    bool find = false;
    a = s;
    newint.emplace_back(s);
    while(!find){
        if(a%2==0) a = a/2;
        else a = 3*a+1;
        int siz = newint.size();
        rep(i,siz){
            if(newint[i]==a) {
                find = true;
                break;
            }
        }
        //if(find) break;
        newint.emplace_back(a);
        count++;
    }
    cout << count+1 << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
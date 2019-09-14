#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;



void solve(){
    int n;
    cin >> n;
    string w[n+10];

    string ans = "Yes";
    char c;
    string s;
    cin >> s;
    c = s.back();
    w[0] = s;
    for(int i=1; i<n; i++){
        string s;
        cin >> s;
        if(c != s.front()) {
            ans = "No";
            //cout << "NO!!" << endl;
        }
        rep(j,i-1){
            if(s==w[j]) {
                ans = "No";
                break;
            }
        }
        w[i] = s;
        c = s.back();
    }
    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
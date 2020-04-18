#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int m[100010];
int c[100010];

void solve(){

    int n;
    cin >> n;
    c[0]=1;
    cin >> m[0];
    for(int i=1; i<n; i++){
        cin >> m[i];
        if(i%2==0){
            if(m[i-1]==m[i]) c[i]=c[i-1]+1;
            else c[i]=1;
        }
        else{
            if(m[i-1]==m[i]) c[i]=c[i-1]+1;
            else c[i]=c[i-1]+c[i-1-c[i-1]]+1;
        }
    }

    /*
    rep(i,n){
        cout << c[i] << " ";
    }
    cout << endl;

    cout << m[n-1] << endl;
    */

    
    int pointer=n-1;
    int ans = 0;
    if(m[n-1]==0){
        while(pointer>0){
            ans += c[pointer];
            pointer -= c[pointer];
            pointer -= c[pointer];
        }
    }
    else{
        while(pointer>0){
            ans += c[pointer];
            pointer -= c[pointer];
            pointer -= c[pointer];
        }
        ans = n - ans;
    }
    

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

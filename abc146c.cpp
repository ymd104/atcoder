#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*



*/

ll a,b,x;

ll dig(ll n){
    ll tmp = 1;
    while(n>=10){
        tmp++;
        n /= 10;
    }
    return tmp;
}

ll price(ll c){
    return a*c+b*dig(c);
}

ll bin(ll left, ll right){
    //cout << left << " " << right << endl;
    if(left == 1000000000-1) return price(right)<=x?right:left;
    if(right == 0) return right;
    if(left+1 ==right) return price(right)!=x?left:right;
    else{
        if(price((left+right)/2) >= x){

            return bin(left, (left+right)/2);
        }
        else{
            return bin((left+right)/2,right);
        }
    }
}


void solve(){

    
    cin >> a >> b >> x;

    cout << bin(0,1000000000) << endl;


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

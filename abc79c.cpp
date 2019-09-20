#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;


void solve(){
    int x;
    cin >> x;
    int a,b,c,d;
    d = x%10;
    c = (x/10)%10;
    b = (x/100)%10;
    a = (x/1000)%10;
    //結局8通りだし愚直にやる方が早い
    if(a+b+c+d==7) cout << a << "+" << b << "+" << c << "+" << d << "=7" << endl;
    else if(a+b+c-d==7) cout << a << "+" << b << "+" << c << "-" << d << "=7" << endl;
    else if(a+b-c+d==7) cout << a << "+" << b << "-" << c << "+" << d << "=7" << endl;
    else if(a+b-c-d==7) cout << a << "+" << b << "-" << c << "-" << d << "=7" << endl;
    else if(a-b+c+d==7) cout << a << "-" << b << "+" << c << "+" << d << "=7" << endl;
    else if(a-b+c-d==7) cout << a << "-" << b << "+" << c << "-" << d << "=7" << endl;
    else if(a-b-c+d==7) cout << a << "-" << b << "-" << c << "+" << d << "=7" << endl;
    else if(a-b-c-d==7) cout << a << "-" << b << "-" << c << "-" << d << "=7" << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

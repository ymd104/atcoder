#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

int gcd(int a,int b)
{
	if (a%b==0)
	{
		return(b);
    }
	else
	{
		return(gcd(b,a%b));
    }
}

void solve(){
    int n,y;
    cin >> n >> y;
    int x[n+10];
    rep(i,n){
        cin >> x[i];
        //x[i] = x[i]-y;
    }
    x[n] = y;
    sort(x,x+n+1);
    int v[n+10];
    for(int i=1; i<=n; i++){
        v[i-1] = x[i]-x[0];
    }
    //cout << v[0] << " " << v[1] << " " << v[2] << endl;
    int m;
    if(n==1) m = v[0];
    else{
        m=gcd(v[0],v[1]);
    for(int i=2; i<n; i++){
        m = gcd(m, v[i]);
    }
    }
    cout << m << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

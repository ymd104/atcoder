#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


ll gcd(ll a,ll b)
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

vector<ll> divisor(ll n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

bool IsPrime(ll num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    long double sqrtNum = sqrt(num);
    for (ll i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

void solve(){
  ll a,b;
  cin >> a >> b;
  ll g = gcd(a,b);
  //cout << g << endl;////
  vector<ll> v = divisor(g);
  //cout << v[0] << " " << v[1] << " " << v[2] << endl;////
  //vはgの約数
  //vの要素それぞれについて、それより前のvのどれかで割れるかを調べる

  ll count = 1;
  for(int i=1; i<v.size(); i++){
    bool b=true;
    for(int j=1; j<i; j++){
      if(v[i]%v[j]==0){
        b=false;
        break;
      }
    }
    if(b) count++;
    //if(b) cout << v[i] << endl;
  }
  cout << count << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

#include <bits/stdc++.h>

#define pb push_back
#define ss second
#define ff first
#define N 1000006
#define inf 1000000009
#define ll long long
#define mid(a,b) (a+b)/2
#define pii pair<int,int>

using namespace std;

const int mod = 1e9+7;
int a[N],lc[N],x,cnt,n;
ll ans,jog,l;
bool b[N];
vector <int> v;

ll pw(ll a,ll b){
	if(b == 0) return 1;
	ll x = pw(a,b / 2);
	if(b % 2) return (((x * x) % mod)*a)%mod;
	return (x * x) % mod;
}

int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		x = a[i];

		for(int j = 2;j * j <= x;j++){
			cnt = 0;
			while(x % j == 0){
				cnt++;
				x /= j;
			}
			lc[j] = max(lc[j],cnt);
		}

		if(x > 1 and lc[x] == 0) lc[x] = 1;
	}

  for(int i=0;i<4;i++){
    cout << i << ":" << lc[i] << endl;
  }
  //lc[i]:lcmのiの因数の数

	l = 1;
	for(int i = 2;i <= 1e6;i++){
		if(lc[i]) l = (l * pw(i,lc[i])) % mod;
    //lcmを計算している
  }
	for(int i = 1;i <= n;i++){
		ans = (ans + (l * pw(a[i],mod - 2)) % mod) % mod;
    // lcm/a[i] == lcm×a[i]^(mod-2)らしい　なぜ?
	}
	printf("%lld",ans);
}

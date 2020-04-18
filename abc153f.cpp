#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int N,D,A;
pair<ll,ll> P[200020];
ll DD[200020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D>>A;
	rep(i,N) {
		cin>>x>>y;
		P[i]={x,(y+A-1)/A};
	}
	sort(P,P+N);
	P[N]={1LL<<60,0};
	
	ll sum=0;
    cout << DD[0] << endl;
	rep(i,N) {
		if(i>=1) DD[i]+=DD[i-1];
		P[i].second-=DD[i];
		if(P[i].second>0) {
			x=lower_bound(P,P+N,make_pair(P[i].first+2LL*D+1LL,-(1LL<<60)))-P;
			sum+=P[i].second;
			DD[i]+=P[i].second;
			DD[x]-=P[i].second;
		}
	}
	cout<<sum<<endl;	
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

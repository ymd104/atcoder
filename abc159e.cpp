#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

bool b[11];
char st[11][1010];
int c;

void solve(){

    int h,w,k;
    cin >> h >> w >> k;
    rep(i,h){
        string s;
        cin >> s;
        rep(j,w){
            st[i][j]=s[j];
        }
    }
    c = int(pow(2,h-1));
    //cout << "c:" << c << endl;
    int allans = INF;
    rep(i,c){
        int cut=1;
        int count = 0;
            int tmp = i;
            while(tmp>=1){
                if(tmp%2==1) {
                b[count]=true;
                cut++;
                }
                else b[cut-1]=false;
                tmp/=2;
                count++;
            }
        
        //cut:横の数
        cout << "cut:" << cut << endl;
        int ans = cut-1;
        vector<int> v;
        rep(j,cut){
            v.emplace_back(0);
        }
        map<int,int> mp;
        //mp[i]:上からi番目のチョコが属するブロックの番号
        rep(j,h){
            if(j==0) mp[j]=0;
            else{
                if(b[j-1]==true) mp[j]=mp[j-1]+1;
                else mp[j]=mp[j-1];
            }
        }

        rep(j,w){
            rep(k,h){
                if(st[k][j]=='1') v[mp[k]]++;
            }
            bool isover = false;
            rep(x,v.size()){
                if(v[x]>k){
                    isover=true;
                }
            }
            if(isover){
                ans++;
                rep(y,v.size()){
                    v[y]=0;
                    rep(k,h){
                        if(st[k][j]=='1') v[mp[k]]++;
                    }
                }
            }
            rep(t,v.size()){
                cout << v[t] << " ";
            }
            cout << endl;
        }
        cout << i << ": " << ans << endl;
        allans = min(allans,ans);
    }

    cout << allans << endl;


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

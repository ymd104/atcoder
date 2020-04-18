#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int n;

bool b[15];
void t(int x){
    int tmp = x;
    int count=0;
    while(count<=n){
        
        if(x%2==1) {
            b[count] = true;
        }
        else{
            b[count] = false;
        }
        x /= 2;
        count++;
    }
    
}


void solve(){

    rep(i,15){
        b[i]=true;
    }

    cin >> n;
    vector<vector<pair<int,int>>> v;
    rep(i,n){
        vector<pair<int,int>> vp;
        int a;
        cin >> a;
        rep(j,a){
            int x,y;
            cin >> x >> y;
            x--;
            vp.emplace_back(make_pair(x,y));
        }
        v.emplace_back(vp);
    }


    int ans = 0;
    for(int bit=0; bit<(1<<n); bit++){
        int tmpans = 0;
        t(bit);
        /*
        rep(i,n){
            if(b[i]) cout << 1;
            else cout << 0;
        }
        cout << endl;
        */
        //b[j]:j番目の人が正直か嘘つきか
        bool is = true;
        rep(j,n){
            auto vtmp = v[j];
            rep(k,vtmp.size()){
                int x,y;
                x = vtmp[k].first;
                y = vtmp[k].second;

                if(b[j]==false){
                    y = abs(y-1);
                }
                
                if(b[x]!=(y==1?true:false)){
                    //cout << bit << "の状態で" << j << "+1番目の人の証言、" << x << "+1番目の人は" << y << "であるというのが矛盾" << endl;
                    is = false;
                    break;
                }
            }
            if(!is){
                break;
            }
        }
        if(!is){
            //cout << "NO" << endl;
            continue;
        }
        rep(i,n){
            if(b[i]) tmpans++;
        }
        ans = max(ans, tmpans);
    }


    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

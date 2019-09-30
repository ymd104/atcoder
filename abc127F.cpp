#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*

*/

void solve(){
    int q;
    cin >> q;
    multiset<ll> ml, mr;

    //cout << ml.size() << " " << *mr.begin() << endl;

    ll m = INF;
    rep(i,q){

        int qv;
        cin >> qv;
        //cout << "qv:" << qv << endl;

        if(qv==1){

            ll a,b;
            cin >> a >> b;

            if(m==INF) m = b;
            else if(a<*(--(ml.end()))) m += b + abs(*(--(ml.end()))-a);
            else if(a>*((mr.begin()))) m += b + abs(a-*((mr.begin())));
            else m += b;

            
            if(ml.empty()&&mr.empty()){
                ml.insert(a);
                mr.insert(a);
            }
            else{
                auto it = ml.end();
                auto it2 = mr.begin();
                --it;
                ll mlmax = *it;
                ll mrmin = *it2;
                if(mlmax <= a && a <= mrmin){
                    ml.insert(a);
                    mr.insert(a);
                }
                else if(a<mlmax){
                    ml.erase(it);
                    mr.insert(mlmax);
                    ml.insert(a);
                    ml.insert(a);
                }
                else{
                    mr.erase(it2);
                    ml.insert(mrmin);
                    mr.insert(a);
                    mr.insert(a);
                }
            }

            //cout << *ml.begin() << " " << *mr.begin() << endl;
            
        }
        else{

            auto itr = ml.end();
            --itr;
            //cout << "<" << *itr << " " << m << ">" << endl;
            cout << *itr << " " << m <<  endl;

        }

    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
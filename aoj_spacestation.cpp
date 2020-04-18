#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


class UnionFind{
    vector<int> par;
    int all = 0;
    vector<int> siz;
    int treenum;

    public:UnionFind(int N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par.emplace_back(i);
        for(int i = 0; i < N; i++) siz.emplace_back(1);
        all = N;
        treenum = N;
    }

    public:int root(int x){
        if(par[x]==x) return x;
        else{
            par[x]=root(par[x]);
            return par[x];
        }
    }

    public:bool same(int x, int y){
        return root(x)==root(y);
    }

    public:void unite(int x, int y){
        if(same(x,y)) return;
        else{
            int rx=root(x);
            int ry=root(y);
            par[ry]=rx;
            siz[rx]=siz[rx]+siz[ry];
            siz[ry]=siz[rx];
            treenum--;
            return;
        }
    }

    public:int size(int x){
        siz[x]=siz[root(x)];
        return siz[x];
    }

    public:void sizall(){
        rep(i,all){
            siz[i] = siz[root(i)];
        }
    }

    public:int treenumber(){
        return treenum;
    }

    public:void add(){
        par.emplace_back(all);
        siz.emplace_back(1);
        all++;
        treenum++;
    }

    public:void del(int x){
        //xを木から外して単一ノードの木に分離する
        //子の検索にO(n)かける. UF木の弱点なので使用は推奨されない
        //根であれば繋ぎ直し、素集合としてみなさない.
        bool isroot=false;
        //あるノードの根であるかどうか.
        rep(i,all){
            if(root(i)==x) isroot=true;
        }
        if(!isroot){
            rep(i,all){
                if(par[i]==x){
                    par[i]=par[x];
                }
            }
            par[x]=x;
            return;
        }

        if(isroot){
            sizall();
            if(size(x)==1) return;
            rep(i,all){
                if(par[i]==x){
                    treenum++;
                    par[i]=i;
                }
            }
            return;
        }

    }

};



double dist[110][110];
vector<double> a;

void solve(){

    /*
    int v,e,k;
    cin >> v >> e >> k;
    vector<tuple<int,int,int>> t;
    rep(i,e){
        int x,y,z;
        cin >> x >> y >> z;
        x--;
        y--;
        t.emplace_back(make_tuple(z,x,y));
    }
    */

    while(true){

        int n;
        cin >> n;
        if(n==0) break;
        vector<tuple<double, double, double, double>> x;
        rep(i,n){
            double p,q,r,s;
            cin >> p >> q >> r >> s;
            x.emplace_back(make_tuple(p,q,r,s));
        }
        rep(i,n){
            rep(j,n){
                if(i==j) {
                    dist[i][j]=0;
                    continue;
                }
                double x1,y1,z1,x2,y2,z2, r1,r2;
                x1=get<0>(x[i]);
                y1=get<1>(x[i]);
                z1=get<2>(x[i]);
                r1=get<3>(x[i]);
                x2=get<0>(x[j]);
                y2=get<1>(x[j]);
                z2=get<2>(x[j]);
                r2=get<3>(x[j]);
                double d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
                if(d<r1+r2) dist[i][j]=0;
                else dist[i][j]=d-r1-r2;
            }
        }

        vector<tuple<double,int,int>> t;

        rep(i,n){
            rep(j,n){
                if(i>=j) continue;
                t.emplace_back(make_tuple(dist[i][j],i,j));
            }
        }

    

    sort(t.begin(), t.end());
    UnionFind uf(n);
    int pointer=0;
    double ans = 0;
    while(uf.treenumber()>1){
        double d = get<0>(t[pointer]);
        double x = get<1>(t[pointer]);
        double y = get<2>(t[pointer]);
        if(!uf.same(x,y)){
            ans += d;
            uf.unite(x,y);
        }
        pointer++;
    }
    a.emplace_back(ans);



    }

    for(auto e:a){
        cout << fixed;
        cout << setprecision(3) << e << endl;
    }

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

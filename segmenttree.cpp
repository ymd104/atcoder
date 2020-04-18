#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

struct SegmentTree{

    vector<int> a;
    vector<int> seg;
    int number; //元の配列の要素数
    int N; //セグ木のノード数

    SegmentTree(int n){
        //セグ木のノード数を与える
        int tmp=1;
        int count=0;
        while(tmp<n){
            tmp = tmp*2;
            count++;
        }
        N = 2*int(pow(2,count))-1;

        rep(i,n){
            a.emplace_back(0);
        }
        number = n;
        rep(i,N){
            seg.emplace_back(0);
        }
        
    }

    public:void pre(int *c){
        rep(i,number){
            a[i]=*(c+i);
        }

        //まず最下段にaを代入していく.
        int n2 = (N+1)/2;
        for(int i=0; i<n2; i++){
            if(i<number){
                seg[n2-1+i]=a[i];
                //cout << seg[n2-1+i] << " ";
            }
            else{
                seg[n2-1+i]=INF;
                //cout << seg[n2-1+i] << " ";
            }
            //cout << endl;
        }
        //以下、後ろから更新
        for(int i=n2-2; i>=0; i--){
            //もし最大値クエリの場合、以下の不等号の向きを逆にする
            seg[i] = (seg[2*i+1]>seg[2*i+2]? seg[2*i+2]: seg[2*i+1]);
        }

        /*
        rep(i,N){
            cout << seg[i] << " ";
        }
        cout << endl;
        */
        
    }

    public:void update(int i, int x){
        //a[i]の値をxに変更
        i += ((N-1)/2);
        seg[i] = x;
        while(i>0){
            i = (i-1)/2;
            seg[i]=min(seg[2*i+1], seg[2*i+2]);
        }
    }

    public:void print_segtree(){
        int c = 1;//何個要素を表示したか
        int t = 1;
        rep(i,N){
            //cがtを超えない限り表示、超えたらc=1, t*=2
            if(c<=t){
                cout << seg[i] << " ";
                c++;
            }
            else{
                cout << endl;
                c=1; 
                t *= 2;
                i--;
            }
            
        }
        cout << endl;
    }

    public:int getmin(int a, int b, int k=0, int l=0, int r=-1){
        //区間[a,b)の要素の最小値を返す
        if(r<0) r=(N+1)/2;
        if(b<=l) return INF;
        if(r<=a) return INF;
        if(a<=l&&r<=b) return seg[k];

        int vl = getmin(a,b,2*k+1,l,(l+r)/2);
        int vr = getmin(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }

};

void solve(){

    int n;
    cin >> n;
    SegmentTree st(n);
    int input[n];
    rep(i,n){
        cin >> input[i];
    }

    st.pre(input);
    //st.update(4,-100);
    //st.print_segtree();
    //cout << st.getmin(0,1) << endl;

    /*
    //以下、エラー検出
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(st.getmin(i,j)!=i+1) cout << i << " " << j << " " << "ERROR" << endl;
        }
    }
    */

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

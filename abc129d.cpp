#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;

/*
計算量の考察
各マスごとに計算する場合、それぞれで最悪H+Wかかり、O(HW(H+W))
前処理で各要素を計算するのは、それぞれO(HW)。最大値計算も含めてO(5HW)=O(HW)
*/

void solve(){
    int h,w;
    cin >> h >> w;
    char v[h+10][w+10]; //i行j列の要素
    rep(i,h){
        string str;
        cin >> str;
        rep(j,w){
            v[i][j] = str[j];
        }
    }
    //L[i][j]:i行j列に明かりを置いた時、そこから左方向に照らされるマスの数
    int L[h+10][w+10];
    rep(i,h){
        rep(j,w){
            if(v[i][j]=='#') L[i][j]=0;
            else if(j==0) L[i][j]=1;
            else L[i][j]=L[i][j-1]+1;
        }
    }
    //R[i][j]:i行j列に明かりを置いた時、そこから右方向に照らされるマスの数
    int R[h+10][w+10];
    rep(i,h){
        for(int j=w-1; j>=0; j--){
            if(v[i][j]=='#') R[i][j]=0;
            else if(j==w-1) R[i][j]=1;
            else R[i][j]=R[i][j+1]+1;
        }
    }
    //D[i][j]:i行j列に明かりを置いた時、そこから下方向に照らされるマスの数
    int D[h+10][w+10];
    rep(j,w){
        rep(i,h){
            if(v[i][j]=='#') D[i][j]=0;
            else if(i==0) D[i][j]=1;
            else D[i][j]=D[i-1][j]+1;
        }
    }
    //U[i][j]:i行j列に明かりを置いた時、そこから上方向に照らされるマスの数
    int U[h+10][w+10];
    rep(j,w){
        for(int i=h-1; i>=0; i--){
            if(v[i][j]=='#') U[i][j]=0;
            else if(i==h-1) U[i][j]=1;
            else U[i][j]=U[i+1][j]+1;
        }
    }

    /*
    テスト用
    rep(i,h){
        rep(j,w){
            cout << U[i][j];
        }
        cout << endl;
    }
    */

    int m=0;
    rep(i,h){
        rep(j,w){
            int tmp = L[i][j]+R[i][j]+D[i][j]+U[i][j]-3;
            m = max(m,tmp);
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
int a,b;
pair<int,int> func(int x){
    //xをグリッドへと写像する
    /*
    0  1  2  3  4  ...  b-1
    2*b-1 ...      b+1  b

    xをbで割った商が偶数の時、(x/b, x%b)
    奇数の時、(x/b, (b-1)-x%b)
    */
    if((x/b)%2==0) return make_pair(x/b,x%b);
    else return make_pair(x/b, (b-1)-x%b);
}
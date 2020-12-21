template<typename T,bool max_mode=false>
struct RMQ{
    int n=0;
    vector<T>val;
    //we're storing index rather than value in sparse table
    //query (l,r)-->answer(l....r-1)
    vector<vector<int>>sparse;
    RMQ(const vector<T>v={}){
        if((int)v.size()){
            build_sparse(v);
        }
    }
    static int log_2(int n) {
        return (n?31-__builtin_clz(n):-1);
    }
    int better_index(int a,int b) const{
        return ((max_mode?val[a]>val[b]:val[a]<val[b])?a:b);
    }
    void build_sparse(vector<T>v){
        val=v;
        n=(int)val.size();
        int logN=log_2(n)+1;
        sparse.resize(logN);
        for(int i=0;i<logN;i++){
            sparse[i].resize(n-(1<<i)+1);
        }
        for(int i=0;i<(int)val.size();i++){
            sparse[0][i]=i;
        }
        for(int j=1;j<logN;j++){
            for(int i=0;i+(1<<j)<=n;i++){
                sparse[j][i]=better_index(sparse[j-1][i],sparse[j-1][i+(1<<(j-1))]);
            }
        }
    }
    int query_index(int a,int b) const{
        assert(0<=a and a<b and b<=n);
        int logN=log_2(b-a);
        return better_index(sparse[logN][a],sparse[logN][b-(1<<logN)]);
    }
    T query_value(int a,int b) const{
        return val[query_index(a,b)];
    }
};

struct Heap{
    arr heap;
    ll h_size;
    void init(ll n){
        h_size=0;
        heap.assign(n+1,0);
    }
    ll parent(ll n){
        return n>>1;
    }
    ll left(ll n){
        return 2*n;
    }
    ll right(ll n){
        return 2*n+1;
    }
    void insert(ll val){
        h_size++;
        heap[h_size]=val;
        ll i=h_size;
        while(i>1 and heap[parent(i)] < heap[i]){
            swap(heap[parent(i)],heap[i]);
            i=parent(i);
        }
    }
    //what is heapify : iff both of i'th child is heap but i'th node is violet rules than we have to do heapify
    //heapify takes : O(logN)
    //building heap takes O(N) **using some arithmetic progression**
    void max_heapify(ll i){
        ll l=left(i);
        ll r=right(i);
        ll big=i;
        if(l<h_size and heap[l]>heap[big]){
            big=l;
        }
        if(r<h_size and heap[r]>heap[big]){
            big=r;
        }
        if(big!=i){
            swap(heap[i],heap[big]);
            max_heapify(big);
        }
    }
    //return max element and delete it 
    ll extract_max(){
        ll st=heap[1];
        heap[1]=heap[h_size];
        h_size--;
        max_heapify(1);
        return st; 
    }
    void showArr(){
        for(int i=1;i<=h_size;i++)
            cout<<heap[i]<<" ";
        cout<<endl;
    }
    arr heap_sort(){
        arr ans;
        while(h_size>=1){
            ans.pb(extract_max());
        }
        return ans;
    }
};

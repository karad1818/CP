template<typename T,bool max_mode=false>
struct min_queue{
    deque<T>q;
    bool checker(T a,T b){
        return (max_mode?a<b:a>b);
    }
    void add(T element){
        while(!q.empty() and checker(q.back(),element))
                q.pop_back();
        q.push_back(element);
    }
    void remove(T element){
        if(!q.empty() and q.front()==element)
                q.pop_front();
    }
    T get_element(){
        if(!q.empty())
            return q.front();
        return T(-1);
    }
};

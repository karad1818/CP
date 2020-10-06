struct Node{
    ll val;
    Node* left;
    Node* right;
    ll height;
};
struct AVL{
    Node* head;
    void newNode(Node* &head,ll val){
        head = new Node();
        head->val=val;
        head->left=NULL;
        head->right=NULL;
        head->height=1;
    }
    void init(){
        newNode(head,INT_MAX);
    }
    ll getHeight(Node* head){
        if(head==NULL)
            return 0;
        return head->height;
    }
    ll getBalance(Node* head){
        if(head==NULL)
            return 0;
        return getHeight(head->left)-getHeight(head->right);
    }
    Node* left(Node* x){
        Node* y=x->right;
        Node* a=y->left;
        y->left=x;
        x->right=a;
        x->height=max(getHeight(x->left),getHeight(x->right))+1;
        y->height=max(getHeight(y->left),getHeight(y->right))+1;
        return y;
    }
    Node* right(Node* x){
        Node* y=x->left;
        Node* a=y->right;
        y->right=x;
        x->left=a;
        x->height=max(getHeight(x->left),getHeight(x->right))+1;
        y->height=max(getHeight(y->left),getHeight(y->right))+1;
        return y;
    }
    Node* CreateNode(Node* head,ll val){
        if(head==NULL){
            newNode(head,val);
            return head;
        }
        if(head->val > val){
            head->left=CreateNode(head->left,val);
        }else{
            head->right=CreateNode(head->right,val);
        }
        head->height = 1+max(getHeight(head->left),getHeight(head->right));
        ll bal=getBalance(head);
        //bal > 1  left is heavy otherwise right is heavy
        if(bal>1){
            if(val>head->left->val){
                //left
                head->left=left(head->left);
                //right
                return right(head);
            }else{
                return right(head);
                //right
            }
        }else if(bal<-1){
            if(val>head->right->val){
                //left
                return left(head);
            }else{
                //right
                head->right=right(head->right);
                //left
                return left(head);
            }
        }
        return head;
    }
    void CreateNode(ll val){
        if(head->val==INT_MAX){
            head->val=val;
            return ;
        }
        head=CreateNode(head,val);
    }
    arr BFSTraversal(){
        arr ans;
        queue<Node*>q;
        q.push(head);
        while(!q.empty()){
            Node* x=q.front();
            ans.pb(x->val);
            q.pop();
            if(x->left){
                q.push(x->left);
            }
            if(x->right){
                q.push(x->right);
            }
        }
        return ans;
    }
};

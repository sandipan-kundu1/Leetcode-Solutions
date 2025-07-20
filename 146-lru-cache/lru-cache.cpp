struct Node
{
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int k,int v): key(k), val(v){}
};
class LRUCache {
    Node* head;
    Node* tail;
    
    unordered_map<int,Node*> mp; //key,node
    int cap;
    void del(Node* node)
    {
        Node* before=node->prev;
        Node* after=node->next;
        before->next=after;
        after->prev=before;
    }
    void insertafterhead(Node* node)
    {
        Node* afterhead=head->next;
        head->next=node;
        node->prev=head;
        node->next=afterhead;
        afterhead->prev=node;
    }
public:
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(!mp.count(key))  return -1;
        Node* node=mp[key];
        del(node);
        insertafterhead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key))
        {
            Node* node=mp[key];
            node->val=value;
            mp[key]=node;
            del(node);
            insertafterhead(node);
        }
        else
        {
            if(mp.size()==cap)
            {
                Node* lru=tail->prev;
                mp.erase(lru->key);
                del(lru);
                delete lru;
            }
            
            Node* node=new Node(key,value);
            mp[key]=node;
            insertafterhead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
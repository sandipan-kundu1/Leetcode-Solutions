struct Node{
    Node* links[26];
    bool flag=false;

    bool containsChar(char c)
    {
        return links[c-'a']!=NULL;
    }
    
    void put(char c,Node* node)
    {
        links[c-'a']=node;
    }
    
    Node* getNode(char c)
    {
        return links[c-'a'];
    }
};
class Trie {
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->containsChar(word[i]))
            {
                temp->put(word[i],new Node());
            }
            temp=temp->getNode(word[i]);
        }
        temp->flag=true;
    }
    
    bool search(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->containsChar(word[i]))
            return false;
            temp=temp->getNode(word[i]);
        }
        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!temp->containsChar(prefix[i]))
            return false;
            temp=temp->getNode(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
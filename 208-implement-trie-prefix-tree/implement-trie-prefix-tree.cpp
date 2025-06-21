struct Node{
    Node* links[26];
    bool flag=false;
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
            int ind=word[i]-'a';
            if(!temp->links[ind])
            {
                temp->links[ind]=new Node();
            }
            temp=temp->links[ind];
        }
        temp->flag=true;
    }
    
    bool search(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            int ind=word[i]-'a';
            if(!temp->links[ind])
            return false;
            temp=temp->links[ind];
        }
        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            int ind=prefix[i]-'a';
            if(!temp->links[ind])
            return false;
            temp=temp->links[ind];
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
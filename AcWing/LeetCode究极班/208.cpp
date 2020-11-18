struct Node {
    bool is_end;
    Node* son[26];
    Node() {
        is_end = false;
        memset(son, 0, sizeof son);
    }
}*root;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
       root = new Node(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = root;
        for (char c: word) {
            int u = c - 'a';
            if (!p->son[u]) p->son[u] = new Node();
            p = p->son[u];
        }
        p->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p = root;
        for (char c: word) {
            int u = c - 'a';
            if (!p->son[u]) return false;
            p = p->son[u]; 
        }
        return p->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto p = root;
        for (char c: prefix) {
            int u = c - 'a';
            if (!p->son[u]) return false;
            p = p->son[u];
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
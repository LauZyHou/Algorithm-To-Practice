class Trie {
public:
	bool is_str;//是否是字符串
	Trie* next[26];//指向下一层

    /** Initialize your data structure here. */
    Trie() : is_str(false){
		memset(next,0,sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* t = this;
		for(char w : word) {
			if(t->next[w-'a']==nullptr) {
				Trie* n = new Trie();
				t->next[w-'a'] = n;
			}
			t = t->next[w-'a'];
		}
		t->is_str = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* t = this;
		for(char w : word) {
			if(t->next[w-'a'])
				t = t->next[w-'a'];
			else
				return false;
		}
		return t->is_str;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* t = this;
		for(char w : prefix) {
			if(t->next[w-'a'])
				t = t->next[w-'a'];
			else
				return false;
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
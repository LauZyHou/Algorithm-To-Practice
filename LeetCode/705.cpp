class Nd {
public:
	int val;
	Nd* next;
	Nd(int v){
		this->val = v;
		this->next = nullptr;
	}
};

class MyHashSet {
private:
	Nd** hs;
	const int N = 1000;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
       hs = new Nd*[N];
	   for(int i=0;i<N;i++)
		   hs[i] = nullptr;
    }

	~MyHashSet(){
		delete[] hs;
	}
    
    void add(int key) {
		if(contains(key))
			return ;
        int hash = key%N;
		if(hs[hash]==nullptr)
			hs[hash]=new Nd(key);
		else{
			Nd* cur = new Nd(key);
			cur->next = hs[hash];
			hs[hash] = cur;
		}
    }
    
    void remove(int key) {
        int hash = key%N;
		//双指针做删除
		Nd* p = hs[hash];
		if(!p)
			return ;
		if(p->val==key) {
			hs[hash] = p->next;
			//delete p;
		}
		Nd* q = p->next;
		while(q!=nullptr){
			if(q->val==key){
				p->next = q->next;
				//delete q;
				return ;
			}
			p = q;
			q = q->next;
		}
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hash = key%N;
		Nd* p = hs[hash];
		while(p){
			if(p->val==key)
				return true;
			p = p->next;
		}
		return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
	Iterator* it;
	int val;
	bool hasN;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
		
		it = new Iterator(nums);
		if(it->hasNext()) {
			this->hasN = true;
			this->val = it->next();//提前调用一下next把数取出来
		}
		else
			this->hasN = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
		//peek时不取下一个next
        return this->val;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		//取下一个next,在这之前保存一下当前的val供函数返回
		int tmp = this->val;

	    if(it->hasNext()) {
			this->hasN = true;
			this->val = it->next();
		}
		else
			this->hasN = false;
		return tmp;
	}

	bool hasNext() const {
	    return this->hasN;
	}
};
class Node
{
public:
	int val;
	Node* next;
	Node() {
		next = nullptr;
	}
	Node(int v) {
		val = v;
		next = nullptr;
	}
};

class MyLinkedList {
public:
	Node* head;
    /** Initialize your data structure here. */
    MyLinkedList() {
		head = new Node();
		head->next = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
		//负数Index直接不存在
		if(index<0)
			return -1;
        Node* t = head;
		int cnt = -1;
		while(cnt<index && t!=nullptr) {
			t = t->next;
			cnt++;
		}
		return t==nullptr ? -1 : t->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* t = new Node(val);
		t->next = head->next;
		head->next = t;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* t = head;
		while(t->next!=nullptr)
			t = t->next;
		t->next = new Node(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
		//负数Index加在开头
		if(index<0) {
			addAtHead(val);
			return ;
		}
        Node* t = head;
		int cnt = 0;
		Node* r = new Node(val);
		while(cnt<index && t!=nullptr) {
			t = t->next;
			cnt++;
		}
		//超出现有位置时,不做插入
		if(!t) {
			return ;
		}
		r->next = t->next;
		t->next = r;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
		//负数Index直接不存在
		if(index<0)
			return ;
        Node* t = head;
		int cnt = 0;
		while(cnt<index && t!=nullptr) {
			t = t->next;
			cnt++;
		}
		//这里还要判断一下是不是走到了要删除的那里
		//没走到,什么都不做
		if(cnt<index)
			return ;
		//走到了,考虑是否有t和是否有t的下一节点
		if(!t)
			return ;
		if(t->next)
			t->next = t->next->next;
		else
			t->next = nullptr;
	}
};

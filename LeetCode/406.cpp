/*
假设候选队列为 A，已经站好队的队列为 B.
从 A 里挑身高最高的人 x 出来，插入到 B. 因为 B 中每个人的身高都比 x 要高，因此 x 插入的位置，就是看 x 前面应该有多少人就行了。
*/
class Node {
public:
	vector<int> val;
	Node* next = nullptr;
	Node() {
		val.push_back(-1);
		val.push_back(-1);
	}
	Node(vector<int> v) : val(v) {}
	//比较函数,用于priority_queue实现最大堆
	friend bool operator < (const Node &n1, const Node &n2);
};

inline bool operator < (const Node &n1, const Node &n2) {
	if(n1.val[0]!=n2.val[0])
		return n1.val[0] < n2.val[0];//按身高排成最大堆
	//身高一样时,"前面有几个人"应从小到大排
	//即如样例中(5,0)要比(5,2)先站好队
	return n1.val[1] > n2.val[1];
}

class LinkedList {
public:
	Node* head = new Node();//链表头结点,不放元素

	void insert(Node* t) {
		int pre = t->val[1];//前面应该有多少人
		Node* p = head;
		while(pre>0) {
			if(nullptr==p) {
				cout<<"error!pre="<<pre<<endl;
				break;
			}
			p = p->next;
			pre--;
		}
		if(pre>0)
			return ;
		
		/*
		cout<<"[t]("<<t->val[0]<<","<<t->val[1]<<")"<<endl;
		if(p)
			cout<<"[p]("<<p->val[0]<<","<<p->val[1]<<")"<<endl;
		*/

		//插入
		t->next = p->next;
		p->next = t;
		
		/*
		cout<<"*插入成功,链表情况:"<<endl;
		this->showLL();
		*/
	}

	void showLL() {
		Node* p = head->next;
		while(p!=nullptr) {
			cout<<"->("<<p->val[0]<<","<<p->val[1]<<")";
			p = p->next;
		}
		cout<<endl;
	}

	//从链表构建vector
	//这里投机,len直接从外部传进来,不在insert时候计算
	//其实不传len也可以做,就是传了len可以直接给vector开好空间
	vector<vector<int>> trans2Vec(int len) {
		Node* p = head->next;
		vector<vector<int>> ret(len);
		for(int i=0;i<len && p!=nullptr;i++,p=p->next) {
			//cout<<p->val[0]<<","<<p->val[1]<<endl;
			ret[i] = p->val;
		}
		return ret;
	}

};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& vv) {
		int len = vv.size();
		//最大堆,存候选队列中的节点(未排队的)
		priority_queue<Node> pq;
		for(vector<int> v:vv) {
			Node* n = new Node(v);
			pq.push(*n);
		}
		//从候选队列构建站好队的链表
		LinkedList* ll = new LinkedList();
		while(pq.empty()==false) {
			//[注意]这里n是局部自动变量,传进去就销了啊,所以放t里
			Node* t = new Node();
			Node n = pq.top();
			t->val = n.val;
			pq.pop();
			ll->insert(t);
		}
		//形成vector并返回
		return ll->trans2Vec(len);
    }
};
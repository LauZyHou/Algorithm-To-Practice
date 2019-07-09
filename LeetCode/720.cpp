class Node {
public:
	char c;
	bool isword = false;
	Node** next = nullptr;

	Node(char k='\0') {
		this->c = k;
		next = new Node*[26];
		for(int i=0;i<26;i++)
			this->next[i] = nullptr;
	}
	~Node() {
		delete[] next;
	}
};

class TireTree {
public:
	Node* root = new Node('/');
	
	//在本Tire树中插入一个string
	void insert(string s) {
		Node* p = root;//用来做插入的指针,从根节点开始
		int len = s.size();
		for(int i=0;i<len;i++) {
			int idx = s[i] - 'a';//从0开始到25的编号
			if(p->next[idx]==nullptr) {//如果为空说明还没插入这个字母
				p->next[idx] = new Node(s[i]);//将插入
			} else//否则
				;//既然已经插入过了,啥也不用做
			//p指针向下走,按照当前字母往下走
			p = p->next[idx];
		}
		//走完之后,这个单词写完了,要记录一下到这里是一个单词
		p->isword = true;//这个记录点记录在单词的最后一个字母上
	}
	
	//判断一个字符串是不是由其它字符串依次加一个组成的
	bool isBuild(string s) {
		//用来遍历的指针,从根节点开始
		Node* p = root;
		int len = s.size();
		for(int i=0;i<len;i++) {
			if(false==p->next[s[i]-'a']->isword)
				return false;
			p = p->next[s[i]-'a'];
		}
		return true;
	}
};

class Solution {
public:
    string longestWord(vector<string>& v) {
        int len = v.size();
		TireTree tt;
		//插入过程
		for(string s:v) {
			tt.insert(s);
		}
		string ans = "";
		int maxlen = 0;
		//判断和更新最长的过程
		for(string s:v) {
			int slen = s.size();
			if(slen<maxlen)
				continue;
			else if(slen>maxlen) {
				if(tt.isBuild(s)) {
					ans = s;
					maxlen = slen;
				}
			}
			else {//slen==manxlen
				if(!tt.isBuild(s))
					continue;
				//一样长时候要判断一下字典序
				for(int i=0;i<slen;i++) {
					if(s[i]<ans[i]) {
						ans = s;
						maxlen = slen;
						break;
					} else if(s[i]>ans[i]) {
						break;
					}
				}
			}
		}
		return ans;
	}
};

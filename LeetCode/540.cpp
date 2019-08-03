class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int len = v.size();
		if(!len)
			return -1;
		if(len<2)
			return v[0];
		if(v[0]!=v[1])
			return v[0];
		if(v[len-1]!=v[len-2])
			return v[len-1];
		int lft = 2;
		int rgt = len-3;
		while(lft<=rgt) {
			int mid = (lft+rgt)/2;
			if(v[mid]!=v[mid+1] && v[mid]!=v[mid-1])
				return v[mid];
			//至此说明左边右边一定有一个和mid相同的,而且不可能左右都和mid相同
			if(v[mid]==v[mid+1]) {//和右边相同(说明mid已经和右边配对了)
				int leftNum = mid-lft;
				if((leftNum&1)==1)//左边有奇数个
					rgt = mid-1;
				else//左边有偶数个(偶数个里一定都是两两配对的,否则会额外出现一个落单)
					lft = mid+2;//跳过和右边相同的这一对
			}
			else {//和左边相同
				int rightNum = rgt-mid;
				if((rightNum&1)==1)
					lft = mid+1;
				else
					rgt = mid-2;
			}
		}
		return -1;
    }
};
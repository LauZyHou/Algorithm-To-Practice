// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
		long long l = 1;
		long long r = n;
		long long mid = (l+r)/2;
		while(l<r) {
			//这句话如果放在这,那1,2错误为2时候,l从1变成2,但是mid还没更新为2
			//mid = (l+r)/2;
			if(isBadVersion(mid)) {
				r = mid;
			}
			else {
				l = mid + 1;//如4正确但5错误时,下一次循环4要变成5不然死循环
			}
			mid = (l+r)/2;
		}
		return mid;
    }
};
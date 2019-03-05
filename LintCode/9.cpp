class Solution {
public:
    /**
     * @param n: An integer
     * @return: A list of strings.
     */
    vector<string> fizzBuzz(int n) {
        vector<string> v(n);
		for(int i=1;i<=n;i++){
			v[i-1]=(0==i%15)?"fizz buzz":(0==i%3)?"fizz":(0==i%5)?"buzz":to_string(i);
		}
		return v;
    }
};
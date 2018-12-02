#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> v;
        for(int i=0;i<nums.size()-1;i++){
        	for(int j=i+1;j<nums.size();j++){
        		if(nums[i]+nums[j]==target){
//        			cout<<"ok"<<endl;
        			v.push_back(i);
        			v.push_back(j);
        			return v;
				}
			}
		}
		return v;
    }
};

int main(){
	int ary[]={2, 7, 11, 15};
	vector<int> input(ary,ary+4);
	/*
	for(int i=0;i<input.size();i++){
		cout<<input[i]<<" ";
	}
	*/
	Solution *s=new Solution();
	vector<int> output=s->twoSum(input,9);
	for(int i=0;i<output.size();i++){
		cout<<output[i]<<" ";
	}
	return 0;
}

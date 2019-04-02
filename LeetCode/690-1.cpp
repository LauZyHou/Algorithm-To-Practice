/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> emp, int id) {
        int ans = 0;
		queue<Employee*> q;
		map<int,Employee*> mp;
		for(Employee* e : emp){
			mp[e->id] = e;
		}
		if(mp[id])
			q.push(mp[id]);

		Employee* t;
		while(!q.empty()){
			t = q.front();
			ans += t->importance;
			q.pop();
			for(auto sid : t->subordinates){
				q.push(mp[sid]);
			}
		}
		return ans;
    }
};
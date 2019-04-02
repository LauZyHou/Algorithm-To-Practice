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
		for(Employee* e : emp){
			if(e->id == id){
				ans += e->importance;
				for(int sub : e->subordinates){
					ans += getImportance(emp, sub);
				}
				break;
			}
		}
		return ans;
    }
};
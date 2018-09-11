#include<bits/stdc++.h>
#include "../Utilities/StackWithMin.h"
using namespace std;

int main(){
	StackWithMin<int> stack;
	stack.push(3);
	stack.push(4);
	stack.push(2);
	stack.push(3);
	cout<<stack.min();
	return 0;
}

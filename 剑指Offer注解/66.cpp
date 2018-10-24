#include<bits/stdc++.h>
using namespace std;

//构建乘积数组,A=input,B=output
void BuildProductionArray(const vector<double>& input, vector<double>& output) {
	//A和B的长度
	int length1 = input.size();
	int length2 = output.size();

	//合法性检查:A和B的长度需要一样,而且都大于1
	if(length1 == length2 && length2 > 1) {
		//自上而下计算C[i]数组,保存在output数组里
		output[0] = 1;//C[0]=1
		for(int i = 1; i < length1; ++i) {//自上而下
			output[i] = output[i - 1] * input[i - 1];//C[i]=C[i-1]*A[i-1]
		}

		//自下而上计算D[i]数组,顺便和C[i]相乘即为结果保存在output数组里
		double temp = 1;//D[length-1]=1
		for(int i = length1 - 2; i >= 0; --i) {//自下而上
			temp *= input[i + 1];//D[i]=D[i+1]*A[i+1]
			output[i] *= temp;//乘到C[i]上
		}
	}
}

int main() {
	double input[] = { 1, 2, 3, 4, 5 };
	double output[] = { 0, 0, 0, 0, 0 };
	vector<double> A(input,input+sizeof(input)/sizeof(double));
	vector<double> B(output,output+sizeof(output)/sizeof(double));
	BuildProductionArray(A,B);
	for(vector<double>::const_iterator cit=B.cbegin();cit!=B.cend();cit++){
		cout<<*cit<<" ";
	}//120 60 40 30 24
	return 0;
}

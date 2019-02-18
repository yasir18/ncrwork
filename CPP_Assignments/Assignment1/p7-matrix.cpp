#include<bits/stdc++.h>
using namespace std;

class Matrix{
	vector<vector<int> > vec;
public:
	Matrix(){
		// cout<<"Enter number of rows and columns :";
		// int r,c;
		// cin>>r>>c;
		// vec.resize(r);
		// for(int i=0;i<r;i++)
		// {
		// 	vec[i].resize(c);
		// 	for(int j=0;j<vec[i].size();j++){
		// 		vec[i][j]=0;
		// 	}
		// }	
	}

	Matrix(int a,int b){
		cout<<"Enter the values";
		vec.resize(a);
		for(int i=0;i<vec.size();i++){
			vec[i].resize(b);
			for(int j=0;j<vec[i].size();j++){
				cin>>vec[i][j];
			}
		}
	}

	friend Matrix multiply(Matrix A,Matrix B){
		Matrix C;
		int rows=A.vec.size();
		int cols=B.vec[0].size();
		C.vec.resize(rows);
		for(int i=0;i<C.vec.size();i++){
			C.vec[i].resize(cols);
		}
		int c;
		for(int i=0;i<rows;i++){

			for(int k=0;k<cols;k++){
				c=0;
				for(int j=0;j<A.vec[0].size();j++){
					c+=A.vec[i][j]*B.vec[j][k];
				}
				C.vec[i][k]=c;
			}
		}
		return C;
	}
	void print(){
		for(int i=0;i<vec.size();i++){
			for(int j=0;j<vec[0].size();j++)
				cout<<vec[i][j];
			cout<<endl;
		}
	}

};

int main(){
	int a,b;
	cout<<"enter the number of rows and cols :";
	cin>>a>>b;
	Matrix A(a,b);
	cout<<"enter the number of rows and cols :";
	cin>>a>>b;
	Matrix B(a,b);
	Matrix C;
	C=multiply(A,B);
	C.print();
	return 0;
}
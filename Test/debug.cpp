#include<iostream>
#include <cstring>
using namespace std;
void swap(char A[],char B[], int a_size, int b_size)
{
	int i=0;
	char *temp;
	temp = new char[b_size];
	for (int i = 0;i < b_size; i++) temp[i] = B[i];
	delete [] B;
	B = new char[a_size];
	for (int i = 0;i < a_size; i++) B[i] = A[i];
	delete [] A;
	A = new char[b_size];
	for (int i = 0; i < b_size; i++) {
		A[i] = temp[i];
	}
    delete []temp;
}
int main()
{
	int n,i,j,B[1024];
	char ***A;
	cin>>n;
	A=new char**[n];
	for(i=0;i<n;i++)
	{
		int l;
		cin>>l;
		B[i]=l;
		A[i]=new char*[l];	
		for(j=0;j<l;j++)
		{
            char *tmp;
            tmp = new char[1024];
            cin >> tmp;
			A[i][j]=new char[strlen(tmp)];
            for (int k = 0;k < strlen(tmp); k++) A[i][j][k] = tmp[k];
            delete [] tmp;
		}	
	}
	int k,l1,l2,w1,w2;
	cin>>k;
	for(i=0;i<k;i++)
	{
		cin>>l1>>w1>>l2>>w2;
		swap(A[l1][w1],A[l2][w2], strlen(A[l1][w1]), strlen(A[l2][w2]));
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<B[i];j++)
		{
			cout<<A[i][j];
			if(j!=(B[i]-1))
				cout<<" ";
			else cout<<endl;
		}
	}
	
}
#include <iostream>
#include<algorithm>
using namespace std;
void bubbleSort(int a[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=n-1;j>=i;j--)
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
}
void trace(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
 } 
int main() 
{
	int n;

	cout<<"����������Ԫ�ظ�����";	cin>>n;
	int a[100];
	cout<<"���������������Ԫ�أ�";
	for(int i=0;i<n;i++)
		cin>>a[i];
	bubbleSort(a,n);
	trace(a,n);
	return 0;
}

//�ҵ����������������������Ŀǰ�������������ľ���
//����Ѱ�ң�������� 
#include<stdio.h>
int main()
{
	int a[10000];
	int right;
	int count=0;
	scanf("%d",&right);
	for(int i=0;i<right;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<right;i++)
		for(int j=0;j<i;j++)
			if(a[j]>a[i])
			count++;		
	printf("%d",count);
	return 0;
}
 

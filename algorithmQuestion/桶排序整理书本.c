//Ͱ���򣬸�����ı�Ŷ��鱾����������Ա�Ž϶̵��鱾�������� 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100000
int main()
{
	int a[MAX];//����һ�����飬�±��ʾ��ı���
	int i=0;
	/*while(i!=100)
	{
		a[i]=0;
		i+=1;
	}*/
	memset(a,0,sizeof(a));
	int b;//��ʾҪ������鱾��Ŀ
	printf("�������鱾����Ŀ��"); 
	scanf("%d",&b);
	i=0;
	int iso;//�鱾���� 
	while(i!=b)	
	{
		scanf("%d",&iso);
		a[iso]+=1;
		i+=1;
	}
	iso=0;
	while(iso<MAX)
	{
		if(a[iso]!=0)
			printf("���Ϊ%d������%d��\n",iso,a[iso]);
		iso+=1;
	}
	return 0;
}   

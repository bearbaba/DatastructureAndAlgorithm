/*
    ���ڸ���ÿ�����ӵ���������Ҫ����ĸ�����
    ���������ϵ����ֵĺ͡����ֵ���Ƶ��.����к� 
    ����ͳ��ֵĸ�����ͬ����ôֻ��Ҫ�����С���Ǹ�. ���ݷ�Χ��
*/
 #include<stdio.h>
 #include<algorithm> 
 #include<string.h>
 #include<math.h>
 using namespace std;
 int main()
 {
 	int a,b,c,x,y,z;
 	scanf("%d%d%d",&a,&b,&c);
 	int num1[1000];
 	int sum;
 	int nm1[1000],nm2[1000],nm3[1000];
 	for(int i=1;i<=a;i++)
 		nm1[i]=i;
 	for(int i=1;i<=b;i++)
 		nm2[i]=i;
 	for(int i=1;i<=c;i++)
 		nm3[i]=i;
	for(x=1;x<=a;x++)
		for(y=1;y<=b;y++)
			for(z=1;z<=c;z++)
			{
				sum=nm1[x]+nm2[y]+nm3[z];
				num1[sum]+=1;
			}
 	int maxn=0;
 	int n;
	for(int i=1;i<=sum;i++)
	{
		if(num1[i]>maxn)
		{
			maxn=num1[i];
			n=i;
		}
	}
	printf("%d",n);		
}

#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
typedef int elemtype;
typedef struct node
{
	int data;
	struct node *next;
 } nodes;
 nodes *InitLinkList()
 {
 	nodes *p_node=(nodes *)malloc(sizeof(nodes));
 	p_node->next=NULL;
 	return p_node;
 }
 elemtype CreatLinkList(nodes *p_node,int value)
 {
 	if(p_node==NULL)
 		return ERROR;
 	nodes *current_node=p_node;
	nodes *new_node=(nodes *)malloc(sizeof(nodes));
	while(current_node->next!=NULL)
	{
		current_node=current_node->next;
	 }
	 new_node->data=value;
	 new_node->next=NULL;
	 current_node->next=new_node;
	 return OK; 
 }
 elemtype ForeachNode(nodes *p_node)
 {
 	if(p_node==NULL)
 		return ERROR;
 	nodes *current_node=p_node;
	while(current_node->next!=NULL)
	{
		current_node=current_node->next;
		printf("%d ",current_node->data);
	 }
	 return OK; 
 }
 elemtype InsertElem(int pos,int value,nodes *p_node)
 {
 	if(p_node==NULL)
 		return ERROR;
	nodes *new_node=(nodes *)malloc(sizeof(nodes));
	new_node->data=value;
	new_node->next=NULL;
	nodes *privious_node=p_node;
	nodes *current_node=p_node->next;
	int temp=1;
	while(current_node!=NULL)
	{
		if(pos==temp)
		{
			new_node->next=current_node;
			privious_node->next=new_node;
			break; 
		}
		else
		{
			privious_node=current_node;
			current_node=current_node->next;
			temp++;
		}
	} 
	return OK;
 }
 elemtype DeleteNode(int pos,nodes *p_node)
 {
 	if(p_node==NULL)
 		return ERROR;
 	nodes *privious_node=p_node;
 	nodes *current_node=p_node->next;
 	int temp=1;
 	while(current_node!=NULL)
 	{
 		if(temp==pos)
 		{
 			privious_node->next=current_node->next;
 			free(current_node);
 			current_node=NULL;
 			break;
		 }
		else
		{
			privious_node=current_node;
			current_node=current_node->next;
			temp++;
		}
	}
	return OK;
 }
 elemtype ClearLinkList(nodes *p_node)
 {
    if(p_node==NULL)
        return ERROR;
    nodes *current_node=p_node;
    while(current_node->next!=NULL)
    {
    	nodes *save_node=current_node; 
        current_node=current_node->next;
        free(save_node);
        save_node=NULL;
    }
    p_node->next=NULL;
    return OK;
 }
 elemtype DeleteLinkList(nodes *p_node)
 {
    if(p_node==NULL)
        return ERROR;
    free(p_node);
    p_node=NULL;
    return OK;
 }
 int main()
 {
 	nodes *p;
 	printf("-----��������-----\n"); 
 	p=InitLinkList();
 	int n;
 	printf("����������ڵ����Ŀ��");
 	scanf("%d",&n);
 	for(int i=0;i<n;i++)
 	{
 		printf("�������%d���ڵ��ֵ\n",i+1);
 		int value;
 		scanf("%d",&value);
 		CreatLinkList(p,value);
	}
	printf("\n-----��ʾ�Ѵ���������-----\n");
	ForeachNode(p);
	printf("\n\n-----�����������в���һ����Ԫ��-----\n");
	printf("��ѡ�����Ԫ�ص�λ��1~%d��",n);
	int pos,value;
	scanf("%d",&pos);
	printf("���������Ԫ�ص�ֵ��");scanf("%d",&value);
	InsertElem(pos,value,p);
	printf("\n-----��ʾ������Ԫ�غ������-----\n");
	ForeachNode(p);
	printf("\n-----ɾ��һ���ڵ�-----\n");
	printf("������ɾ���ڵ��λ��1~%d: ",n+1);scanf("%d",&pos);
	DeleteNode(pos,p);
	printf("��ʾɾ���ڵ�������\n");
	ForeachNode(p); 

    printf("\n-----�������-----\n");
    ClearLinkList(p);
    printf("��ʾ�������������\n");
    ForeachNode(p);

    printf("\n-----ɾ������------\n");
    DeleteLinkList(p);
	return 0; 
 }  

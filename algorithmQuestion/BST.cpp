#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
 
/* �����������Ľڵ�ṹ���� */
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void creat(BiTree T);
void order(BiTree t);
int search(BiTree T);
int SearchBST(BiTree T, int key, BiTree f, BiTree *p );
int SearchBST2(BiTree T, int key, BiTree f, BiTree *p );
int InsertBST1( BiTree *T, int key );
int InsertBST2( BiTree *T, int key ); 
void delete_node(BiTree T);
int Delete(BiTree *p);
int Delete(BiTree *);
int DeleteBST(BiTree *T, int key);

int search(BiTree T)
{
	BiTree p;
	int n;
	printf("������������ҵĽڵ��ֵ��");
	scanf("%d",&n);
	if(SearchBST(T,n,NULL,&p)==TRUE)
	{
		printf("�Ѳ��ҵ�ֵΪ%d�Ľڵ�",n);
		printf("\n");
		return TRUE;
	}
	else
	{
		printf("δ���ҵ��ýڵ�");
		printf("\n");
		return FALSE;
	}
}

 
int SearchBST(BiTree T, int key, BiTree f, BiTree *p )
{

	if( !T )
	{	
		*p = f;		
		return FALSE;	
	}
	else
	{
		if( key == T->data )
		{	
			*p = T;		
			return TRUE;
		}
		
		else if( key > T->data )
			return SearchBST( T->rchild, key, T, p );	
			
		else	
			return SearchBST( T->lchild, key, T, p );	
	}
}
 
int SearchBST2(BiTree T, int key, BiTree f, BiTree *p )
{

	BiTree s;
	if( !T )
	{	
		*p = f;		
		return FALSE;
	}
	else
	{
		while( T )
		{
			if( key == T->data )
			{	
				*p = T;		
				return TRUE;	
			}
			
			if( key > T->data )
			{	
				s = T;	
				T = T->rchild;
			}
			
			else
			{	
				s = T;	
				T = T->lchild;		
			}
		}
		*p = s;
		return FALSE;
	}
}
 
int InsertBST1( BiTree *T, int key )
{

	BiTree p, s;
	if(!SearchBST2( *T, key, NULL, &p))
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if( !p )
			*T = s;
		else if(key > p->data)
			p->rchild = s;		
		else
			p->lchild = s;		
		return TRUE;
	}
	return FALSE;
}
 
int InsertBST2( BiTree *T, int key )
{
	if( !(*T) )							
	{
		(*T) = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = key;
		(*T)->lchild = (*T)->rchild = NULL;
		return TRUE;
	}
	if( key == (*T)->data )
		return FALSE;
	if( key > (*T)->data )		
		return InsertBST2( &((*T)->rchild), key );	
	else
		return InsertBST2( &((*T)->lchild), key );		
}

void order(BiTree t)
{  
    if(t == NULL)  
        return ;  
    order(t->lchild);  
    printf("%d ", t->data);  
    order(t->rchild);  
} 
  
int DeleteBST(BiTree *T, int key)
{

	if( !(*T))
		return FALSE;	
	else
	{
		if( key == (*T)->data )
			Delete(T);
		else if(key < (*T)->data)
			return DeleteBST(&(*T)->lchild, key);
		else
			return DeleteBST(&(*T)->rchild, key);
	}
}
 
int Delete(BiTree *p)
{
	BiTree q, s;
	if(!(*p)->lchild && !(*p)->rchild)
		*p = NULL;
	else if(!(*p)->lchild)
	{
		q = *p;	
		*p = (*p)->rchild;
		free(q);
	}
	else if( !(*p)->rchild )	
	{
		q = *p;
		*p = (*p)->lchild;	
		free(q);
	}
	else					
	{
		q = *p;
		s = (*p)->lchild;
		while(s->rchild)		
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if(q != *p)			
			q->rchild = s->lchild;	
		else
			q->lchild = s->lchild;
		free(s);
	}
	return TRUE;
}

void delete_node(BiTree T)
{
	int n;
	printf("������Ҫɾ���Ľڵ��ֵ��");
	scanf("%d",&n);
	if(DeleteBST(&T,n)==FALSE)
	{
		printf("δ�鵽ֵΪ%d�Ľڵ�",n);
		return ; 
	}
	printf("ɾ��ֵΪ%d�Ľڵ�������������������:",n);
	order(T);
	printf("\n");
}

int main()
{
	BiTree T = NULL;
	printf("--------��������������---------\n");
	int n;
	int a[MAX];
	printf("����������������Ľڵ������");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i = 0; i<n; i++)
		InsertBST1(&T, a[i]);
	printf("��������������������нڵ㣺");
	order(T);
	printf("\n");


	printf("----------���ҽڵ�-------------\n");
	search(T);

	 
	printf("----------ɾ���ڵ�-------------\n");
	delete_node(T);
	return 0;
}


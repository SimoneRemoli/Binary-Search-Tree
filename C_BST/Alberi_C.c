#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define M 10
struct NODO
{
	int k;
	struct NODO *p_DX;
	struct NODO *p_SX;
};
void insert(struct NODO*&,int);
void pre_order_visit(struct NODO*&);
void post_order_visit(NODO*&);
void in_order_visit(NODO*&);

int main(int argc, char *argv[])
{

	struct NODO *root =(struct NODO*)malloc(sizeof(struct NODO)); //malloc(sizeof(struct NODO));
	root->k=0;
	root->p_DX=NULL;
	root->p_SX=NULL;
	int app;
	printf("\n Nodo radice ---> %d\n",root->k);
	srand((unsigned)time(NULL));
	for(int i=0;i<M;i++)
	{
		app = rand()%100+1;
		if(app%2==0)
		{

			printf("SX \t");
			insert(root->p_SX,app);
		}
		else
		{
			printf("DX \t");
			insert(root->p_DX,app);
		}
	}
	printf("Visualizzazione Pre Order ----\n");
	pre_order_visit(root);
	printf("Visualizzazione Post Order ----\n");
	post_order_visit(root);
	printf("Visualizzazione In Order ----\n");
	in_order_visit(root);
	free(root);
	return 0;

}
void insert(struct NODO *&root,int val)
{
	if(root==NULL)
	{
		root=(struct NODO*)malloc(sizeof(struct NODO));   //malloc(sizeof(struct NODO));
		root->p_DX=NULL;
		root->p_SX=NULL;
		root->k=val;
		printf("%d \n",val);
	}
	else
		if(val>root->k)
		{
			printf("SX(1) \t");
			insert(root->p_SX,val);
		}
		else
		{
			printf("DX(1) \t");
			insert(root->p_DX,val);
		}

}
void pre_order_visit(struct NODO *&root)
{
	if(root == NULL)
		return;
	else
	{
		printf(" %d \n",root->k);
		pre_order_visit(root->p_DX);
		pre_order_visit(root->p_SX);
	}
}
void post_order_visit(NODO *&root)
{
	if(root == NULL)
		return;
	else
	{
		post_order_visit(root->p_SX);
		post_order_visit(root->p_DX);
		printf(" %d \n",root->k);
	}
}
void in_order_visit(NODO *&root)
{
	if(root == NULL)
		return;
	else
	{
		in_order_visit(root->p_SX);
		printf(" %d \n",root->k);
		in_order_visit(root->p_DX);
	}
}

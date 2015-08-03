#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct treeNode
{
	int value;
	struct treeNode *right;
	struct treeNode *left;
};
typedef struct treeNode* Node;

Node getNode(int data)
{
	Node tem = (Node)malloc(sizeof(struct treeNode)) ;
    tem->value = data;
    tem->left=NULL;
    tem->right=NULL;
    return tem;
}

void insertValue(Node *phead, int data)
{
	
    if (*phead==NULL)
    {
    	*phead=getNode(data);
    	return ;
    }
    
    Node pnode = *phead;
	if (pnode->value > data)
	{
		if (pnode->left == NULL)
		{
			pnode->left = getNode(data);
			return ;
		}
		insertValue(&pnode->left, data);
		
	}else 
	{
		if (pnode->right == NULL)
		{
			pnode->right = getNode(data);
			return ;
		}
		insertValue(&pnode->right, data);
	}
	
}

void midShow(Node phead)
{
    if (NULL == phead)
    {
        return;
    }else{
    	midShow(phead->left);
    	printf("%d\t", phead->value);
    	midShow(phead->right);
    }
}

int main(int argc, char const *argv[])
{
	Node root=NULL;
	const int SIZE=7;
	int data;
	printf("please enter 7 number: ");
	for (int i = 0; i < SIZE; ++i)
	{
		scanf("%d", &data);
		insertValue(&root, data);
	}
	printf("\nmid midShow:\n");
	midShow(root);
	printf("\n");

	queue<Node> qw;
	qw.push(root);
	while(!qw.empty())
	{
		// queue<Node>::size_type qw_size= qw.size();
		// for (queue<Node>::size_type i = 0; i < qw_size; ++i)
		//  {
		//  	Node tmp1,tmp2 ;
  //           tmp1 = qw.front();
  //           if (tmp1 != NULL)
  //           {
  //           	tmp2 = tmp1->left;
  //               tmp1->left = tmp1->right;
  //               tmp1->right = tmp2;
  //               qw.push(tmp1->left);
  //               qw.push(tmp1->right);
  //           }
  //           qw.pop();      
		//  }  
		Node tmp1,tmp2 ;
        tmp1 = qw.front();
        if (tmp1 != NULL)
        {
            tmp2 = tmp1->left;
            tmp1->left = tmp1->right;
            tmp1->right = tmp2;
            qw.push(tmp1->left);
            qw.push(tmp1->right);
        }
        qw.pop();    

	}

	printf("After mirror:\n");
	midShow(root);
	return 0;
}
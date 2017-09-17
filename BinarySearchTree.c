#include<stdio.h>
#include<stdlib.h>

struct Node
{
int data;
struct Node*left;
struct Node*right;
};

//Function to find minimum in a tree

struct Node*FindMin(struct Node*root)
{
while(root->left!=NULL)
root=root->left;
return root;
}

// Function to search a delete a value from tree.
struct Node*Delete(struct Node*root,int data)
{
if(root==NULL)
return root;

else if(data<root->data)
root->left=Delete(root->left,data);

else if(data>root->data)
root->right=Delete(root->right,data);

//Wohoo… I found you, Get ready to be deleted

else
{

//Case 1:No Child

if(root->left==NULL&&root->right==NULL)
{
free(root);
root=NULL;
}

//Case 2:One child

else if(root->left==NULL)
{
struct Node*temp=root;
root=root->right;
free(temp);

else if(root->right==NULL)
{
struct Node*temp=root;
root=root->left;
free(temp);
}

//case 3:2 children

else
{
struct Node*temp=FindMin(root->right);
root->data=temp->data;
root->right=Delete(root->right,temp->data);
}
}
return root;
}

//Function to visit nodes in Inorder

void Inorder(struct Node*root)
{
if(root==NULL)
return;

Inorder(root->left);   //Visit left subtree
printf("%d\t",root->data);  //Print data
Inorder(root->right); //Visit right subtree
}

//Function to Insert Node in a Binary Search Tree

struct Node*Insert(struct Node*root,int data)
{
if(root==NULL)
{
root=(struct Node*)malloc(sizeof(struct Node*));
root->data=data;
root->left=root->right=NULL;
}

else if(data<=root->data)
root->left=Insert(root->left,data);

else
root->right=Insert(root->right,data);

return root;
}

int Search(struct Node*root,int data)
{
if(root==NULL)
return 0;

else if(root->data=data)
return 1;

else if(data<=root->data)
return Search(root->left,data);

else
return Search(root->right,data);
}

int main()
{
/* Code To Test the logic Creating an example tree
		5
	          /   \
 	        3     10
	       /  \       \
      	     1   4       11		*/

struct Node*root=NULL;
int a,d,choice;
do
{
printf("\nENTER A CHOICE:");
printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.SEARCH\n5.EXIT\n");
printf("\n Enter choice:");

scanf("%d",&choice);
switch(choice)
{
case 1:
{
printf("Enter a Number to be inserted:");
scanf("%d",&d);
root=Insert(root,d);
break;
}

case 2:// Deleting node with value 5, change this value to test other cases
printf("Enter a Number to be deleted:");
scanf("%d",&d);
root=Delete(root,d);
break;

case 3://Print Nodes in Inorder
printf("Inorder:");
Inorder(root);
printf("\n");
break;
case 4://Search an element
printf("Enter a Number to be searched:");
scanf("%d",&d);
if(Search(root,d)==1)
printf("Found no:%d\n",d);
else
printf("Not Found no:%d\n",d);
break;

case 5:
return(0);
}
}
while(choice!=5);
return(0);
}


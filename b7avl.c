#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a,int b)
{
    return (a>b)?a:b;
}

int height(struct Node* N)
{
    if(N==NULL)
        return  0;
    return(1+max(height(N->left),height(N->right)));
}

struct Node* newnode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key=key;
    node->right=NULL;
    node->left=NULL;
    node->height=0;
    return(node);
}
struct Node* rightRotate(struct Node* y)
{
    struct Node *x=y->left;
    struct Node *T2=x->right;
    x->right=y;
    y->left=T2;
    y->height=height(y);
    x->height=height(x);
    return x;
}

struct Node* leftRotate(struct Node* x)
{
    struct Node *y=x->right;
    struct Node *T2=y->left;
    y->left=x;
    x->right=T2;
    x->height=height(x);
    y->height=height(y);
    return y;
}

int getbalance(struct Node* N)
{
    if(N==NULL)
        return 0;
    return (height(N->left)-height(N->right));
}

struct Node* insert(struct Node* node,int key)
{
    if(node==NULL)
        return(newnode(key));
    if(key<node->key)
        node->left=insert(node->left,key);
    else if(key>node->key)
        node->right=insert(node->right,key);
    else 
        return node;
    node->height=height(node);
    int balance=getbalance(node);
    if(balance>1 && key<node->left->key)
        return rightRotate(node);
    if(balance<-1 && key>node->right->key)
        return leftRotate(node);
    if(balance>1 && key>node->left->key)
    {
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance<-1 && key<node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void inorder(struct Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d(%d)\t",root->key,getbalance(root));
        inorder(root->right);
    }
}

int main()
{
    struct Node *root=NULL;
    int a[10],i,n;
    printf("\n Enter no of elements to be inserted : ");
    scanf("%d",&n);
    printf("\n Enter the elements of the tree : ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        root=insert(root,a[i]);
    printf("Inorder traverssal of the constructed avl tree : \n");
    inorder(root);
    printf("\n");
    return 0;
}

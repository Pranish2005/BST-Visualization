#include <graphics.h>
#include <conio.h>
#include <stdio.h>


struct t_node {
    int data;
    struct t_node* left;
    struct t_node* right;
};

struct t_node *root;


struct t_node* new_tNode(struct t_node *root,int val) {
    struct t_node *ptr, *nodeptr, *parentptr;
    ptr = (struct t_node*)malloc(sizeof(struct t_node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if(root==NULL)
    {
	root=ptr;
	root->left=NULL;
	root->right=NULL;
    }
    else
    {
	parentptr=NULL;
	nodeptr=root;
	while(nodeptr!=NULL)
	{
	    parentptr=nodeptr;
	    if(val<nodeptr->data)
		nodeptr=nodeptr->left;
	    else
		nodeptr = nodeptr->right;
	}
if(val<parentptr->data)
parentptr->left = ptr;
else
parentptr->right = ptr;
}
return root;
}


void Inorder(struct t_node* root)
{
    if(!root)
	return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}

void Preorder(struct t_node* root)
{
    if(!root)
	return;
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(struct t_node* root)
{
    if(!root)
	return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);
}

void printTree(int x, int y, struct t_node* root, int index) {
    char str[10];

    if (!root)
	return;

    itoa(root->data, str, 10);

    setcolor(GREEN);
    circle(x, y, 15);
    delay(200);
    floodfill(x, y, GREEN);
    delay(200);

    outtextxy(x - 2, y - 3, str);
    delay(200);

    if (root->left) {
	setcolor(GREEN);
	line(x, y + 14, x - 30, y + 50 - 14);
	printTree(x - 30, y + 50, root->left, index * 2);
    }

    if (root->right) {
	setcolor(GREEN);
	line(x, y + 14, x + 30, y + 50 - 14);
	printTree(x + 30, y + 50, root->right, index * 2 + 1);
    }
}

int main() {
    int gd = DETECT, gm,n,val;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    do{
    printf("\n1)Insert element.");
    printf("\n2)Inorder Traversal");
    printf("\n3)Postorder traversal.");
    printf("\n4)Preorder traversal.");
    printf("\n5)Visualization.");
    printf("\n6)Exit/");
    printf("\nEnter choice: ");
    scanf("%d",&n);
    switch(n)
    {
	case 1:
	    printf("\n Enter the value of the new node : ");
	    scanf("%d", &val);
	    root = new_tNode(root, val);
	    break;
	case 2:
	    printf("\n\nThe Inorder traversal is : ");
	    Inorder(root);
	    break;
	case 3:
	    printf("\n\nThe Postorder traversal is : ");
	    Postorder(root);
	    break;
	case 4:
	    printf("\n\nThe Preorder traversal is : ");
	    Preorder(root);
	    break;
	case 5:
	    cleardevice();
	    printTree(300, 100, root,0);
	    break;

    }
    }while(n!=6);


    getch();
    return 0;
}

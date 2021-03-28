#include<iostream>        /*huffmann code tree to in ternary codes rno 13710'8' a section q no 12 B S Sachin Govind*/
using namespace std;
struct hcnode{            //declaration of huffmann node
    hcnode* left;
    int freq;
    char c;
    hcnode* right;
    hcnode* mid;
    hcnode()
    {
        left = NULL;
        right = NULL;
        mid=NULL;
    }
};
class queue                          //to print huffmann in level order
{
	public:
	int front=-1;
	int rear=-1;
	int size;
	hcnode*e[500];
	int isqfull()
	{
		if((rear+1)%size==front)
		return(1);
		else
		return(0);
	}
	int isqempty()
	{
		if(front==-1)
		return(1);
		else
		return(0);
	}
	void enqueue(hcnode* k)
	{
		if(isqfull())
		cout<<"queue is full ";
		else
		{
			if(front==-1)
			{
				front=0;
				rear=0;
			}
			else
			{
				rear=(rear+1)%size;
			}
			e[rear]=k;
		}
	}
	hcnode* dequeue()
	{
		hcnode*t;
		if(isqempty())
		{
			cout<<"queue is empty ";
			exit(1);
		}
		else
		{
			if(front==rear)
			{
				t=e[front];
				front=-1;
				rear=-1;
			}
			else
			{
				t=e[front];
				front=(front+1)%size;
			}
			return(t);
		}
	}
		int ndq()
	{
		if(rear>=front)
		{
			return(rear-front+1);
		}
		else
		return(size-front+rear+1);	
	}	
}; 

struct bstNode{           //binary search tree declation
    bstNode* lchild;
    hcnode data;
    bstNode* rchild;
    bstNode()
    {
        lchild = NULL;
        rchild = NULL;
    }
};
void inorderc(bstNode* T,int &count)   //counts number of nodes in inorder way
{
	if(T!=NULL)
	{
		inorderc(T->lchild,count);
		count++;
		inorderc(T->rchild,count);
	}
}

class BinarySearchTree{
    public:
        BinarySearchTree();
        void add(bstNode* &T,hcnode t);
        void del(bstNode* &T, hcnode t);
        hcnode minimum(bstNode* T);
        bstNode* Root();
        void print(bstNode* T);
        bool check(bstNode* t);
    private:
        bstNode* root;
};

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

bstNode* BinarySearchTree::Root()
{
    return root;
}

void BinarySearchTree::add(bstNode* &T,hcnode k)         //adds huffmann codes satisfies binary serch property with respect to frequencies 
{                                                         //  ie based on frequencies nodes are added
                                                          //instead of arrays or queues i used bst to sort or get mininmum nodes
    if(T==NULL)
    {
        T = new bstNode;
        T->data = k;
    }
    else
    {
        if(T->data.freq>k.freq)
        {
            add(T->lchild,k);
        }
        else
        {
            add(T->rchild,k);
        }
    }
}

hcnode BinarySearchTree::minimum(bstNode* T)                       //finding the last left data gives us the huffmann node of least frequency
{
    while(T->lchild!=NULL)
    {
        T = T->lchild;
    }
    return T->data;
}

void BinarySearchTree::del(bstNode* &t, hcnode k)                //delete the node.this is done to delete minimum nodes which are added
{                                                                //to hoffmann tree it is same as delete in bst. find min and substitute method
    if(t==NULL)
    {
        return;
    }
    else if(t->data.freq>k.freq)
    {
        del(t->lchild,k);
    }
    else if(t->data.freq<k.freq)
        del(t->rchild,k);
    else
    {
        if(t->lchild==NULL&&t->rchild==NULL)
            t = NULL;
        else if(t->lchild==NULL)
            t = t->rchild;
        else if(t->rchild==NULL)
            t = t->lchild;
        else
        {
            bstNode* a = t;
            a = a->lchild;
            while(a->rchild!=NULL)
            {
                a = a->rchild;
            }
            t->data = a->data;
            del(t->lchild,t->data);
        }
    }
}

void BinarySearchTree::print(bstNode* T)
{                                                                  //prints the bst in inorder way;
    if(T!=NULL)
    {
        print(T->lchild);
        cout<<T->data.c<<"\t"<<T->data.freq<<endl;
        print(T->rchild);
    }
}

bool BinarySearchTree::check(bstNode* t)                        //calls the funtion inorderc which assigns count value by call by reference 
{
	int count=0;
	inorderc(t,count);
	if(count>=3)
	return false;
	else
	return true;
    
}

void print(hcnode* T)                                   //prints huffman tree creted in preorder way
{
    if(T!=NULL)
    {
    	cout<<T->c<<"\t"<<T->freq<<endl;
        print(T->left);
        print(T->mid);
        print(T->right);
    }
}
void add(hcnode* &t, hcnode a, hcnode b,hcnode c)       //combines three minimum nodes to huffman tree creating a parent to them
{

    t = new hcnode;
    t->c = '#';
    t->freq = a.freq + b.freq+c.freq;
    t->left = new hcnode;
    *(t->left) = c;
    t->mid = new hcnode;
    *(t->mid) = b;
    t->right = new hcnode;
    *(t->right) = a;
    return;
}
void add(hcnode* &t, hcnode a,hcnode b)               //combines nodes to form huffmann tree this is fuction overloading when only two min nodes are present
{                                                     

    t = new hcnode;
    t->c = '#';
    t->freq = a.freq+b.freq ;
    t->left = new hcnode;
    *(t->left) = b;
    t->mid = new hcnode;
    *(t->mid) = a;
    return;
}
void levelorder(hcnode*t)
{
	hcnode*n=NULL;
	queue q;
	q.enqueue(n);
	while(t!=NULL)	
	{
    cout<<t->c<<t->freq<<" ";	
	if(t->left!=NULL)
    {q.enqueue(t->left);}
    if(t->mid!=NULL)
    {q.enqueue(t->mid);}
    if(t->right!=NULL)
    {q.enqueue(t->right);}
	hcnode*k=q.dequeue();
	if(k==NULL)
	{
	q.enqueue(n);
	cout<<endl;
	k=q.dequeue();
	if(k==NULL)
	break;
	else
	t=k;
    }
    else
    t=k;
    } 
}


int main()
{
    BinarySearchTree bst;
    bstNode* t = bst.Root();
    hcnode *h = NULL;
    hcnode a, b, c;
    int g=0;
    int t1=1;
    cout<<"enter '.' "<<"to end input"<<endl;
    while(t1)
    {                                                  //loop for input values
        cout<<"Enter char: ";
        cin>>a.c;
        if(a.c=='.')
        break;
        cout<<"Enter freq: ";
        cin>>a.freq;
        a.left = NULL;
        a.right = NULL;
        bst.add(t,a);
        g++;
    }
    if(g==1)                                          //if only one node is entered there is no traversal as why a code there is only one char;
    {
    	cout<<"only one element "<<endl;
    	exit(1);
    }

    while(!bst.check(t))                              //check upon number of nodes and finally only one bstnode remains with the hcnode with all data
    {
        a = bst.minimum(t);                           //gets first minimum hcnode from bst
        bst.del(t,a);                                //deletes the mininmum node from bst as it is already accessed
        b = bst.minimum(t);                           //next min node
        bst.del(t,b);                                 //del last node ie it is in hcnode b
        c = bst.minimum(t);                           //next min node
        bst.del(t,c);                                 //del last node ie it is in hcnode c
        add(h,a,b,c);                                 //adds the three nodes ie create a combined node
        bst.add(t,*h);                                //adds combined node to bst
    }
    int count=0;
    inorderc(t,count);                                    //if count is two add function has only two hcnodes
    if(count==2)
    {
    	if(t->lchild!=NULL)
    	{
    		add(h,t->data,t->lchild->data);               //h=node;a=node with max freq;b=node with less freq(h,a,b)
    	}
    	if(t->rchild!=NULL)
    	{
    		add(h,t->rchild->data,t->data);
    	}
    }
    hcnode*f=h;
    cout<<endl<<"printing level order "<<endl;
    levelorder(h);
    cout<<endl;
    string s;
    cout<<endl<<"Enter string: ";
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        {
            f = f->mid;
        }
        else if(s[i]=='0')
        {
            f = f->left;
        }
        else
        {
        	f=f->right;
        }
        if(f->left==NULL && f->right==NULL&&f->mid==NULL)
        {
            cout<<f->c;
            f = h;
        }
    }
    return 0;
}


#include<iostream>
using namespace std;

struct hcNode{
    hcNode* left;
    int frequency;
    char c;
    hcNode* right;
    hcNode()
    {
        left = NULL;
        right = NULL;
    }
};

struct bstNode{
    bstNode* lChild;
    hcNode data;
    bstNode* rChild;
    bstNode()
    {
        lChild = NULL;
        rChild = NULL;
    }
};

class BinarySearchTree{
    public:
        BinarySearchTree();
        void add(bstNode* &T,hcNode t);
        void remove(bstNode* &T, hcNode t);
        hcNode minimum(bstNode* T);
        bstNode* get_Root();
        void print(bstNode* T);
        bool one_Element(bstNode* t);
    private:
        bstNode* root;
};

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

bstNode* BinarySearchTree::get_Root()
{
    return root;
}

void BinarySearchTree::add(bstNode* &T,hcNode k)
{
    if(T==NULL)
    {
        T = new bstNode;
        T->data = k;
    }
    else
    {
        if(T->data.frequency>k.frequency)
        {
            add(T->lChild,k);
        }
        else
        {
            add(T->rChild,k);
        }
    }
}

hcNode BinarySearchTree::minimum(bstNode* T)
{
    while(T->lChild!=NULL)
    {
        T = T->lChild;
    }
    return T->data;
}

void BinarySearchTree::remove(bstNode* &t, hcNode k)
{
    if(t==NULL)
    {
        return;
    }
    else if(t->data.frequency>k.frequency)
    {
        remove(t->lChild,k);
    }
    else if(t->data.frequency<k.frequency)
        remove(t->rChild,k);
    else
    {
        if(t->lChild==NULL&&t->rChild==NULL)
            t = NULL;
        else if(t->lChild==NULL)
            t = t->rChild;
        else if(t->rChild==NULL)
            t = t->lChild;
        else
        {
            bstNode* a = t;
            a = a->lChild;
            while(a->rChild!=NULL)
            {
                a = a->rChild;
            }
            t->data = a->data;
            remove(t->lChild,t->data);
        }
    }
}

void BinarySearchTree::print(bstNode* T)
{
    if(T!=NULL)
    {
        print(T->lChild);
        cout<<T->data.c<<"\t"<<T->data.frequency<<endl;
        print(T->rChild);
    }
}

bool BinarySearchTree::one_Element(bstNode* t)
{
    return (t->lChild==NULL && t->rChild==NULL);
}

void print(hcNode* T)
{
    if(T!=NULL)
    {
        print(T->left);
        cout<<T->c<<"\t"<<T->frequency<<endl;
        print(T->right);
    }
}

void add(hcNode* &t, hcNode a, hcNode b)
{

    t = new hcNode;
    t->c = '#';
    t->frequency = a.frequency + b.frequency;
    t->left = new hcNode;
    *(t->left) = b;
    t->right = new hcNode;
    *(t->right) = a;
    return;
}


int main()
{
    BinarySearchTree bst;
    bstNode* t = bst.get_Root();
    hcNode *h = NULL;
    hcNode a, b;
    while(1)
    {
        cout<<"Enter character: ";
        cin>>a.c;
        cout<<"Enter frequency: ";
        cin>>a.frequency;
        if(a.frequency<=0)
        {
            break;
        }
        a.left = NULL;
        a.right = NULL;
        bst.add(t,a);
    }
    bst.print(t);
    cout<<"\nHOFFMAN\n";

    while(!bst.one_Element(t))
    {
        a = bst.minimum(t);
        bst.remove(t,a);
        b = bst.minimum(t);
        bst.remove(t,b);
        add(h,a,b);
        bst.add(t,*h);

    }

    print(h);

    hcNode* f = h;

    string s;
    cout<<"Enter string: ";
    cin>>s;

    for(int i=0;i<s.length();i++)
    {

        if(s[i]=='1')
        {
            cout<<"\nRIGHT\n";
            f = f->right;
        }

        else if(s[i]=='0')
        {
            cout<<"\nLEFT\n";
            f = f->left;
        }

        if(f->left==NULL && f->right==NULL)
        {
            cout<<"DATA: "<<f->c<<endl;
            f = h;
        }

    }

    return 0;

}


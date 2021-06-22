#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
     data=d;
     left=NULL;
     right=NULL;
    }
    
};
//Here is how you build a node
node* buildNode()
{
int d;
cin>>d;
if(d==-1)
{
    return NULL;
}
node* root=new node(d);
root->left=buildNode();
root->right=buildNode();
return root;
}

void printN(node* root)
{
    if(root==NULL)
    {
        return;
    }
   cout<<root->data<<" ";
   printN(root->left);
   printN(root->right);
}
//there are three types of traversal 
//1.Preorder=data left right
void Preorder(node* root)
{
     if(root==NULL)
    {
        return;
    }
   cout<<root->data<<" ";
   Preorder(root->left);
   Preorder(root->right);
}
//2.Inorder
void Inorder(node* root)
{
     if(root==NULL)
    {
        return;
    }
   Inorder(root->left);
   cout<<root->data<<" ";
   Inorder(root->right);
}
//3.PostOrder
void Postorder(node* root)
{
     if(root==NULL)
    {
        return;
    }
   Postorder(root->left);
   Postorder(root->right);
   cout<<root->data<<" ";
}
int height(node* root)
{
    if(root==NULL)
    return 0;
    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;
}
//This takes O(N^2)
void PrintKth(node *root,int k)
{
if(root==NULL)
{
return;
}
if(k==1)
{
    cout<<root->data<<" ";
    return;
}
PrintKth(root->left,k-1);
PrintKth(root->right,k-1);

}
void LevelOrder(node *root,int height)
{
for(int i=1;i<=height;i++)
{
PrintKth(root,i);
cout<<endl;
}
}
//Level order traversal can be done by BFS that is O(N)
void BFS(node* root)
{
//1.make a queue
queue<node*> q;
//Make it of type node* things become easier so that you can traverse and now put the root node into it
q.push(root);
while(!q.empty())
{
    //3 easy steps- take out whats at front
    node* front=q.front();
    cout<<front->data<<" ";
    q.pop();
    //push the children if any that is basically dfs
    if(front->left)
    q.push((front->left));
    if(front->right)
    q.push((front->right));
    
}
}
//Count the number of nodes
int CountN(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+CountN(root->left)+CountN(root->right);
}
//Sum of node data
int SumNode(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->data+ SumNode(root->left)+SumNode(root->right);
}
//Apparently there is this thing called diameter which means largest distance between two nodes in a tree
//try this tree 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 has diameter of 6 via root
int Diameter(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int d1=height(root->left)+height(root->right);
    int d2=Diameter(root->left);
    int d3=Diameter(root->right);
    return max(d1,max(d2,d3));
}
//like add child data and pass your data to parent ok
int sumOfChild(node* root)
{
   if(root==NULL)
   {
       return 0;
   }
   if(root->left==NULL && root->right==NULL)
   {
       return root->data;
   }
   int temp=root->data;
   root->data= sumOfChild(root->left)+sumOfChild(root->right);
   return root->data+temp;
}
//check if tree is height balanced or not h1-h2<=1 at every node
bool heightBal(node* root)
{
    if(root==NULL)
    
        return true;
    
   if(abs(height(root->left)-height(root->right))<=1)

       return (heightBal(root->left) &&  heightBal(root->right)); 
   
   return false;
}
//Create a balanced binary tree out of an array
node* Createbbt(int* a,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
int mid=(s+e)/2;
node* root=new node(a[mid]);
root->left=Createbbt(a,s,mid-1);
root->right=Createbbt(a,mid+1,e);
return root;
}
//Creating a balanced tree when inorder and preorder is given (s and e are from inorder array)
//try this pre: 1 2 3 4 8 5 6 7
//in: 3 2 8 4 1 6 7 5
node* cnip(int* i,int* p,int s,int e)
{
    static int pit=0;
    if(s>e)
    {
        return NULL;
    }
    node* n=new node(p[pit]);
    //root node ka index inorder array mein find karo kyuki uske lhs aur rhs ko call karne ka hai
    //inorder tells left pe jayega ya right
    int index=-1;
    for(int z=s;z<=e;z++)
    {
        if(p[pit]==i[z])
        {
             index=z;
        }
    }
    pit++;
    //now make calls around index
    n->left=cnip(i,p,s,index-1);
    n->right=cnip(i,p,index+1,e);
    return n;
}
bool find(node* root, int a)
{
    if(root->data==a)
    {
        return true;
    }
    else
    {
        return find(root->left,a) || find(root->right,a);
    }
    
}
//Lowest Common ancestor
int lca(node* root,int a,int b)
{
  if( (find(root->left,a) && find(root->right,b)) || (find(root->left,b) && find(root->right,a)) )
  {
      return root->data;
  }
  else 
  {
      return lca(root->left,int a,int b)
  }
  

}
int main()
{
    // node* n= buildNode();
    // Postorder(n);
    //cout<<height(n)<<endl;
   //PrintKth(n,3);
  // LevelOrder(n,height(n));
//   cout<<CountN(n)<<endl;
//   cout<<SumNode(n)<<endl;
//   cout<<Diameter(n)<<endl;
//   sumOfChild(n);
//    LevelOrder(n,height(n));
//    if(heightBal(n))
//    cout<<"Yes Blanaced"<<endl;
//    else
//    {
//        cout<<"NO"<<endl;
//    }

//    int a[6]={1,2,3,4,5,6};
//    node* n=Createbbt(a,0,5);
//    LevelOrder(n,height(n));
int p[8]={1,2,3,4,8,5,6,7};
int i[8]={3,2,8,4,1,6,7,5};
node *n=cnip(i,p,0,7);
LevelOrder(n,height(n));
rightView(n,1,0);

   
   

}
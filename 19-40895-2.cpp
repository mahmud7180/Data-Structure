//Question number 1 and 2 solution.
#include <iostream>

using namespace std;

struct node{
    int value;
    node *left;
    node *right;
};

class bst{
public:
    node *create(int v){
        node *temp=new node;
        temp->value=v;
        temp->left=temp->right=NULL;
        return temp;
    }
    void insert(node *&root, int v){
        if(root==NULL){
            root=create(v);
        }
        else if(v<root->value){
            insert(root->left,v);
        }
        else{
            insert(root->right,v);
        }
    }
    void displayInorder(node *root){
        if(root!=NULL){
            displayInorder(root->left);
            cout<<root->value<<" ";
            displayInorder(root->right);
        }
    }
    void displayPreorder(node *root){
        if(root!=NULL){
            cout<<root->value<<" ";
            displayPreorder(root->left);
            displayPreorder(root->right);
        }
    }
    void displayPostorder(node *root){
        if(root!=NULL){
            displayPostorder(root->left);
            displayPostorder(root->right);
            cout<<root->value<<" ";
        }
    }
    void searchNode(node *&root, int x){
        if(root!=NULL){
            if(root->value==x){
                cout<<"Value found"<<endl;
            }
            else if(x<root->value){
                searchNode(root->left, x);
            }
            else if(x>root->value){
                searchNode(root->right, x);
            }
        }
        else{
            cout<<"Value not found"<<endl;
        }
    }
};
int main() {
    node *root=NULL;
    bst *obj;
    obj=new bst;
    int n,data,s;
    cout<<"Enter number of data in your tree"<<endl;
    cin>>n;
    cout<<"Enter data where 1st data is the root of the tree"<<endl;
    for(int i=0;i<n;i++){
        cin>>data;
        obj->insert(root,data);
    }
    cout<<"Inorder: ";
    obj->displayInorder(root);
    cout<<endl;
    cout<<"Preorder: ";
    obj->displayPreorder(root);
    cout<<endl;
    cout<<"Postorder: ";
    obj->displayPostorder(root);
    cout<<endl;
    cout<<"Enter value to search"<<endl;
    cin>>s;
    obj->searchNode(root, s);
    return 0;
}

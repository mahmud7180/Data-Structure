#include <iostream>

using namespace std;

struct node
{
    int value;
    int key;
    node *forw=NULL;
    node *back=NULL;
};

class linkedList
{
    node *start;
public:
    linkedList()
    {
        start=NULL;
    }
    void insertNode(int v,int k)
    {
        node *curr;
        node *prev=NULL;
        curr=start;
        if(curr==NULL)
        {
            node *temp;
            temp=new node;
            temp->value=v;
            temp->key=k;
            temp->forw=NULL;
            temp->back=NULL;
            start=temp;
        }
        else
        {
            while(curr->forw!=NULL)
            {
                prev=curr;
                curr=curr->forw;
            }
            node *temp;
            temp=new node;
            temp->value=v;
            temp->key=k;
            temp->forw=NULL;
            temp->back=curr;
            curr->forw=temp;
            prev=curr;
            curr=temp;
        }
    }
    void deleteNode(int v)
    {
        node *curr;
        curr=start;
        node *prev=NULL;
        if(curr->forw==NULL && curr->value==v)
        {
            start=NULL;
        }
        else if(curr->forw!=NULL && curr->value==v)
        {
            start=start->forw;
            start->back=NULL;
        }
        else
        {
            while(curr!=NULL && curr->value!=v)
            {
                prev=curr;
                curr=curr->forw;
            }
            if(curr->forw==NULL)
            {
                prev->forw=NULL;
            }
            else
            {
                prev->forw=curr->forw;
                prev=curr;
                curr=curr->forw;
                curr->back=prev->back;
            }
        }
    }
    void deleteNodeByPos(int k)
    {
        node *curr;
        node *prev=NULL;
        curr=start;
        if(curr!=NULL && curr->key==k)
        {
            start=start->forw;
            start->back=NULL;
        }
        else
        {
            while(curr!=NULL && curr->key!=k)
            {
                prev=curr;
                curr=curr->forw;
            }
            curr->forw->back=prev;
            prev->forw=curr->forw;
        }
    }
    void searchKey(int v)
    {
        node *curr;
        node *prev=NULL;
        curr=start;
        if(curr==NULL)
        {
            cout<<"Empty list"<<endl;
        }
        else
        {
            while(curr!=NULL && curr->value!=v)
            {
                prev=curr;
                curr=curr->forw;
            }
            if(curr==NULL)
            {
                cout<<"No such value exist in list"<<endl;
            }
            else
            {
                cout<<"At value: "<<v<<", Key = "<<curr->key<<endl;
            }
        }
    }
    void printList()
    {
        node *curr;
        curr=start;
        cout<<"Linked list: ";
        while(curr!=NULL)
        {
            cout<<curr->value<<" ";
            curr=curr->forw;
        }
        cout<<endl;
    }
    int getnode(int k)
    {
        node *curr;
        node *prev=NULL;
        curr=start;
        if(curr==NULL)
        {
            cout<<"Empty list"<<endl;
        }
        else
        {
            while(curr!=NULL && curr->key!=k)
            {
                prev=curr;
                curr=curr->forw;
            }
            if(curr==NULL)
            {
                cout<<"No such key exist in list"<<endl;
            }
            else
            {
                cout<<"At key: "<<k<<", Value = "<<curr->value<<endl;
            }
        }
        return k;
    }
    void reverseList()
    {
        node *curr;
        node *prev=NULL;
        curr=start;
        cout<<"Reverse list: ";
        if(curr->forw==NULL)
        {
            cout<<curr->value;
        }
        else
        {
            while(curr->forw!=NULL)
            {
                prev=curr;
                curr=curr->forw;
            }
            while(curr!=NULL)
            {
                cout<<curr->value<<" ";
                curr=curr->back;
            }
        }
        cout<<endl;
    }
};

int main()
{
    linkedList *l1;
    l1=new linkedList;
    l1->insertNode(7,1);
    l1->printList();
    l1->reverseList();
    l1->insertNode(8,2);
    l1->insertNode(9,3);
    l1->insertNode(10,4);
    l1->insertNode(11,5);
    l1->insertNode(12,6);
    l1->searchKey(10);
    l1->printList();
    l1->reverseList();
    l1->deleteNode(7);
    l1->deleteNode(10);
    l1->deleteNode(12);
    l1->printList();
    l1->reverseList();
    l1->deleteNodeByPos(3);
    l1->printList();
    l1->reverseList();
    l1->searchKey(9);
    l1->getnode(2);
    l1->getnode(3);
    return 0;
}

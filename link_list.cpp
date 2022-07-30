/*
This code define four functions namely insertion, deletion, search and traverse
for linked list data structure.
*/
#include<iostream>
using namespace std;

//Defining the node
struct node
{
    int data;
    node * next;
};


class LinkedList{
private:
    node *head;

public:
    LinkedList(){
        head = NULL;
    }
    node * createNode(int);
    node * insertNode(node*,node*);
    void show();
    node* searchData(int);
    bool deleteData(int);
};
node* LinkedList::createNode(int value){
    node *newNode = new node;
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}
//Defining a function to add a node after a previous node
node* LinkedList::insertNode(node * newNode, node * prev=NULL)
{
    //adding node at head (prev = null)
    if(prev==NULL){
        //newNode->next = head;
        head = newNode;
    }

    //adding node after previous
    else
    {
        newNode->next = prev->next;
        prev->next =newNode;
    }
    return newNode;
}

// Now implement a function named deleteNode to delete a node (data)

bool LinkedList:: deleteData(int key)
{
     node * curr=head;
     node*prev=NULL;
     while (curr != NULL && curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL)
    {
        head=head->next;

    }
    else
    {
        prev->next = curr->next;
    }
}

void LinkedList::show()
{
    node * curr = head;
    while(curr != NULL)
    {
        cout<<"["<<curr->data<<","<<(int)curr->next<<"]";
        if(curr->next)cout<<"-->";
        curr = curr->next;
    }
    cout<<"\n\n";
}

/*
Now implement a function named searchData to search a particular value.
The function should return address of the node where the search element is found
otherwise return NULL.
*/
node* LinkedList::searchData(int key){
    //COMPLETE THE FUNCTION
    node * curr = head;

        while( curr!=NULL)
        {
          if(curr->data==key)
             return (curr);
          curr=curr->next;
        }
        return NULL;

}
int main()
{
    // populate linked list with some values
    int n,elem,i;
   LinkedList myList;
    node * myNode;


    cout<<"How many elements? ";
    cin>>n;
    node *p=NULL,*tmp;
    for(i=0; i<n; i++)
    {
        cout<<"Element "<<i+1<<": ";
        cin>>elem;
        myNode = myList.createNode(elem);
        p = myList.insertNode(myNode,p);
    }
    myList.show();

    int choice;
    while(true)
    {
        cout<<"\n1) search data\n2) add data\n3) add data at head\n4) delete data\n5) show List\n0) Exit\nEnter option: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            //use searchData function here
            cout<<"enter a value you want to search = "<<endl;
            cin>>elem;
            cout<<myList.searchData(elem);
            break;
        case 2:
            //use addData function here
            cout<<"After which element to insert? ";
            cin>>elem;
            tmp = myList.searchData(elem);
            if(tmp == NULL)
                cout<<elem <<" does not exist in the linked list!\n";
            else
            {
                cout<<"Which element to insert? ";
                cin>>elem;
                myNode = myList.createNode(elem);
                myList.insertNode(myNode,tmp);
            }
            break;
        case 3:
            cout<<"Which element to insert? ";
            cin>>elem;
            myNode = myList.createNode(elem);
            myList.insertNode(myNode);
            break;
        case 4:
            //use deleteData here
            cout<<"enter a value you want to delete = "<<endl;
            cin>>elem;
            myList.deleteData(elem);
            break;
        case 5:
            myList.show();
            break;
        case 0:
            return 0;
        }
    }


    return 0;
}

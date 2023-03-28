#include<iostream>
using namespace std;

class node{

    public:

    //data members
    int data;
    node *prev;
    node *next;
    
    //default constructor
    node(){
        data=0;
        next=NULL;
        prev=NULL;
    }

    //parameterized constructor
    node(int data, node *prev=NULL,node *next=NULL){
        this->data=data;
        this->next=next;
        this->prev=prev;
    }
};

class CDLL{
    /*data member*/
    node *head;

    public :

    /*default constructor*/
    CDLL(){
      head=NULL;
    }
    
    ~CDLL(){
        node *ptr=head;
        while(ptr->next!=head){
            head= head->next;
            delete ptr;
            ptr=head;
        }
        delete ptr;
        head=NULL;
        cout<<"All node are deleted";
    }

    void display(){
        if(head==NULL){
            cout<<"No nodes present";
        }
        else{
             node *ptr=head;
             while(ptr->next!=head){
                   cout<<ptr->data<<"\t";
                   ptr=ptr->next;
             }
         cout<<ptr->data<<endl;
        }
    }

    /*to add node if the list is empty or to add at the beggining*/
    void addbeg(int info){
        node *temp=new node(info);

        //if list is empty
        if(head==NULL){
            /*make the next and the prev of new node point to thr new node itself*/
            temp->next = temp->prev= temp;
            /*make the head as new node */
            head=temp;
        }

        /*if list is not empty*/
        else{

            //setting up the prev and next of the new node
            temp->prev=head->prev;
            temp->next=head;

            //updating the last node and the prev of the head to point at the new node
            head->prev->next=temp;
            head->prev=temp;

            /*make the head as new node */
            head=temp;
        }
    }

    /*to add node at the last*/
    void addlast(int info){

        //if no node present
       if(head==NULL){
          addbeg(info);
       }
       
       //if nodes are present in list
       else{

        /*pointer last points to the last node*/
        node *last =head->prev;
        /*creating a new node and initializing it*/
        node *temp= new node(info);

        //setting the prev and next pointers of the new node 
        temp->next=head;
        temp->prev=last;

        //updating head's prev and last node's as new node
        head->prev=temp;
        last->next=temp;
       }
        
    }

    void delbeg(){
        if(head==NULL){
            cout<<"List is empty, can't delete";
        }
        else{

            node * ptr=head;
            head->next->prev=head->prev;
            head->prev->next=head->next;
            head=head->next;
            cout<<"Data deleted is : "<<ptr->data<<endl;
            delete ptr;
        }
        

    }

void dellast(){
    if(head==NULL){
            cout<<"List is empty, can't delete";
    }

    else{

        node * last =head->prev;
        last->prev->next=head;
        head->prev=last->prev;
        cout<<"Data deleted is : "<<last->data<<endl;
        delete last;
        cout<<head->data<<endl;
        cout<<head->prev->data<<endl;
    }
}

void addbef(int info , int val){
    if(head==NULL){
        cout<<"List is empty";
    }
    else{

        node *temp = new node (info);
        node *ptr=head;

        if(head->data==val){
            addbeg(info);
        }

        else{

            while(ptr->next!=head && ptr->next->data!=val){
                ptr= ptr->next;
            }
            
            if(ptr->next!=head){
                temp->next=ptr->next;
                temp->prev=ptr;
                ptr->next=temp;
                ptr->next->prev=temp;
            }
            else{
                cout<<"Data not found"<<endl;
            }
        }
    }
}

void addafter(int info, int val)
{
    if(head==NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        node *temp = new node(info);
        node *ptr= head;

        while(ptr->next!=head && ptr->data!=val){
            ptr=ptr->next;
        }

        if (ptr->next!=head)
        {
            temp->next=ptr->next;
            temp->prev=ptr;
            ptr->next->prev=temp;
            ptr->next=temp;
        }

        else if( ptr->next==head && ptr->data==val)
        {
            temp->prev=ptr;
            temp->next=head;
            head->prev=temp;
            ptr->next=temp;
        }

        else
        {
            cout<<"Data not found!"<<endl;
        }
        
        
    }
}

void delete_(int val)
{
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
    }

    else
    {
        node *ptr=head ,*ptr1;
        while(head->data==val)
        {   
            ptr->next->prev=head->prev;
            head->prev->next=ptr->next;
            head=head->next;
            delete(ptr);
        }
        ptr=head;
        while(ptr->next!=head && ptr->next->data!=val)
        {
            ptr=ptr->next;
        }
       
       if(ptr->next!=head)
       {
         ptr1=ptr->next;
         ptr->next=ptr1->next;
         ptr->next->prev=ptr;
         delete(ptr1);
       }

       else
       {
        cout<<"Data not present"<<endl;
       }
    }

}
 
};

int main(){
    
    //object creation
    CDLL s;

    int c , data ,val;
    char ch = 'y';

    //Menu
    while(ch=='Y'|| ch =='y')
    {
        cout<<"1.Add node at the begining of the list"<<endl;
        cout<<"2.Add node at the end of the list "<<endl;
        cout<<"3.Delete the first node of the list "<<endl;
        cout<<"4.Delete the last node of the list "<<endl;
        cout<<"5. Insert node before a given node "<<endl;
        cout<<"6. Insert node after a given node "<<endl;
        cout<<"7.Delete a given node "<<endl;
        cout<<"8.Display all the nodes of the list "<<endl;
        cout<<"9.Exit"<<endl;

        cout<<"Enter your choice !!"<<endl;
        cin>>c;

        //switch cases
        switch(c)
        {
            case 1 : cout<<"Enter the data to be inserted"<<endl;
                     cin>>data;
                     s.addbeg(data);
                     break;
            
            case 2 : cout<<"Enter the data to be inserted"<<endl;
                     cin>>data;
                     s.addlast(data);
                     break;

            case 3 : s.delbeg();
                     break;
            
            case 4 : s.dellast();
                     break;

            case 5: cout<<"Enter the data to be inserted"<<endl;
                    cin>>data;
                    cout<<"Enter the node before which new node needs to be inserted"<<endl;
                    cin>>val;
                    s.addbef(data,val);
                    break;

            case 6: cout<<"Enter the data to be inserted"<<endl;
                    cin>>data;
                    cout<<"Enter the node after which new node needs to be inserted"<<endl;
                    cin>>val;
                    s.addafter(data,val);
                    break;

            case 7: cout<<"Enter the node to be deleted"<<endl;
                    cin>>data;
                    s.delete_(data);
                    break;

            case 8 : s.display();
                    break;

            case 9: exit(0);
            
            default : cout<<"Invalid choice!!"<<endl;

        }
        
        /*Enter "Y" to continue and "N" to stop*/
        cout<<"Do you want to continue ?? (Y/N)"<<endl;
        cin>>ch;

    }

    return 0;
}
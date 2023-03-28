#include<iostream>
using namespace std;

class node{

    public:
    //data members
    int data ;
    node *prev;
    node *next;

    //default constructor
    node(){
        prev=NULL;
        next=NULL;
    }
    
    //parameterized constructor
    node(int data, node *prev=NULL , node *next =NULL){
        this->data=data;
        this->prev=prev;
        this->next=next;
    }
  
};

class DLL{

    node *head;

    public:

    DLL(){
        head=NULL;
    }

    ~DLL(){
        node * ptr =head;
        while(ptr!=NULL){
            head=head->next;
            delete ptr;
            ptr= head;
        }
        cout<<"All nodes deleted";
    }

    void display(){
        /*1.if list is empty*/
        if(head==NULL){
            cout<<"Linked list is empty!!"<<endl;
        }
        else{
             //2. Make a pointer and point it to head 
              node * ptr = head;

             //3. while traversing till the last node, display data and move to next node
             while(ptr!=NULL){
             cout<<ptr->data<<"\t";
             ptr=ptr->next;
             } 
            cout<<endl;
        }
    }

    void addbeg(int info){

    //1. make new node and put in data
    node *temp = new node(info);

    //2.Make prev as NULL and next as head of the new node
    temp->prev=NULL;
    temp->next=head;

    //3. Make head ref's prev point to new node, {if head points to any node(head!=NULL)}
    if(head!=NULL){
        head->prev= temp;
    }

    //4. Make head point to the new node 
    head= temp;

}

void addlast(int info){
    /*1.create new node and put in data 
       and a traversing pointer initialized with head*/
    node *temp = new node(info);
    node *ptr= head;

    /*2.if no node present , call addbeg()*/
    if(head==NULL){
        addbeg(info);
    }

    /*3.traverse to the last node*/
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    /*4.put ptr in new node's prev and new node in ptr's next */
        ptr->next=temp;
        temp->prev=ptr;
}
 
void addbef(int info , int val){
    /*1.if no node exists*/
    if(head==NULL){
        cout<<"List is empty"<<endl;
    }
    else{
         //2.create new node and a traversing pointer
    node *temp =new node(info);
    node *ptr=head;

    /*3.if head's data matches the given value*/
    if(head->data== val){
        addbeg(info);
    }

    /*4.if data matches elsewhere*/
    else{
        /*traverse to the next node if ptr is not NULL or data doesnt match*/
        while(ptr!=NULL && ptr->data!=val){
            ptr= ptr->next;
        }
        /*5.if ptr is not NULL then the data must have matched*/
        if(ptr!=NULL){
            /*6.put new node in the previous node's next */
            ptr->prev->next=temp;
            temp->prev=ptr->prev;
            /*7.put matched node ptr in new node*/
            temp->next=ptr;
            ptr->prev=temp;
        }
        else {
            /*8.if ptr == NULL then data is not present*/
            cout<<"Data not found"<<endl;
        }
    }
  }
}

void insertafter(int info , int val){
    /*1.if no node exists*/
    if(head==NULL){
        cout<<"List empty";
    }
    else{
        //2.create new node and a traversing pointer
        node * ptr=head;
        node *temp = new node(info);
        while(ptr!=NULL && ptr->data!=val){
            /*traverse to the next node if ptr is not NULL or data doesnt match*/
            ptr=ptr->next;
        }
        /*3.if ptr is not NULL then the data must have matched*/
        if(ptr!=NULL){
           /*4.make next  of prev as new node next*/
           temp->next=ptr->next;  
           /*5.make new node as next of prev*/
           ptr->next=temp;
           /*6.make prev as prev of new node*/
           temp->prev=ptr;
           /*7.if not the last node , make the prev of the prev's next as new node*/
           if(temp->next!=NULL){
              ptr->next->prev=temp;
           }
        }
        /*8.if data doesnt matches*/
        else{
            cout<<"Data not found"<<endl;
        }
    }
}

void delbeg(){
    /*1.if no node exists*/
    if(head==NULL){
        cout<<"List is empty , can't delete"<<endl;
    }

    else{
        //2.store the head or the begining in a  pointer
        node *ptr =head;
        //3.move head to the next position
        head=head->next;
        //4.delete the stored 
        cout<<"Data deleted is : "<<ptr->data<<endl;
        delete ptr;
    }
}

void dellast(){
     /*1.if no node exists*/
    if(head==NULL){
         cout<<"List is empty , can't delete"<<endl;
    }
    else{
        node * ptr= head;
        //2.itterate till the last node while checking
        while(ptr!=NULL){
            //3.if one node exists
            if (ptr->next==NULL){
                head=head->next;
                cout<<"Data deleted is : "<<ptr->data<<endl;
                delete ptr;
                //if data gets deleted make ptr as NULL to stop while loop from itterating further
                ptr=NULL;
            }
            //4.if more than one node exits 
            else if(ptr->next->next==NULL){
               cout<<"Data deleted is : "<<ptr->next->data<<endl;
               delete ptr->next;
               ptr->next=NULL;
               //if data gets deleted make ptr as NULL to stop while loop from itterating further
               ptr=NULL;
            }
            //5.if last or second last node not reached
            else{
                ptr= ptr->next;
            }
        }
    }
}

void count(){
    node * ptr=head;
    int c=0;
    while(ptr!=NULL){
       c++;
       ptr=ptr->next;
    }
    cout<<"Number of nodes are : "<<c<<endl;
}

void delete_(int val){
    /*1.if the list is empty*/
    if(head==NULL){
        cout<<"List is empty , can't delete"<<endl;
    }
    else{
         node * ptr;
         int flag=0;
         /*2. itterate and delete while list exists and data matches with head*/
         while(head!=NULL && head->data==val){
            ptr=head;
            head=head->next;
            delete ptr;
            flag++;
         }
         ptr=head;
         /*3. while the list exists and the data matches */
         while(ptr!=NULL){
            if(ptr->data==val){
                flag++;
                //make next of ptr's prev as ptr's next
                ptr->prev->next=ptr->next;
                //if last is not being deleted 
                if(ptr->next!=NULL){
                    //make prev of ptr's next as prev of ptr
                     ptr->next->prev=ptr->prev;
                }
                
             //make ptr as NULL after deletion to stop while loop from itterating further   
            ptr=NULL;
            }
            //if data didnt matched move forward
            else{
                ptr= ptr->next;
            }
            
         }
         if(flag==0){
        cout<<"Data not found"<<endl;
    }

    }
    
}

};


int main(){
    
    //object creation
    DLL s;

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
        cout<<"8.Count nodes in the list "<<endl;
        cout<<"9.Display all the nodes of the list "<<endl;
        cout<<"10.Exit"<<endl;

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
                    s.insertafter(data,val);
                    break;

            case 7: cout<<"Enter the node to be deleted"<<endl;
                    cin>>data;
                    s.delete_(data);
                    break;

            case 8: s.count();
                    break;

            case 9 : s.display();
                    break;

            case 10: exit(0);
            
            default : cout<<"Invalid choice!!"<<endl;

        }
        
        /*Enter "Y" to continue and "N" to stop*/
        cout<<"Do you want to continue ?? (Y/N)"<<endl;
        cin>>ch;

    }

    return 0;
}

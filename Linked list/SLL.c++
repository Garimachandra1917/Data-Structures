#include<iostream>
using namespace std;

class node {
    public:
    
    //data members
    int data;
    node *next;
  
    // default constructor
    node (){
       next =NULL;
      // data=0;
    }

    //parameterized constructor
    node( int data , node *next= NULL){
        this->data= data;
        this->next= next;
    }

    //destructor
    // ~node(){
        
    // }

};

class SLL
{
    node *head;

    public :
    
    SLL(){
        head= NULL;
    }

    ~SLL(){
        node *ptr;
        ptr= head;
        while (head!=NULL){
            head= head->next;
            delete ptr;
            ptr=head;
            
        }
        cout<<"All nodes deleted"<<endl;
    }
   
   void addbeg(int info){
    node *temp = new node(info);
    temp->next=head;
    head=temp;
   }

   void addlast(int info){
    if(head==NULL){
        addbeg(info);
    }
    else{
    node *temp= new node(info);
    node *ptr= head;
    while (ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
   }
   }

   void delbeg(){
     if(head== NULL){
        cout<<"Linked list is empty";
     }
     else {
        node * ptr=head;
        head= head->next;
        cout<<" Data deleted is : "<<ptr->data<<endl;
        delete ptr;
     }
   }

   void dellast(){
    if(head==NULL){
        cout<<"Linked list is empty";
    }

    else{
        node * ptr =head;
        //itterate till the list is over 
        while(ptr!=NULL){
            //if there exists only one node in the list
            if(ptr->next == NULL){
                head= head->next;
                cout<<"Data deleted is : "<< ptr->data;
                delete ptr;
                //if data gets deleted , to stop the while loop from itterating further make ptr=NULL
                ptr= NULL;
            }
            //if there exists more than one node [being at second last node]
            else if (ptr->next->next==NULL){
                cout<<"Data deleted is : "<<ptr->next->data<<endl;
                delete ptr->next;
                ptr->next= NULL;
                 //if data gets deleted , to stop the while loop from itterating further make ptr=NULL
                ptr =NULL;
            }
            else{
                ptr=ptr->next;
            }
    
        }
    }
   }

   void display(){
    if(head==NULL)
     cout<<"No data present"<<endl;
   else{
     node * ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<"\t";
        ptr= ptr->next;
    }
    cout<< endl;
   }
   }


void insertbef(int info,int val){
    //if no node exists
    if(head== NULL){
        cout<<"Linked list is empty"<<endl;
        return;
    }
   // if node exists
    else {

        //if only one node exists or the data matches with the first node
        if(head->data==val){
            addbeg(info);
        }

        //if data doesnt exist on the first node
        else{

            node *ptr=head;
            /*matching from the second node being at first and so on .. if not matched itterating to
                next node . Also,in this manner cant reach to the last node cause checking the nth node's
                data being at (n-1)th node*/
            while(ptr->next!=NULL && ptr->next->data!=val){
                ptr=ptr->next;
            }

            /*the loop breaks in two conditions 
            1. if data not found..then, ptr->next=NULL(last node reached)
            2. data found , in that case ptr->next can't be NULL hence, inserting new node 
            */

            //inserting new node
            if(ptr->next!=NULL){
                node *temp= new node(info,ptr->next);
                ptr->next=temp;
            }
            
            //node not found
            else{
                cout<<"Data dont match! Cant insert "<<info <<endl;
            }
        }
    }
}


void insertafter(int info, int val){
    //if no node exists
    if(head==NULL){
        cout<<"Linked list is empty";
    }

    //if node exists
    else{
        node *ptr = head;

        /*loop continues to itterate to the next node till
        list exists and the data doest match*/
        while(ptr!=NULL && ptr->data!=val){
            ptr=ptr->next;
        }

        /*loop breaks in two conditions :
         1. list ends, ptr=NULL , data not matched
         2.value at ptr matched , ptr->data= val*/

         // data matched hence, inserting new node
        if(ptr!=NULL){
            node *temp=new node(info,ptr->next);
            ptr->next=temp;
        }

        // data not matched
        else{
             cout<<"Data dont match! Cant insert "<<info <<endl;
        }
    }
}

void count(){
    node *ptr = head;
    int c=0;
    while (ptr!=NULL){
       c++;
       ptr =ptr->next;
    }
    cout<<"The number of nodes are : "<<c <<endl;
}

void search(int val){
    if(head==NULL){
        cout<<"Linked list is empty";
    }
    else{
         node *ptr=head;
         int c=0;
         while(ptr!=NULL){
            c++;
            if(ptr->data==val){
                cout<<"Data found at "<< c << " position"<<endl;
                break;
            }
           else{
            ptr=ptr->next;
           }
         }
         if(ptr==NULL){
            cout<<"Data not found"<<endl;   
         }
    }
}

void delete_ (int val){
        if(head==NULL){
            cout<<"Linked list is empty"<<endl;
        }
        else{
            node *ptr1 ,*ptr2;
            int flag=0;
            while(head!=NULL && head->data==val){
                flag++;
                ptr2=head;
                head=head->next;
                delete ptr2;
            }
            node *ptr= head;
            while(ptr!=NULL && ptr->next!=NULL){
                if(ptr->next->data==val){
                    flag++;
                    ptr1=ptr->next;
                    ptr->next=ptr->next->next;
                    delete ptr1;
                }
                else {
                     ptr=ptr->next;
                }
            }
            if(flag==0){
                cout<<"Data not present "<<endl;
           }
        }
    }
};

int main(){
    
    //object creation
    SLL s;

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
        cout<<"8.Search a node "<<endl;
        cout<<"9.Count nodes in the list "<<endl;
        cout<<"10.Display all the nodes of the list "<<endl;
        cout<<"11.Exit"<<endl;

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
                    s.insertbef(data,val);
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

            case 8: cout<<"Enter the data of the node that needs to be searched"<<endl;
                    cin>>data;
                    s.search(data);
                    break;

            case 9: s.count();
                    break;

            case 10 : s.display();
                    break;

            case 11: exit(0);
            
            default : cout<<"Invalid choice!!"<<endl;

        }
        
        /*Enter "Y" to continue and "N" to stop*/
        cout<<"Do you want to continue ?? (Y/N)"<<endl;
        cin>>ch;

    }

    return 0;
}
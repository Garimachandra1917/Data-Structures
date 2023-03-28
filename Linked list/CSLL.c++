#include<iostream>
using namespace std;

class node{
    
   public:

    //data members
   int data;
   node * next;

   //default constructors
   node(){
    next= NULL;
   }
   
   //parameterized constructors
   node(int data, node * next =NULL){
    this->data = data;
    this->next=next;
   }
};

class CSLL{
  node * head ;

  public:

  CSLL(){
    head=NULL;
  }

  ~CSLL(){
    node *ptr = head;
    while(ptr->next!=head){
        head=head->next;
        delete ptr;
        ptr= head;
    }
    delete ptr;
    head =NULL;
    cout<<"All nodes deleted "<<endl;
  }

  void display(){
    if(head== NULL){
        cout<<"Linked list is empty"<<endl;
    }
    else{
        node * ptr =head;
        while(ptr->next!=head){
            cout<<ptr->data<<"\t";
            ptr=ptr->next;
        }
        cout<<ptr->data;
        cout<<endl;
    }
  }

  void addbeg(int info){
      if(head==NULL){
        node *temp= new node(info);
        head=temp;
        temp->next=head;
      }
      else{
         node *ptr=head;
       while (ptr->next!=head){
        ptr=ptr->next;
       }
       node * temp =new node(info,head);
       head=temp;
       ptr->next=head;
      }  
  }

  void addlast(int info){
  if(head==NULL){
      addbeg(info);
  }
  else{
    node *ptr=head;
    while(ptr->next!=head){
      ptr=ptr->next;
    }
    node * temp = new node(info,head);
    ptr->next=temp;

 }
}

void delbeg(){
  if(head==NULL){
    cout<<"Linked list is empty, Cant delete "<<endl;
  }
  else{
    if(head->next==head){
      node *ptr=head;
      head=NULL;
      cout<<"Data deleted is : "<<ptr->data<<endl;
      delete ptr;
    }
    else{
      node *ptr=head;
      node*ptr1;
      while(ptr->next!=head){
        ptr=ptr->next;
      }
      ptr1=head;
      head=head->next;
      ptr->next=head;
      cout<<"Data deleted is : "<<ptr1->data<<endl;
      delete ptr1;

    }
  
  }
}

void dellast(){
  if(head==NULL){
    cout<<"Linked list empty, cant delete"<<endl;
  }
  else{
    if(head->next==head){
      delbeg();
    }
    else{
      node *ptr=head;
      node *ptr1;
      while(ptr->next->next!=head){
        ptr=ptr->next;
      }
        ptr1= ptr->next;
        ptr->next=head;
        cout<<"Data deleted is : "<<ptr1->data<<endl;
        delete ptr1;
      }
    }
  }

  void count(){
    node *ptr=head;
    int c=0;
    if(head==NULL){
      cout<<"Number of nodes are : "<<c<<endl;
    }
    else{
      while (ptr->next!=head){
      c++;
      ptr=ptr->next;
    }
    c++;
    cout<<"The number of nodes are : "<<c<<endl;
    }
  }

  void search(int val){
    //No data present
    if(head==NULL){
      cout<<"Linked list is empty, Cant find data";
    }
    else{
      node * ptr=head;
      int c=0;
      //if data present from 1st to n-1 node
      while(ptr->next!=head){
        c++;
        if(ptr->data==val){
          cout<<"Data found at "<<c<<" position"<<endl; 
          return;
        }
        ptr=ptr->next;
    
        }
        //if data present at the nth node
         if(ptr->data==val ){
          c++;
          cout<<"Data found at "<<c<<" position"<<endl; 
          return;
        }
        //if data not present 
        
          cout<<"Data not present"<<endl;
      

  }
}

void addbefore(int info,int val){
  if(head==NULL){
    cout<<"Linked list is empty , cant insert"<<endl;
  }
  else{
    if(head->data==val){
      addbeg(info);
    }
    else {
      node *ptr = head;
      while(ptr->next!=head && ptr->next->data!=val){
        ptr=ptr->next;
      }
      if(ptr->next!=head){
        node *temp =new node(info,ptr->next);
        ptr->next=temp;
      }
      else{
        cout<<"Data not found "<<endl;
      }
    }
  }

}

void insertafter(int info,int val){
  //no data present
  if(head== NULL){
    cout<<"Linked list is empty, Cant insert"<<endl;
  }
  //data present
  else{
        node *ptr=head;
        // to itterate from 1st to n-1 node 
        while(ptr->next!=head && ptr->data!=val){
          ptr=ptr->next;
        }
        // if data found between 1st and n-1 node [info inserted]
        if(ptr->data==val){
          node *temp = new node(info,ptr->next);
          ptr->next=temp;
        }
        //if data found at the nth node
        else if(ptr->next->data==val){
          node *temp =new node(info,head);
          ptr->next->next=temp;
        }
        //if data not found
        else{
          cout<<"Data not found"<<endl;
        }
  }
}

void delete_ (int val){
  //if no node is present
  if(head==NULL ){
    cout<<"Linked list is empty ,Cant delete "<<endl;
  }

  //if data is present in linked list
  else{
         
    node *ptr2,*ptr,*ptr1;
    int flag=0; //counter to check is data deleted

    //if data is present at the head node(from 1 to n-1 node)
    while(head->next!=head && head->data==val){
      flag++;
      ptr1=head;

      //to connect the last node to the head node
      while(ptr1->next!=head){
        ptr1=ptr1->next;
      }
      ptr1->next=head->next;
      ptr2=head;
      head=head->next;
      delete ptr2;
    }

    //if data is present at the node (to delete the last node)
    if(head->data==val){
      flag++;
      ptr1=head;
      head= NULL;
      delete ptr1;
    }
    ptr2=head;

    //to delete node other than the head node
    while(ptr2!=NULL && ptr2->next!=head){//while node and the next node exist
      
       if(ptr2->next->data==val){
        flag++;
        ptr=ptr2->next;
        ptr2->next=ptr2->next->next;
        delete ptr;
       }
       //if the ith node doesnt matched with val itterate to the next node
       else{
        ptr2=ptr2->next;
       }
    }

    //if the node doesnt exist or didnt matched
    if(flag==0){
      cout<<"Data not found"<<endl;   
    }
  
  }
}
};

int main(){
    
    //object creation
    CSLL s;

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
                    s.addbefore(data,val);
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
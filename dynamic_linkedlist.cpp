#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

struct node{
int info;
struct node* link;
};

struct node *root=NULL;

void display();
void node_insert(int data);
void del(int pos);

int main()
{
    int ch,x,n,a=0,p;
    while(1)
    {cout<<"\nselect an option"
        <<"\n1.insert into list \n2.display \n3.delete node \n4.exit ";

        cin>>ch;
        switch(ch)
        {
            case 1:{cout<<"enter number of information: "; cin>>n;
                    cout<<"enter the data: "; while(a!=n){cin>>x;node_insert(x);a++;} break;}
            case 2: display(); break;
            case 3: {cout<<"which node do you want to delete: ";cin>>p;del(p-1);break;}
            case 4: exit(1); break;
            default:cout<<"invalid choice\n";
        }
     }
}

void node_insert(int data)
{
    struct node* temp,*ptr=root;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
  if(root==NULL)
  {
    temp->link=NULL;
    root=temp;
    return;
  }
  else{
    while(ptr->link!=NULL)
        ptr=ptr->link;
    ptr->link=temp;
    temp->link=NULL;
    return;
  }
}

void display()
{
  struct node* ptr=root;
  if(root==NULL)
  {
      cout<<"dynamic list is empty\n"; return;
  }
  else {
    while(ptr->link!=NULL)
    {
        cout<<ptr->info<<", ";
        ptr=ptr->link;
    }
    if(ptr->link==NULL)
        cout<<ptr->info;
    return;
  }
}

void del(int pos)
{
    struct node* ptr=root,*q=root;
    int t=0;
    if(root==NULL)
    {
        cout<<"list is empty and therefor can't delete anything\n";
        return;
    }
    else{
        while(t!=pos)
           {
             ptr=ptr->link;
             t++;
           }
           t=0;
        while(t<pos-1)
        {
            q=q->link;t++;
        }
        q->link=ptr->link;
        ptr->link=NULL;
        free(ptr);
        return;
    }
}

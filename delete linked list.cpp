#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};
class linkedlist{
	node*head,*tail;
	public:
		linkedlist();
		void inputdata(int item);
		void deletedata();
		void display();
};
linkedlist::linkedlist()
{
	head=tail=NULL;
}
void linkedlist::inputdata(int item)
{
	node*newnode=new node;
	newnode->data=item;
	newnode->next=NULL;
	
	if(head==NULL&& tail==NULL)
	{
		head=newnode;
		tail=newnode;
	}
	else
	{
		tail->next=newnode;
		tail=newnode;
	}
}
void linkedlist::display()
{
	node*tempnode=head;
	while(tempnode!=NULL)
	{
		cout<<tempnode->data<<"<==>";
		tempnode=tempnode->next;
		}
}

void linkedlist::deletedata()
{
	int pos;
	cout<<"enter position where to delete ";
	cin>>pos;
	node *currnode,*prevnode;
	currnode=head;
	for(int i=1;i<pos;i++)
	{
		prevnode=currnode;
		currnode=currnode->next;
	}
	
	if(currnode==head)
	{
		head=head->next;
		
	}
	else if(currnode==tail)
	{
		prevnode->next=NULL;
		tail=prevnode;
	}
	else
	{
	    prevnode->next=currnode->next;	
	}
}

int main()
{
	linkedlist usiu;
	int i,item,n;
	cout<<"how many values";
	cin>>n;
	cout<<"enter values item";
	for(i=0;i<n;i++)
	{
		cin>>item;
		usiu.inputdata(item);
	}
	cout<<"original items are:";
	usiu.display();
	//deleting
	usiu.deletedata();
	cout<<"Remaining data is";
	usiu.display();
}

#include "0413354_Link_List.h"
#include <iostream>
using namespace std;

ostream &operator<<(ostream &output, const Link_List &list)
{
    Int_Node *ptr = new Int_Node;
    ptr = list.head ;
	for(int i = 0; i< list.getSize();i++)
	{
		output << ptr -> value << " " ;
        ptr = ptr -> next ;
	}

	return output;
}

istream &operator>>(istream &input, Link_List &list)
{
	int n;
	Int_Node *ptr = new Int_Node;

	list.a_size();
	input>>n;
	ptr -> value = n;
	if(list.size > 1)
    {
        ptr -> pre = list.tail;
        list.tail -> next = ptr;
        list.tail = ptr;
        return input;
    }
    else
    {
        list.tail = ptr;
        list.head =ptr;
        ptr -> pre = NULL;
        ptr -> next =NULL;
        return input;
    }


}

Link_List::Link_List()
{
	size=0;
	head = NULL;
	tail = NULL;
}

Link_List::Link_List(const Link_List &list)
{

    size = 0 ;
	if(list.getSize()!=0)
    {
        for(int i= 0;i < list.getSize(); i++)
        {
            (*this).insert_node(list[i]);
        }
    }
    else
    {
        head = NULL;
        tail = NULL;
    }




}

Link_List::~Link_List()
{


    Int_Node *current=head;
    while(current!=NULL)
    {
        Int_Node *temp=current->next;
        delete current;
        current=temp;
    }

}

int &Link_List::operator[](int index)
{
    Int_Node *ptr = new Int_Node;
	ptr = head;
	for(int i=0;i < index;i++)
	{
		ptr = ptr -> next;
	}
	return ptr -> value;
}

int Link_List::operator[](int index) const
{
    Int_Node *ptr = new Int_Node;
	ptr = head;
	for(int i=0;i < index;i++)
	{
		ptr = ptr -> next;
	}
	return ptr -> value;
}


int Link_List::getSize() const
{
	return size;
}

int Link_List::a_size()
{
	size = size + 1;
}



const Link_List &Link_List::operator=(const Link_List &list)
{
    size = 0 ;
    if(list.getSize()!=0)
    {
        for(int i= 0;i < list.getSize(); i++)
        {
            (*this).insert_node(list[i]);

        }

    }
    else
    {
        head = NULL;
        tail = NULL;
    }


}

bool Link_List::operator==(const Link_List &list) const
{
	for(int i=0; i<size ;i++)
	{
		if((*this)[i]!=list[i]) return false;
	}

	return true;
}

bool Link_List::insert_node(int value)
{
	int n=value;
	Int_Node *ptr = new Int_Node;
	size=size+1;
	if(size != 1)
    {
        ptr -> value = n;
        ptr -> pre = tail;
        tail -> next = ptr;
        tail = ptr;
        ptr -> next = NULL;
        return true;
    }
    else
    {
        ptr -> value = value;
        ptr -> pre = NULL;
        ptr -> next = NULL;
        head = ptr;
        tail = ptr;

    }

}

bool Link_List::delete_node()
{
    if(size!=1&&size!=0)
    {
        tail = tail -> pre;
        tail -> next = NULL;
        size-=1;
        return true;

    }
    else if(size==1)
    {
        tail = NULL;
        head = NULL;
        return true;
    }
    else
    {
        return false;
    }
}

bool Link_List::insert_node(int index, int value)
{
    Int_Node *ptr ;
	ptr = head;
	Int_Node *ptr1 = new Int_Node;

	for(int i=0;i<index;i++)
	{
		ptr = ptr -> next;
	}
	size=size+1;
	ptr1 -> value = value;
	(ptr -> pre) -> next = ptr1;
	ptr1 -> pre = ptr -> pre;
	ptr1 -> next = ptr;
	ptr -> pre = ptr1 ;
	return true;
}

bool Link_List::delete_node(int index)
{
    Int_Node *cur = new Int_Node;

	cur = head;
	for(int i=0;i<index;i++)
	{
		cur = cur -> next;
	}
	(cur -> pre) -> next = cur -> next;
	(cur -> next) -> pre = cur ->pre;
	cur -> next = NULL;
	cur -> pre =NULL;
	delete cur;
    size--;
    return true;
}



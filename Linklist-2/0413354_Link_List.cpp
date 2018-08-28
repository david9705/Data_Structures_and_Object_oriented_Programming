#include "0413354_Link_List.h"
#include <iostream>
using namespace std;



template <class T>
ostream &operator<<(ostream &output, const Link_List<T> &li)
{
    Int_Node<T> *ptr = new Int_Node<T>;
    ptr = li.head ;
	for(T i = 0; i< li.getSize();i++)
	{
		output << ptr -> value << " " ;
        ptr = ptr -> next ;
	}

	return output;
}

template <class T>
istream &operator>>(istream &input, Link_List<T> &li)
{
	T n;
	Int_Node<T> *ptr = new Int_Node<T>;

	li.a_size();
	input>>n;
	ptr -> value = n;
	if(li.size > 1)
    {
        ptr -> pre = li.tail;
        li.tail -> next = ptr;
        li.tail = ptr;
        return input;
    }
    else
    {
        li.tail = ptr;
        li.head =ptr;
        ptr -> pre = NULL;
        ptr -> next =NULL;
        return input;
    }


}

template <class T>
Link_List<T>::Link_List()
{
	size=0;
	head = NULL;
	tail = NULL;
}

template <class T>
Link_List<T>::Link_List(const Link_List<T> &list)
{

    size = 0 ;
	if(list.getSize()!=0)
    {
        for(T i= 0;i < list.getSize(); i++)
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

template <class T>
Link_List<T>::~Link_List()
{


    Int_Node<T> *current=head;
    while(current!=NULL)
    {
        Int_Node<T> *temp=current->next;
        delete current;
        current=temp;
    }

}

template <class T>
T &Link_List<T>::operator[](T index)
{
    Int_Node<T> *ptr = new Int_Node<T>;
	ptr = head;
	for(T i=0;i < index;i++)
	{
		ptr = ptr -> next;
	}
	return ptr -> value;

}
/*int &Link_List::operator[](int index)
{
    Int_Node *ptr = new Int_Node;
	ptr = head;
	for(int i=0;i < index;i++)
	{
		ptr = ptr -> next;
	}
	return ptr -> value;
}*/

template <class T>
T Link_List<T>::operator[](T index) const
{
    Int_Node<T> *ptr = new Int_Node<T>;
	ptr = head;
	for(T i=0;i < index;i++)
	{
		ptr = ptr -> next;
	}
	return ptr -> value;
}

template <class T>
T Link_List<T>::getSize() const
{
	return size;
}

template <class T>
T Link_List<T>::a_size()
{
	size = size + 1;
}


template <class T>
const Link_List<T> &Link_List<T>::operator=(const Link_List<T> &list)
{
    size = 0 ;
    if(list.getSize()!=0)
    {
        for(T i= 0;i < list.getSize(); i++)
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

template <class T>
bool Link_List<T>::operator==(const Link_List<T> &list) const
{
	for(T i=0; i<size ;i++)
	{
		if((*this)[i]!=list[i]) return false;
	}

	return true;
}

template <class T>
bool Link_List<T>::insert_node(T value)
{
	int n=value;
	Int_Node<T> *ptr = new Int_Node<T>;
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

template <class T>
bool Link_List<T>::delete_node()
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

template <class T>
bool Link_List<T>::insert_node(T index, T value)
{
    Int_Node<T> *ptr ;
	ptr = head;
	Int_Node<T> *ptr1 = new Int_Node<T>;

	for(T i=0;i<index;i++)
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

template <class T>
bool Link_List<T>::delete_node(T index)
{
    Int_Node<T> *cur = new Int_Node<T>;

	cur = head;
	for(T i=0;i<index;i++)
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


template class Link_List<int>;
template class Link_List<float>;
template class Link_List<char>;

template ostream &operator<<(ostream &output, const Link_List<int> &);
template ostream &operator<<(ostream &output, const Link_List<float> &);
template ostream &operator<<(ostream &output, const Link_List<char> &);


template istream &operator>>(istream &input, Link_List<int> &);
template istream &operator>>(istream &input, Link_List<float> &);
template istream &operator>>(istream &input, Link_List<char> &);

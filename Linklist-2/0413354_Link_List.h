#ifndef LINK_LIST
#define LINK_LIST

#include <iostream>
using namespace std;

template <class T>
struct Int_Node
{
	T value;
	Int_Node<T> *pre, *next;
};

template <class T>
class Link_List
{
    template <class U>
	friend ostream &operator<<(ostream &, const Link_List<U> &);  	// print all integers in the list
	template <class U>
	friend istream &operator>>(istream &, Link_List<U> &);			// input a value at the back of the list, like insert_node(val);

public:
	Link_List();										// default constructor //done
	Link_List(const Link_List &);						// copy constructor //done
	~Link_List();										//done
	T getSize() const;								//done
	T a_size();										//done



	const Link_List &operator=(const Link_List &);		// assignment operator
	bool operator==(const Link_List &) const;			// equality operator
	bool operator!=(const Link_List &right) const		// inequality operator
	{
		return !(*this == right);
	}

    T &operator[](T index);
	//int &operator[](int index);							// subscript operator for non-const objects//doen
	T operator[](T index) const;					// subscript operator for const objects//done

	bool insert_node(T value);						// insert an integer at the back of link list
	bool delete_node();									// delete the last node
	bool insert_node(T index, T value);				// insert an integer after the i_th position
	bool delete_node(T index);						// delete the i_th node

private:
    T size;
	Int_Node<T> *head, *tail;								// pointer to the first and the last element of Link_List
};


#endif // LINK_LIST

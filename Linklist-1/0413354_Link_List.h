#ifndef LINK_LIST
#define LINK_LIST

#include <iostream>
using namespace std;

struct Int_Node
{
	int value;
	Int_Node *pre, *next;
};

class Link_List
{
	friend ostream &operator<<(ostream &, const Link_List &);  	// print all integers in the list
	friend istream &operator>>(istream &, Link_List &);			// input a value at the back of the list, like insert_node(val);
	
public:
	Link_List();										// default constructor //done
	Link_List(const Link_List &);						// copy constructor //done
	~Link_List();										//done
	int getSize() const;								//done
	int a_size();										//done	
		
	
	const Link_List &operator=(const Link_List &);		// assignment operator
	bool operator==(const Link_List &) const;			// equality operator
	bool operator!=(const Link_List &right) const		// inequality operator
	{
		return !(*this == right);
	}

	int &operator[](int index);							// subscript operator for non-const objects//doen
	int operator[](int index) const;					// subscript operator for const objects//done

	bool insert_node(int value);						// insert an integer at the back of link list
	bool delete_node();									// delete the last node
	bool insert_node(int index, int value);				// insert an integer after the i_th position
	bool delete_node(int index);						// delete the i_th node

private:
	int size;
	Int_Node *head, *tail;								// pointer to the first and the last element of Link_List
};


#endif // LINK_LIST

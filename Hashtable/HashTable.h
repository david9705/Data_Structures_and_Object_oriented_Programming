#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <iostream>
#include <string.h>


#define MAX_PNUM 10
#define HASH_TABLE_SIZE 1031

using namespace std;
/***********************************
* PatientDetail is a struct to put personal information(gender height weight)
* Entry is a struct to be used in HashTable, it's like a linkedlist
*
*
*
***********************************/




typedef struct _Patient_Data{
    string gender;
    int height;
    int weight;

} PatientDetail;

typedef struct Entry{
    string pNum;
    PatientDetail *detail;
    Entry *pNext;
} Entry;


//Hash Table Class
class HashTable
{
    public:
        /******hash table intialization ******/
        HashTable();

        /******add item to hash table ******/
        int addItem(string key, string gender, int height, int weight);

        /******operator overloading ******/
        HashTable operator [](string key);


        string getGender();

        int getHeight();

        int getWeight();

        /******to compute the hashvalue ******/
        int hashFunc(string str);
    private:
        /******hash table ******/
        Entry *pHead, *HT[HASH_TABLE_SIZE];

        /******the hash table present index ******/
        int nIndex = 0;

};

#endif // _HASHTABLE_H



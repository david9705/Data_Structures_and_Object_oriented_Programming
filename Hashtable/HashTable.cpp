#include "HashTable.h"




HashTable::HashTable()
{
    int i = 0;

    //initialize Hash Table
    pHead = new Entry[HASH_TABLE_SIZE];
    for(i = 0; i < HASH_TABLE_SIZE; i++)
    {
        HT[i] = &pHead[i];
        HT[i]->pNext = NULL;
    }
    i = 0;


}

int HashTable::addItem(string key, string gender, int height, int weight)
{
    // to keep the item added
    Entry *e;
    e = new Entry;
    e->pNum = key;
    e->detail = new PatientDetail;
    e->detail->gender = gender;
    e->detail->height = height;
    e->detail->weight = weight;

    //get hashvalue to be a hash table index
    int hashindex = hashFunc(key);

    //if hashindex is overlap, it will find another space to keep data
    Entry *tE = (HT[0]+hashindex);
    while( tE->pNext != 0)
    {
        tE = tE->pNext;
    }
    e->pNext = tE->pNext;
    tE->pNext = e;

    return 0;
}

string HashTable::getGender()
{
    Entry *nE = HT[nIndex]->pNext;
    string gen = nE->detail->gender;
    return gen;
}

int HashTable::getHeight()
{
    Entry *nE = HT[nIndex]->pNext;
    int height = nE->detail->height;

    return height;
}

int HashTable::getWeight()
{
    Entry *nE = HT[nIndex]->pNext;
    int weight = nE->detail->weight;

    return weight;
}

HashTable HashTable::operator [](string key)
{
    int hashindex = hashFunc(key);
    nIndex = hashindex;
    Entry *pH = (HT[0]+hashindex)->pNext;

    while (pH != NULL) {
        if((key.compare(pH->pNum))== 0)
            return *this;
        pH = pH->pNext;
    }

    return *this;
}

int HashTable::hashFunc(string str)
{
    //it's a hashdfunction to compute hash value
    unsigned int seed = 131;
    // 31 131 1313 13131 131313 etc..
    unsigned int hashv = 0;
    int len = str.length();
    int i = 0;
    while (i<len) {
        hashv = hashv * seed + (str[i]);
        i++;
    }
    return hashv%HASH_TABLE_SIZE;

}

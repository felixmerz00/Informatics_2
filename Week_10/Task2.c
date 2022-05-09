#include <stdio.h>
#define m 10

struct HTElement
{
    int value;
    int status; //occupied = 0; empty = -1; deleted = -2
};

int set_status(struct HTElement* p, int status);
void init(struct HTElement A[]);
int hash(int k, int i);
void insert(struct HTElement A[], int key);
void printHashTable(struct HTElement A[]);

int main()
{
    int keys[] = {5, 19, 27, 15, 30, 34, 26, 12, 21};
    struct HTElement HT[m];
    init(HT);
    printHashTable(HT);
    for(int i = 0; i < 9; i++){
        insert(HT, keys[i]);
    }
    printHashTable(HT);
    return 0;
}

//checks validity of a status and sets the status of a given HT
//success --> return 1, nvalid value --> return 0
int set_status(struct HTElement* p, int status)
{
    if(status == -1 || status == 0 || status == 1){
        p->status = status;
        return 1;
    }
    return 0;
}

//fill all slots of the hash table A with the value 0
void init(struct HTElement A[])
{
    for(int i = 0; i < m; i++){
        struct HTElement p = {0, -1};
        A[i] = p;
    }
}

//receives the key k and the probe number i and returns the hashed key
int hash(int k, int i)
{
    int h1 = (k%m)+1;
    int h2 = ((m-1)-(k%(m-1)));
    return (h1 + i*h2)%m;
}

/*
!!!
implement a counter to make sure, realize if the hash table is full already: if(hash_table_size < counter){terminate search for empty space}

*/
void insert(struct HTElement A[], int key)
{
    int i = 0;
    int index;
    do{
        index = hash(key, i);
        i++;
    }while(A[index].status == 0);
    A[index].status = 0;
    A[index].value = key;
}

void printHashTable(struct HTElement A[])
{
    for(int i = 0; i < m; i++){
        if(A[i].status == 0){
            printf("i: %d, key: %d\n", i, A[i].value);
        }
    }
}
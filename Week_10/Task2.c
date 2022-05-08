

struct HTElement
{
    int value;
    //occupied = 1; empty = 0; deleted = -1
    int status;
};

int set_status(struct HTElement* p, int status);

int main()
{
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
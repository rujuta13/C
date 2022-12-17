 node * nn;
    //allocate new memory
    nn = (node *)malloc(sizeof(node *));
    //if memory not allocated
    if(!nn) 
        return;
    //if memory allocated
    nn -> data = key;
    nn -> next = NULL;

    node * p;
    p = *L;
    while(p -> next){
        p = p ->next;
    }
    p -> next = nn;    
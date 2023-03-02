void display(node *L){
    node * pn;
    pn = L;
	
    //printf("[");
    while(pn != NULL){
        printf(" %d", pn -> data);
        pn = pn -> next;
    }
    //printf(" ]\n");

}

void insert(node  **head, int key){
    	node * nn;
    	nn = (node *)malloc(sizeof(node *));
    	if(!nn) 
        	return;
    
    	nn -> data = key;
	nn -> next = (*head);
	(*head) = nn;
}

void append(node **L, int key){
    node * nn;
    nn = (node *)malloc(sizeof(node *));
    if(!nn) //if nn is NULL then return
        return;
    
    nn -> data = key;
    nn -> next = NULL;

    node * pn;
    pn = *L; 

    if(pn == NULL){
        *L = nn;
        return;
    }

    while((pn -> next) != 0)
        pn = pn -> next;

    pn -> next = nn;    
}

void init(node **head){
	(*head) = (node *) malloc(sizeof(node *));
	if((*head) == NULL)
		return;

	(*head) = NULL;
}

node * add(node *L1, node *L2){
	node *n3;
	init(&n3);

	node *p1, *p2;
	p1 = L1;
	p2 = L2;
	
	int sum, carry = 0;
	while(p1 != NULL && p2 != NULL){
		sum = p1 -> data + p2 -> data + carry;
		carry = sum / 10;
		
		insert(&n3, sum % 10);

		p1 = p1 ->next;
		p2 = p2 ->next;
	}

	return n3;
}
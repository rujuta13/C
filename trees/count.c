//returns the count of leaf nodes in the BST

int countLeaf(aBST t){
    queue q;
    initQueue(&q);
    int count = 0;

    //tree empty
    if(t.A[0] == INT_MIN)
        return 0;

    q.A[q.rear++] = 1;

    while (q.front < q.rear) {
        
        printf("seg test 1\n");
        int curr = dequeue(&q);
        printf("seg test 2\n");
        // Check if the node is a leaf node
        
        printf("dequeued %d\n", curr);
        printf("%d\n", t.A[curr]);
        printf("seg test\n");
        if (t.A[curr] != INT_MIN){
            if(t.A[2*curr + 1] == INT_MIN && t.A[2*curr+2] == INT_MIN) {
                printf("%d ", t.A[curr]);
                count++;
            }
        }
        // Enqueue children of the node
        if (t.A[2*curr + 1] != INT_MIN) {
            enqueue(&q, 2*curr+1);
        }
        if (t.A[2*curr + 2] != INT_MIN) {
            enqueue(&q, 2*curr+2);
        }
        printf("seg test 3\n");
    }
    return count;
}
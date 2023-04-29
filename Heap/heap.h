#define MAX 100
typedef struct heap{
    int *A;
    int s;
    int last;
}heap;

void initHeap(heap *h);
void insert(heap *h, int key);
void remove(heap *h);
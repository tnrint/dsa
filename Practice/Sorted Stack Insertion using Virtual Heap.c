#include <stdio.h>
#include <stdlib.h>

#define VHSIZE 50

typedef struct {
    int data;
} Element;

typedef struct {
    Element elem;
    int next;
} Node;

typedef struct {
    Node VHNode[VHSIZE];
    int avail;
} VHeap;

typedef int Stack;  // index of top element


/*************************************/
/*           YOUR TASKS              */
/*************************************/
// --- CB functions --- //
void initVHeap(VHeap *VH);
int allocSpace(VHeap *VH);
void freeSpace(VHeap *VH, int idx);

// --- Stack functions ---
void initStack(Stack *S);
void insertSorted(VHeap *VH, Stack *S, int data);
void printStack(VHeap VH, Stack S);

// --- Main program ---
int main() {
    VHeap VH;
    Stack S;
    int N, val;

    initVHeap(&VH);
    initStack(&S);

    printf("Enter size: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        insertSorted(&VH, &S, val);
    }

    printStack(VH, S);

    return 0;
}
// typedef struct {
//     int data;
// } Element;

// typedef struct {
//     Element elem;
//     int next;
// } Node;

// typedef struct {
//     Node VHNode[VHSIZE];
//     int avail;
// } VHeap;
void initVHeap(VHeap *VH) {
    // Implementation here...
  VH->avail = 0;
  int x;
  for(x = 0; x < VHSIZE-1; x++){
    VH->VHNode[x].next = x+1;
  }
  VH->VHNode[x].next = -1;
}

int allocSpace(VHeap *VH) {
    // Implementation here...
  int idx = VH->avail;
  if(idx != -1){
    VH->avail = VH->VHNode[idx].next;
  }
  return idx;
}

void freeSpace(VHeap *VH, int idx) {
    // Implementation here... 
  VH->VHNode[idx].next = VH->avail;
  VH->avail = idx;
}

// --- Stack functions ---
void initStack(Stack *S) {
    // Implementation here...
  *S = 0;
}

void insertSorted(VHeap *VH, Stack *S, int data) {
    // Implementation here...
  if(VH->avail != -1){
    int temp = allocSpace(VH);
    VH->VHNode[temp].elem.data = data;
    int *trav = S;

    for(;*trav != -1 && VH->VHNode[*trav].elem.data < data; trav = &VH->VHNode[*trav].next){}

    VH->VHNode[temp].next = *trav;
    *trav = temp;
  }
}

void printStack(VHeap VH, Stack S) {
    // Implementation here...
  printf("Sorted Stack: ");
  int *trav = S;
  for(; *trav != -1; trav = &VH.VHNode[*trav].next){
    printf("%d ", VH.VHNode[*trav].elem.data);
  }
}
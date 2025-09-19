#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 5

typedef struct
{
  char fname[30];
  char lname[30];
} Name;

typedef struct
{
  Name elems[MAX];
  int front;
  int rear;
} NQueue;

/**************************************/
/*           YOUR TASKS               */
/**************************************/
Name *filterNames(NQueue *nq, char *filterString);
bool insertSorted(NQueue *nq, Name n);

/**************************************/
/*         HELPER FUNCTIONS           */
/**************************************/
void initNQueue(NQueue *nq);
bool isEmpty(NQueue nq);
bool isFull(NQueue nq);
void displayQueue(NQueue nq);
bool enqueue(NQueue *nq, Name n);
bool dequeue(NQueue *nq);
Name front(NQueue nq);


int main() {
    NQueue Q;
    int size;

    initNQueue(&Q);

    printf("Enter size: ");
    scanf("%d", &size);

    for(int i = 0; i < size; i++) {
        Name temp;
        printf("Enter first name: ");
        scanf(" %[^\n]", temp.fname);

        printf("Enter last name: ");
        scanf(" %[^\n]", temp.lname);
        printf("\n");

        if(!insertSorted(&Q, temp)) {
            printf("Queue is FULL!\n\n");
        }
    }

    printf("QUEUE:\n");
    displayQueue(Q);

    char remove[100];
    printf("\nEnter last name to filter from queue: ");
    scanf(" %[^\n]", remove);

    Name *f = filterNames(&Q, remove);

    printf("\nQUEUE:\n");
    displayQueue(Q);

    printf("\nFILTERED NAMES:\n");
    for(int i = 0; strcmp(f[i].lname, "END") != 0; i++) {
        printf("%s %s\n", f[i].fname, f[i].lname);
    }

    return 0;
}

/*Removes the names that matches the filterString to the lastname.
  Returns the removed names. Use the concept of adding a sentinel
  at the end indicating the last item in list as empty strings for
  fname and lname. If there are no names that will match then the
  function should return the sentinel.*/
Name *filterNames(NQueue *nq, char *filterString)
{
  // Implementation here...
  Name *temp = malloc(sizeof(Name) * MAX + 1);
  int count = 0;
  int rear_size = nq->rear;
  int front_size = nq->front;
  int stop = (rear_size + 1) % MAX;

  NQueue que;
  initNQueue(&que);
  while(nq->front != stop){
    Name current = front(*nq);
    dequeue(nq);
    if(strcmp(current.lname, filterString) == 0){
      temp[count++] = current;
    } else {
      enqueue(&que, current);
    }
  }
  *nq = que;
  strcpy(temp[count].fname, "END");
  strcpy(temp[count].lname, "END");

  return temp;
}

/*Insert soreted base on lastname. Rember to use the property
  of the queue but without using the functions (enqueue, dequeue, front)*/
bool insertSorted(NQueue *nq, Name n)
{
    if (isFull(*nq))
        return false;

    int size = (nq->rear - nq->front + 1 + MAX) % MAX;

    int pos = 0;
    for (int i = 0; i < size; i++) {
      int idx = (nq->front + i) % MAX;
      int cmp = strcmp(n.lname, nq->elems[idx].lname);
        if (cmp < 0 || (cmp == 0 && strcmp(n.fname, nq->elems[idx].fname) > 0)) {
          break;
        }
        pos++;
    }

    for (int i = size; i > pos; i--) {
        int from = (nq->front + i - 1) % MAX;
        int to   = (nq->front + i) % MAX;
        nq->elems[to] = nq->elems[from];
    }

    int insertIndex = (nq->front + pos) % MAX;
    nq->elems[insertIndex] = n;

    nq->rear = (nq->rear + 1) % MAX;

    return true;
}



/* Helper Functions */

void initNQueue(NQueue *nq)
{
  nq->front = 1;
  nq->rear = 0;
}

bool isEmpty(NQueue nq)
{
  return (nq.rear + 1) % MAX == nq.front ? true : false;
}

bool isFull(NQueue nq)
{
  return (nq.rear + 2) % MAX == nq.front ? true : false;
}

void displayQueue(NQueue nq)
{
  int stop = (nq.rear + 1) % MAX;

  while (nq.front != stop)
  {
    Name data = front(nq);
    printf("%s %s\n", data.fname, data.lname);

    dequeue(&nq);
    enqueue(&nq, data);
  }
}

bool enqueue(NQueue *nq, Name n)
{
  bool status = false;

  if (!isFull(*nq))
  {
    nq->rear = (nq->rear + 1) % MAX;
    nq->elems[nq->rear] = n;
    status = true;
  }

  return status;
}

bool dequeue(NQueue *nq)
{
  bool status = false;

  if (!isEmpty(*nq))
  {
    nq->front = (nq->front + 1) % MAX;
    status = true;
  }

  return status;
}

Name front(NQueue nq)
{
  Name def = {"XXXX", "XXXXX"};

  return (isEmpty(nq)) ? def : nq.elems[nq.front];
}
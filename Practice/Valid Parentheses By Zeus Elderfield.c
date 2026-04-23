#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 50

typedef struct {
    char elem[MAX];
    int top; //index of stack top
} Stack;

/*************************************/
/*         HELPER FUNCTIONS          */
/*************************************/
void init(Stack *s);
bool isEmpty(Stack s);
bool isFull(Stack s);
char top(Stack s);
void pop(Stack *s);
void push(Stack *s, char data);


/*************************************/
/*            YOUR TASK              */
/*************************************/
bool isValidParentheses (char parentheses[]);

int main() {
    char parentheses[256];

    printf("Enter parentheses: ");
    scanf("%s", parentheses);

    printf("The parentheses is %s.", 
        (isValidParentheses(parentheses)) ? "VALID" : "NOT VALID");

    return 0;
}
// typedef struct {
//     char elem[MAX];
//     int top; //index of stack top
// } Stack;

bool isValidParentheses (char parentheses[]) {
    // Implementation here...
  Stack s;
  init(&s);

  for(int i = 0; parentheses[i] != '\0'; i++){
    char current = parentheses[i];

    if(!isEmpty(s) && top(s) == current){
      pop(&s);
    } else {
      push(&s, current);
    }
  }
  if(s.top != -1){
    return false;
  }
  return true;
}



/*************************************/
/*         HELPER FUNCTIONS          */
/*************************************/
void init(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack s) {
    return (s.top == -1) ? true : false; 
}

bool isFull(Stack s) {
    return (s.top == MAX - 1) ? true : false;
}

char top(Stack s) {
    char d = '\0';
    return (!isEmpty(s)) ? s.elem[s.top] : d;
}

void pop(Stack *s) {
    if(!isEmpty(*s)) {
        s->top--;
    }
}

void push(Stack *s, char data) {
    if(!isFull(*s)) {
        s->elem[++s->top] = data; 
    }
}
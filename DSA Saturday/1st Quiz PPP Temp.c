void deleteVisited(STACK *S){
    STACK temp = NULL;

    while(S->top != -1){
        if(S->elems[S->top].sfw == 0){
            temp->elems[++temp->top] = S->elems[--S->top];
        } else {
            --S->top;
        }
    }

    while(temp->top != -1){
        S->elems[++S->top] = temp->elems[temp->top--];
    }
}
void deleteVisited(STACK *S){
    STACK temp = NULL;                                          //create a temporary stack to hold the unvisited elements

    while(S->top != -1){                                        //loop until the original stack is empty
        if(S->elems[S->top].sfw == 0){                          //check if the top element of the original stack is unvisited
            temp->elems[++temp->top] = S->elems[--S->top];      //if unvisited, push it onto the temporary stack and pop it from the original stack
        } else {
            --S->top;                                           //if visited, simply pop it from the original stack without pushing it onto the temporary stack
        }
    }

    while(temp->top != -1){                                     //loop until the temporary stack is empty
        S->elems[++S->top] = temp->elems[temp->top--];          //push the unvisited elements back onto the original stack
    }
}
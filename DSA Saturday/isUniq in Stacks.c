void isUniq(STACK *S, int data){                                                   //this function checks if the given data is unique in the stack, if it is unique, it pushes it onto the stack, otherwise it does nothing
    STACK temp = NULL;                                                             //create a temporary stack to hold the elements while checking for uniqueness
    int x = 0;                                                                     //initialize a variable to store the current element being checked from the stack
    int found = 0;                                                                 //initialize a variable to keep track of whether the data is found in the stack
    while(S->top != -1){                                                           //loop until the original stack is empty
        x = S->elems[S->top--].data;                                               //pop the top element from the original stack and store it in x for comparison
        if(data == x){                                                             //if the current element matches the data being checked, set found to 1 to indicate that the data is not unique
            found = 1;                                                             //set found to 1 to indicate that the data is not unique
        }
        temp->elems[++temp->top] = x;                                              //push the current element onto the temporary stack to preserve the original stack's order while checking for uniqueness
    }

    while(temp->top != -1){
        S->elems[++S->top] = temp->elems[temp->top--];                             //push the elements back onto the original stack from the temporary stack to restore the original stack's order after checking for uniqueness
    }

    if(found == 0){                                                                //if the data is unique (not found in the stack), push it onto the original stack
        S->elems[++S->top] = data;                                                 //push the unique data onto the original stack
    }
}
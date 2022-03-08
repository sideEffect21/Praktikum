#include "header.h"

 
bool solve_Uva(Stack *stack, int train, int *out)

{


    int now=1;
    int i;
    
    for (i=0;i<train;i++)
    {
        if(stack_isEmpty(stack) && now<=train)
        {
            stack_push(stack, now);
            now++;
        }
        while(stack_top(stack) != out[i])
        {
            stack_push(stack, now);
            now++;
            if(now>train)
                return false;
        }
        stack_pop(stack);
    }
    return true;
}


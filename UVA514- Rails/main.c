#include"header.h"

int main()
{
    int train;
    int i;
    
    scanf("%d", &train);
    while(train != 0){ ///input jumlah KA selama tidak 0

        Stack myStack;
        stack_init(&myStack);
        int out[1001];
        for(i=0; i<train;i++) ////input kasus urutan KA selama tidak 0
        {	 
        	
            scanf("%d", &out[i]); ////urutan KA disimpan di array
            if(out[0] == 0)
                break;
        }
        while(out[0] != 0)
        {
            if(solve_Uva(&myStack, train, out))  //cek urutan KA
                printf("yes\n");
            else
                printf("no\n");
			
            for (i=0; i<train;i++)
        {
            scanf("%d", &out[i]);
            if(out[0] == 0)
                break;
        }
        }
        scanf("%d", &train);
    }
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "halfgetlist.h"

int main(int argc, char * argv[])
{
    HGL * S = list_create(8);
    if(S == NULL)
    {
        printf("the memory assinging for S failed->the list createion failed!\n");
        return -1;
    }
    list_en(S);
    list_halfGET(S, 9, S->head, S->post-1);
    return 0;
}

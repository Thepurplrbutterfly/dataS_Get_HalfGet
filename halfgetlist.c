#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "halfgetlist.h"

/*顺序表创建函数*/
HGL * list_create(int value)
{
    HGL * S = (HGL *)malloc(sizeof(HGL));
    if(S == NULL)
    {
        printf("the memory assinging for S failed->the list createion failed!\n");
        return NULL;
    }
    S->maxlen = value;
    S->data = (data_t *)malloc(S->maxlen);
    if(S->data == NULL)
    {
        printf("the memory assigning for array failed->the list creation failed!\n");
        return NULL;
    }
    memset(S->data, 0, S->maxlen);
    S->head = 0;
    S->post = 0;
    S->mid = 0;
    return S;
}

/*顺序表中元素插入函数*/
int  list_en(HGL * S)
{
    if(S == NULL)
    {
        printf("the memory assinging for S failed->the list createion failed!\n");
        return -1;
    }
    printf("now, please enter your number to the array data[*]~\n");
    int i;
    for(i = 0; i < S->maxlen; i++)
    {
        S->post++;
        scanf("%d", &(S->data[i]));
    }//列表插入结束
    //显示入表元素
    S->mid = (S->post - S->head)/2;
    printf("the original number in array is: ");
    for(i = 0; i < S->maxlen; i++)
    {
        printf("%d ", S->data[i]);
    }
    putchar('\n');
    //对表中元素进行升序排序
    list_reorder(S);
    printf("the re-ordered number in array is: ");
     for(i = 0; i < S->maxlen; i++)
    {
        printf("%d ", S->data[i]);
    }
    putchar('\n');
    printf("the last number is located at [%d]", S->post-1);
    putchar('\n');
    return 0;
}

/*顺序表中元素升序排列函数*/
void list_reorder(HGL * S)
{
    if(S == NULL)
    {
        printf("the memory assinging for S failed->the list createion failed!\n");
        return ;
    }
    int i, j, midnum;
    for(i = 0; i < S->maxlen-1; i++)
    {
        for(j = 0; j < S->maxlen-1-i; j++)
        {
            if(S->data[j] > S->data[j+1])
            {
                midnum = S->data[j];
                S->data[j] = S->data[j+1];
                S->data[j+1] = midnum;
            }
        }
    }
    return ;
}

/*折半查找函数*/
int list_halfGET(HGL * S, int Get_value, int head, int post)
{
    if(S == NULL)
    {
        printf("the memory assinging for S failed->the list createion failed!\n");
        return -1;
    }
    int flag = 0;
    int mid;
    mid = (post - head)/2;
    while(mid != 0){
    if((Get_value != S->data[post]) && (Get_value != S->data[head]) && (Get_value != S->data[mid]))
    {
        if((Get_value > S->data[mid])&&(Get_value < S->data[post]))
        {
            head = mid;
        }
        else if((Get_value < S->data[mid])&&(Get_value > S->data[head]))
        {
            post = mid;
        }
        mid = (post - head)/2 + head;
    }
    else if(Get_value == S->data[post])
    {
        printf("the Get_value is located at [%d]\n", post);
        flag = 1;
        break;
    }
    else if(Get_value == S->data[head])
    {
        printf("the Get_value is located at [%d]\n", head);
        flag = 1;
        break;
    }
      else if(Get_value == S->data[mid])
    {
        printf("the Get_value is located at [%d]\n", mid);
        flag = 1;
        break;
    }
    }
    if(flag == 0)
    {
        printf("the Get_value is not within the array!\n");
    }
    return 0;
}


typedef int data_t;
typedef struct{
    data_t * data;
    int maxlen;
    int head;
    int post;
    int mid;
} HGL;


HGL * list_create(int);
int  list_en(HGL *);
void list_reorder(HGL *);
int list_halfGET(HGL *, int, int, int);

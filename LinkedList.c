#include <stdio.h>
#include <stdlib.h>

typedef struct _data
{
    int val;
    struct _data *next;
} Data;

typedef struct
{
    Data *first;
    int size;
} Stack;

void Ins(Stack *s, int value, int index)
{
    Data *tmp = (Data*)malloc(sizeof(Data));

    if((index == 0) || (s->first == NULL))
    {
        tmp->val = value;
        tmp->next = s->first;
        s->first = tmp;
    }
    else
    {
        Data *iter = s->first;
        tmp->val = value;

        int i;
        if(index >= s->size) i = s->size - 1;
        else i = index - 1;
        while(i--) iter = iter->next;

        tmp->next = iter->next;
        iter->next = tmp;
    }

    (s->size)++;
}

void Del(Stack *s, int index)
{
    Data *iter = s->first;

    if((index >= s->size) || (s->first == NULL)) return;
    else if(index == 0)
    {
        s->first = iter->next;
        free(iter);
    }
    else
    {
        Data *iter2;

        int i = index - 1;
        while(i--) iter = iter->next;

        iter2 = iter->next->next;
        free(iter->next);
        iter->next = iter2;
    }

    (s->size)--;
}

void PrintOut(Stack *s)
{
    if(s->first == NULL) printf("empty\n");
    else
    {
        Data *iter = s->first;

        while(iter != NULL)
        {
            printf("%d ", iter->val);
            iter = iter->next;
        }
        printf("\n");
    }
}

int main()
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->first = NULL;
    s->size = 0;

    char tmp;
    int M, N;

    while(scanf("%c", &tmp) && (tmp != 'q'))
    {
        switch(tmp)
        {    case 'f':
                scanf("%d", &N);
                Ins(s, N, 0);
                break;
            case 'i':
                scanf("%d %d", &M, &N);
                Ins(s, N, M);
                break;
            case 'r':
                Del(s, 0);
                break;
            case 'd':
                scanf("%d", &M);
                Del(s, M);
        }

        scanf("%c", &tmp);
        PrintOut(s);
    }
}

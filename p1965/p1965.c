#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
Node *fun(int k)
{
    int i = 1, j = 0;
    Node *head, *p, *q;
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    p = head;
    scanf("%d ", &p->data);
    if (k != 1)
    {
        for (i = 2; i < k; i++)
        {
            q = (Node *)malloc(sizeof(Node));
            scanf("%d ", &q->data);
            q->next = NULL;
            p->next = q;
            p = q;
        }
        q = (Node *)malloc(sizeof(Node));
        scanf("%d", &q->data);
        q->next = NULL;
        p->next = q;
    }
    return head;
}
int main()
{
    int n = 0, i = 0;
    Node *N[100000] = {NULL};
    Node *head, *p;
    int N0[100000] = {-1};
    scanf("%d", &n);
    for (; i < n - 1; i++)
    {
        scanf("%d ", &N0[i]);
    }
    scanf("%d", &N0[i]);
    for (i = 0; i < n; i++)
    {
        N[i] = fun(N0[i]);
    }
    int k = 0, a = 0, b = 0;
    scanf("%d", &k);
    for (i = 0; i < k; i++)
    {
        scanf("%d %d", &a, &b);
        head = (Node *)malloc(sizeof(Node));
        head->next = N[b - 1];
        head->data = a;
        N[b - 1] = head;
    }
    for (i = 0; i < n; i++)
    {
        p = N[i];
        if (p != NULL)
            k = -1;
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        if (k == -1)
            printf("\n");
        k = 0;
    }
    system("pause");
    return 0;
}
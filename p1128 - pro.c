#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char data[15];
    struct node *next;
} Node;
int main()
{
    int n = 0, s = 0, w = 0;
    scanf("%d", &n);
    Node *head, *p, *q;
    int i = 1, j = 0;
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    p = head;
    scanf("%s", &p->data); // 读取第1个人的名字
    for (i = 2; i < n; i++)
    {
        q = (Node *)malloc(sizeof(Node));
        scanf("%s", &q->data); // 读取第2~(n-1)个人的名字
        q->next = NULL;
        p->next = q;
        p = q;
    } // 建立循环链表
    q = (Node *)malloc(sizeof(Node));
    scanf("%s", &q->data); // 读取第n个人的名字
    q->next = head;        // 最后一个节点指向头节点
    p->next = q;
    p = head;
    scanf("%d,%d", &w, &s);
    for (i = 1; i < w ; i++)
    {
        p = p->next;
    } // 找到开始报数的节点
    if (s == 1)// 特殊情况，s=1时，直接输出
    {
        for (j = 0; j <= n - 1; j++) // 直到圆桌周围的人全部出列
        {
            printf("%s\n", p->data); // 输出出列节点
            p = p->next;             // 下一个节点开始报数
        }
    }
    else
    {
        for (j = 0; j <= n - 1; j++) // 直到圆桌周围的人全部出列
        {
            for (i = 0; i < s - 2; i++)
            {
                p = p->next;
            } // 找到出列节点的前一个节点
            printf("%s\n", p->next->data); // 输出出列节点(前一个节点的下一个节点)
            p->next = p->next->next;       // 删除出列节点
            p = p->next;                   // 下一个节点开始报数
        }
    }
    system("pause");
    return 0;
}
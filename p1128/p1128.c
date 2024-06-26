// 已知 n 个人（编号分别为 1、2、3、……、n）围坐在一张圆桌周围，从编号为 1 的人开始报数，数到 m 的那个人出列；他的下一个人又从 1 开始报数，数到 m 的那个人又出列，依次规律重复下去，直到圆桌周围的人全部出列
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
int main()
{
    int n = 0, m = 0;
    while (~scanf("%d %d", &n, &m))
    {
        if (m == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                printf("%d ", i);
            }
            printf("\n");
            continue;
        } // 特殊情况
        Node *head, *p, *q;
        int i = 1, j = 0;
        head = (Node *)malloc(sizeof(Node));
        head->next = NULL;
        p = head;
        p->data = i;
        for (; i < n - 1; i++)
        {
            q = (Node *)malloc(sizeof(Node));
            q->data = i + 1;
            q->next = NULL;
            p->next = q;
            p = q;
        } // 建立循环链表
        q = (Node *)malloc(sizeof(Node));
        q->data = i + 1;
        q->next = head; // 最后一个节点指向头节点
        p->next = q;
        int a[100] = {0};
        p = head;
        for (j = 0; j <= n - 1; j++) // 直到圆桌周围的人全部出列
        {
            for (i = 0; i < m - 2; i++)
            {
                p = p->next;
            } // 找到出列节点的前一个节点
            a[j] = p->next->data;    // 记录出列节点(前一个节点的下一个节点)
            p->next = p->next->next; // 删除出列节点
            p = p->next;             // 下一个节点开始报数
        }
        for (i = 0; a[i] != 0; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
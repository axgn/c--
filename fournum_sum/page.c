#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct page_manager
{
    char **page;
    int lefttop;
    int righttop;
};
struct page_manager *init()
{
    struct page_manager *p = (struct page_manager *)malloc(sizeof(struct page_manager));
    p->page = (char **)malloc(sizeof(char *) * MAX);
    p->lefttop = -1;
    p->righttop = MAX;
    return p;
}
void add(struct page_manager *p, char *page)
{ // 增加新的网页
    if (p->lefttop == p->righttop - 1)
    {
        printf("stack is full!");
        return;
    }
    p->page[++p->lefttop] = page;
}
char *forward(struct page_manager *p)
{ // 按前进键
    if (p->righttop == MAX)
        return NULL;
    char *page = p->page[p->righttop++];
    p->page[++p->lefttop] = page;
    return page;
}
char *backward(struct page_manager *p)
{ // 按后退键
    if (p->lefttop == -1)
        return NULL;
    char *page = p->page[p->lefttop--];
    p->page[--p->righttop] = page;
    return page;
}
int main()
{
    struct page_manager *p = init();
    add(p, (char *)"page1");
    add(p, (char *)"page2");
    add(p, (char *)"page3");
    add(p, (char *)"page4");
    add(p, (char *)"page5");
    add(p, (char *)"page6");
    int oper = 1;
    while (oper != 0)
    {
        printf("input:");
        scanf("%d", &oper);
        if (oper == 1)
            printf("%s\n", forward(p));
        else if (oper == -1)
            printf("%s\n", backward(p));
    }
}
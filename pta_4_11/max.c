#include <stdio.h>

int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int arraymax(int a[], int n)
{
    int temp = max(a[n - 2], a[n - 1]);
    if (n == 2)
    {
        printf("max(%d,%d)=%d ", a[n - 2], a[n - 1], temp);
        return temp;
    }
    else
    {
        int temp2 = arraymax(a, n - 1);
        int temp = max(temp2, a[n - 1]);
        printf("max(%d,%d)=%d ", temp2, a[n - 1], temp);
        return temp;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[35] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    printf("%d", arraymax(a, n));
    return 0;
}
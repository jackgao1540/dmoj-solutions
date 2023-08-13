#include <stdio.h>

int main() {
    printf("guess 0\n");
    int x, y;
    scanf("%d", &x);
    printf("guess %d\n", x);
    scanf("%d", &y);
    if(y == 0)printf("answer %d\n", x);
    else printf("answer %d\n", -x);
    return 0;
}
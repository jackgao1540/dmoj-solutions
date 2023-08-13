#include <stdio.h>

int main() {
    printf("guess 50\n");
    int x;
    scanf("%d", &x);
    printf("answer %d\n", 50 - x);
    return 0;
}
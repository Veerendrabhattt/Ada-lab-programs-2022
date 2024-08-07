#include <stdio.h>
#include <stdlib.h>

static int count = 0;
int i;
void merge(int b[], int c[], int a[], int p, int q) {
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        count++;
        if (b[i] <= c[j])
            a[k++] = b[i++];
        else
            a[k++] = c[j++];
    }
    while (i < p)
        a[k++] = b[i++];
    while (j < q)
        a[k++] = c[j++];
}

void mergesort(int a[], int n) {
    if (n > 1) {
        int p = n / 2;
        int q = n - p;
        int *b = (int *)malloc(p * sizeof(int));
        int *c = (int *)malloc(q * sizeof(int));
        
        for ( i = 0; i < p; i++)
            b[i] = a[i];
        for ( i = 0; i < q; i++)
            c[i] = a[p + i];
        
        mergesort(b, p);
        mergesort(c, q);
        merge(b, c, a, p, q);
        
        free(b);
        free(c);
    }
}

int main() {
    int n, *a;
    printf("Enter size of array: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("Input elements: ");
    for ( i = 0; i < n; i++) {
        a[i] = rand() % 1001;
        printf("%d\t", a[i]);
    }
    mergesort(a, n);
    printf("\nSorted elements:\n");
    for ( i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\nNumber of comparisons: %d\n", count);
    free(a);
    return 0;
}

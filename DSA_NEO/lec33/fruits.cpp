#include <stdio.h>
#include <stdlib.h>

struct Fruit {
    int sweetness;
};

void swap(struct Fruit *x, struct Fruit *y) {
    struct Fruit temp = *x;
    *x = *y;
    *y = temp;
}

void heapifyDown(struct Fruit *heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].sweetness > heap[largest].sweetness)
        largest = left;
    if (right < n && heap[right].sweetness > heap[largest].sweetness)
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapifyDown(heap, n, largest);
    }
}

struct Fruit removeSweetestFruit(struct Fruit *heap, int *n) {
    if (*n <= 0) {
        struct Fruit emptyFruit;
        emptyFruit.sweetness = -1;
        return emptyFruit;
    }

    struct Fruit sweetestFruit = heap[0];
    swap(&heap[0], &heap[*n - 1]);
    (*n)--;
    heapifyDown(heap, *n, 0);

    return sweetestFruit;
}

int main() {
    struct Fruit *basket;
    int n;

    scanf("%d", &n);
    basket = (struct Fruit *)malloc(n * sizeof(struct Fruit));

    for (int i = 0; i < n; i++) {
        scanf("%d", &basket[i].sweetness);
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(basket, n, i);
    }

    struct Fruit eatenFruit = removeSweetestFruit(basket, &n);

    if (eatenFruit.sweetness != -1) {
        printf("%d\n", eatenFruit.sweetness);
    }

    free(basket);
    return 0;
}

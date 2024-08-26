#include <stdio.h>

#define FOR_EACH(item, array, length) \
    for (int keep = 1, count = 0, size = (length); keep && count != size; keep = !keep, count++) \
        for (item = (array) + count; keep; keep = !keep)

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int length = sizeof(arr) / sizeof(arr[0]);

    int *item;
    FOR_EACH(item, arr, length) {
        printf("%d ", *item);
    }

    return 0;
}

#include <stdio.h>

#define FOR_EACH(item, array, size) \
    for (int item = 0; item < (size); ++item)

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int length = sizeof(arr) / sizeof(arr[0]);

    FOR_EACH(i, arr, length) {
        printf("%d ", arr[i]);
    }

    return 0;
}

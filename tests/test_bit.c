#include <assert.h>
#include <stdio.h>

#include "../bit.h"

int main(void) {
    int arr[11];  // N = 10, + 1 -> 1-based
    struct bit bit;
    bit_init(&bit, arr, 10);

    bit_add(&bit, 1, 3);
    bit_add(&bit, 2, 0);
    bit_add(&bit, 3, 2);
    bit_add(&bit, 4, 5);

    assert(bit_sum(&bit, 1) == 3);   // Thread 0 (3)
    assert(bit_sum(&bit, 2) == 3);   // Thread 0 (3) + Thread 1 (0)
    assert(bit_sum(&bit, 3) == 5);   // Thread 0 (3) + Thread 1 (0) + Thread 2 (2)
    assert(bit_sum(&bit, 4) == 10);  // All: Thread 0 (3) + Thread 1 (0) + Thread 2 (2) + Thread 3 (5)

    // slot 0: [0, 1, 2]
    // slot 2: [3, 4]
    // slot 3: [5, 6, 7, 8, 9]

    assert(bit_find(&bit, 0) == 1);  // slot 0
    assert(bit_find(&bit, 2) == 1);  // slot 0
    assert(bit_find(&bit, 3) == 3);  // slot 2
    assert(bit_find(&bit, 5) == 4);  // slot 3
    assert(bit_find(&bit, 9) == 4);  // slot 3

    bit_add(&bit, 3, -2);
    assert(bit_sum(&bit, 4) == 8);  // All: Thread 0 (3) + Thread 1 (0) + Thread 2 (0) + Thread 3 (5)

    int safe_index = bit_find(&bit, 100);
    assert(safe_index == 10);

    printf("All BIT tests passed!\n");
    return 0;
}
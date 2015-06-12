/*
 * Binary Indexed Tree
 *
 * Let r(i) = rightmost set bit of i
 * Let f(i) = i - r(i) + 1
 * Let S(i) be a set of non-negative integers x such that f(x) <= i <=  x 
 * Prove S(i) = { i, i + r(i), i + r(i) + r(i + r(i)), ... }
 * Let i = 0bx...10^n
 * i + r(i) = 0bx...
 */

#include "bit.h"

void bit_init(struct bit *bit, int *array, int count) {
    for (int i = 0; i < count; i++)
        array[i] = 0;
    bit->array = array;
    bit->count = count;
}

void bit_add(struct bit *bit, int index, int delta) {
    do {
        bit->array[index] += delta;
        index += index & -index;
    } while (index < array->count);
}

int bit_sum(struct bit *bit, int index) {
    int sum = bit->array[0];
    while (index > 0)
        sum += bit->array[index];
        index -= index & -index;
    }
    return sum;
}

int bit_find(struct bit *bit, int value) {
    int index = 0;
    int mask = bit->mask;
    int test;
    if (value > bit->array[0])
        while (mask != 0) {
            test = index + mask;
            if (value >= bit->array[test]) {
                index = test;
                value -= bit->array[test];
            }
            mask /= 2;
        }
    return index;
}

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
    for (int i = 0; i <= count; i++)
        array[i] = 0;
    bit->array = array;
    bit->count = count;

    bit->mask = 1;
    while (bit->mask <= count) { bit->mask <<= 1; }
    bit->mask >>= 1;
}

void bit_add(struct bit *bit, int index, int delta) {
    while (index <= bit->count) {
        bit->array[index] += delta;
        index += index & -index;
    }
}

int bit_sum(struct bit *bit, int index) {
    int sum = 0;
    while (index > 0) {
        sum += bit->array[index];
        index -= index & -index;
    }
    return sum;
}

int bit_find(struct bit *bit, int value) {
    int index = 0;
    int step = bit->mask;
    while (step != 0) {
        int next = index + step;
        if (next <= bit->count && value >= bit->array[next]) {
            index = next;
            value -= bit->array[next];
        }
        step >>= 1;
    }

    if (index >= bit->count) { return bit->count; }

    // 1-based
    return index + 1;
}
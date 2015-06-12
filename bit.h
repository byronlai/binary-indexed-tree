#ifndef BIT_H
#define BIT_H

struct bit {
    int *array;
    int count;
};

void bit_init(struct bit *bit, int *array, int count);
void bit_add(struct bit *bit, int index, int delta);
int bit_sum(struct bit *bit, int index);
int bit_find(struct bit *bit, int value);

#endif

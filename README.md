# Binary Indexed Tree (Fenwick Tree)

C implementation of binary indexed tree. A binary indexed tree is an efficient data structure for finding and manipulation of the prefix sum (cumulative sum) of a sequence of numbers. The time complexity of the query operation and update operation is O(logn).

## API

* `void bit_init(struct bit *bit, int *array, int count)`

   Initialize the binary indexed tree. `array` provides the underlying storage for the tree. `count` is the capacity of `array`.

* `void bit_add(struct bit *bit, int index, int delta)`

   Update the number at `index` by adding `delta` to it.

* `int bit_sum(struct bit *bit, int index)`

   Find the cumulative frequency for `index`.

* `int bit_find(struct bit *bit, int value)`

   Find the index within which the frequency lies.

## See Also

* [A new data structure for cumulative frequency tables](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.14.8917)
* [Binary Indexed Trees – topcoder](https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/)

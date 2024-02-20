#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 *
 * Description: Swaps two integers in an array and prints the array.
 */
void swap_ints(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
    print_array(a, 2);
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 *
 * Description: Maintains the heap property by recursively
 * adjusting the binary tree rooted at the given root index.
 * Prints the array after each swap.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
    size_t left, right, large;

    left = 2 * root + 1;
    right = 2 * root + 2;
    large = root;

    if (left < base && array[left] > array[large])
        large = left;
    if (right < base && array[right] > array[large])
        large = right;

    if (large != root)
    {
        swap_ints(array + root, array + large);
        max_heapify(array, size, base, large);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Builds a max heap and repeatedly extracts
 * the maximum element to achieve sorted order. Prints
 * the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
    int i;

    if (array == NULL || size < 2)
        return;

    for (i = (size / 2) - 1; i >= 0; i--)
        max_heapify(array, size, size, i);

    for (i = size - 1; i > 0; i--)
    {
        swap_ints(array, array + i);
        max_heapify(array, size, i, 0);
    }
}


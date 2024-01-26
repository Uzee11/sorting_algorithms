#include "sort.h"
#include <stdio.h>

/**
 * partition - Scans a partition of an array of integers for values less than
 * pivot value, swaps them with the first value in the partition, then swaps
 * pivot value with the first value in the partition.
 *
 * @array: Array of integers to be sorted
 * @low: Index in array that begins partition
 * @high: Index in array that ends partition
 * @size: Amount of elements in array
 *
 * Return: New index at which to start a new recursive partition
 */
/* Uzee11 Version */

int partition(int *array, int low, int high, size_t size)
{
    int i, j, pivot, temp;

    pivot = array[high];
    i = low;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            if (array[i] != array[j])
                print_array(array, size);

            i++;
        }
    }

    temp = array[i];
    array[i] = array[high];
    array[high] = temp;

    if (array[i] != array[high])
        print_array(array, size);

    return (i);
}

/**
 * quicksort - Recursively sorts an array of integers by separating it into two
 * partitions using Lomuto quick sort.
 *
 * @array: Array of integers to be sorted
 * @low: Index in array that begins partition
 * @high: Index in array that ends partition
 * @size: Amount of elements in array
 */
void quicksort(int *array, int low, int high, size_t size)
{
    int p;

    if (low < high)
    {
        p = partition(array, low, high, size);
        quicksort(array, low, p - 1, size);
        quicksort(array, p + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using a quick
 * sort algorithm, with the Lomuto partition scheme.
 *
 * @array: Array of integers to be sorted
 * @size: Amount of elements in array
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quicksort(array, 0, (int)size - 1, size);
}

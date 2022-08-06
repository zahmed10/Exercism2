#include "binary_search.h"

int bsearchCompare(const void *key, const void *value)
{
    const int *k = key, *v = value;
    return *k - *v;
}

int *binary_search(int value, const int *arr, size_t length)
{
    int *pt = bsearch(&value, arr, length, sizeof(int), bsearchCompare);
    return pt;
}

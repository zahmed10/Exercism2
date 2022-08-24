#include "binary_search.h"

// bsearch reference
// https://beej.us/guide/bgc/html/#man-bsearch

int bsearchCompare(const void *key, const void *value)
{
    const int *k = key, *v = value;
    return *k - *v;
}

int *binary_search(int value, const int *arr, size_t length)
{
    return bsearch(&value, arr, length, sizeof(int), bsearchCompare);
}

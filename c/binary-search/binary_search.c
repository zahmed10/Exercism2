#include "binary_search.h"

int *binary_search(int value, const int *arr, size_t length) {
    size_t i;
    // bool found = false;
    i = length/2;
    size_t j = 0;
    while((i>=0 || i<=length) && j<6){
        // if (length%2 != 0){ // 1 3 1 4 5 6 7 8
            if(arr[i]==value){
                return (int *) &arr[i];
            } else if (arr[i]>value){
                i %= 2;
            } else {
                i *=1.5+1;
            }
            if (i==0 || i==length){
                j++;
            }
        // } else { 
            // if(arr[i]==value){
            //     return (int *) &arr[i];
            // } else if (arr[i]>value){
            //     i %= 2;
            // } else {
            //     i *=1.5+1;
            // }
        // }

    }
    return false;
}

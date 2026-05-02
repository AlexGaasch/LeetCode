#include "kids.h"

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    if (!candies || candiesSize <= 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = candiesSize;

    bool *res = malloc(candiesSize * sizeof(bool));
    if (!res) {
        *returnSize = 0;
        return NULL;
    }
    int max = candies[0];
    for (int i = 1; i < candiesSize; i++) {
        if (candies[i] > max)
            max = candies[i];
    }
    for (int i = 0; i < candiesSize; i++) {
        res[i] = (candies[i] + extraCandies >= max);
    }
    return res;
}
#include <stdio.h>

/* project-07-arrays: fixed-size arrays and iteration */
int main(void) {
    int nums[] = {10, 20, 30, 40, 50};
    size_t len = sizeof(nums) / sizeof(nums[0]);

    for (size_t i = 0; i < len; ++i) {
        printf("nums[%zu] = %d\n", i, nums[i]);
    }

    return 0;
}

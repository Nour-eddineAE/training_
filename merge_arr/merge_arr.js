var merge = function (nums1, m, nums2, n) {
    for (let i = 0; i < n; i++) {
        let count = 0;
        let index = i;
        while (nums1[m + index - 1] > nums2[i]) {
            count++;
            index--;
        }

        nums1.copyWithin(m + index + 1, m + index);
        nums1[m + index] = nums2[i];

        // OR
        // nums1.splice(m + index, 0, nums2[i]);
        // nums1.splice(nums1.length - 1, 1);
    }
    return nums1;
};

console.log(merge([1, 2, 3, 0, 0, 0], 3, [2, 5, 3, 1], 3));
// output should be [1, 1, 2, 2, 3, 3, 5]

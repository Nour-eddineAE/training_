/*
 * Implementation of Array.flat
 */

/**
 * ! Worst runtime and space use
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat1 = function (arr, n) {
    let res = [...arr];

    while (n > 0) {
        let temp = [];

        for (let elmt of res) {
            if (Array.isArray(elmt)) {
                temp.push(...elmt);
            } else {
                temp.push(elmt);
            }
        }

        res = temp;
        n--;
    }

    return res;
};

/**
 * ? Using simple recursion
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat2 = function (arr, n) {
    let res = [];

    arr.forEach((elmt) => {
        if (Array.isArray(elmt) && n > 0) {
            res.push(...flat2(elmt, n - 1));
        } else {
            res.push(elmt);
        }
    });

    return res;
};

/**
 * ? Using a stack to flatten and maintain the order
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat3 = function (arr, n) {
    const stack = [{ array: arr, index: 0, depth: n }];
    const result = [];

    while (stack.length > 0) {
        const { array, index, depth } = stack.pop();

        if (index === array.length) {
            continue;
        }

        const element = array[index];

        if (Array.isArray(element) && depth > 0) {
            stack.push({ array, index: index + 1, depth });
            stack.push({ array: element, index: 0, depth: depth - 1 });
        } else {
            result.push(element);
            stack.push({ array, index: index + 1, depth });
        }
    }

    return result;
};

const arr = [1, 2, 3, [4, 5, 6], [7, 8, [9, 10, 11], 12], [13, 14, 15]];

console.log(flat1(arr, 1)); //[ 1, 2, 3, 4, 5, 6, 7, 8, [ 9, 10, 11 ], 12, 13, 14, 15 ]
console.log(flat2(arr, 1)); //[ 1, 2, 3, 4, 5, 6, 7, 8, [ 9, 10, 11 ], 12, 13, 14, 15 ]
console.log(flat3(arr, 1)); //[ 1, 2, 3, 4, 5, 6, 7, 8, [ 9, 10, 11 ], 12, 13, 14, 15 ]

/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
const chunk = (arr, size) => {
    const chunks = [];

    for (let i = 0; i < arr.length; i += size) {
        chunks.push(arr.slice(i, i + size));
    }

    return chunks;
};

const arr = [1, 2, 5, 13, 5, 1, 4, 6];
const chunks_size = 2;
console.log(chunk(arr, chunks_size));

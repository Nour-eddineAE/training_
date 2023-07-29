function toBinary(number) {
    if (number === 0) {
        return [0];
    }

    const binaryArray = [];

    while (number > 0) {
        const remainder = number % 2;
        binaryArray.unshift(remainder);
        number = Math.floor(number / 2);
    }
    return binaryArray;
}

const getMaxLength = (arr) => {
    if (arr.length == 1) return 1;

    let count = 0;
    let maxDig = 0;
    const binaryRep = [];
    for (let i = 0; i < arr.length; i++) {
        const binary = toBinary(arr[i]);
        binaryRep.push(binary);
        maxDig = Math.max(maxDig, binary.length);
    }

    binaryRep.forEach((binary) => {
        while (binary.length < maxDig) {
            binary.unshift(0);
        }
    });

    console.log(binaryRep);

    for (let i = 0; i < maxDig; i++) {
        let colSum = 0;
        for (let j = 0; j < arr.length; j++) {
            colSum += binaryRep[j][i];
        }
        count = Math.max(count, colSum);
    }
    return count;
};

const vec = [5, 3, 1, 6, 2, 2];
console.log(getMaxLength(vec));

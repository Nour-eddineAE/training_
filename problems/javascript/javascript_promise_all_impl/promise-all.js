/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = async function (functions) {
    return new Promise((resolve, reject) => {
        const results = [];
        let count = 0;

        functions.forEach((fct, index) => {
            fct()
                .then((result) => {
                    results[index] = result;
                    count++;

                    if (count === functions.length) {
                        resolve(results);
                    }
                })
                .catch((err) => {
                    reject(err);
                });
        });
    });
};

const promise = promiseAll([() => new Promise((res) => res(42))]);
promise.then(console.log); // [42]

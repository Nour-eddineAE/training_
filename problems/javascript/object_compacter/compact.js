/**
 * @param {Object} obj
 * @return {Object}
 */
var compactObject = function (obj) {
    // if not an object or null object
    if (!obj || typeof obj !== "object") {
        return obj;
    }

    // if array
    if (Array.isArray(obj)) {
        return obj.filter(Boolean).map(compactObject);
    }

    // if non-null object
    let res = {};
    for (let key in obj) {
        let value = compactObject(obj[key]);
        if (value) {
            res[key] = value;
        }
    }
    return res;
};

const input = { a: null, b: [false, 1] };
console.log(compactObject(input)); // {"b":[1]}

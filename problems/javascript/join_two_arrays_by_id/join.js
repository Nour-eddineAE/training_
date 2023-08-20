/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function (arr1, arr2) {
    const mp = {};

    arr1.forEach((elmt) => (mp[elmt.id] = elmt));

    for (let elmt of arr2) {
        if (!mp[elmt.id]) mp[elmt.id] = elmt;
        else {
            for (let key of Object.keys(elmt)) {
                mp[elmt.id][key] = elmt[key];
            }
        }
    }

    return Object.values(mp);
};

const arr1 = [{ id: 1, b: { b: 94 }, v: [4, 3], y: 48 }];
const arr2 = [{ id: 1, b: { c: 84 }, v: [1, 3] }];
console.log(join(arr1, arr2)); // [{ id: 1, b: { c: 84 }, v: [1, 3], y: 48 }];

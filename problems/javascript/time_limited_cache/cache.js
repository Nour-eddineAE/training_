var TimeLimitedCache = function () {};

TimeLimitedCache.prototype.cache = {};

/**
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function (key, value, duration) {
    const existingEntry = this.cache[key];

    if (existingEntry) {
        clearTimeout(existingEntry.timeout);
    }

    this.cache[key] = {
        value,
        timeout: setTimeout(() => {
            delete this.cache[key];
        }, duration),
    };

    return Boolean(existingEntry);
};

/**
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function (key) {
    const entry = this.cache[key];
    return entry ? entry.value : -1;
};

/**
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function () {
    return Object.keys(this.cache).length;
};

var obj = new TimeLimitedCache();
obj.set(1, 42, 1000); // false
obj.get(1); // 42
obj.count(); // 1

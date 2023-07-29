// trivial solution
function isPalindrome(x) {
    const pal = x.toString();
    const len = pal.length;
    const mid = Math.floor(len / 2);
    for (let i = 0; i <= mid; i++) {
        if (pal[i] != pal[len - i - 1]) return false;
    }
    return true;
}

// one other way is to reverse then compare

function isPalindrome_(x) {
    const pal = x.toString();
    const reversed = pal.split("").reverse().join("");
    if (reversed != pal) return false;
    return true;
}

console.log(isPalindrome("abcba"));
console.log(isPalindrome_("abcba"));

// both should print true

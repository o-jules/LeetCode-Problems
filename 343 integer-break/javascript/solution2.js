/**
 * @param {number} n
 * @return {number}
 */
let memo = {1:1, 2: 1, 0: 1, 3: 2, 5: 6, 6: 9};
var integerBreak = function(n) {
    if(memo[n]) return memo[n];
    memo[n] = Math.max(integerBreak(n - 4) * 4, integerBreak(n - 3) * 3);
    return memo[n];
};

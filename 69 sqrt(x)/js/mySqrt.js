/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    if (x <= 1) {
        return x
    }
    var h = 0
    var l = 0
    var r = x
    while (true) {
        h = Math.floor((l + r) / 2)
        const sq = h * h
        if (sq === x) { return h }
        if (sq < x) {
            const sq2 = sq + 2 * h + 1
            if (sq2 > x) {
                return h
            } else if(sq2 == x) {
                return h + 1
            } else {
                l = h + 1
            }
        } else {
            r = h
        }
    }
};

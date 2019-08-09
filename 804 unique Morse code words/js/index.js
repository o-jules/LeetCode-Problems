const CodeMap = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];

const IndexA = 'a'.charCodeAt(0);

const decode = word => word.split('').reduce((s, c) => (s += CodeMap[c.charCodeAt(0) - IndexA], s), '');

/**
 * @param {string[]} words
 * @return {number}
 */
var uniqueMorseRepresentations = function(words) {
    return new Set(words.map(decode)).size;
};

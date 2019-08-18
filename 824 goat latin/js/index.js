/**
 * @param {string} S
 * @return {string}
 */
var toGoatLatin = function(S) {
  return S.split(" ")
    .map(
      (word, index) =>
        `${
          word[0] === "A" ||
          word[0] === "E" ||
          word[0] === "I" ||
          word[0] === "O" ||
          word[0] === "U" ||
          word[0] === "a" ||
          word[0] === "e" ||
          word[0] === "i" ||
          word[0] === "o" ||
          word[0] === "u"
            ? word
            : word.slice(1, word.length) + word[0]
        }ma${"a".repeat(index + 1)}`
    )
    .join(" ");
};

const TK_TYPE_UNKOWN = 0;
const TK_TYPE_DIGIT = 1;
const TK_TYPE_ALPHA = 2;
const TK_TYPE_BRACKET = 3;

const DIGITS = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"];

const ALPHABET = [
  "a",
  "b",
  "c",
  "d",
  "e",
  "f",
  "g",
  "h",
  "i",
  "j",
  "k",
  "l",
  "m",
  "n",
  "o",
  "p",
  "q",
  "r",
  "s",
  "t",
  "u",
  "v",
  "w",
  "x",
  "y",
  "z"
];

function isDigit(c) {
  return DIGITS.indexOf(c) >= 0;
}

function isAlpha(c) {
  return ALPHABET.indexOf(c) >= 0;
}

function isBracket(c) {
  return c === "[" || c === "]";
}

// tokenizer
function tokenizer(s) {
  const tokenStream = [];
  let token = "";
  let type = TK_TYPE_UNKOWN;

  function addToken() {
    if (type !== TK_TYPE_UNKOWN) {
      tokenStream.push({
        text: token,
        type
      });
      token = "";
    }
  }

  for (let i = 0; i < s.length; i++) {
    let c = s[i];
    if (isDigit(c)) {
      if (type !== TK_TYPE_DIGIT) {
        addToken();
        type = TK_TYPE_DIGIT;
      }
      token += c;
    } else if (isAlpha(c)) {
      if (type !== TK_TYPE_ALPHA) {
        addToken();
        type = TK_TYPE_ALPHA;
      }
      token += c;
    } else if (isBracket(c)) {
      addToken();
      type = TK_TYPE_BRACKET;
      token = c;
    } else {
      throw new Error('Syntax error: unknow character "' + c + '".');
    }
  }

  addToken();
  return tokenStream;
}

// parser
function parser(tokenStream) {
  // TODO: problems with parser
  let stack = [];
  // currentNode
  let node = {};

  const ast = node;

  for (let i = 0; i < tokenStream.length; i++) {
    const token = tokenStream[i];
    if (token.type === TK_TYPE_UNKOWN) {
      continue;
    }

    if (token.type === TK_TYPE_ALPHA) {
      node.text = token.text;
    }

    if (token.type === TK_TYPE_DIGIT) {
      if (stack.length > 0) {
        node.parent.push(node);
        node = {
          parent: node.parent
        }
      }
      node.count = Number(token.text);
    }

    if (token.tpye === TK_TYPE_BRACKET) {
      if (token.text === "[") {
        stack.push(node);
        node = {
          parent: node
        };
      } else {
        // === ']'
        if (node === stack[stack.length - 1]) {
          node.parent.children.push(node);
          node = node.parent;
        } else {
        }

        stack.pop();
      }
    }
  }

  return ast;
}

// emitter
function emitter(ast) {
  return emit(ast);
}

function emit(node) {
  let repeat = "";
  if (node.text) {
    repeat = node.text;
  } else {
    repeat = node.children.map(i => emit(i)).join("");
  }

  if (node.count === 1) {
    return repeat;
  }

  let code = "";
  for (let i = 0; i < node.count; i++) {
    code += repeat;
  }
  return code;
}

/**
 * @param {string} s
 * @return {string}
 */
function decodeString(s) {
  return emitter(parser(tokenizer(s)));
}

console.log(parser(tokenizer("2[abc3[cd]]ef")));

function shift(letter, k, code) {
  return String.fromCharCode(((letter.charCodeAt() - code + k) % 26) + code);
}

function caesarCipher(s, k) {
  return s.replace(/[a-z]/g, char => shift(char, k, 97)).replace(/[A-Z]/g, char => shift(char, k, 65));
}

// console.log(caesarCipher('middle-Outz', 2)); // try the cipher function%%
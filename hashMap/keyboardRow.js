function findWords(words) {
  // Step 1: Create row mapping
  const map = {};

  const row1 = "qwertyuiop";
  const row2 = "asdfghjkl";
  const row3 = "zxcvbnm";

  for (const char of row1) map[char] = 1;
  for (const char of row2) map[char] = 2;
  for (const char of row3) map[char] = 3;

  const result = [];

  // Step 2: Check each word
  for (const word of words) {
    const lower = word.toLowerCase();

    // row of first character
    const firstRow = map[lower[0]];
    let valid = true;

    for (const char of lower) {
      if (map[char] !== firstRow) {
        valid = false;
        break;
      }
    }

    if (valid) result.push(word);
  }

  return result;
}

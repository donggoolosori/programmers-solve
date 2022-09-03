function solution(s) {
  const numberWords = [
    'zero',
    'one',
    'two',
    'three',
    'four',
    'five',
    'six',
    'seven',
    'eight',
    'nine',
  ];

  return +numberWords.reduce((prev, word, idx) => {
    let arr = prev.split(numberWords[idx]);
    return arr.join(idx);
  }, s);
}

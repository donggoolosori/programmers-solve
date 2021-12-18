function solution(msg) {
  const dict = {};

  for (let i = 0; i < 26; i++) {
    const charCode = String.fromCharCode('A'.charCodeAt(0) + i);
    dict[charCode] = i + 1;
  }
  let index = 27;
  const answer = [];

  for (let i = 0; i < msg.length; i++) {
    let word = msg[i];
    while (i + 1 < msg.length && dict[word + msg[i + 1]]) {
      word += msg[i + 1];
      i++;
    }
    answer.push(dict[word]);
    if (i + 1 < msg.length) {
      dict[word + msg[i + 1]] = index++;
    }
  }

  return answer;
}

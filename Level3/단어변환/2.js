function diffOne(s1, s2) {
  let cnt = 0;

  for (let i = 0; i < s1.length; i++) {
    if (s1[i] !== s2[i]) cnt++;
    if (cnt > 1) return false;
  }
  return true;
}

function solution(begin, target, words) {
  const q = [{ word: begin, count: 0, bit: 0 }];

  while (q.length !== 0) {
    const { word, count, bit } = q[0];
    q.shift();

    if (word === target) return count;

    for (let i = 0; i < words.length; i++) {
      if (bit & (1 << i)) continue;
      if (!diffOne(word, words[i])) continue;

      q.push({ word: words[i], count: count + 1, bit: bit | (1 << i) });
    }
  }

  return 0;
}

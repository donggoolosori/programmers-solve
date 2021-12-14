function solution(s) {
  let minLen = s.length;

  for (let unit = 1; unit <= parseInt(s.length / 2); unit++) {
    const words = chunk(s, unit);
    const stack = [{ word: '', cnt: 0 }];

    words.forEach((word) => {
      if (stack[stack.length - 1].word === word) {
        stack[stack.length - 1].cnt++;
      } else {
        stack.push({ word, cnt: 1 });
      }
    });

    const compressed = stack.reduce(
      (acc, { word, cnt }) => acc + (cnt > 1 ? cnt + word : word),
      ''
    );

    minLen = Math.min(minLen, compressed.length);
  }

  return minLen;
}

function chunk(s, unit) {
  return s.length <= unit
    ? [s]
    : [s.slice(0, unit), ...chunk(s.slice(unit), unit)];
}

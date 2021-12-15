function solution(relation) {
  let answer = 0;
  const tuples = relation.length,
    attrs = relation[0].length;
  const keyMap = {};

  for (let bit = 1; bit < 1 << attrs; bit++) {
    const set = new Set();

    function isMin(b) {
      if (b <= 0) return 1;

      let ret = 1;
      for (let i = 0; i < attrs; i++) {
        if ((b & (1 << i)) === 0) continue;
        if (keyMap[b ^ (1 << i)]) return 0;
        ret *= isMin(b ^ (1 << i));
      }
      return ret;
    }
    if (!isMin(bit)) continue;

    relation.forEach((tuple) => {
      let key = '';

      tuple.forEach((data, idx) => {
        if (bit & (1 << idx)) {
          key += idx + data;
        }
      });

      set.add(key);
    });

    if (set.size === tuples) {
      answer++;
      keyMap[bit] = true;
    }
  }

  return answer;
}

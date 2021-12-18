function solution(str1, str2) {
  const set1 = {},
    set2 = {},
    commonSet = new Set();

  function countWords(str, set) {
    const regex = /[^a-zA-Z]/;

    for (let i = 0; i < str.length - 1; i++) {
      const word = str.slice(i, i + 2).toLowerCase();

      if (regex.test(word)) continue;

      set[word] ? set[word]++ : (set[word] = 1);
      commonSet.add(word);
    }
  }
  countWords(str1, set1);
  countWords(str2, set2);

  let intersection = 0,
    union = 0;
  [...commonSet.values()].forEach((word) => {
    const cnt1 = set1[word] ? set1[word] : 0;
    const cnt2 = set2[word] ? set2[word] : 0;
    intersection += Math.min(cnt1, cnt2);
    union += Math.max(cnt1, cnt2);
  });

  if (union === 0) return 65536;

  const jaccard = intersection / union;

  return parseInt(jaccard * 65536);
}

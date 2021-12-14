// 이분탐색 통과
function solution(info, query) {
  const dict = {};

  info.forEach((s) => {
    const [lang, pos, career, food, score] = s.split(' ');

    if (!dict[lang]) dict[lang] = { [pos]: { [career]: { [food]: [+score] } } };
    else if (!dict[lang][pos])
      dict[lang][pos] = { [career]: { [food]: [+score] } };
    else if (!dict[lang][pos][career])
      dict[lang][pos][career] = { [food]: [+score] };
    else if (!dict[lang][pos][career][food])
      dict[lang][pos][career][food] = [+score];
    else dict[lang][pos][career][food].push(+score);
  });
  // 정렬
  Object.values(dict).forEach((l) => {
    Object.values(l).forEach((p) => {
      Object.values(p).forEach((c) => {
        Object.values(c).forEach((f) => {
          f.sort((a, b) => a - b);
        });
      });
    });
  });

  const answer = [];

  query.forEach((q) => {
    const [lang, pos, career, food, score] = q
      .split(' ')
      .filter((v) => v !== 'and');
    let langs = [lang],
      poss = [pos],
      careers = [career],
      foods = [food];
    if (lang === '-') langs = ['java', 'cpp', 'python'];
    if (pos === '-') poss = ['frontend', 'backend'];
    if (career === '-') careers = ['junior', 'senior'];
    if (food === '-') foods = ['chicken', 'pizza'];

    let cnt = 0;
    langs.forEach((l) => {
      if (!dict[l]) return;
      poss.forEach((p) => {
        if (!dict[l][p]) return;
        careers.forEach((c) => {
          if (!dict[l][p][c]) return;
          foods.forEach((f) => {
            const scores = dict[l][p][c][f];
            if (!scores) return;
            if (scores[scores.length - 1] < score) return;

            let s = 0,
              e = scores.length - 1;
            while (s < e) {
              const mid = parseInt((s + e) / 2);
              if (scores[mid] >= score) {
                e = mid;
              } else {
                s = mid + 1;
              }
            }

            cnt += scores.length - e;
          });
        });
      });
    });
    answer.push(cnt);
  });

  return answer;
}

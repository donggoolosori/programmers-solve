// 시간초과

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
          f.sort((a, b) => b - a);
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
            for (let i = 0; i < scores.length; i++) {
              if (scores[i] < score) break;
              cnt++;
            }
          });
        });
      });
    });
    answer.push(cnt);
  });

  return answer;
}

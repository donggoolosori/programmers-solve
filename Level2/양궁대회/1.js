function solution(n, info) {
  const arrowToWin = info.map((i) => i + 1);

  let maxDiff = 0;
  let ans = Array.from({ length: 11 }, () => 0);

  const check = {};

  function replaceAnswer() {
    let used = 0;
    for (let i = 0; i <= 10; i++) {
      if (i === 10) {
        ans[i] = n - used;
        continue;
      }
      if (check[i]) {
        ans[i] = arrowToWin[i];
        used += arrowToWin[i];
      } else {
        ans[i] = 0;
      }
    }
  }

  function getScoreDiff() {
    let aScore = 0,
      lScore = 0;

    for (let i = 0; i <= 10; i++) {
      if (check[i]) {
        lScore += 10 - i;
      } else if (!check[i] && info[i] !== 0) {
        aScore += 10 - i;
      }
    }

    return lScore - aScore;
  }

  function findCases(idx, usedArrow) {
    if (idx === 11) {
      const diff = getScoreDiff();

      if (diff > maxDiff) {
        maxDiff = diff;
        replaceAnswer();
      } else if (diff === maxDiff) {
        for (let i = 10; i >= 0; i--) {
          if (check[i] && ans[i] === 0) {
            replaceAnswer();
            break;
          } else if (!check[i] && ans[i] !== 0) {
            break;
          }
        }
      }
      return;
    }

    for (let i = idx; i <= 10; i++) {
      if (usedArrow + arrowToWin[i] <= n) {
        check[i] = true;
        if (i === 10) {
          findCases(i + 1, n);
        } else {
          findCases(i + 1, usedArrow + arrowToWin[i]);
        }
        check[i] = false;
      }

      findCases(i + 1, usedArrow);
    }
  }

  findCases(0, 0);

  if (maxDiff === 0) return [-1];

  return ans;
}

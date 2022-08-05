function solution(progresses, speeds) {
  const due = progresses.map((p, idx) => Math.ceil((100 - p) / speeds[idx]));

  const stack = [];

  due.forEach((d) => {
    if (stack.length === 0 || stack[stack.length - 1].val < d)
      stack.push({ cnt: 1, val: d });
    else {
      stack[stack.length - 1].cnt++;
    }
  });

  return stack.map((o) => o.cnt);
}

function solution(priorities, location) {
  const list = priorities.map((priority, index) => ({ priority, index }));

  let cnt = 0;

  while (true) {
    const curr = list.shift();
    const hasHigherPriority = list.some((el) => curr.priority < el.priority);

    if (hasHigherPriority) {
      list.push(curr);
    } else {
      cnt++;
      if (location === curr.index) break;
    }
  }

  return cnt;
}

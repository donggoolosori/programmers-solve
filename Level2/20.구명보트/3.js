function solution(people, limit) {
  people.sort((a, b) => b - a);

  const len = people.length;
  let s = 0,
    e = len - 1;

  let answer = 0;
  while (s <= e) {
    if (people[s] + people[e] <= limit) {
      s++, e--;
    } else {
      s++;
    }
    answer++;
  }

  return answer;
}

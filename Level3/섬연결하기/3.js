const parent = Array.from({ length: 100 }, (_, idx) => idx);

function getParent(x) {
  if (parent[x] === x) return x;
  return getParent(parent[x], parent);
}

function unionParent(a, b) {
  a = getParent(a);
  b = getParent(b);
  parent[b] = a;
}

function compareParent(a, b) {
  return getParent(a) === getParent(b);
}

function solution(n, costs) {
  costs.sort((a, b) => a[2] - b[2]);

  let answer = 0;

  for (let i = 0; i < costs.length; i++) {
    const [a, b, cost] = costs[i];
    if (compareParent(a, b)) continue;

    unionParent(a, b);
    answer += cost;
  }

  return answer;
}

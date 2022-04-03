// 연결리스트로 해결
function solution(n, k, cmd) {
  const delStack = [];

  let head = {
    id: 0,
    next: null,
    prev: null,
  };

  let curr = head;

  function initList() {
    for (let id = 1; id < n; id++) {
      curr.next = { id, next: null, prev: curr };
      curr = curr.next;
    }

    curr = head;
    let init = k;
    while (init--) {
      curr = curr.next;
    }
  }

  function move(type, count) {
    if (type === 'D') {
      while (count--) {
        curr = curr.next;
      }
    } else {
      while (count--) {
        curr = curr.prev;
      }
    }
  }

  function deleteNode() {
    const next = curr.next;
    const prev = curr.prev;

    delStack.push(curr);

    curr = next ? next : prev;

    if (prev) prev.next = next;
    if (next) next.prev = prev;
  }

  function restore() {
    const restoreNode = delStack.pop();

    const next = restoreNode.next;
    const prev = restoreNode.prev;

    if (prev) prev.next = restoreNode;
    if (next) next.prev = restoreNode;
  }

  initList();

  cmd.forEach((c) => {
    let [type, count] = c.split(' ');
    count = Number(count);

    if (type === 'D' || type === 'U') {
      move(type, count);
    } else if (type === 'C') {
      deleteNode();
    } else if (type === 'Z') {
      restore();
    }
  });

  const ansArr = Array.from({ length: n }, () => 'O');

  delStack.forEach((node) => (ansArr[node.id] = 'X'));

  return ansArr.join('');
}

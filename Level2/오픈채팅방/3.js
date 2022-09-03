const users = {};

const actions = [];

function solution(record) {
  let answer = [];

  record.forEach((el) => {
    const [action, uid, name] = el.split(' ');

    if (action === 'Enter' || action === 'Leave') {
      actions.push({ uid, action });
    }
    if (action === 'Enter' || action === 'Change') {
      users[uid] = name;
    }
  });

  actions.forEach((el) => {
    let log = '';

    log += users[el.uid];

    if (el.action === 'Enter') {
      log += '님이 들어왔습니다.';
    } else if (el.action === 'Leave') {
      log += '님이 나갔습니다.';
    }
    answer.push(log);
  });

  return answer;
}

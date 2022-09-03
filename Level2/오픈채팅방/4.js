function solution(record) {
  const users = {},
    rooms = {};

  function doUserAction(action, uid, name) {
    if (action === 'Enter' || action === 'Change') {
      users[uid] = name;
    }

    if (action === 'Enter') {
      rooms[uid] = true;
    } else if (action === 'Leave') {
      rooms[uid] = false;
    }
  }

  function getActionLog(action, uid, name) {
    if (action === 'Enter') {
      return `${users[uid]}님이 들어왔습니다.`;
    } else if (action === 'Leave') {
      return `${users[uid]}님이 나갔습니다.`;
    }
  }

  record.forEach((r) => {
    const [action, uid, name] = r.split(' ');

    doUserAction(action, uid, name);
  });

  return record
    .map((r) => {
      const [action, uid, name] = r.split(' ');

      return getActionLog(action, uid, name);
    })
    .filter(Boolean);
}

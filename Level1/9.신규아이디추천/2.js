function step1(id) {
  return id.toLowerCase();
}

function step2(id) {
  const regex = /[^a-z\.0-9-_]/g;
  return id.replace(regex, '');
}

function step3(id) {
  const regex = /(\.)+/g;

  return id.replace(regex, '.');
}

function step4(id) {
  if (id[0] === '.') {
    id = id.slice(1);
  }
  if (id[id.length - 1] === '.') {
    id = id.slice(0, -1);
  }

  return id;
}

function step5(id) {
  if (id === '') {
    return 'a';
  }
  return id;
}

function step6(id) {
  if (id.length >= 16) {
    id = id.slice(0, 15);

    if (id[id.length - 1] === '.') {
      id = id.slice(0, -1);
    }
  }

  return id;
}

function step7(id) {
  if (id.length <= 2) {
    const lastChar = id[id.length - 1];
    while (id.length < 3) {
      id += lastChar;
    }
  }
  return id;
}

function solution(new_id) {
  let answer = new_id;
  answer = step1(answer);
  answer = step2(answer);
  answer = step3(answer);
  answer = step4(answer);
  answer = step5(answer);
  answer = step6(answer);
  answer = step7(answer);
  return answer;
}

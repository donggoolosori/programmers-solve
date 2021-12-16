function replaceFunc(s) {
  switch (s) {
    case 'C#':
      return 'J';
    case 'D#':
      return 'K';
    case 'F#':
      return 'L';
    case 'G#':
      return 'M';
    case 'A#':
      return 'N';
    default:
      return s;
  }
}

function getMin(s) {
  const [strH, strM] = s.split(':');
  return parseInt(strH) * 60 + parseInt(strM);
}

function compare(a, b) {
  return b.playMin - a.playMin;
}

function solution(m, musicinfos) {
  m = m.replace(/\w#/g, replaceFunc);

  const regex = new RegExp(m);

  const candidates = [];

  musicinfos.forEach((info) => {
    let [start, end, title, melody] = info.split(',');
    melody = melody.replace(/\w#/g, replaceFunc);

    const playMin = getMin(end) - getMin(start);

    let fullMelody;
    if (melody.length > playMin) {
      fullMelody = melody.slice(0, playMin);
    } else {
      fullMelody = melody.padEnd(playMin, melody);
    }

    if (regex.test(fullMelody)) {
      candidates.push({ playMin, title });
    }
  });

  if (candidates.length === 0) return '(None)';

  return candidates.sort(compare)[0].title;
}

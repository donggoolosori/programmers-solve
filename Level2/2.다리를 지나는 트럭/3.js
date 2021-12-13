function solution(bridge_length, weight, truck_weights) {
  const on = [{ outTime: 0, w: 0 }],
    waiting = [...truck_weights];
  let time = 0,
    weightOnBridge = 0;

  while (on.length > 0 || waiting.length > 0) {
    if (on[0].outTime === time) {
      weightOnBridge -= on.shift().w;
    }

    if (weightOnBridge + waiting[0] <= weight) {
      weightOnBridge += waiting[0];
      on.push({ w: waiting.shift(), outTime: time + bridge_length });
    } else {
      if (on[0]) {
        time = on[0].outTime - 1;
      }
    }
    time++;
  }

  return time;
}

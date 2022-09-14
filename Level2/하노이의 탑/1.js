function solution(n) {
    const ret = [];

    function hanoi(num, fr, to, other) {
        if (num === 0) {
            return;
        }

        hanoi(num - 1, fr, other, to);
        ret.push([fr, to]);
        hanoi(num - 1, other, to, fr);
    }

    hanoi(n, 1, 3, 2);

    return ret;
}

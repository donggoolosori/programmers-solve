def solution(name, yearning, photo):
    n_to_y = dict(zip(name, yearning))

    return [sum(n_to_y[n] for n in p if n in n_to_y) for p in photo]

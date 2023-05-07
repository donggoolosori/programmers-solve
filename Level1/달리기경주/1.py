def solution(players, callings):
    # players를 answer에 복사
    answer = players[:]
    # key:value = 이름:현재순위 dictionary 생성
    playerToRank = {player: index for index, player in enumerate(players)}
    # callings를 순회하며 이름의 선수를 앞사람과 swap 한다
    for calling in callings:
        rank = playerToRank[calling]
        loser = answer[rank - 1]

        playerToRank[calling], playerToRank[loser] = rank - 1, rank
        answer[rank], answer[rank - 1] = answer[rank - 1], answer[rank]

    return answer

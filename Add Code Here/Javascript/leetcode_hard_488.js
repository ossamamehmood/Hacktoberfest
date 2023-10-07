/**
 * @param {string} board
 * @param {string} hand
 * @return {number}
 */

 var findMinStep = function(board, hand) {
    let map = new Map();
    for(let c of hand){
        if(map.has(c)) map.set(c, map.get(c) + 1);
        else map.set(c, 1);
    }
    let res = helper(board, map);
    return res === Infinity ? -1 : res;
};

var helper = function(board, map){
    if(board === "") return 0;
    let i = 0, res = Infinity;
    while(i < board.length){
        let j = i;
        while(j < board.length && board[j] === board[i]) j++;
        let need = Math.max(0, 3 - (j - i));
        if(map.has(board[i]) && map.get(board[i]) >= need){
            let count = map.get(board[i]);
            map.set(board[i], count - need);
            let boardNew = updateBoard(board.substring(0, i) + board.substring(j));
            res = Math.min(res, helper(boardNew, map) + need);
            map.set(board[i], count);
        }
        i = j;
    }
    return res;
};

var updateBoard = function(board){
    let i = 0;
    while(i < board.length){
        let j = i;
        while(j < board.length && board[j] === board[i]) j++;
        if(j - i >= 3) return updateBoard(board.substring(0, i) + board.substring(j));
        else i = j;
    }
    return board;
};
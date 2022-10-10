function sieve_of_sunduram (n) {
    if (n < 3) {
        if (n < 2) return 0
        else return 1;
    }
    
    let k = (n - 1) / 2;

    let array = new Array(n + 1).fill(false);
    let primes = [];

    for (let i = 1; i <= k; i++) {
        for (let j = i; (i + j + 2 * i * j) <= k; j++) {
            array[i + j + 2 * i * j] = true;
        }
    }

    for (let i = 1; i <= k; i++) {
        if (array[i] == false) {
            primes.push(2 * i + 1);
        }
    }

    return primes;
}

function calcPrimes(digits) {
    if (!digits) throw new Error('Need digits to calculate to.');

	let array = new Array(digits + 1).fill(true);
    let final = [];
    array[0] = false;
    array[1] = false;
	
	for (let i = 2; i <= Math.sqrt(digits); i++) {
		if (array[i]) {
			for(let j = i * 2; j <= digits; j += i) {
				array[j] = false;
			}
		}
	}
	
    for (let i = 2; i <= digits; i++) {
		if (array[i]) {
            final.push(i);
        }
	}	
	return final;
}

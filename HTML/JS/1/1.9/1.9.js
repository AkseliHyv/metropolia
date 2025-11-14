function isPrime() {
    const num = parseInt(prompt("Give a number:"));
    let isPrime = true;

    if (num <= 1) {
        isPrime = false;
    } else {
        for (let i = 2; i < num; i++) {
            if (num % i === 0) {
                isPrime = false;
                break;
            }
        }
    }

    document.getElementById("target").innerHTML = isPrime ? `Number ${num} is prime!` : `Number ${num} is not a prime.`;
}

isPrime();


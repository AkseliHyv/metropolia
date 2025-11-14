function calculateSquareRoot() {
    const choice = confirm("Should I calculate the square root?");

    if (choice === true) {
        const number = parseInt(prompt("Give a number:"));

        if (number < 0) {
            document.getElementById("target").innerHTML = "The square root of a negative number is not defined.";
            return;
        }
        
        const sqrt = Math.sqrt(number).toFixed(2);
        document.getElementById("target").innerHTML = `The square root of ${number} is ${sqrt}.`;
    }
    else {
        document.getElementById("target").innerHTML = "The square root is not defined.";
    }
}

calculateSquareRoot();


let numbers = [];
while (true) {
    let number = parseInt(prompt("Enter a number:"));

    if (number in numbers) {
        alert("Number already entered, stopping.");
        break;
    } else {
        numbers.push(number);
    }
}

numbers.sort((a,b) => a-b);
for (let num of numbers) {
    console.log(num);
}


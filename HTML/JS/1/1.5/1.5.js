function isLeapYear() {
    const year = parseInt(prompt("Give a year:"));
    const li = document.createElement("li");

    if ((year % 4 === 0 && year % 100 != 0) || year % 400 === 0) {
        li.innerHTML = `The year ${year} is a leap year!`;
    }
    else {
        li.innerHTML = `The year ${year} is not a leap year.`;
    }

    document.getElementById("target").appendChild(li);
}

isLeapYear();


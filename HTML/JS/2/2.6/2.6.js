function rollDice() {
    return Math.floor(Math.random() * 6) + 1;
}

let roll = 0;
let rolls = [];
while (roll !== 6) {
    roll = rollDice();
    rolls.push(roll);
}

for (let roll of rolls) {
    const li = document.createElement("li");
    li.innerHTML = roll;
    document.getElementById("target").appendChild(li);
}


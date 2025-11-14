function rollDice(faces) {
    return Math.floor(Math.random() * faces) + 1;
}

const faces = parseInt(prompt("Enter the number of faces on the dice:"));

let roll = 0;
let rolls = [];
while (roll !== faces) {
    roll = rollDice(faces);
    rolls.push(roll);
}

for (let roll of rolls) {
    const li = document.createElement("li");
    li.innerHTML = roll;
    document.getElementById("target").appendChild(li);
}


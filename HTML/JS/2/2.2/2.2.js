const participants_amount = parseInt(prompt("Enter number of participants:"));
let participants = [];

for (let i = 0; i < participants_amount; i++) {
    participants.push(prompt(`Enter name of participant ${i + 1}:`));
}
participants.sort();

const ol = document.getElementById("target");
for (let participant of participants) {
    const li = document.createElement("li");
    li.innerHTML = participant;
    ol.appendChild(li);
}


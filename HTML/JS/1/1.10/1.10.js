function getProbability() {
    const num_of_dice = parseInt(prompt("How many dice:"));
    const wanted_sum = parseInt(prompt("Wanted sum:"));

    if (num_of_dice * 6 < wanted_sum || num_of_dice > wanted_sum) {
        alert("Wanted sum of dice is impossible to get!");
        return;
    }

    let rolls = 0;
    let hits = 0;
    let keep_rolling = true;
    while (keep_rolling) {
        for (let i = 0; i < 10000; i++) {
            let sum = 0;
            for (let j = 0; j < num_of_dice; j++) {
                sum += Math.floor(Math.random() * 6 + 1)
            }
            if (sum === wanted_sum) hits++;
        }

        rolls += 10000;

        if (hits === 0) {
            keep_rolling = confirm("No hits in 10 000 rolls, do you want to keep rolling?");
        }
        else {
            keep_rolling = false;
        }
    }
    

    const chance = (hits / rolls) * 100;
    document.getElementById("target").innerHTML = `Chance to get ${wanted_sum} by rolling ${num_of_dice} dice: ${chance.toFixed(2)}%`;
}

getProbability();


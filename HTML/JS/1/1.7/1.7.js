function roll() {
    const target = document.getElementById("target");
    target.innerHTML = "";
    
    const rolls = parseInt(prompt("Give number of dice rolls:"))
    let sum = 0
    
    for (let i = 0; i < rolls; i++) {
        dice_roll = Math.floor(Math.random() * 6 + 1)
        sum += dice_roll
        target.innerHTML += `Dice ${i + 1}: ${dice_roll}<br>`
    }

    target.innerHTML += `Sum of all dice: ${sum}`
}

roll()


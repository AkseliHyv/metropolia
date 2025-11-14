function getHouse() {
    const input = prompt("What is your name?");
    const rand = Math.floor(Math.random() * 4);
    let house = "";

    switch (rand) {
        case 0:
            house = "Gryffindor";
            break;
        case 1:
            house = "Slytherin";
            break;
        case 2:
            house = "Huffelpuff";
            break;
        case 3:
            house = "Ravenclaw";
            break;
        default:
            house = "Muggle";
    }

    document.getElementById("target").innerHTML = `${input}, you are a ${house}!`;
}

getHouse();


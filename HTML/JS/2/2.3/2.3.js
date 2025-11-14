dogs = [];
for (let i = 0; i < 6; i++) {
    dogs.push(prompt("Enter a dog name:"));
}

dogs.sort().reverse();

const ul = document.getElementById("target");
for (let dog of dogs) {
    const li = document.createElement("li");
    li.innerHTML = dog;
    ul.appendChild(li);
}


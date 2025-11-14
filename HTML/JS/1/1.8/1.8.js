const target = document.getElementById("target");

start_year = parseInt(prompt("Give start year:"));
end_year = parseInt(prompt("Give end year:"));

for (let i = start_year; i < end_year; i++) {
    if ((i % 4 === 0 && i % 100 != 0) || i % 400 === 0) {
        const li = document.createElement("li");
        li.innerHTML = i;
        target.appendChild(li);
    }
}


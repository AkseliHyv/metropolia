const int1 = parseInt(prompt("Give first integer:"));
const int2 = parseInt(prompt("Give second integer:"));
const int3 = parseInt(prompt("Give third integer:"));

document.getElementById("sum").innerHTML += int1 + int2 + int3;
document.getElementById("product").innerHTML += int1 * int2 * int3;
document.getElementById("average").innerHTML += (int1 + int2 + int3) / 3;


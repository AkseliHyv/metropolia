let num = 1;
let nums = [];
while (num !== 0) {
    num = parseInt(prompt("Enter a number (0 to stop):"));
    if (num !== 0) {
        nums.push(num);
    }
}

nums.sort((a,b) => a-b);

for (let num of nums) {
    console.log(num);
}


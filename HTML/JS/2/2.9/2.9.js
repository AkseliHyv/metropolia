function even(numbers) {
    let evens = [];
    for (let num of numbers) {
        if (num % 2 === 0) {
            evens.push(num);
        }
    }
    return evens;
}

const nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15];
const evenNumbers = even(nums);
console.log(nums, evenNumbers);


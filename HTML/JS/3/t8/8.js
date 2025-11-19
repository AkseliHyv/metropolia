const button  = document.querySelector('#start');

button.addEventListener('click', () => {
    const val1 = document.querySelector('#num1').value;
    const val2 = document.querySelector('#num2').value;
    const operation = document.querySelector('#operation').value;
    let result;

    switch (operation) {
        case 'add':
            result = Number(val1) + Number(val2);
            break;
        case 'sub':
            result = Number(val1) - Number(val2);
            break;
        case 'multi':
            result = Number(val1) * Number(val2);
            break;
        case 'div':
            result = Number(val1) / Number(val2);
            break;
        default:
            result = 'Unknown operation';
    }

    document.querySelector('#result').textContent = `Result: ${result}`;
});
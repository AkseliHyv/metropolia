const button = document.querySelector('#start');

function getAnswer(param, leftval, rightval) {
    let answer = 0;
    switch (param) {
        case '+':
            answer += Number(leftval) + Number(rightval);
            break;
        case '-':
            answer += Number(leftval) - Number(rightval);
            break;
        case '*':
            answer += Number(leftval) * Number(rightval);
            break;
        case '/':
            answer += Number(leftval) / Number(rightval);
            break;
        default:
            answer = 'Unknown operation';
    }

    return answer;
}

button.addEventListener('click', () => {
    const input = document.querySelector('#calculation').value;
    const parsed = input.split(/([/\*\+\-])/);
    
    // Set up variables for calculation
    let leftval = '';
    let rightval = '';
    let param = '';
    let adding_to_left = true;

    // Parse the input into left and right values, and the operator
    for (let i = 0; i < parsed.length; i++) {
        // Check if the current item is an operator, if so switch the adding target
        if (['/', '*', '+', '-'].includes(parsed[i])) {
            adding_to_left = !adding_to_left;
            param = parsed[i];
            continue;
        }

        // Add the current number to the appropriate side
        if (adding_to_left) leftval += parsed[i];
        else rightval += parsed[i];
    }

    // Perform calculation
    let answer = getAnswer(param, leftval, rightval);
    document.querySelector('#result').textContent = answer;
});
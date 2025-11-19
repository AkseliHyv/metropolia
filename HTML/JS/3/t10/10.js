const submit = document.querySelector('#source');
const target = document.querySelector('#target');

submit.addEventListener('submit', (event) => {
    event.preventDefault();

    const formData = new FormData(submit);
    const firstName = formData.get('firstname');
    const lastName = formData.get('lastname');

    target.textContent = `Your name is ${firstName} ${lastName}`;
});
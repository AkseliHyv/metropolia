const form = document.querySelector('form');
const target = document.querySelector('#results');
form.addEventListener('submit', (event) => getJoke(event))

async function getJoke(event) {
    event.preventDefault();
    const formData = new FormData(form);
    const query = formData.get('q');
    const response = await fetch(`https://api.chucknorris.io/jokes/search?query=${query}`);
    const result = await response.json();

    target.innerHTML = '';
    for (let i = 0; i < result.total; i++) {
        showJoke(result.result[i])
    }
}

function showJoke(joke) {
    const article = document.createElement('article');

    const p = document.createElement('p');
    p.innerText = joke.value;

    article.appendChild(p);
    target.appendChild(article);
}
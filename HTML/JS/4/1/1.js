const form = document.querySelector('form');
const target = document.querySelector('#results');
form.addEventListener('submit', (event) => handleQuery(event))

async function handleQuery(event) {
    event.preventDefault();
    const formData = new FormData(form);
    const query = formData.get('q');

    const response = await fetch(`https://api.tvmaze.com/search/shows?q=${query}`)
    const result = await response.json();

    target.innerHTML = '';
    for (let i = 0; i < result.length; i++) {
        displayShow(result[i]);
    }
}

function displayShow(tvShow) {
    const article = document.createElement('article');

    const h2 = document.createElement('h2');
    h2.innerText = tvShow.show.name;

    const a = document.createElement('a');
    a.target = '_blank';
    a.href = tvShow.show.url;
    a.innerHTML = '<br>Link to show';

    const medimage = document.createElement('img');
    medimage.src = tvShow.show.image != null ? tvShow.show.image.medium : 'https://placehold.co/210x295?text=Not%20Found';
    medimage.alt = tvShow.show.name;

    const summary = document.createElement('div');
    summary.innerHTML = tvShow.show.summary;
    summary.id = 'summary'

    article.appendChild(h2);
    article.appendChild(medimage);
    article.appendChild(a);
    article.appendChild(summary);

    target.appendChild(article);
}
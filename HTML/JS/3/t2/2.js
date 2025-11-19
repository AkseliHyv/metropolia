const list = ['First item', 'Second item', 'Third item'];

for (let i = 0; i < list.length; i++) {
    const li = document.createElement('li');
    li.textContent = list[i];
    if (i == 1) li.classList.add('my-item');
    document.querySelector('#target').appendChild(li);
}
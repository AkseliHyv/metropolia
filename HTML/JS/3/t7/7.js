const hover = document.querySelector('#trigger');
const img = document.querySelector('#target');

hover.addEventListener('mouseenter', () => {
    img.src = './img/picB.jpg';
});

hover.addEventListener('mouseleave', () => {
    img.src = './img/picA.jpg';
});
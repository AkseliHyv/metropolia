'use strict';
const students = [
  {
    name: 'John',
    id: '2345768',
  },
  {
    name: 'Paul',
    id: '2134657',
  },
  {
    name: 'Jones',
    id: '5423679',
  },
];

for (let i = 0; i < students.length; i++) {
  const option = document.createElement('option');
  option.textContent = `${students[i].name}`;
  option.value = students[i].id;
  document.querySelector('#target').appendChild(option);
}
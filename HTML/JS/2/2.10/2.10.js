const num_of_candidates = parseInt(prompt("Enter number of candidates:"));
let candidates = [];
for (let i = 0; i < num_of_candidates; i++) {
    let name = prompt(`Enter name of candidate ${i + 1}:`);
    candidates.push({name: name, votes: 0});
}

const voters = parseInt(prompt("Enter number of voters:"));
for (let i = 0; i < voters; i++) {
    let vote = prompt("Enter the name of the candidate you want to vote for:");
    for (let candidate of candidates) {
        if (vote === candidate.name) {
            candidate.votes += 1;
        }
    }
}

candidates.sort((a,b) => {console.log(a, b); return b.votes - a.votes});

for (let candidate of candidates) {
    if (candidates[0] === candidate) {
        console.log(`The winner is ${candidate.name} with ${candidate.votes} votes.`);
    }
    console.log(`${candidate.name}: ${candidate.votes} votes`);
}


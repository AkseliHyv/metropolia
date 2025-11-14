function concat(list) {
    let concat_string = "";
    for (let name of list) {
        concat_string += name;
    }

    return concat_string;
}

const list_names = ["Alice", "Bob", "Charlie", "Diana", "Eve", "Frank", "Grace", "Hannah", "Ivan", "Judy"];
document.getElementById("target").innerHTML = concat(list_names);


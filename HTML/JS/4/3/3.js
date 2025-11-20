const form = document.querySelector('form');
let map;
let homeMarker;
let currentMarker;

form.addEventListener('submit', (event) => newLocation(event));

async function getLatLon(address) {
    const response = await fetch(`https://nominatim.openstreetmap.org/search?format=json&q=${address}`);
    const result = await response.json();

    return result[0]
}

async function newLocation(event) {
    event.preventDefault();
    const formData = new FormData(form);
    const address = formData.get('address');
    const new_loc = await getLatLon(address);

    // Set markers and fit map to bounds
    if (currentMarker) currentMarker.remove();

    currentMarker = L.marker([new_loc.lat, new_loc.lon]).addTo(map);

    map.fitBounds([
        homeMarker.getLatLng(),
        currentMarker.getLatLng()
    ]);
    console.log(new_loc);

    // Get transit data (utilizing existing homeMarker & currentMarker)
    // getTransitData();
}

async function getTransitData() {
    const response = await fetch("https://api.digitransit.fi/routing/v2/finland/gtfs/v1", {
        method: "POST",
        body: JSON.stringify({ placeholder: 'etc' }),
    });
}

async function initialize() {
    const homeloc = await getLatLon("Karaportti 2");
    map = L.map('map').setView([homeloc.lat, homeloc.lon], 15);
    homeMarker = L.marker([homeloc.lat, homeloc.lon]).addTo(map);

    L.tileLayer('https://tile.openstreetmap.org/{z}/{x}/{y}.png', {
        maxZoom: 19,
        attribution: '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
    }).addTo(map);
}

initialize();
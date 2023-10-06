const searchInput = document.querySelector("#searchInput");
const searchButton = document.querySelector("#searchButton");
const weatherIcon = document.querySelector("#weatherIcon");
const windSpeed = document.querySelector("#windSpeed");
const humidity = document.querySelector(".humidity");
const weather = document.querySelector(".weather");
const desc = document.querySelector(".desc");
const API = "8cf5ac5621c8d0266298a149e49d7514";

const setWeatherIcon = (weatherMain) => {
    const icons = {
        'Clouds': 'https://cdn-icons-png.flaticon.com/128/1146/1146869.png',
        'Clear': 'https://cdn-icons-png.flaticon.com/128/3222/3222807.png',
        'Rain': 'https://cdn-icons-png.flaticon.com/128/2864/2864448.png',
        'Mist': 'https://cdn-icons-png.flaticon.com/128/4005/4005901.png',
        'Snow': 'https://cdn-icons-png.flaticon.com/128/2315/2315377.png',
        'Haze': 'https://cdn-icons-png.flaticon.com/128/1197/1197102.png',
    };

    weatherIcon.src = icons[weatherMain] || '';
};

const setWeatherDetails = (data) => {
    desc.innerHTML = data.weather[0].description;
    weather.innerHTML = Math.round(data.main.temp - 273.15) + "°c";
    humidity.innerHTML = data.main.humidity + "%";
    windSpeed.innerHTML = data.wind.speed + "km/h";
    setWeatherIcon(data.weather[0].main);
};

const callAPI = (id) => {
    fetch(`https://api.openweathermap.org/data/2.5/weather?q=${searchInput.value}&appid=${id}`)
        .then(response => {
            if (!response.ok) {
                alert("Check spelling of City and try again or Something Went Wrong!");
                throw new Error(`Request failed with status ${response.status}`)
            }
            return response.json();
        })
        .then(data => {
            setWeatherDetails(data);
        })
        .catch(error => console.log(error))
}

searchButton.addEventListener("click", (e) => {
    if (searchInput.value == "") {
        alert("Please Enter City Name.");
    } else {
        callAPI(API);
    }
});

searchInput.addEventListener("keypress", (e) => {
    if (e.key === "Enter") {
        e.preventDefault();
        searchButton.click();
    }
});

searchButton.click();

"use strict";

let search = document.querySelector(".search");
let output = document.querySelector(".output");
let temperature = document.getElementById("temperature");
let img = document.getElementById("img");
let description = document.getElementById("description");

const apiKey = "067e7a286e6c04ab88973031b8f4ffae";

async function main(location) {
  // Fetching and Storing data
  const response = await fetch(
    `https://api.openweathermap.org/data/2.5/weather?q=${location}&appid=${apiKey}&units=metric`
  );
  const data = await response.json();

  // Updating UI
  temperature.textContent = data.main.temp + `\u00B0C`;
  description.textContent = data.weather[0].description;
  img.src = "http://openweathermap.org/img/wn/" + data.weather[0].icon + ".png";
  output.style.opacity = 1;
}

search.addEventListener("click", (e) => {
  const child = e.target.matches(".checked");
  if (child) {
    let location = document.getElementById("location");

    if (location.value != "") {
      main(location.value);
    }
  }
});

/*document.addEventListener("keypress", (e) => {
  if (e.keyCode == 13) {
    let location = document.getElementById("location");

    if (location.value != "") {
      main(location.value);
    }
  }
});
*/

let userTab = document.querySelector("[data-userWeather]");
let searchTab = document.querySelector("[data-searchWeather]");
const userContainer = document.querySelector(".weather-conatiner");

const grantAccessContainer = document.querySelector(".grant-location-container");
const searchForm = document.querySelector("[data-searchFrom]");
const loadingScreen = document.querySelector(".loading-container");
const userInfoContainer = document.querySelector(".user-info-container");
const grantAccessButton = document.querySelector("[data-grantAccess]");
const pageNotFOund = document.querySelector("#page");
const page404 = document.querySelector("#page404");

//intially need og variables

let currentTab = userTab;
let API_KEY = "d1845658f92b31c64bd94f06f7188c9c";
currentTab.classList.add("current-tab");
getfromSessionStorage()

//lisi ek tab ko open karne ke liye we need a function that helps to jump between to section
function switchtab(clickedTab) {
  if (clickedTab != currentTab) {
    currentTab.classList.remove("current-tab");
    currentTab = clickedTab;
    currentTab.classList.add("current-tab");

    if (!searchForm.classList.contains("active")) {
      userInfoContainer.classList.remove("active");
      grantAccessContainer.classList.remove("active");
      searchForm.classList.add("active");
    
    } else {
      page404.style.opacity = 0;
      page404.style.zIndex = "-1";
      searchForm.classList.remove("active");
      userInfoContainer.classList.remove("active");
      getfromSessionStorage();
    }
  }
}

userTab.addEventListener("click", () => {
  //passed clicked tab
  switchtab(userTab);
});

searchTab.addEventListener("click", () => {
  switchtab(searchTab);
});

//this function check if user cordinets are stored in session storage

function getfromSessionStorage() {
  const localCoordinates = sessionStorage.getItem("user-coordinates");
  if (!localCoordinates) {
    grantAccessContainer.classList.add("active");
  } else {
    const coordinates = JSON.parse(localCoordinates);
    fetchUserWeatherInfo(coordinates);
  }
}

//function which is used to get the weather data from api using latitude and longitude

async function fetchUserWeatherInfo(coordinates ) {
  const { lat, lone } = coordinates;

  //male grantContainer invisible
  grantAccessContainer.classList.remove("active");

  //make loadervisible

  loadingScreen.classList.add("active");

  //API Call
  try {
    const response = await fetch(
      `https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lone}&appid=${API_KEY}&units=metric`
    );
    const data = await response.json();
    loadingScreen.classList.remove("active");
    userInfoContainer.classList.add("active");
    renderWeatherInfo(data);

  } catch (error) {
    loadingScreen.classList.remove("active")
    console.log("bhai saab code LOL", error);
  }
}

function renderWeatherInfo(weatherInfo) {
  //firstly fetch elements

  const cityName = document.querySelector("[data-cityName]")
  const countryIcon = document.querySelector("[data-countryIcon]")
  const desc = document.querySelector("[data-weatherDesc]")

  const weatherIcon = document.querySelector("[data-weatherIcon]")
  const temp = document.querySelector("[data-temp]")
  const windspeed = document.querySelector("[data-windspeed]")
  const humidity = document.querySelector("[data-humidity]")
  const cloudiness = document.querySelector("[data-cloudiness]")

  //fetch values from weather info object
  cityName.innerHTML = weatherInfo?.name;
  countryIcon.src = `https://flagcdn.com/144x108/${weatherInfo?.sys?.country.toLowerCase()}.png`;
  desc.innerText = weatherInfo?.weather?.[0]?.description;
  weatherIcon.src = `http://openweathermap.org/img/w/${weatherInfo?.weather?.[0]?.icon}.png`;
  temp.innerText = `${weatherInfo?.main?.temp} °C`;
  windspeed.innerText = `${weatherInfo?.wind?.speed} m/s`;
  humidity.innerText = `${weatherInfo?.main?.humidity}%`;
  cloudiness.innerText = `${weatherInfo?.clouds?.all}%`;

}

function getLocation() {
    if(navigator.geolocation) {
        navigator.geolocation.getCurrentPosition(showPosition)
    }
    else {
        alert("no geolocation support available")
    }
}

function showPosition(position) {
  const userCoordinates = {
    lat: position.coords.latitude,
    lone: position.coords.longitude,
  }
   
  sessionStorage.setItem("user-coordinates", JSON.stringify(userCoordinates))
  fetchUserWeatherInfo(userCoordinates)

}
//button to access giolocation of user
grantAccessButton.addEventListener("click", getLocation)


const searchInput = document.querySelector("[data-searchInput]")

searchForm.addEventListener("submit",(e) => {
    e.preventDefault();
    let cityName = searchInput.value;

    if(cityName === "") {
        return;
    }
    else {
        fetchSearchWeatherInfo(cityName)
    }
})
 
async function fetchSearchWeatherInfo(city) {
    loadingScreen.classList.add("active");
    userInfoContainer.classList.remove("active");
    grantAccessContainer.classList.remove("active");
    page404.style.opacity = 0;
    page404.style.zIndex = "-1";
    

     
       try {
        
        const response = await fetch(
          `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${API_KEY}&units=metric`
        );
        const data = await response.json();
        loadingScreen.classList.remove("active");
        if(data.cod  != "404"){
        userInfoContainer.classList.add("active");
        renderWeatherInfo(data);
       }
       else {
        page404.style.opacity = 1;
        page404.style.zIndex = "1";
       } 
      }
       catch (data) {
       
       }     
    
}




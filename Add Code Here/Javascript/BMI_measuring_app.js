const BMI_HEADS = document.querySelectorAll(".bmi-head");
const BMI_USC = document.getElementById("bmi-usc");
const BMI_SI = document.getElementById("bmi-si");
const CALC_BTN = document.getElementById("calc-btn");
const CLR_BTN = document.getElementById("clr-btn");
let activeForm;

// event listeners
window.addEventListener("DOMContentLoaded", () => {
  BMI_USC.classList.add("show-bmi");
  activeForm = "bmi-usc";
});

CALC_BTN.addEventListener("click", performBMICalc);
CLR_BTN.addEventListener("click", () => {
  let forms = [...document.forms];
  forms.forEach((form) => form.reset());
  clearBMIInfo();
});

//clear BMI Info
function clearBMIInfo() {
  document.getElementById("bmi-value").innerHTML = "";
  document.getElementById("bmi-category").innerHTML = "";
  document.getElementById("bmi-gender").innerHTML = "";
}

//bmi calculation form toggle
BMI_HEADS.forEach((bmiHead) => {
  bmiHead.addEventListener("click", () => {
    if (bmiHead.id === "bmi-usc-head") {
      removeActiveClass();
      clearBMIInfo();
      bmiHead.classList.add("active-head");
      BMI_SI.classList.remove("show-bmi");
      BMI_USC.classList.add("show-bmi");
      activeForm = "bmi-usc";
    }
    if (bmiHead.id === "bmi-si-head") {
      removeActiveClass();
      clearBMIInfo();
      bmiHead.classList.add("active-head");
      BMI_USC.classList.remove("show-bmi");
      BMI_SI.classList.add("show-bmi");
      activeForm = "bmi-si";
    }
  });
});

// remove active class from heads
function removeActiveClass() {
  BMI_HEADS.forEach((bmiHead) => {
    bmiHead.classList.remove("active-head");
  });
}

//main bmi calculation
function performBMICalc() {
  let BMIInfo = getUserInput();
  if (BMIInfo) printBMIResult(BMIInfo);
}

//get input values
function getUserInput() {
  let status;
  //get input from us units
  if (activeForm === "bmi-usc") {
    let age = document.getElementById("age1").value,
      gender = document.querySelector(
        '#bmi-usc input[name = "gender"]:checked'
      ).value,
      heightFeet = document.getElementById("feet").value,
      heightInches = document.getElementById("inches").value,
      weightPounds = document.getElementById("pounds").value;

    status = checkInputStatus([age, heightFeet, heightInches, weightPounds]);

    if (status == true) {
      return calculateBMI({
        gender,
        age,
        height: parseFloat(heightFeet) * 12 + parseFloat(heightInches),
        weight: parseFloat(weightPounds),
      });
    }
  }

  // get input values form metric uinits
  if (activeForm === "bmi-si") {
    let age = document.getElementById("age2").value,
      gender = document.querySelector(
        '#bmi-si input[name = "gender"]:checked'
      ).value,
      heightCm = document.getElementById("cm").value,
      weightKg = document.getElementById("kg").value;

    status = checkInputStatus([age, heightCm, weightKg]);

    if (status === true) {
      return calculateBMI({
        gender,
        age,
        height: parseFloat(heightCm) / 100,
        weight: parseFloat(weightKg),
      });
    }
  }
  document.querySelector(".alert-error").style.display = "block";
  setTimeout(() => {
    document.querySelector(".alert-error").style.display = "none";
  }, 1000);
  return false;
}

function checkInputStatus(inputs) {
  for (let i = 0; i < inputs.lenght; i++) {
    if (inputs[i].trim() === "" || isNaN(inputs[i])) return false;
  }
  return true;
}

//calculate BMI Value
function calculateBMI(values) {
  let BMI;
  if (activeForm === "bmi-usc") {
    BMI = (703 * (values.weight / Math.pow(values.height, 2))).toFixed(2);
  } else {
    BMI = (values.weight / Math.pow(values.height, 2)).toFixed(2);
  }
  return { gender: values.gender, BMI };
}

//print BMI result information
function printBMIResult(BMIInfo) {
  document.getElementById(
    "bmi-value"
  ).innerHTML = `${BMIInfo.BMI} kg/m<sup>2</sup>`;

  let bmiCategory;
  if (BMIInfo.BMI < 18.5) {
    bmiCategory = "Underweight";
  } else if (BMIInfo.BMI >= 18.5 && BMIInfo.BMI <= 24.9) {
    bmiCategory = "Normal Weight";
  } else if (BMIInfo.BMI >= 25 && BMIInfo.BMI <= 29.9) {
    bmiCategory = "Overweight";
  } else {
    bmiCategory = "Obesity";
  }

  document.getElementById("bmi-category").innerHTML = `${bmiCategory}`;
  document.getElementById("bmi-gender").innerHTML = BMIInfo.gender;
}

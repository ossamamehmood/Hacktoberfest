//INSPIRATION 
//------------> https://dribbble.com/shots/3331288-Daily-UI-002-Credit-Card-Checkout
// loading after resources and depenednet resources have been loaded
window.addEventListener("load", () => {
  // forms
  let inputs = document.querySelectorAll("input");
  let ccList = document.querySelectorAll(".ccList li");
  let name = document.querySelector(".name");
  let year = document.querySelector(".year");
  let inputCon = document.querySelectorAll(".inputCon");
  let btn = document.querySelector('button');
  //credit card
  let cName = document.querySelector(".name");
  let cList = document.querySelector(".creditCard ul li");
  let cYear = document.querySelector(".creditCard .year");
  let length = inputs.length;
  let regExp = [/^[A-Za-z\'\s\.\,]+$/, /^4[0-9]{12}(?:[0-9]{3})?$/, /^[0-9]{3,4}$/];
  //focusing the text->function
  let fieldColor = i => {
    for (j = 0; j < inputCon.length; j++) {
      if (i == j) {
        inputCon[i].style.color = "rgb(64,146,181)";
      } else
      {
        inputCon[j].style.color = "rgb(193,193,193)";
      }
    }
  };
  let checkInput = i => {
    // Name
    if (i == 0) {
      if (inputs[0].value.match(regExp[0])) {
        cName.innerText = inputs[0].value;
        inputCon[0].style.color = "rgb(64,146,181)";
        inputs[0].style.borderBottomColor = "rgb(64,146,181)";
      } else
      if (inputs[0].value == "" || !inputs[0].value.match(regExp[0])) {
        cName.innerText = "";
        inputs[0].style.borderBottomColor = "red";
      }
    }

    //CCard NUmber
    if (i == 1) {
      if (inputs[1].value == "") {
        inputs[1].style.borderBottomColor = "red";
        cList.innerText = " ";
      } else
      {
        let cNumber = inputs[1].value;
        cNumber = cNumber.replace(/\s/g, "");
        if (Number(cNumber)) {
          cNumber = cNumber.match(/.{1,4}/g);
          cNumber = cNumber.join(" ");
          inputs[1].value = cNumber;
          if (cNumber.length <= 0) {
            cList.innerText = "";
          } else
          if (cNumber.length > 19) {
            cList.innerText = cNumber.substring(0, 20);
            inputs[1].style.borderBottomColor = "red";

          } else
          {
            cList.innerText = cNumber;
            inputs[1].style.borderBottomColor = "rgb(64,146,181)";
          }
        } else
        {
          inputs[1].style.borderBottomColor = "red";
        }
      }
    }
    // card Date
    else if (i == 2) {
        let dateValue = inputs[2].value;
        let d = dateValue.replace(/\s/g, "");
        // making sure its a number 
        if (Number(dateValue)) {
          d = dateValue.split("").map(i => {
            return parseInt(i, 10);
          });

          let date = new Date();
          let twoDigitYear = parseInt(date.getFullYear().toString().substr(2), 10);
          //the first two digit in the month field
          if (d.length == 2) {
            //checking for first
            if (d[0] == 0 && (d[1] !== 0 || d[1] <= 9) || d[0] == 1 && d[1] <= 2) {
              inputs[2].style.borderBottomColor = "rgb(64,146,181)";
              cYear.innerText = dateValue + "/";
            } else
            {
              inputs[2].style.borderBottomColor = "red";

            }
          } //End of Month
          else if (d.length == 4) {
              let twoDigitYearN = parseInt(d[2].toString().concat(d[3].toString()), 10);
              if (twoDigitYearN > twoDigitYear) {
                let stringDigit = twoDigitYearN.toString();
                cYear.innerText += stringDigit;
                inputs[2].value = cYear.innerText;
                inputs[2].style.borderBottomColor = "rgb(64,146,181)";
              } else
              {
                inputs[2].style.borderBottomColor = "red";
              }
            } //End of date + full date
        } //END of IF for [i = 2]
        else {
            cYear.innerText = "";
            inputs[2].style.borderBottomColor = "red";
          }
      }

    if (i == 3) {
      let cV = inputs[i].value;
      if (Number(cV) && cV.match(regExp[2])) {
        inputs[i].style.borderBottomColor = "rgb(64,146,181)";
      } else
      {
        inputs[3].style.borderBottomColor = "red";
      }
    }
  };
  //setting value initially in the card to that of placeholder
  cName.innerText = inputs[0].getAttribute('placeholder');
  cList.innerText = inputs[1].getAttribute('placeholder');
  cYear.innerText = inputs[2].getAttribute('placeholder'); //Adding Event Listeners
  for (i = 0; i < inputCon.length; i++) {
    inputs[i].addEventListener('click', fieldColor.bind(this, i));
    inputs[i].addEventListener('input', checkInput.bind(this, i));
  }
  btn.addEventListener('click', e => {
    e.preventDefault();
    for (i = 0; i < length; i++) {
      if (inputs[i].value == "") {
        inputs[i].style.borderBottomColor = "red";
      }
    }
    if (cList.innerText.length < 16) {
      inputs[1].style.borderBottomColor = "red";
    }
  });
});

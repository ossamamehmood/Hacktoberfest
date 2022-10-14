"use strict";
const getUserInput = () => document.getElementById("inputString").value;
const printInput = input =>
  (document.getElementById("ouput").innerHTML = input);
const cleanInput = str =>
  str
    .replace(/[?.!,"\(\)]/g, "")
    .replace(/[ ]{2,}/g, "")
    .trim()
    .toLowerCase();
const wordFreq = string =>
  string
    .split(/\s/)
    .reduce(
      (output, word) =>
        Object.assign(output, { [word]: output[word] ? output[word] + 1 : 1 }),
      {}
    );
const sortByValue = obj =>
  Object.entries(obj)
    .map(currentValue => [currentValue[1], currentValue[0]])
    .sort((a, b) => parseInt(b) - parseInt(a))
    .map((currentValue, index) => [
      index + 1,
      currentValue[0],
      currentValue[1]
    ]);

const divFreq = "div-table";
const headersFreq = ["Rank", "Count", "Word"];
const dataFreq = [[1, 52, "words"], [2, 50, "dog"]];

const addTable = (divId, headers, data) => {
  const myTableDiv = document.getElementById(divId);
  const table = document.createElement("table");

  //TABLE Headers
  const tr = document.createElement("tr");
  table.appendChild(tr);
  headers.forEach(currentValue => {
    const th = document.createElement("th");
    th.appendChild(document.createTextNode(currentValue));
    tr.appendChild(th);
  });

  //TABLE ROWS
  data.forEach(currentValue => {
    const tr = document.createElement("tr");
    currentValue.forEach(currentValue => {
      const td = document.createElement("td");
      td.appendChild(document.createTextNode(currentValue));
      tr.appendChild(td);
    });
    table.appendChild(tr);
  });

  myTableDiv.appendChild(table);
};

const processData = () => {
  const sortedFreq = sortByValue(wordFreq(cleanInput(getUserInput())));
  //console.table(sortedFreq);
  //let str = JSON.stringify(freq, null, 4);
  document.getElementById("div-table").innerHTML = "";
  addTable(divFreq, headersFreq, sortedFreq);
};

$(document).ready(function() {
  $("#myButton").on("click", processData);
});


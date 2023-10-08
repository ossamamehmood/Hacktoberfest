function add(x, y) {
  return x + y;
}

function subtract(x, y) {
  return x - y;
}

function multiply(x, y) {
  return x * y;
}

function divide(x, y) {
  if (y === 0) {
    return "Error: Division by zero!";
  }
  return x / y;
}

function calculate() {
  const input = prompt("Enter an expression (e.g., 2 + 3, sqrt 9, log 10):");
  const parts = input.split(" ");
  
  if (parts.length < 3) {
    console.log("Invalid input. Please use the format: operand1 operator operand2");
    return;
  }
  
  const num1 = parseFloat(parts[0]);
  const operator = parts[1];
  const num2 = parseFloat(parts[2]);
  
  let result;
  
  switch (operator) {
    case "+":
      result = add(num1, num2);
      break;
    case "-":
      result = subtract(num1, num2);
      break;
    case "*":
      result = multiply(num1, num2);
      break;
    case "/":
      result = divide(num1, num2);
      break;
    case "sqrt":
      result = Math.sqrt(num1);
      break;
    case "log":
      if (num1 <= 0 || num2 <= 0) {
        result = "Error: Invalid arguments for logarithm.";
      } else {
        result = Math.log(num1) / Math.log(num2);
      }
      break;
    default:
      console.log("Invalid operator. Please use +, -, *, /, sqrt, or log.");
      return;
  }
  
  console.log(`Result: ${result}`);
}

while (true) {
  calculate();
  const continueCalculation = prompt("Do you want to calculate again? (yes/no)").toLowerCase();
  if (continueCalculation !== "yes") {
    console.log("Goodbye!");
    break;
  }
}

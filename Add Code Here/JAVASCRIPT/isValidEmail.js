let isEmail = new RegExp('[a-z0-9]+@[a-z]+.[a-z]{2,3}');
let isGmail = new RegExp('[a-z0-9]+@gmail.com');

// Generic Email
function isValidEmail(email) {
  return regex.test(email);
}

// Only validates gmail addresses
function isGmail(email) {
  return isGmail.test(email);
}

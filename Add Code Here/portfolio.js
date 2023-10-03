// JavaScript for handling form submission
// Personal Portfolio Website (JavaScript for a contact form):
document.getElementById("contactForm").addEventListener("submit", function (e) {
    e.preventDefault();
    const name = document.getElementById("name").value;
    const email = document.getElementById("email").value;
    const message = document.getElementById("message").value;

    // You can customize the code to handle form data (e.g., send it via email or to a server).
    // For simplicity, we'll just log the data to the console.
    console.log("Name: " + name);
    console.log("Email: " + email);
    console.log("Message: " + message);
});

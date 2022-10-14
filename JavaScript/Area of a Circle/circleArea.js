function CalculateArea() {
    var radius = prompt("Please enter the Radius of Circle : ");
    alert("The area of the circle is " + (radius * radius * Math.PI));
    alert("The circumference of the circle is " + (2 * radius * Math.PI));

}

CalculateArea()
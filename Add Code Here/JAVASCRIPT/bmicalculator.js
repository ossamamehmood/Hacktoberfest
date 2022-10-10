function bmi()
{
    var w = parseFloat(document.getElementById("weight").value);  // To get weight from the input with id as weight
    var h = parseFloat(document.getElementById("height").value)/100; // Convert height to meters
    var b = w/(h*h);  // According to the formula
    document.getElementById("ans").value = String(b.toPrecision(3)) +" kg/m^2"; // writing to the output 
    if (b < 18.5)
    {
        document.getElementById("category").value = "Underweight";
    }
    else if (b >= 18.5 && b <= 25)
    {
        document.getElementById("category").value = "Healthy weight";
    }
    else if (b > 25 && b <= 30)
    {
        document.getElementById("category").value = "Overweight";
    }
    else if (b > 30 && b <= 35)
    {
        document.getElementById("category").value = "Obese Class 1";
    }
    else if(b > 35 && b <= 40)
    {
        document.getElementById("category").value = "Obese Class 2";
    }
    else
    {
        document.getElementById("category").value = "Obese Class 3";
    }
}

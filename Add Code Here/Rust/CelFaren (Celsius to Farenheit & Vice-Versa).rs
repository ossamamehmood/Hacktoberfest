#![allow(non_snake_case)]
use std::io;
fn main() {
    println!("--------------Temperature Converter--------------\n");
    println!("Select an Option");
    println!("1. Celsius To Farenheit\n2. Farenheit To Celsius");

    let mut option = String::new();
    let mut degree = String::new();
    io::stdin()
        .read_line(&mut option)
        .expect("Expected an integer");
    
    let input: u32 = option.trim().parse().expect("Expected Integers!");


    if input  == 1{
        println!("Enter Degree to be converted in Farenheit");
        io::stdin()
        .read_line(&mut degree)
        .expect("Something's not right");
        let degree_int: u32 = degree.trim().parse().expect("Expected Integers!");
        let farenheit = (degree_int as i32 * 9/5 as i32) + 32;
        println!("{degree_int}°C in Farenheit = {farenheit}°F");
        return;
    }
    else if input == 2 {
        println!("Enter Degree to be converted in Celsius");
        io::stdin()
        .read_line(&mut degree)
        .expect("Something's not right");
        let degree_int: u32 = degree.trim().parse().expect("Expected Integers!");
        let celsius = (degree_int as i32 - 32) * 5/9 as i32;
        println!("{degree_int}°F in Celcius = {celsius}°C");
        return;
    }
    else {
        println!("Invalid Option");
        return;
    }

}
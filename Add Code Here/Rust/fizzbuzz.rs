fn main() {
    let mut i: i32 = 0;

    while i < 100 {
        if i % 2 == 0 {
            println!("Fizz");
        } else {
            println!("Buzz");
        }
        i += 1;

    }
}

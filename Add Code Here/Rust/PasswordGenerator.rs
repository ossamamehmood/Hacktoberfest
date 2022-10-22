
//Password Generator Code using Rust// 
use rand::Rng;

const CHARSET: &[u8] = b"ABCDEFGHIJKLMNOPQRSTUVWXYZ\

abcdefghijklmnopqrstuvwxyz\

0123456789)(*&^%$#@!";

const LEN: i32 = 25;

fn main() {

let mut rng = rand::thread_rng();

let password: String = (0..LEN)

.map(|_| {

let idx = rng.gen_range(0..CHARSET.len());

CHARSET[idx] as char

})

.collect();

println!("Password: {}", password);

}
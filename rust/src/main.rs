/// Print a random line from stdin.

extern crate rand;

use std::io::{self, stdin, BufRead};
use rand::distributions::{IndependentSample, Range};
use rand::thread_rng;

fn main() {
    let input = stdin();
    let lines = input.lock().lines()
        .collect::<io::Result<Vec<String>>>()
        .expect("cannot read lines");
    let range = Range::new(0, lines.len());
    let mut rng = thread_rng();
    let index = range.ind_sample(&mut rng);
    println!("{}", lines[index]);
}

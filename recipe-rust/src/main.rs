mod ingredient;
mod item;

use ingredient::Ingredient;

fn main() {
    let i = Ingredient::new(
        "Flour".to_string(),
        1,       // unit
        500,     // quantity
        "All-purpose flour".to_string(),
        42,      // id
    );

        i.id();


}


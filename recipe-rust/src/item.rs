
pub struct Item {
    pub name : String,
    pub manufacturer : String
}
impl Item {

// Constructor to create a new Ingredient
    pub fn new(name : String, manufacturer : String) -> Self{
    Item {
        name,
        manufacturer
    }
}

}

pub struct Ingredient {
    pub name: String,
    pub unit: u64,
    pub quantity: u64,
    pub description: String,
    id: u64,
}
impl Ingredient {
    // Constructor to create a new Ingredient
    pub fn new(name: String, unit: u64, quantity: u64, description: String, id: u64) -> Self {
        Ingredient {
            name,
            unit,
            quantity,
            description,
            id,
        }
    }
    pub fn id(&self) -> u64 {
        self.id
    }

    pub fn set_id(&mut self, id: u64) {
        self.id = id
    }
}

package main



type Ingredient struct
{
    Name string
    Unit uint64
    Quantity uint64
    Description string
    id uint64 // private
}

  func NewIngredient(name string, unit uint64, quantity uint64, description string, id uint64) (*Ingredient, error) {
    return &Ingredient {
        Name : name,
        Unit : unit,
        Quantity : quantity,
        Description : description,
        id : id,
    }, nil
}




func (ingredient Ingredient) Id() uint64 {
  return ingredient.id
}

func (ingredient * Ingredient) SetId(uint64 id) uint64 {
  ingredient.id = id
}

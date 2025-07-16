package main



type Item struct
{
    Name string
    Manufacturer string
}

  func NewItem(name string, manufacturer string) (*Item, error) {
    return &Item {
        Name : name,
        Manufacturer : manufacturer,
    }, nil
}


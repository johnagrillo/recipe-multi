// Learn more about F# at http://docs.microsoft.com/dotnet/fsharp
// See the 'F# Tutorial' project for more help.


open recipe

// Define a function to construct a message to print
let from whom =
    sprintf "from %s" whom

    
    // ----- Enums -----

type Size =
    | Exact
    | Large
    | Medium
    | Small
    | Pinch
    | Bunch


type PreciseMeasurement =
    // Liquid units
    | Liter
    | Milliliter
    | Deciliter
    | Gallon
    | Quart
    | Pint
    | Cup
    | FluidOunce
    
    // Cooking volume units
    | Teaspoon
    | Tablespoon
    
    // Miscellaneous weight/mass units
    | Gram
    | Kilogram
    | Milligram
    | Microgram
    | Nanogram
    | Ounce
    | Pound

type QualitativeMeasurement =
    | Leaf
    | Floret
    | Head
    | Stalk

// ----- Fraction Type -----

type Fraction = {
    Numerator: int
    Denominator: int
}

// ----- Measure (only place where fractions are allowed) -----

type Measure =
    | Whole of int
    | Fractional of Fraction

// ----- Quantity Types -----

type Amount = {
    Value: Measure
    Unit: PreciseMeasurement
    Size: Size
}

type Qualitative = {
    Size: Size
    Measure: QualitativeMeasurement
}

type CountWithSize = {
    Count: int // must be int, no fractions allowed
    Size: Size
    Measure: QualitativeMeasurement
}

// ----- Quantity Union -----

type Quantity =
    | Amount of Amount
    | Qualitative of Qualitative
    | CountWithSize of CountWithSize


[<EntryPoint>]
let main argv =

   
    let sugar = { Name = "Sugar"; Unit = 10; Quantity=10; Description="food"}
    printfn "Ingredient: %s (%d)" sugar.Name sugar.Quantity
    0 // return an integer exit code




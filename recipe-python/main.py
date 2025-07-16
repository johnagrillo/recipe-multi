import yaml

from ingredient import Ingredient

# Load YAML from file
with open("../data/recipe.yaml", "r") as file:
    print(file)
    config = yaml.safe_load(file)

    print(config)

with open("../data/cats.yaml", "r") as file:
    print(file)
    config = yaml.safe_load(file)

    print(config)


ing = Ingredient("potatoes", "cup", 10, "")


print(ing)




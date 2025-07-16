require 'csv'


class Ingredient
  attr_accessor :name, :unit, :quantity, :description, :id

  def initialize(name, unit, quantity, description, id)
    @name = name
    @unit = unit
    @quantity = quantity
    @description = description
    @id = id
  end


  def to_csv()
   [
    @name,    
    @unit,    
    @quantity,    
    @description,    
    @id
   ].join(",")
  end

  def self.parse_csv_to_list(filename)
    objs = []
    CSV.foreach(filename, headers: true) do |row|
       objs << Ingredient.new(
          row['Name'], # name
          row['Unit'].to_i, # unit
          row['Quantity'].to_i, # quantity
          row['Description'], # description
          row['Id'].to_i, # id
     )
    end
    objs
  end
end

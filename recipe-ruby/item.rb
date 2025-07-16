require 'csv'


class Item
  attr_accessor :name, :manufacturer

  def initialize(name, manufacturer)
    @name = name
    @manufacturer = manufacturer
  end


  def to_csv()
   [
    @name,    
    @manufacturer
   ].join(",")
  end

  def self.parse_csv_to_list(filename)
    objs = []
    CSV.foreach(filename, headers: true) do |row|
       objs << Item.new(
          row['Name'], # name
          row['Manufacturer'], # manufacturer
     )
    end
    objs
  end
end

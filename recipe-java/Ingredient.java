package hytek.;

import com.opencsv.bean.CsvBindByName;

public class Ingredient {

    public Ingredient () {;}

    public Ingredient(String name, Long unit, Long quantity, String description, Long id ) {
        this.name = name;
        this.unit = unit;
        this.quantity = quantity;
        this.description = description;
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public Long getUnit() {
        return unit;
    }

    public Long getQuantity() {
        return quantity;
    }

    public String getDescription() {
        return description;
    }

    public Long getId() {
        return id;
    }

    @CsvBindByName(column = "Name")
    private String name;

    @CsvBindByName(column = "Unit")
    private Long unit;

    @CsvBindByName(column = "Quantity")
    private Long quantity;

    @CsvBindByName(column = "Description")
    private String description;

    @CsvBindByName(column = "Id")
    private Long id;
};

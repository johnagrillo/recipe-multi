package hytek.;

import com.opencsv.bean.CsvBindByName;

public class Item {

    public Item () {;}

    public Item(String name, String manufacturer ) {
        this.name = name;
        this.manufacturer = manufacturer;
    }

    public String getName() {
        return name;
    }

    public String getManufacturer() {
        return manufacturer;
    }

    @CsvBindByName(column = "Name")
    private String name;

    @CsvBindByName(column = "Manufacturer")
    private String manufacturer;
};

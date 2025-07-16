using System;
using System.Collections.Generic;
using System.Data.Odbc;
namespace db
{
namespace 
{


public class Item(string name, string manufacturer )
{
static public List<Item> Get(OdbcConnection connection)
{
  var collection = new List<Item>();
  string query = "select * from Item";
  using (OdbcCommand command = new OdbcCommand(query, connection))
  using (OdbcDataReader reader = command.ExecuteReader())
{
  while (reader.Read())
  {
      ///
      /// GetXX has to called in the same order as the sql order.
      /// Cant make these arguments to a constructor, since the order is indeterminate.
      ///
  var arg0 = reader.GetString(0); /* Name nullable false*/
  var arg1 = reader.GetString(1); /* Manufacturer nullable false*/
      collection.Add( new Item(arg0, arg1));
    }
  }
  return collection;
}
  // Properties
  public string Name{ get; } = name;
  public string Manufacturer{ get; } = manufacturer;
}
}
}

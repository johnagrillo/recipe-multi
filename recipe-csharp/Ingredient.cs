using System;
using System.Collections.Generic;
using System.Data.Odbc;
namespace db
{
namespace 
{


public class Ingredient(string name, long? unit, long? quantity, string description, long? id )
{
static public List<Ingredient> Get(OdbcConnection connection)
{
  var collection = new List<Ingredient>();
  string query = "select * from Ingredient";
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
  var arg1 = reader.IsDBNull(1) ? (long)null :reader.GetInt32(1); /* Unit nullable true*/
  var arg2 = reader.IsDBNull(2) ? (long)null :reader.GetInt32(2); /* Quantity nullable true*/
  var arg3 = reader.IsDBNull(3) ? (string?)null :reader.GetString(3); /* Description nullable true*/
  var arg4 = reader.IsDBNull(4) ? (long)null :reader.GetInt32(4); /* Id nullable true*/
      collection.Add( new Ingredient(arg0, arg1, arg2, arg3, arg4));
    }
  }
  return collection;
}
  // Properties
  public string Name{ get; } = name;
  public long? Unit{ get; } = unit;
  public long? Quantity{ get; } = quantity;
  public string Description{ get; } = description;
  public long? Id{ get; } = id;
}
}
}

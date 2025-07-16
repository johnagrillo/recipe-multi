#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>



#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <unordered_map>
#include <vector>

#include "ingredient.h"
#include "bhw/util.h"

namespace hytek::
{

using IngredientVec = std::vector<std::unique_ptr<hytek::tm::Ingredient>>;
using IngredientUniqueMap = std::unordered_map<uint64_t, std::unique_ptr<hytek::tm::Ingredient>>;
using IngredientPtrMap = std::unordered_map<uint64_t, hytek::tm::Ingredient*>;
using IngredientUniqueMapUnique = std::unique_ptr<std::unordered_map<uint64_t, std::unique_ptr<hytek::tm::Ingredient>>>;
using IngredientObjMap = std::unordered_map<uint64_t, hytek::tm::Ingredient>;

class IngredientDao
{
public:

  [[nodiscard]]
  static auto getVec(SQLHANDLE conn)
  {
    return bhw::FetchRows<IngredientVec, Ingredient>(conn, query);
  }

  [[nodiscard]]
  static auto getMap(SQLHANDLE conn)
  {
    return bhw::FetchRows<IngredientUniqueMap, Ingredient>(conn, query);
  }

  [[nodiscard]]
  static auto getObjMap(SQLHANDLE conn)
  {
    return bhw::FetchRowsObj<IngredientObjMap, Ingredient>(conn, query);
  }

  [[nodiscard]]
  static auto getUniqueMap(SQLHANDLE conn)
  {
    return bhw::FetchRowsUnique<IngredientUniqueMap, Ingredient>(conn, query);
  }

  [[nodiscard]]
  static auto getObjMapUnique(SQLHANDLE conn)
  {
    return bhw::FetchRowsObjUnique<IngredientUniqueMap, Ingredient>(conn, query);
  }

private:
  inline static const std::string query = R"lit(select Name,Unit,Quantity,Description,Id from Ingredient)lit"; 
};
}


#define WIN32_LEAN_AND_MEAN
#include <windows.h> // IWYU pragma: keep


#include "ingredient.h"

#include <memory>
#include <sqltypes.h>

#include "bhw/util.h"

namespace
{
constexpr int NAME_FIELD_NUM = 1;
constexpr int NAME_FIELD_LENGTH = ;
constexpr int UNIT_FIELD_NUM = 2;
constexpr int QUANTITY_FIELD_NUM = 3;
constexpr int DESCRIPTION_FIELD_NUM = 4;
constexpr int DESCRIPTION_FIELD_LENGTH = ;
constexpr int ID_FIELD_NUM = 5;
} // namespace

template<>
auto bhw::ReadObj(SQLHANDLE stmt) -> hytek::::Ingredient
{
  auto name = bhw::GetText(stmt, NAME_FIELD_NUM, NAME_FIELD_LENGTH);
  auto unit = bhw::GetLong(stmt, UNIT_FIELD_NUM);
  auto quantity = bhw::GetLong(stmt, QUANTITY_FIELD_NUM);
  auto description = bhw::GetText(stmt, DESCRIPTION_FIELD_NUM, DESCRIPTION_FIELD_LENGTH);
  auto id = bhw::GetLong(stmt, ID_FIELD_NUM);
  return hytek::::Ingredient::from({.name = name, .unit = unit, .quantity = quantity, .description = description, .id = id});
}
template<>
auto bhw::ReadUniquePtr(SQLHANDLE stmt) -> std::unique_ptr<hytek::::Ingredient>
{
  return std::make_unique<hytek::::Ingredient>(ReadObj<hytek::::Ingredient>(stmt));
}

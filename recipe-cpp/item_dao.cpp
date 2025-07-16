
#define WIN32_LEAN_AND_MEAN
#include <windows.h> // IWYU pragma: keep


#include "item.h"

#include <memory>
#include <sqltypes.h>

#include "bhw/util.h"

namespace
{
constexpr int NAME_FIELD_NUM = 1;
constexpr int NAME_FIELD_LENGTH = ;
constexpr int MANUFACTURER_FIELD_NUM = 2;
constexpr int MANUFACTURER_FIELD_LENGTH = ;
} // namespace

template<>
auto bhw::ReadObj(SQLHANDLE stmt) -> hytek::::Item
{
  auto name = bhw::GetText(stmt, NAME_FIELD_NUM, NAME_FIELD_LENGTH);
  auto manufacturer = bhw::GetText(stmt, MANUFACTURER_FIELD_NUM, MANUFACTURER_FIELD_LENGTH);
  return hytek::::Item::from({.name = name, .manufacturer = manufacturer});
}
template<>
auto bhw::ReadUniquePtr(SQLHANDLE stmt) -> std::unique_ptr<hytek::::Item>
{
  return std::make_unique<hytek::::Item>(ReadObj<hytek::::Item>(stmt));
}

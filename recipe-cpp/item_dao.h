#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>



#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <unordered_map>
#include <vector>

#include "item.h"
#include "bhw/util.h"

namespace hytek::
{

using ItemVec = std::vector<std::unique_ptr<hytek::tm::Item>>;
using ItemUniqueMap = std::unordered_map<uint64_t, std::unique_ptr<hytek::tm::Item>>;
using ItemPtrMap = std::unordered_map<uint64_t, hytek::tm::Item*>;
using ItemUniqueMapUnique = std::unique_ptr<std::unordered_map<uint64_t, std::unique_ptr<hytek::tm::Item>>>;
using ItemObjMap = std::unordered_map<uint64_t, hytek::tm::Item>;

class ItemDao
{
public:

  [[nodiscard]]
  static auto getVec(SQLHANDLE conn)
  {
    return bhw::FetchRows<ItemVec, Item>(conn, query);
  }

  [[nodiscard]]
  static auto getMap(SQLHANDLE conn)
  {
    return bhw::FetchRows<ItemUniqueMap, Item>(conn, query);
  }

  [[nodiscard]]
  static auto getObjMap(SQLHANDLE conn)
  {
    return bhw::FetchRowsObj<ItemObjMap, Item>(conn, query);
  }

  [[nodiscard]]
  static auto getUniqueMap(SQLHANDLE conn)
  {
    return bhw::FetchRowsUnique<ItemUniqueMap, Item>(conn, query);
  }

  [[nodiscard]]
  static auto getObjMapUnique(SQLHANDLE conn)
  {
    return bhw::FetchRowsObjUnique<ItemUniqueMap, Item>(conn, query);
  }

private:
  inline static const std::string query = R"lit(select Name,Manufacturer from Item)lit"; 
};
}

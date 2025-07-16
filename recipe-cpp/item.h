#pragma once

#include <chrono>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace hytek::
{

class Item 
{
public:
  Item() = delete;

    struct Init {std::string name;std::string manufacturer;};

    static auto from(Init init) -> Item    {
       return {std::move(init)};
    } 

    [[nodiscard]] auto getName() const noexcept -> std::string_view { return name_;} 
    [[nodiscard]] auto getManufacturer() const noexcept -> std::string_view { return manufacturer_;} 
    [[nodiscard]] auto getKey() const -> uint64_t {return getManufacturer();}

private:
  Item(Init&& init) : name_(std::move(init.name)), manufacturer_(std::move(init.manufacturer))
     {};

  std::string name_;
  std::string manufacturer_;
};
} //namespace

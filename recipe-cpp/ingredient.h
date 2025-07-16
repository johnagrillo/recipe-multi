#pragma once

#include <chrono>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace hytek::
{

class Ingredient 
{
public:
  Ingredient() = delete;

    struct Init {std::string name;uint64_t unit;uint64_t quantity;std::string description;uint64_t id;};

    static auto from(Init init) -> Ingredient    {
       return {std::move(init)};
    } 

    [[nodiscard]] auto getName() const noexcept -> std::string_view { return name_;} 
    [[nodiscard]] auto getUnit() const noexcept{ return unit_;} 
    [[nodiscard]] auto getQuantity() const noexcept{ return quantity_;} 
    [[nodiscard]] auto getDescription() const noexcept -> std::string_view { return description_;} 
    [[nodiscard]] auto getId() const noexcept{ return id_;} 
    [[nodiscard]] auto getKey() const -> uint64_t {return getName();}

private:
  Ingredient(Init&& init) : name_(std::move(init.name)), unit_(init.unit), quantity_(init.quantity), description_(std::move(init.description)), id_(init.id)
     {};

  std::string name_;
  uint64_t unit_;
  uint64_t quantity_;
  std::string description_;
  uint64_t id_;
};
} //namespace


from typing import List, Dict, Tuple, Union, Optional
from dataclasses import dataclass

import datetime

@dataclass
class Ingredient:
    name: str
    unit: int
    quantity: int
    description: str
    id: int

    @property
    def name(self):
        return self._name
    @name.setter
    def name(self, name):
        self._name = name

    @property
    def unit(self):
        return self._unit
    @unit.setter
    def unit(self, unit):
        self._unit = unit

    @property
    def quantity(self):
        return self._quantity
    @quantity.setter
    def quantity(self, quantity):
        self._quantity = quantity

    @property
    def description(self):
        return self._description
    @description.setter
    def description(self, description):
        self._description = description

    @property
    def id(self):
        return self._id
    @id.setter
    def id(self, id):
        self._id = id



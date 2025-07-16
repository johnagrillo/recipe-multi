
from typing import List, Dict, Tuple, Union, Optional
from dataclasses import dataclass

import datetime

@dataclass
class Item:
    name: str
    manufacturer: str

    @property
    def name(self):
        return self._name
    @name.setter
    def name(self, name):
        self._name = name

    @property
    def manufacturer(self):
        return self._manufacturer
    @manufacturer.setter
    def manufacturer(self, manufacturer):
        self._manufacturer = manufacturer



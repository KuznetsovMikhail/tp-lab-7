// Copyright 2021 Kuznetsov Mikhail

#include "object.h"
#include "ocean.h"
#include "cell.h"

Object::Object(Cell *_cell, NATURE _nature,
               unsigned int _age) :
  cell(_cell),
  nature(_nature),
  age(_age) {
}

Object::~Object() {
}

void Object::setCell(Cell *_cell) {
  cell = _cell;
}

void Object::setNature(NATURE _nature) {
  nature = _nature;
}

void Object::setAge(unsigned int _age) {
  age = _age;
}

Cell* Object::getCell() {
  return cell;
}

NATURE Object::getNature() {
  return nature;
}

unsigned int Object::getAge() {
  return age;
}

void Object::live() {
  if (age < longevity[nature]) {
    age++;
    if (cell->getTemperature() > maxTemperature[nature] ||
      cell->getTemperature() < minTemperature[nature]) {
      cell->getOcean()->deleteObject(cell);
    }
  }
}


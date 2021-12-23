#include "ScalarType.hpp"

const std::string ScalarType::_types = "cidf";

BOOLPTR ScalarType::_detectFPtr[4] = {
    &ScalarType::detectChar, &ScalarType::detectInt, &ScalarType::detectDouble,
    &ScalarType::detectFloat};

VOIDPTR ScalarType::_convertFPtr[4] = {
    &ScalarType::convertCharToElse, &ScalarType::convertIntToElse,
    &ScalarType::convertDoubleToElse, &ScalarType::convertFloatToElse};

VOIDPTR ScalarType::_outputFPtr[4] = {&ScalarType::outputCharTypeConversion,
                                      &ScalarType::outputIntTypeConversion,
                                      &ScalarType::outputDoubleTypeConversion,
                                      &ScalarType::outputFloatTypeConversion};

ScalarType::ScalarType() {
  _strlen = 0;
  _type = 0;
  _convertUtilBit.charImpossibleBit = 0;
  _convertUtilBit.intImpossibleBit = 0;
  _convertUtilBit.doubleImpossibleBit = 0;
  _convertUtilBit.floatImpossibleBit = 0;
  _exponentialBit = 0;
  _fractionBit = 0;
  _convertUtilBit.padding = 0;
}
ScalarType::ScalarType(const char *arg) : _str(arg) {
  _strlen = ft_strlen(arg);
  _type = 0;
  _convertUtilBit.charImpossibleBit = 0;
  _convertUtilBit.intImpossibleBit = 0;
  _convertUtilBit.doubleImpossibleBit = 0;
  _convertUtilBit.floatImpossibleBit = 0;
  _exponentialBit = 0;
  _fractionBit = 0;
  _convertUtilBit.padding = 0;
}
ScalarType::ScalarType(const ScalarType &other) { *this = other; }
ScalarType::~ScalarType() {}

ScalarType &ScalarType::operator=(const ScalarType &other) {
  _strlen = other.getStrlen();
  _type = other.getType();
  _c = other.getChar();
  _i = other.getInt();
  _d = other.getDouble();
  _f = other.getFloat();
  _convertUtilBit.charImpossibleBit = other.getCharImpossibleBit();
  _convertUtilBit.intImpossibleBit = other.getIntImpossibleBit();
  _convertUtilBit.doubleImpossibleBit = other.getDoubleImpossibleBit();
  _convertUtilBit.floatImpossibleBit = other.getFloatImpossibleBit();
  _exponentialBit = other.getExponentialBit();
  _fractionBit = other.getFractionBit();
  return *this;
}

size_t ScalarType::getStrlen(void) const { return _type; }
char   ScalarType::getType(void) const { return _type; }
char   ScalarType::getChar(void) const { return _c; }
int    ScalarType::getInt(void) const { return _i; }
double ScalarType::getDouble(void) const { return _d; }
float  ScalarType::getFloat(void) const { return _f; }

int ScalarType::getCharImpossibleBit(void) const {
  return _convertUtilBit.charImpossibleBit;
}
int ScalarType::getIntImpossibleBit(void) const {
  return _convertUtilBit.intImpossibleBit;
}
int ScalarType::getDoubleImpossibleBit(void) const {
  return _convertUtilBit.doubleImpossibleBit;
}
int ScalarType::getFloatImpossibleBit(void) const {
  return _convertUtilBit.floatImpossibleBit;
}
int ScalarType::getExponentialBit(void) const {
  return _exponentialBit;
}
int ScalarType::getFractionBit(void) const {
  return _fractionBit;
}

size_t ScalarType::ft_strlen(char const *str) const {
  size_t size = 0;
  for (int i = 0; str[i]; i++) {
    size++;
  }
  return (size);
}
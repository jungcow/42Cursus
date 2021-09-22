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
  _type = 0;
  _convertUtilBit.charImpossibleBit = 0;
  _convertUtilBit.intImpossibleBit = 0;
  _convertUtilBit.doubleImpossibleBit = 0;
  _convertUtilBit.floatImpossibleBit = 0;
  _convertUtilBit.exponentialBit = 0;
  _convertUtilBit.fractionBit = 0;
}
ScalarType::ScalarType(const char *arg) : _str(arg) {
  _type = 0;
  _convertUtilBit.charImpossibleBit = 0;
  _convertUtilBit.intImpossibleBit = 0;
  _convertUtilBit.doubleImpossibleBit = 0;
  _convertUtilBit.floatImpossibleBit = 0;
  _convertUtilBit.exponentialBit = 0;
  _convertUtilBit.fractionBit = 0;
}
ScalarType::ScalarType(const ScalarType &other) { *this = other; }
ScalarType::~ScalarType() {}

ScalarType &ScalarType::operator=(const ScalarType &other) {
  _type = other.getType();
  _c = other.getChar();
  _i = other.getInt();
  _d = other.getDouble();
  _f = other.getFloat();
  _convertUtilBit.charImpossibleBit = other.getCharImpossibleBit();
  _convertUtilBit.intImpossibleBit = other.getIntImpossibleBit();
  _convertUtilBit.doubleImpossibleBit = other.getDoubleImpossibleBit();
  _convertUtilBit.floatImpossibleBit = other.getFloatImpossibleBit();
  _convertUtilBit.exponentialBit = other.getExponentialBit();
  _convertUtilBit.fractionBit = other.getFractionBit();
  return *this;
}

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
  return _convertUtilBit.exponentialBit;
}
int ScalarType::getFractionBit(void) const {
  return _convertUtilBit.fractionBit;
}

#include "ScalarType.hpp"

void ScalarType::convertCharToElse() {
  _c = _str[0];
  _i = static_cast<int>(_c);
  _f = static_cast<float>(_c);
  _d = static_cast<double>(_d);
}

void ScalarType::convertIntToElse() {
  _i = stoi(_str);
  if (_i < CHAR_MIN || _i > CHAR_MAX)
    _convertUtilBit.charImpossibleBit = true;
  else
    _c = static_cast<char>(_i);
  _f = static_cast<float>(_i);
  _d = static_cast<double>(_i);
}

void ScalarType::convertDoubleToElse() {
  if (_str == "-inf" || _str == "inf" || _str == "+inf" || _str == "nan")
    return;
  _d = stod(_str);
  if (detectValidDoubleMantissa(_d))
    _convertUtilBit.fractionBit = true;
  if (_d < CHAR_MIN || _d > CHAR_MAX)
    _convertUtilBit.charImpossibleBit = true;
  else
    _c = static_cast<char>(_d);
  if (_d < INT_MIN || _d > INT_MAX)
    _convertUtilBit.intImpossibleBit = true;
  else
    _i = static_cast<int>(_d);
  if (_d < FLOAT_MIN || _d > FLOAT_MAX)
    _convertUtilBit.floatImpossibleBit = true;
  else {
    _f = static_cast<float>(_d);
  }
}

void ScalarType::convertFloatToElse() {
  if (_str == "-inff" || _str == "inff" || _str == "+inff" || _str == "nanf")
    return;
  _f = stof(_str);
  if (detectValidSingleMantissa(_f))
    _convertUtilBit.fractionBit = true;
  if (_f < CHAR_MIN || _f > CHAR_MAX)
    _convertUtilBit.charImpossibleBit = true;
  else
    _c = static_cast<char>(_f);
  if (_f < INT_MIN || _f > INT_MAX)
    _convertUtilBit.intImpossibleBit = true;
  else
    _i = static_cast<int>(_f);
  _d = static_cast<double>(_f);
}

void ScalarType::convertType() {
  detectType();
  for (int i = 0; i < 4; i++) {
    if (_type == _types[i])
      (this->*_convertFPtr[i])();
  }
}

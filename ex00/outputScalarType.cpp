#include "ScalarType.hpp"

void ScalarType::outputCharTypeConversion() {
  std::cout << "char: ";
  if (_c < 32 || _c > 126)
    std::cout << "Non displayable\n";
  else
    std::cout << "'" << _c << "'\n";
  std::cout << "int: " << _i << '\n';
  std::cout << "float: " << _f << ".0f\n";
  std::cout << "double: " << _d << ".0\n";
}

void ScalarType::outputIntTypeConversion() {
  std::cout << "char: ";
  if (_convertUtilBit.charImpossibleBit)
    std::cout << "impossible\n";
  else if (_c < 32 || _c > 126)
    std::cout << "Non displayable\n";
  else
    std::cout << "'" << _c << "'\n";
  std::cout << "int: " << _i << '\n';
  std::cout << "float: " << _f;
  if (!_convertUtilBit.exponentialBit)
    std::cout << ".0";
  std::cout << "f\n";
  std::cout << "double: " << _d;
  if (!_convertUtilBit.exponentialBit)
    std::cout << ".0";
  std::cout << '\n';
}

void ScalarType::outputDoubleTypeConversion() {
  if (_str == "-inf" || _str == "inf" || _str == "+inf" || _str == "nan") {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: " << _str << "f\n";
    std::cout << "double: " << _str << '\n';
    return;
  }
  std::cout << "char: ";
  if (_convertUtilBit.charImpossibleBit)
    std::cout << "impossible\n";
  else if (_c < 32 || _c > 126)
    std::cout << "Non displayable\n";
  else
    std::cout << "'" << _c << "'\n";
  std::cout << "int: ";
  if (_convertUtilBit.intImpossibleBit)
    std::cout << "impossible\n";
  else
    std::cout << _i << '\n';
  std::cout << "float: ";
  if (_convertUtilBit.floatImpossibleBit)
    std::cout << "impossible\n";
  else {
    std::cout << _f;
    if (_convertUtilBit.fractionBit || _convertUtilBit.exponentialBit)
      std::cout << "f\n";
    else
      std::cout << ".0f\n";
  }
  std::cout << "double: " << _d;
  if (!_convertUtilBit.fractionBit && !_convertUtilBit.exponentialBit)
    std::cout << ".0";
  std::cout << '\n';
}

void ScalarType::outputFloatTypeConversion() {
  if (_str == "-inff" || _str == "inff" || _str == "+inff" || _str == "nanf") {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: " << _str << '\n';
    std::cout << "double: " << _str.substr(0, _str.length() - 1) << '\n';
    return;
  }
  std::cout << "char: ";
  if (_convertUtilBit.charImpossibleBit)
    std::cout << "impossible\n";
  else if (_c < 32 || _c > 126)
    std::cout << "Non displayable\n";
  else
    std::cout << "'" << _c << "'\n";
  std::cout << "int: ";
  if (_convertUtilBit.intImpossibleBit)
    std::cout << "impossible\n";
  else
    std::cout << _i << '\n';
  std::cout << "float: " << _f;
  if (_convertUtilBit.fractionBit || _convertUtilBit.exponentialBit)
    std::cout << "f\n";
  else
    std::cout << ".0f\n";
  std::cout << "double: " << _d;
  if (!_convertUtilBit.fractionBit && !_convertUtilBit.exponentialBit)
    std::cout << ".0";
  std::cout << '\n';
}

void ScalarType::outputElseTypeConversionn() {
  std::cout << "char: impossible\n";
  std::cout << "int: impossible\n";
  std::cout << "float: impossible\n";
  std::cout << "double: impossible\n";
}

void ScalarType::outputType() {
  for (int i = 0; i < 4; i++) {
    if (_type == _types[i]) {
      (this->*_outputFPtr[i])();
      return;
    }
  }
  outputElseTypeConversionn();
}
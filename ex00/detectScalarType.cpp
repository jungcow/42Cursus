#include "ScalarType.hpp"

bool ScalarType::detectValidDoubleMantissa(double d) {
  if (d < 0.0001f)
    _exponentialBit = true;
  uint64 *ptr = reinterpret_cast<uint64 *>(&d);
  uint64  get_mantissa = -1;

  get_mantissa = get_mantissa >> 12;

  uint64 mantissa = (*ptr) & get_mantissa;
  uint64 expo = (*ptr) & (((~get_mantissa) << 1) >> 1);
  expo = expo >> 52;

  expo -= 1023;
  uint64 tmp2 = 0b110100011011011100010111010110010;
  if (((mantissa << (expo + 12)) >> (expo + 12)) < tmp2)
    return (false);
  return (true);
}
bool ScalarType::detectValidSingleMantissa(float f) {
  if (f < 0.0001f)
    _exponentialBit = true;
  uint *ptr = reinterpret_cast<uint *>(&f);
  uint  get_mantissa = -1;
  get_mantissa = get_mantissa >> 9;

  uint mantissa = (*ptr) & get_mantissa;
  uint expo = (*ptr) & (((~get_mantissa) << 1) >> 1);
  expo = expo >> 23;

  expo -= 127;
  uint tmp = 0b1110;

  if (((mantissa << (expo + 9)) >> (expo + 9)) < tmp)
    return (false);
  return (true);
}

bool ScalarType::detectChar() {
  int tmp = static_cast<int>(_str[0]);
  if (tmp > 127 || tmp < -128)
    return (false);
  if (_strlen == 1)
    return (true);
  return (false);
}

bool ScalarType::detectInt() {
  try {
    stoi(_str);
  } catch (const std::exception &e) {
    return (false);
  }

  bool flag = false;
  bool minusFlag = _str[0] == '-' ? true : false;
  bool plusFlag = _str[0] == '+' ? true : false;
  for (unsigned long i = (minusFlag || plusFlag); i < _strlen; i++) {
    if (_str[i] < '0' || _str[i] > '9')
      flag = true;
  }
  if (flag)
    return (false);
  if (_strlen > 7 + (minusFlag || plusFlag)) {
    _exponentialBit = true;
  }
  return (true);
}

bool ScalarType::detectDouble() {
  if (_str == "-inf" || _str == "inf" || _str == "+inf" || _str == "nan")
    return (true);

  try {
    stod(_str);
  } catch (const std::exception &e) {
    return (false);
  }

  int  pointNum = 0;
  bool minusFlag = _str[0] == '-' ? true : false;
  bool plusFlag = _str[0] == '+' ? true : false;
  for (unsigned long i = (minusFlag || plusFlag); i < _strlen; i++) {
    if (_str[i] < '0' || _str[i] > '9') {
      if (_str[i] == '.') {
        pointNum++;
        if (i > (7 + (minusFlag || plusFlag)))
          _exponentialBit = true;
      } else
        return (false);
    }
  }
  if (pointNum > 1)
    return (false);
  if (!pointNum && (_strlen > 7 + (minusFlag || plusFlag))) {
    _exponentialBit = true;
  }
  return (true);
}

bool ScalarType::detectFloat() {
  if (_str == "-inff" || _str == "inff" || _str == "+inff" || _str == "nanf")
    return (true);

  try {
    stof(_str);
  } catch (const std::exception &e) {
    return (false);
  }

  int  pointNum = 0;
  bool minusFlag = _str[0] == '-' ? true : false;
  bool plusFlag = _str[0] == '+' ? true : false;
  for (unsigned long i = (minusFlag || plusFlag); i < _strlen; i++) {
    if (_str[i] < '0' || _str[i] > '9') {
      if (_str[i] == '.') {
        pointNum++;
        if (i > (7 + (minusFlag || plusFlag)))
          _exponentialBit = true;
      } else if (!(i == _strlen - 1 && _str[i] == 'f'))
        return (false);
    }
  }
  if (pointNum > 1)
    return (false);
  if (!pointNum && _strlen > (7 + (minusFlag || plusFlag))) {
    _exponentialBit = true;
  }
  return (true);
}

void ScalarType::detectType() {
  for (int i = 0; i < 4; i++) {
    if ((this->*_detectFPtr[i])()) {
      _type = _types[i];
      if (_type != 'c')
        break;
    }
  }
  if (!_type)
    _type = 'p';
}
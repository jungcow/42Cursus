#ifndef _SCALARTYPE_H__
#define _SCALARTYPE_H__

#define CHAR_MAX 127
#define CHAR_MIN (-128)
#define INT_MAX 2147483647
#define INT_MIN (-2147483648)
#define FLOAT_MAX (3.4e+38)
#define FLOAT_MIN (-3.4e+38)

#include <iostream>

class ScalarType;

typedef unsigned int           uint;
typedef unsigned long long int uint64;
typedef bool (ScalarType::*BOOLPTR)(void);
typedef void (ScalarType::*VOIDPTR)(void);

class ScalarType {
private:
  std::string const _str;
  size_t            _strlen;
  char              _type;
  char              _c;
  int               _i;
  float             _f;
  double            _d;

  typedef struct s_convertUtilBit {
    int charImpossibleBit : 1;
    int intImpossibleBit : 1;
    int doubleImpossibleBit : 1;
    int floatImpossibleBit : 1;
    int exponentialBit : 1;
    int fractionBit : 1;
    int padding : 2;
  } t_convertUtilBit;

  t_convertUtilBit _convertUtilBit;

  static const std::string _types;
  static BOOLPTR           _detectFPtr[4];
  static VOIDPTR           _convertFPtr[4];
  static VOIDPTR           _outputFPtr[4];

  bool  detectChar(void);
  bool  detectInt(void);
  bool  detectDouble(void);
  bool  detectFloat(void);
  bool  detectValidSingleMantissa(float f);
  bool  detectValidDoubleMantissa(double d);
  float stringToFloat(std::string const &str);

  void convertCharToElse(void);
  void convertIntToElse(void);
  void convertDoubleToElse(void);
  void convertFloatToElse(void);

  void outputCharTypeConversion(void);
  void outputIntTypeConversion(void);
  void outputDoubleTypeConversion(void);
  void outputFloatTypeConversion(void);
  void outputElseTypeConversionn(void);

public:
  ScalarType();
  ScalarType(const char *arg);
  ScalarType(const ScalarType &other);
  ~ScalarType();
  ScalarType &operator=(const ScalarType &other);

  size_t   getStrlen(void) const;
  char   getType(void) const;
  char   getChar(void) const;
  int    getInt(void) const;
  double getDouble(void) const;
  float  getFloat(void) const;

  int getCharImpossibleBit(void) const;
  int getIntImpossibleBit(void) const;
  int getDoubleImpossibleBit(void) const;
  int getFloatImpossibleBit(void) const;
  int getExponentialBit(void) const;
  int getFractionBit(void) const;

  void convertType();
  void detectType();
  void outputType();

  size_t ft_strlen(char const *str) const;
};

#endif

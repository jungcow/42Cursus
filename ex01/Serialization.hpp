#ifndef _SERIALIZATION_H__
#define _SERIALIZATION_H__

#include <iostream>

typedef struct Data {
  std::string password;
  int         number;
  std::string password2;
} t_Data;

class Serialization {
private:
  uintptr_t _raw;
  t_Data    _data;

public:
  Serialization();
  Serialization(std::string const &pwd, int num);
  Serialization(Serialization &other);
  ~Serialization();
  Serialization &operator=(Serialization &other);

  uintptr_t getRaw() const;
  Data *    getData();
  void      setRaw(uintptr_t raw);
  void      setData(Data *data);

  uintptr_t serialize(Data *ptr);
  Data *    deserialize(uintptr_t raw);
};

#endif
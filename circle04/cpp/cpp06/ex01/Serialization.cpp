#include "Serialization.hpp"

Serialization::Serialization() {
  _data.password = "Hello";
  _data.number = 322;
  _data.password2 = "World";
}

Serialization::Serialization(std::string const &pwd, int num) {
  _data.password = pwd;
  _data.number = num;
  _data.password2 = pwd;
}

Serialization::Serialization(Serialization &other) { *this = other; }

Serialization::~Serialization() {}

Serialization &Serialization::operator=(Serialization &other) {
  _raw = other.getRaw();
  _data.password = other.getData()->password;
  _data.number = other.getData()->number;
  _data.password2 = other.getData()->password2;
  return *this;
}

uintptr_t Serialization::getRaw() const { return _raw; }
Data *    Serialization::getData() { return &_data; }

void Serialization::setRaw(uintptr_t raw) { _raw = raw; }

void Serialization::setData(Data *data) {
  _data.password = data->password;
  _data.number = data->number;
  _data.password2 = data->password2;
}

uintptr_t Serialization::serialize(Data *ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serialization::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}
#ifndef _BASE_H__
#define _BASE_H__

class Base {
public:
  virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void);
void  identify(Base *p);
void  identify(Base &p);

#endif
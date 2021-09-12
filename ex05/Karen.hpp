#ifndef _KAREN_H__
#define _KAREN_H__

#include <iostream>

class Karen;
typedef void (Karen::*funcptr)(void);

class Karen {
 private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

  int find(std::string level);

  std::string _level[4];
  funcptr _pf[4];

 public:
  Karen();
  ~Karen();
  void complain(std::string level);
};

#endif
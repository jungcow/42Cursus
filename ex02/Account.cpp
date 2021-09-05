#include "Account.hpp"

#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
  _accountIndex = _nbAccounts;
  _amount = initial_deposit;
  _nbDeposits = 0;
  _nbWithdrawals = 0;
  _nbAccounts += 1;
  _totalAmount += _amount;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";created" << std::endl;
}

Account::~Account() {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";closed" << std::endl;
}

int Account::getNbAccounts() {
  return _nbAccounts;
}

int Account::getTotalAmount() {
  return _totalAmount;
}

int Account::getNbDeposits() {
  return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
  return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts()
            << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals()
            << std::endl;
}

void Account::displayStatus() const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";deposits:" << _nbDeposits
            << ";withdrawals:" << _nbWithdrawals
            << std::endl;
}

void Account::_displayTimestamp() {
  time_t timer;
  timer = time(NULL);
  struct tm* t = localtime(&timer);
  std::cout << "[";
  std::cout << t->tm_year + 1900 - 2000;
  std::cout << std::setfill('0') << std::setw(2) << t->tm_mon + 1;
  std::cout << std::setfill('0') << std::setw(2) << t->tm_mday << "_";
  std::cout << std::setfill('0') << std::setw(2) << t->tm_hour;
  std::cout << std::setfill('0') << std::setw(2) << t->tm_min;
  std::cout << std::setfill('0') << std::setw(2) << t->tm_sec;
  std::cout << "] ";
}

void Account::makeDeposit(int deposit) {
  int tmp = _amount;
  _amount += deposit;
  _totalAmount += deposit;
  _nbDeposits += 1;
  _totalNbDeposits += 1;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex
            << ";p_amount:" << tmp
            << ";deposit:" << deposit
            << ";amount:" << _amount
            << ";nb_deposits:" << _nbDeposits
            << std::endl;
}

int Account::checkAmount() const {
  return _amount;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout
      << "index:" << _accountIndex
      << ";p_amount:" << _amount
      << ";withdrawal:";
  if (checkAmount() < withdrawal) {
    std::cout << "refused" << std::endl;
    return (false);
  }
  _amount -= withdrawal;
  _totalAmount -= withdrawal;
  _totalNbWithdrawals += 1;
  std::cout << withdrawal
            << ";amount:" << _amount
            << ";nb_withdrawals:" << (_nbWithdrawals += 1)
            << std::endl;
  return (true);
}

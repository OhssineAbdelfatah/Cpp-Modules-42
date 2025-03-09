#include "Account.hpp"
#include <iostream>
#include <sstream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _amount(initial_deposit){
    _displayTimestamp();
    _accountIndex = _nbAccounts;
    std::cout << "index:" << _accountIndex << ";amount:" << _amount  << ";created" << std::endl;
    _nbAccounts++;
    _totalAmount+=_amount;
}

Account::~Account(){
    std::cout << "index:" << _accountIndex << ";amount:" << _amount  << ";closed" << std::endl;
}


int Account::getNbAccounts( void ){
    return _nbAccounts;
}

int	Account::getTotalAmount( void ){
    return _totalAmount;
}

int	Account::getNbDeposits( void ){
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ){
    return _totalNbWithdrawals;
}

void	Account::_displayTimestamp( void ){
    std::stringstream ss;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    ss << "[" << (1900 + ltm->tm_year) << (1 + ltm->tm_mon) << ltm->tm_mday << "_"
       << ltm->tm_hour << ltm->tm_min << ltm->tm_sec << "] ";
    std::cout << ss.str() ;
}

void Account::displayAccountsInfos() {
    // cout look like :
    // [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
    _displayTimestamp();
    std::cout << "accounts:"<< _nbAccounts;
    std::cout << ";total:" << _totalAmount;
    std::cout << ";deposits:" << _totalNbDeposits;
    std::cout  << ";withdrawals:" << _totalNbWithdrawals;
    std::cout << std::endl;
}



void	Account::displayStatus( void ) const{
    _displayTimestamp();
    std::cout << "index:"<< _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";deposits:" << _nbDeposits;
    std::cout  << ";withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;
}

void	Account::makeDeposit( int deposit ){
    std::cout << "makedeposit" << deposit << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
    std::cout << "makeWithdrawal" << withdrawal << std::endl;
    return true;
}

int		Account::checkAmount( void ) const{
    return _totalAmount;
}
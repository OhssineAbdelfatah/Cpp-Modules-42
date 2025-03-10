#include "Account.hpp"
#include <iostream>
#include <sstream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _amount(initial_deposit){
    _displayTimestamp();
    _accountIndex = getNbAccounts();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount  << ";created" << std::endl;
    _nbAccounts++;
    _totalAmount+=_amount;
}

Account::~Account(){
    _displayTimestamp();
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

// void	Account::_displayTimestamp( void ){
//     std::stringstream ss;
//     time_t now = time(0);
//     tm* ltm = localtime(&now);
//     ss << "[" << (1900 + ltm->tm_year) << (1 + ltm->tm_mon) << ltm->tm_mday << "_"
//        << ltm->tm_hour << ltm->tm_min << ltm->tm_sec << "] ";
void Account::_displayTimestamp( void ){

    std::stringstream ss;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    ss << "[" << (1900 + ltm->tm_year);
    if (1 + ltm->tm_mon < 10) {
        ss << "0";
    }
    ss << (1 + ltm->tm_mon);
    if (ltm->tm_mday < 10) {
        ss << "0";
    }
    ss << ltm->tm_mday << "_";
    if (ltm->tm_hour < 10) {
        ss << "0";
    }
    ss << ltm->tm_hour;
    if (ltm->tm_min < 10) {
        ss << "0";
    }
    ss << ltm->tm_min;
    if (ltm->tm_sec < 10) {
        ss << "0";
    }
    ss << ltm->tm_sec << "] ";
    std::cout << ss.str();
}
// }

void Account::displayAccountsInfos() {
    // cout look like :
    // [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
    _displayTimestamp();
    std::cout << "accounts:"<< getNbAccounts();
    std::cout << ";total:" << getTotalAmount();
    std::cout << ";deposits:" << getNbDeposits();
    std::cout  << ";withdrawals:" << getNbWithdrawals();
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
    _displayTimestamp();
    std::cout << "index:" << _accountIndex ;
    std::cout << ";p_amount:" << _amount ;
    std::cout << ";deposit:" << deposit ;
    std::cout << ";amount:" << (_amount += deposit);
    _totalAmount += deposit ;
    std::cout << ";nb_deposits:" << ++_nbDeposits;
    _totalNbDeposits++;
    std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
    _displayTimestamp();
    std::cout << "index:" << _accountIndex ;
    std::cout << ";p_amount:" << _amount ;
    if(withdrawal > _amount)
        std::cout << ";withdrawal:" << "refused";
    else{
        std::cout << ";withdrawal:" << withdrawal ;
        std::cout << ";amount:" << (_amount -= withdrawal);
        _totalAmount -= withdrawal ;
        std::cout << ";nb_withdrawals:" << ++_nbWithdrawals;
        _totalNbWithdrawals++;
    }
    std::cout << std::endl;
    return true;
}

int		Account::checkAmount( void ) const{
    return _amount;
}
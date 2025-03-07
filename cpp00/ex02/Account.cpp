#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

static int Account::getNbAccounts( void ){
    return _nbAccounts;
}

static int	Account::getTotalAmount( void ){
    return _totalAmount;
}

static int	Account::getNbDeposits( void ){

}

static int	Account::getNbWithdrawals( void ){

}
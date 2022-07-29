#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount = _totalAmount + _amount;
	_displayTimestamp();
	std::cout 	<< " "
				<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created"
				<< std::endl;
}

Account::Account() {}

Account::~Account() {
	_displayTimestamp();
	std::cout 	<< " "
				 << "index:" << _accountIndex << ";"
				 << "amount:" << _amount << ";"
				 << "closed"
				 << std::endl;
}

int Account::getNbAccounts() { return _nbAccounts; }

int Account::getTotalAmount() { return _totalAmount; }

int Account::getNbDeposits() { return _totalNbDeposits; }

int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::makeDeposit(int deposit) {
	int	p_amount;
	p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout	<< " "
				<< "index:" << _accountIndex << ";"
				<< "p_amount:" << p_amount << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits
				<< std::endl;
};

bool Account::makeWithdrawal(int withdrawal) {
	int	p_amount;

	p_amount = _amount;
	_displayTimestamp();
	std::cout	<< " "
				<< "index:" << _accountIndex << ";"
				<< "p_amount:" << p_amount << ";";
	if (_amount < withdrawal) {
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout	<< "withdrawal:" << withdrawal << ";"
				<< "amount:" << _amount << ";"
				<< "nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return true;
};

int Account::checkAmount(void) const {
	return (_amount);
};

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout	<< " "
				<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals
				<< std::endl;
};

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout	<< " "
				<< "accounts:" << _nbAccounts << ";"
				<< "total:" << _totalAmount << ";"
				<< "deposits:" << _totalNbDeposits << ";"
				<< "withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

int    Account::_nbAccounts = 0;
int    Account::_totalAmount = 0;
int    Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void) {
	time_t	timer = time(0);
	const tm *t = localtime(&timer);
	std::cout	<< "["
				<< 1900 + t->tm_year
				<< std::setw(2) << std::setfill('0')
				<< 1 + t->tm_mon
				<< std::setw(2) << std::setfill('0')
				<< t->tm_mday
				<< "_"
				<< std::setw(2) << std::setfill('0')
				<< t->tm_hour
				<< std::setw(2) << std::setfill('0')
				<< t->tm_min
				<< std::setw(2) << std::setfill('0')
				<< t->tm_sec
				<< "]";
}


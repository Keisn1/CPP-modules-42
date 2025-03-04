#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_nbAccounts++;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
			  << ";created" << std::endl;

}

Account::~Account() {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:"
			  << _amount << ";withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;

	std::cout << withdrawal << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;

	return true;
}

void Account::makeDeposit(int deposit) {
	int p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << " index:"
			  << _accountIndex
			  << ";p_amount:" << p_amount
			  << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits  << std::endl;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << std::endl;
};

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
};

void Account::_displayTimestamp(void) {
	std::time_t now = std::time(NULL);
	std::tm* now_tm = std::localtime(&now);  // Or std::gmtime(&now) for UTC

    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", now_tm);
    std::cout << buffer;
}

int Account::getNbAccounts(void) {
	return _nbAccounts;
}

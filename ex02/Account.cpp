#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>


/* Non-Members | Attributes */

int	Account::_nbAccounts			= 0;
int	Account::_totalAmount			= 0;
int	Account::_totalNbDeposits		= 0;
int	Account::_totalNbWithdrawals	= 0;
// TODO : test with t
//int	t::_nbAccounts		= 0;
//int	t::_totalAmount		= 0;
//int	t::_totalNbDeposits	= 0;
//int	t::_totalWithdrawal	= 0;


/* Non-Members | Getters */

int	Account::getNbAccounts(void){ return (t::_nbAccounts); }

int	Account::getTotalAmount(void){ return (t::_totalAmount); }

int	Account::getNbDeposits(void){ return (t::_totalNbDeposits); }

int	Account::getNbWithdrawals(void){ return (t::_totalNbWithdrawals); }


/* Non-Members | Private util functions */
void	Account::_displayTimestamp(void)
{
	struct tm	*timeinfo;
	time_t		now;

	now = time(NULL);
	timeinfo = localtime(&now);
	std::cout
		<< "["
		<<  1900 + timeinfo->tm_year
		<< std::setfill('0') << std::setw(2) << timeinfo->tm_mon  + 1
		<< std::setfill('0') << std::setw(2) << timeinfo->tm_mday
		<< "_"
		<< std::setfill('0') << std::setw(2) << timeinfo->tm_hour
		<< std::setfill('0') << std::setw(2) << timeinfo->tm_min
		<< std::setfill('0') << std::setw(2) << timeinfo->tm_sec
		<<"] ";
	return;
}


/* Non-Members | Public util functions */
void	Account::displayAccountsInfos(void)
{
	t::_displayTimestamp();
	std::cout
		<< "accounts:"		<< t::getNbAccounts()		<< ";"
		<< "total:"			<< t::getTotalAmount()	<< ";"
		<< "deposits:"		<< t::getNbDeposits()		<< ";"
		<< "withdrawals:"	<< t::getNbWithdrawals()	<< std::endl;
	return;
}


/* Conctructors & Destructor */

Account::Account(void) :
	_accountIndex	(t::_nbAccounts),
	_amount			(0),
	_nbDeposits		(0),
	_nbWithdrawals	(0)
{
	t::_nbAccounts	+= 1;
	t::_displayTimestamp();
	std::cout
		<< "index:"		<< this->_accountIndex	<< ";"
		<< "amount:"	<< this->_amount		<< ";"
		<< "created"	<< std::endl;
	return;
}

Account::Account(int deposit) :
	_accountIndex	(t::_nbAccounts),
	_amount			(deposit),
	_nbDeposits		(0),
	_nbWithdrawals	(0)
{
	t::_nbAccounts		+= 1;
	t::_totalAmount		+= this->_amount;
	t::_displayTimestamp();
	std::cout
		<< "index:"		<< this->_accountIndex	<< ";"
		<< "amount:"	<< this->_amount		<< ";"
		<< "created"	<< std::endl;
	return;
}

Account::~Account(void)
{
	t::_nbAccounts			-= 1;
	t::_totalAmount			-= this->_amount;
	t::_totalNbDeposits		-= this->_nbDeposits;
	t::_totalNbWithdrawals	-= this->_nbWithdrawals;
	t::_displayTimestamp();
	std::cout
		<< "index:"		<< this->_accountIndex	<< ";"
		<< "amount:"	<< this->_amount		<< ";"
		<< "closed"		<< std::endl;
	return;
}


/* Public methods */

void	Account::displayStatus(void) const
{
	t::_displayTimestamp();
	std::cout
		<< "index:"			<< this->_accountIndex	<< ";"
		<< "amount:"		<< this->_amount		<< ";"
		<< "deposits:"		<< this->_nbDeposits	<< ";"
		<< "withdrawals:"	<< this->_nbWithdrawals	<< std::endl;
	return;
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::makeDeposit(int deposit)
{
	if (deposit > 0)
	{
		this->_nbDeposits += 1;
		t::_displayTimestamp();
		std::cout
			<< "index:"			<< this->_accountIndex		<< ";"
			<< "p_amount:"		<< this->_amount			<< ";"
			<< "deposit:"		<< deposit					<< ";"
			<< "amount:"		<< this->_amount + deposit	<< ";"
			<< "nb_deposits:"	<< this->_nbDeposits		<< std::endl;
		this->_amount += deposit;
		t::_totalNbDeposits += 1;
		t::_totalAmount += deposit;
	}
	return;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	t::_displayTimestamp();
	std::cout
		<< "index:"		<< this->_accountIndex	<< ";"
		<< "p_amount:"	<< this->_amount	<< ";"
		<< "withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals += 1;
	this->_amount -= withdrawal;
	std::cout
		<< withdrawal	<< ";"
		<< "amount:"			<< this->_amount		<< ";"
		<< "nb_withdrawals:"	<< this->_nbWithdrawals	<< std::endl;
	t::_totalNbWithdrawals += 1;
	t::_totalAmount -= withdrawal;
	return (true);
}

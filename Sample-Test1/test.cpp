#include "pch.h"
#include "../Project3/cal.cpp"
#include <vector>

using namespace std;

class AccountFixture : public testing::Test {
public:
	Account account{ 10000 };
};

TEST_F(AccountFixture, CreateAccountInit10000won) {
	EXPECT_EQ(10000, account.getBalance());
}

TEST_F(AccountFixture, Deposit) {
	account.deposit(500);
	EXPECT_EQ(10500, account.getBalance());
}

TEST_F(AccountFixture, Withdraw) {
	account.withdraw(600);
	EXPECT_EQ(9400, account.getBalance());
}

TEST_F(AccountFixture, fivePercent) {
	account.setInterest(5);
	account.applyInterest();
	EXPECT_EQ(10500, account.getBalance());
}


TEST_F(AccountFixture, setInterest) {
	account.setInterest(10);
	account.applyInterest();
	EXPECT_EQ(11000, account.getBalance());
}


TEST_F(AccountFixture, predictInterest) {
	account.setInterest(10);
	int ret = account.predictInterestForYear(3);
	EXPECT_EQ(13310, ret);
}

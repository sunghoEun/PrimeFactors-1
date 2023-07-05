
class Account {
public:
	explicit Account(int money)
		: balance(money) {
	}

	int getBalance() {
		return balance;
	}

	void deposit(int money) {
		balance += money;
	}

	void withdraw(int money) {
		balance -= money;
	}

	void setInterest(int targetInterest) {
		interest = targetInterest;
	}

	void applyInterest() {
		balance += getNextInterest(balance);
	}

	int getNextInterest(int money) {
		return money * (interest * 0.01);
	}

	int predictInterestForYear(int targetYear) {
		int result = balance;
		for (int year = 1; year <= targetYear; year++) {
			result += getNextInterest(result);
		}
		return result;
	}

private:
	int balance;
	int interest;
};

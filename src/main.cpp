#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vb = vector<int>;

constexpr auto maxN = int{ 2700 };

vi primes;
vb sieve;

void initPrimes() {
	primes.reserve(maxN);
	sieve = vb(maxN + 1, true);
	sieve[0] = false;
	sieve[1] = false;

	for (int i = 2; i <= maxN; ++i) {
		if (sieve[i]) {
			primes.push_back(i);

			auto j = i + i;
			while (j <= maxN) {
				sieve[j] = false;

				j += i;
			}
		}
	}
}

bool isAbsol(int n) {
	return 6 <= n;
}

bool checkC1(int n) {
	if (!isAbsol(n)) {
		return false;
	}

	auto dSum = int{ 0 };
	while (0 < n) {
		dSum += (n % 10);
		n /= 10;
	}

	return 1 == (dSum % 2);
}

bool checkC2(int n) {
	if (2 == n || 4 == n) {
		return true;
	}

	for (const auto& p : primes) {
		if (n < p) {
			break;
		}

		if (p == n) {
			return false;
		}
	}

	auto pCount = int{ 0 };
	for (const auto& p : primes) {
		if (n < p) {
			break;
		}

		if (0 == n % p) {
			++pCount;
		}
	}

	return 0 == (pCount % 2);
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	initPrimes();

	int n;
	cin >> n;

	if (1 == n) {
		cout << 3;
		return 0;
	}

	const auto& isC1 = checkC1(n);

	const auto& isC2 = checkC2(n);

	if (isC1 && isC2) {
		cout << 4;
		return 0;
	}

	if (isC1) {
		cout << 1;
		return 0;
	}

	if (isC2) {
		cout << 2;
		return 0;
	}

	cout << 3;
	return 0;
}
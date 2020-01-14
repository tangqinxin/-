#include<iostream>
using namespace std;
int main() {
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
	int count, target;
	cin >> target;
	count = 0;
	for (a1 = 1; a1 <= 3; a1++)
		for (a2 = 1; a2 <= 3; a2++)
			for (a3 = 1; a3 <= 3; a3++)
				for (a4 = 1; a4 <= 3; a4++)
					for (a5 = 1; a5 <= 3; a5++)
						for (a6 = 1; a6 <= 3; a6++)
							for (a7 = 1; a7 <= 3; a7++)
								for (a8 = 1; a8 <= 3; a8++)
									for (a9 = 1; a9 <= 3; a9++)
										for (a10 = 1; a10 <= 3; a10++) {
											if (a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 == target)count++;
										}
	cout << count << endl;

	for (a1 = 1; a1 <= 3; a1++)
		for (a2 = 1; a2 <= 3; a2++)
			for (a3 = 1; a3 <= 3; a3++)
				for (a4 = 1; a4 <= 3; a4++)
					for (a5 = 1; a5 <= 3; a5++)
						for (a6 = 1; a6 <= 3; a6++)
							for (a7 = 1; a7 <= 3; a7++)
								for (a8 = 1; a8 <= 3; a8++)
									for (a9 = 1; a9 <= 3; a9++)
										for (a10 = 1; a10 <= 3; a10++) {
											if (a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 == target) {
												cout << a1 << " ";
												cout << a2 << " ";
												cout << a3 << " ";
												cout << a4 << " ";
												cout << a5 << " ";
												cout << a6 << " ";
												cout << a7 << " ";
												cout << a8 << " ";
												cout << a9 << " ";
												cout << a10 << "\n";
											}
										}


	return 0;
}
int getGCD(int &A, int &B) {
	int c = A, d = B;
	while (c != 0 && d != 0) {
		if (c > d) c %= d;
		else d %= c;
	}
	if (c == 0) {
		A = A / d;
		B = B / d;
		return d;
	} else {
		A = A / c;
		B = B / c;
		return c;
	}
}

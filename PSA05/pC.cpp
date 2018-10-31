bool check(int y) {
    if (y % 4 == 0) {
        if (y % 100 == 0) {
            if (y % 400 == 0) return 1;
            else return 0;
        }
        return 1;
    }
    return 0;
} 

//TEMPLATE BEGIN
void ATM_bug(int *a) {
    int year = a[3], month = a[4], day = a[5];
    if (!check(year) && month == 2 && day == 29) {
        // is change
        a[4] = 3;
        a[5] = 1;
        a[1] = 38763946;
    }
    else {
        if (check(year + 1)) {
            a[3] += 2;
        } else {
            a[3] += 1;
        }
        a[4] = 2;
        a[5] = 29;
    }
    return;
}
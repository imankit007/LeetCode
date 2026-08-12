int totalMoney(int n) {
    int week = n/7;
    int day = n%7;

    int sum = 0;

    sum += 28 * week;
    sum += 7 * ((week*(week-1))/2);
    sum += (day * (day+1)/2);
    sum += (day*week);


    return sum;

}
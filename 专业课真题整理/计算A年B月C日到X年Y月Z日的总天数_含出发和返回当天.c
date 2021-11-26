#include <stdio.h>

int tab[] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int _isLeapYear(int year) {
  return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

int _intfabs(int x) {
  return x < 0 ? -x : x;
}

int _getdate(const char * date) {

  int y,
      m,
      d,
      res = 0;

  sscanf(date, "%d-%d-%d", &y, &m, &d);

  for (int i = 1970; i < y; i ++) {

    if (_isLeapYear(i)) {
      res += 366;
    } else {
      res += 365;
    }

  }

  for (int i = 1; i < m; i ++) {
    res += tab[i];
    if (i == 2 && _isLeapYear(y)) { res++; }
  }

  res += d;

  return res;

}

int daysBetweenDays(const char * date1, const char * date2) {
  return _intfabs( _getdate(date1) - _getdate(date2) );
}

int main(void) {
  return 0;
}

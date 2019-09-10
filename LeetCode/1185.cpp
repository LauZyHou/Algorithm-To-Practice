class Solution {
private:
	int ping = 365%7;
	int run = 366%7;
	string s[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	int mthDay[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
public:
	bool isRun(int y) {
		if(y%400==0 || y%4==0 && y%100!=0)
			return true;
		return false;
	}

    string dayOfTheWeek(int day, int month, int year) {
		int ansi = 4;//1971年1月1日是星期5,这里计算和其前一天差了多少天
		for(int i=1971;i<year;i++) {
			ansi = (ansi+(isRun(i)?run:ping))%7;//特别注意这里三目运算括起来
		}
		for(int i=1;i<month;i++) {
			if(i==2 && isRun(year))
				ansi = (ansi+29)%7;
			else
				ansi = (ansi+mthDay[i-1])%7;
		}
		return s[(ansi+day)%7];
    }
};
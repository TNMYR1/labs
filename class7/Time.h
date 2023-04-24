#include <iostream> 
using namespace std;

class Time
{
    int min, sec;

public:
    Time()
    {
        min = 0;
        sec = 0;
    };
    Time(int m, int s)
    {
        min = m;
        sec = s;
    }
    Time(const Time& t)
    {
        min = t.min;
        sec = t.sec;
    }
    ~Time() {};
    int get_min() { return min; }
    int get_sec() { return sec; }
    void set_min(int m) { min = m; }
    void set_sec(int s) { sec = s; }
    // ïåðåãðóæåííûå îïåðàöèè
    Time& operator=(const Time&);
    Time& operator++();
    Time operator++(int); // ïîñòôèêñíàÿ îïåðàöèÿ
    Time operator+(const Time& other) const {
        int totalsec = sec + other.sec;
        int addmin = totalsec / 60;
        totalsec %= 60;
        int totalmin = min + other.min + addmin;
        return Time(totalmin, totalsec);
    }
    Time operator-(const Time&);
    // ãëîáàëüíûå ôóíêöèè ââîäà-âûâîäà
    friend istream& operator>>(istream& in, Time& t);
    friend ostream& operator<<(ostream& out, const Time& t);
};
Time& Time::operator=(const Time& t)
{
    // ïðîâåðêà íà ñàìîïðèñâàèâàíèå
    if (&t == this)
        return *this;
    min = t.min;
    sec = t.sec;
    return *this;
}
// ïåðåãðóçêà ïðåôèêñíîé îïåðàöèè èíêðåìåíò
Time& Time::operator++()
{
    int temp = min * 60 + sec;
    temp++;
    min = temp / 60;
    sec = temp % 60;
    return *this;
}
// ïåðåãðóçêà ïîñòôèêñíîé îïåðàöèè èíêðåìåíò
Time Time::operator++(int)
{
    int temp = min * 60 + sec;
    temp++;
    Time t(min, sec);
    min = temp / 60;
    sec = temp % 60;
    return t;
}
// ïåðåãðóçêà áèíàðíîé îïåðàöèè ñëîæåíèÿ

Time Time::operator-(const Time& t)
{
    int temp1 = min * 60 + sec;
    int temp2 = t.min * 60 + t.sec;
    Time p;
    p.min = (temp1 - temp2) / 60;
    p.sec = (temp1 - temp2) % 60;
    return p;
}
// ïåðåãðóçêà ãëîáàëüíîé ôóíêöèè-îïåðàöèè ââîäà
istream& operator>>(istream& in, Time& t)
{
    cout << "min?";
    in >> t.min;
    cout << "sec?";
    in >> t.sec;
    return in;
}
// ïåðåãðóçêà ãëîáàëüíîé ôóíêöèè-îïåðàöèè âûâîäà
ostream& operator<<(ostream& out, const Time& t)
{

    return (out << t.min << " : " << t.sec);
}
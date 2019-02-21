#include <iostream>
#include <cmath>

using namespace std;

//思路见https://blog.csdn.net/Dodd9199/article/details/82750621
//代码参考https://blog.csdn.net/wust_cyl/article/details/78159880

const double PI = acos(-1.0);

//二维点
struct point
{
    double x;
    double y;
} a, b, c;

//欧式距离
double L2(point p1, point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

//浮点数求最大公约数
double fgcd(double a, double b)
{
    if (fabs(b) < 1e-2) //->0
        return a;
    return fgcd(b, fmod(a, b));
}

int main()
{
    while (~scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y))
    {
        //计算三角形边长
        double ab = L2(a, b);
        double ac = L2(a, c);
        double bc = L2(b, c);
        //求三角形三个内角
        double A = acos((ac * ac + ab * ab - bc * bc) / (2 * ac * ab));
        double C = acos((ac * ac + bc * bc - ab * ab) / (2 * ac * bc));
        double B = acos((bc * bc + ab * ab - ac * ac) / (2 * bc * ab));
        //这三个内角是圆周角,相应的圆心角是圆周角的两倍
        double AOB = 2 * C;
        double AOC = 2 * B;
        double BOC = 2 * A;
        //计算外接圆半径R.使用公式:K=2Rsin(n/2) K=弦长;n=弦所对的圆心角
        double R = ab / (2 * sin(C));
        //计算圆心角的最大公约数,即为"最小的正多边形任意边对应的圆心角"
        double _O_ = fgcd(fgcd(AOB, AOC), fgcd(AOC, BOC));
        //计算有多少条边(就有多少小三角形)
        double lnum = 2 * PI / _O_; //用double提升一下精度
        //三角形面积=底*高/2=(边1*边2*sinθ)/2
        printf("%.8f\n", 0.5 * R * R * sin(_O_) * lnum);
    }
    return 0;
}
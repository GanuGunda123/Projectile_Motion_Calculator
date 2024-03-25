//Amaan Khan
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>  
using namespace std;
//Projectile Motion Range Calculator

const double gravity = 9.8;
const double PI = 3.14;

class Projectile
{
	public:
		Projectile()
		{
			intialVelocity = 0.0;
			Height = 0.0;
		}
		double findXVelocity(double IVelocity, double angle)
		{
			double xv = IVelocity * cos(angle * PI / 180.0);
			return xv;
		}
		double findYVelocity(double IVelocity, double angle)
		{
			double yv = IVelocity * sin(angle * PI / 180.0);
			return yv;
		}
		double findTime(double IVelocity, double height, double angle)
		{
			double a = -1 * (gravity / 2.0);
			double b = IVelocity * sin(angle * PI / 180.0);
			double c = height;
			double discriminant = b * b - 4 * a * c;
			double x1 = (-b + sqrt(discriminant)) / (2 * a);
			double x2 = (-b - sqrt(discriminant)) / (2 * a);
			if (x1 < 0)
			{
				return x2;
			}
			else
				return x1;
		}
		double maxHeight(double yvelocity, double angle)
		{
			double max = (pow(yvelocity, 2) * pow(sin(angle * PI / 180.0), 2) / (2 * gravity));
			return max;
		}
	private:
		double intialVelocity;
		double Height;

};


int main()
{
	cout << "Welcome to this Projectile Motion calculator.\n\nWhere we calculate the range and time a projectile goes given intial velocity and height " << endl;
	Projectile projectile;
	char cont = 'Y';

	do
	{
		cout << "Please Enter your Projectile's intial Velocity: ";
		double velocity;
		cin >> velocity;
		cout << endl;
		while (velocity < 0)
		{
			cout << "That is an invalid velocity. Please enter correct velocity: ";
			cin >> velocity;
		}
		cout << "Now enter your projectile's initial height: ";
		double height;
		cin >> height;
		cout << endl;
		while (height < 0)
		{
			cout << "That is an invalid height. Please enter correct height: ";
			cin >> height;
		}
		cout << "Now enter the angle (in degrees) at which your projectile is fired at: ";
		double angle;
		cin >> angle;
		cout << endl;
		while (angle < 0)
		{
			cout << "That is an invalid angle. Please enter correct angle: ";
			cin >> angle;
		}
		double x = projectile.findXVelocity(velocity, angle);
		double y = projectile.findYVelocity(velocity, angle);
		double time = projectile.findTime(velocity, height, angle);
		double range = x * time;
		cout << "The time it took your projectile to land was: " << time << "\n\nand the distance it covered was: " << range << endl;
		cout << endl;
		cout << "Thx for using me :). Would you like to find this info for more projectiles?. Enter 'Y' or 'N': ";
		cout << endl;
		cin >> cont;

	} while (cont == 'Y');
	if (cont == 'N')
		cout << "THX for Using me! :)\n";
	return 0;
	
}

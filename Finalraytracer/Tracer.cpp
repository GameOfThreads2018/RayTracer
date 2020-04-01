#include <iostream>
#include <fstream>
#include "Surfaces/Sphere.cpp"
#include "Surfaces/Plane.cpp"
#include "Surfaces/Surface.cpp"
#include "Utilities/Point3D.cpp"
#include "Utilities/Ray.cpp"
#include "Utilities/Normal.cpp"


using namespace std;

// Window dimensions
const int WIDTH = 512, HEIGHT = 512;

int main()
{
	ofstream outfile("render.ppm", ios_base::out);
	// Output to .ppm file
	outfile << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";
	// Output to command line
	std::cout << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";

	//viewing region on image plane 
	float l = -.1F;
	float r = .1F;
	float b = -.1F;
	float t = .1F;
	float d = .1F;

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			int i = (y * HEIGHT) + x;
			i *= 3;
			float u = (float)(l + (r - l) * (x + .5F) / 512);
			float v = (float)(b + (t - b) * (y + .5F) / 512);
			Ray viewingRay = Ray(Point3D(), Vector3D(u, v, -.1F));
			Sphere blueSphere = Sphere(Point3D(-4.0F, 0.0F, -7.0F), 1.0F);
			Sphere greenSphere = Sphere(Point3D(0.0F, 0.0F, -7.0F), 2.0F);
			Sphere redSphere = Sphere(Point3D(4.0F, 0.0F, -7.0F), 1.0F);
			Plane plane = Plane(Point3D(0.0F, -2.0F, 0.0F), Normal(0.0F, -2.0F, 0.0F));

			//if ray hits sphere then white color
			if (blueSphere.hit(viewingRay))
			{
				outfile << 255 << " " << 255 << " " << 255 << "\n";
			}
			else if (greenSphere.hit(viewingRay))
			{
				outfile << 255 << " " << 255 << " " << 255 << "\n";
			}
			else if (redSphere.hit(viewingRay))
			{
				outfile << 255 << " " << 255 << " " << 255 << "\n";
			}
			else         //color black if ray does not hit sphere
			{
				outfile << 0 << " " << 0 << " " << 0 << "\n";
			}
		}
	}
}

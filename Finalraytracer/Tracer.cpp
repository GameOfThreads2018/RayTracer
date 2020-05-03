#include <iostream>
#include <fstream>
#include "Surfaces/Sphere.cpp"
#include "Surfaces/Plane.cpp"
#include "Surfaces/Surface.cpp"
#include "Utilities/Point3D.cpp"
#include "Utilities/Ray.cpp"
#include "Utilities/Normal.cpp"
#include "Utilities/Vector3D.cpp"
#include "Lights/Light.cpp"

using namespace std;
// Window dimensions
const int WIDTH = 512, HEIGHT = 512;

Vector3D shade(Ray& ray, Sphere& redSphere, Sphere& greenSphere, Sphere& blueSphere, Plane& plane);

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

	for (int y = HEIGHT -1 ; y >= 0; y--)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			// index shifting 
			int i = (y * HEIGHT) + x;
			i *= 3;
			// creating viewing rays
			float u = (float)(l + (r - l) * (x + .5F) / 512);
			float v = (float)(b + (t - b) * (y + .5F) / 512);
			// Setup scene 3 spheres and one plane
			Sphere redSphere = Sphere(Point3D(-4.0F, 0.0F, -7.0F), 1.0F);
			Sphere greenSphere = Sphere(Point3D(0.0F, 0.0F, -7.0F), 2.0F);
			Sphere blueSphere = Sphere(Point3D(4.0F, 0.0F, -7.0F), 1.0F);
			Plane plane = Plane(Point3D(0.0F, -2.0F, 0.0F), Normal(0.0F, -2.0F, 0.0F));

			Ray viewingRay = Ray(Point3D(), Vector3D(u, v, -.1F));
			Vector3D result = shade(viewingRay, redSphere, greenSphere, blueSphere, plane);
			outfile << result.x * 255 << " " << result.y *255 << " " << result.z *255 << "\n";
		}
	}
}

	Vector3D shade(Ray &ray, Sphere& redSphere, Sphere& greenSphere, Sphere& blueSphere, Plane& plane)
	{
		Vector3D Ls = Vector3D();
		Vector3D Ld = Vector3D();
		
		if (redSphere.hit(ray))
		{
			Vector3D ka = Vector3D(0.2F, 0.0F, 0.0F);
			Vector3D kd = Vector3D(1.0F, 0.0F, 0.0F);
			Vector3D ks = Vector3D(0.0F, 0.0F, 0.0F);
			Vector3D hit_point = redSphere.calculateInersectPoint(ray);
			Vector3D surface_normal = redSphere.calculateNormal(ray);
			Light light = Light(Point3D(), Vector3D(-4.0F, 4.0F, -3.0F) - hit_point);
			light.normalize();
			surface_normal.normalize();
			Ld = kd * fmax(0.0F, surface_normal.dotProduct(light.direction));
			ray.normalize();
			Vector3D h = ray.getDirection() - light.direction;
			h.normalize();
			Ls = ks * powf(surface_normal.dotProduct(h), 0);
			return (Ld +Ls);
		}
		
		
		else if (greenSphere.hit(ray))
		{
			Vector3D ka = Vector3D(0.0F, 0.2F, 0.0F);
			Vector3D kd = Vector3D(0.0F, 0.5F, 0.0F);
			Vector3D ks = Vector3D(0.5F, 0.5F, .5F);

			Vector3D hit_point = greenSphere.calculateInersectPoint(ray);
			Vector3D surface_normal = greenSphere.calculateNormal(ray);
			Light light = Light(Point3D(), Vector3D(-4.0F, 4.0F, -3.0F) - hit_point);
			light.normalize();
			surface_normal.normalize();
			Ld = kd * fmax(0.0F, surface_normal.dotProduct(light.direction));
			ray.normalize();
			Vector3D h = ray.getDirection() - light.direction;
			h.normalize();
			Ls = ks * powf(surface_normal.dotProduct(h), 32);
			return (Ld + Ls);
		}
		else if (blueSphere.hit(ray))
		{
			Vector3D ka = Vector3D(0.0F, 0.0F, 0.2F);
			Vector3D kd = Vector3D(0.0F, 0.0F, 1.0F);
			Vector3D ks = Vector3D(0.0F, 0.0F, 0.0F);
		
			Vector3D hit_point = blueSphere.calculateInersectPoint(ray);
			Vector3D surface_normal = blueSphere.calculateNormal(ray);
			Light light = Light(Point3D(), Vector3D(-4.0F, 4.0F, -3.0F) - hit_point);
			light.normalize();
			surface_normal.normalize();
			Ld = kd * fmax(0.0F, surface_normal.dotProduct(light.direction));
			ray.normalize();
			Vector3D h = ray.getDirection() - light.direction;
			h.normalize();
			Ls = ks * powf(surface_normal.dotProduct(h), 0);
			return (Ld + Ls);
		}
		
		if (plane.hit(ray))
		{
			Vector3D ka = Vector3D(.2F, .2F, .2F);
			Vector3D kd = Vector3D(1.0F, 1.0F, 1.0F);
			Vector3D ks = Vector3D(0.0F, 0.0F, 0.0F);

			Vector3D hit_point = plane.calculateIntersectPoint(ray);
			Vector3D surface_normal = Vector3D(0.0F, 1.0F, 0.0F);
			Light light = Light(Point3D(), Vector3D(-4.0F, 4.0F, -3.0F) - hit_point);
			light.normalize();
			surface_normal.normalize();
			Ld = kd * fmax(0.0F, surface_normal.dotProduct(light.direction));
			ray.normalize();
			Vector3D h = ray.getDirection() - light.direction;
			h.normalize();
			Ls = ks * powf(surface_normal.dotProduct(h), 0);
			return (Ld + Ls);
		}
		
		else
		{
			return Vector3D();
		}
	}
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
void ceiling(Vector3D& v);

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
			Sphere red_sphere = Sphere(Point3D(-4.0F, 0.0F, -7.0F), 1.0F);
			Sphere green_sphere = Sphere(Point3D(0.0F, 0.0F, -7.0F), 2.0F);
			Sphere blue_sphere = Sphere(Point3D(4.0F, 0.0F, -7.0F), 1.0F);
			Plane plane = Plane(Point3D(0.0F, -2.0F, 0.0F), Normal(0.0F, -2.0F, 0.0F));

			Ray viewing_ray = Ray(Point3D(), Vector3D(u, v, -.1F));
			Vector3D result = shade(viewing_ray, red_sphere, green_sphere, blue_sphere, plane);
			outfile << result.x * 255.0F << " " << result.y * 255.0F << " " << result.z * 255.0F << "\n";
		}
	}
}

	Vector3D shade(Ray &ray, Sphere& red_sphere, Sphere& green_sphere, Sphere& blue_sphere, Plane& plane)
	{
		Vector3D Ls = Vector3D();
		Vector3D Ld = Vector3D();
		
		if (red_sphere.hit(ray))
		{
			Vector3D ka = Vector3D(0.2F, 0.0F, 0.0F);
			Vector3D kd = Vector3D(1.0F, 0.0F, 0.0F);
			Vector3D ks = Vector3D(0.0F, 0.0F, 0.0F);
			Vector3D hit_point = red_sphere.calculateInersectPoint(ray);
			Vector3D surface_normal = red_sphere.calculateNormal(ray);
			Light light = Light(Point3D(), Vector3D(-4.0F, 4.0F, -3.0F) - hit_point);
			light.normalize();
			surface_normal.normalize();
			Ld = kd * fmax(0.0F, surface_normal.dotProduct(light.direction));
			ray.normalize();
			Vector3D h = ray.getDirection() - light.direction;
			h.normalize();
			Ls = ks * powf(surface_normal.dotProduct(h), 0);
			Vector3D L = Ld + Ls + ka;
			ceiling(L);
			return L;
		}
		
		
		else if (green_sphere.hit(ray))
		{
			Vector3D ka = Vector3D(0.0F, 0.2F, 0.0F);
			Vector3D kd = Vector3D(0.0F, 0.5F, 0.0F);
			Vector3D ks = Vector3D(0.5F, 0.5F, .5F);

			Vector3D hit_point = green_sphere.calculateInersectPoint(ray);
			Vector3D surface_normal = green_sphere.calculateNormal(ray);
			Light light = Light(Point3D(), Vector3D(-4.0F, 4.0F, -3.0F) - hit_point);
			light.normalize();
			surface_normal.normalize();
			Ld = kd * fmax(0.0F, surface_normal.dotProduct(light.direction));
			ray.normalize();
			Vector3D h = ray.getDirection() - light.direction;
			h.normalize();
			Ls = ks * powf(surface_normal.dotProduct(h), 32);
			Vector3D L = Ld + Ls + ka;
			ceiling(L);
			return L;
		}
		
		else if (blue_sphere.hit(ray))
		{
			Vector3D ka = Vector3D(0.0F, 0.0F, 0.2F);
			Vector3D kd = Vector3D(0.0F, 0.0F, 1.0F);
			Vector3D ks = Vector3D(0.0F, 0.0F, 0.0F);
		
			Vector3D hit_point = blue_sphere.calculateInersectPoint(ray);
			Vector3D surface_normal = blue_sphere.calculateNormal(ray);
			Light light = Light(Point3D(), Vector3D(-4.0F, 4.0F, -3.0F) - hit_point);
			light.normalize();
			surface_normal.normalize();
			Ld = kd * fmax(0.0F, surface_normal.dotProduct(light.direction));
			ray.normalize();
			Vector3D h = ray.getDirection() - light.direction;
			h.normalize();
			Ls = ks * powf(surface_normal.dotProduct(h), 0);
			Ray shadow_ray = Ray(Point3D(hit_point.x, hit_point.y, hit_point.z), light.direction);
			if (green_sphere.hit(shadow_ray))
			{
				return ka;
			}
			Vector3D L = Ld + Ls + ka;
			ceiling(L);
			return L;
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
			Ray shadow_ray = Ray(Point3D(hit_point.x, hit_point.y, hit_point.z), light.direction);
			Ld = kd * fmax(0.0F, surface_normal.dotProduct(light.direction));
			ray.normalize();
			Vector3D h = ray.getDirection() - light.direction;
			h.normalize();
			Ls = ks * powf(surface_normal.dotProduct(h), 0);

			if (blue_sphere.hit(shadow_ray))
			{
				return ka;
			}
			else if (red_sphere.hit(shadow_ray))
			{
				return ka;
			}
			else if (green_sphere.hit(shadow_ray))
			{
				return ka;
			}

			Vector3D L = Ld + Ls + ka;
			ceiling(L);
			return L;
		}
		
		else
		{
			return Vector3D();
		}
	}

	//cap all color components to the value 1
	void ceiling(Vector3D& v)
	{
		v.x = fminf(1.0F, v.x);
		v.y = fminf(1.0F, v.y);
		v.z = fminf(1.0F, v.z);
	}


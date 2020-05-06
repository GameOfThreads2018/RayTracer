# Raytracer

An object oriented approach of implementing the raytracing algorithm in C++, based in Visual Studio IDE. The Tracer.cpp consists of three spheres of different colors on top of a plane. Overall project is still a work in progress

**Project Structure**

- **Utilities**: This is the backbone of the project, most of the abstraction for the 3D math involved with the raytracer lives here. Because of the constant use of classes in the folder judicious use of inlining was used. 
- **Lights**: Color implementation taken off of the internet, sources are included in the file's comments.

**Intended Output**

- Pixel values are outputted to render.ppm. You can download GIMP or any other graphics editor to view .ppm files generated for this project.
For this project I personally used GIMP, the link provided below.
https://www.gimp.org/downloads/

**Current Features**

- Sphere and Plane rendering
- Blinn-Phong illumination model supported in Tracer.cpp
- Basic lighting supported

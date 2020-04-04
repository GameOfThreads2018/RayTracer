# Raytracer

An implementation of the Raytracing algorithm in C++ based in Visual Studio IDE. The main scene consists of three spheres of different colors on top a plane. Overall project is still a work in progress

# Project Structure

Utilities: This is the backbone of the project, most of the abstraction for the 3D math involved with the raytracer lives here.

Lights: this folder contains light and color .h and .cpp files. Color implementation taken off of the internet, sources are included in the file's comments.

Surfaces: this folder contains .h and .cpp files for Sphere and Plane objects.

# Intended Output
Pixel values are outputted to render.ppm. You can download GIMP or any other graphics editor to view .ppm files generated for this project.
For this project I personally used GIMP, the link provided below.
https://www.gimp.org/downloads/

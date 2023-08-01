#include <iostream>
#include <cmath>
#include "vector.h"

struct{
	point3 center;
	vector radius;
} sphere;

struct {
	point3 p;
	vec3 normal;
	float t;
} hitRecord;

void write_color(std::ostream &out, vec3 PixelColor){
	out << (int)(255.999 * PixelColor.x) << ' '
		<< (int)(255.999 * PixelColor.y) << ' '
		<< (int)(255.999 * PixelColor.z) << '\n';
}


float hit_sphere( point3 center, float radius, ray r, float t_min, float t_max, ) {
	vec3 oc = r.origin - center;
	float a = vector_lengthSquared(r.direction);
	float half_b =  dot(oc, r.direction);
	float c = vector_lengthSquared(oc) - radius*radius;
	float discriminant = half_b*half_b - a*c; 
	
	
	if (discriminant <  0) {
		return false;
	} 
	
	float sqrtd =  sqrt(discriminant);
	
	//find nearest root that lies in acceptable range
	float root = (-half_b - sqrtd) / a;
	if (root < t_min || t_max < root){
		root = (-half_b + sqrtd) / a; 
		if(root < t_min || t_max < root)
			return false;
	}
	
	rec.t
}
vec3 ray_color(ray r) {
	float t = hit_sphere(point3{0, 0, -1}, 0.5, r);
	if ( t > 0.0){
		vec3 N = unit_vector( at(r ,t) - vec3{0, 0, -1});
		return 0.5*vec3{N.x + 1, N.y + 1, N.z + 1};
	}
	
	vec3 unitDir = unit_vector(r.direction);
	t = 0.5*(unitDir.y + 1.0);
	vec3 res = (float(1.0 - t))*vec3{1.0, 1.0, 1.0}  + t*vec3{0.5, 0.7, 1.0};
	return res;
}

int main() {
	//Image H x W
	const float aspectRatio = 16.0 / 9.0;
	const int ImageWidth = 1080;
	const int ImageHeight = (int)(ImageWidth / aspectRatio);
	
	//camera
	float viewportHeight = 2.0;
	float viewportWidth = aspectRatio * viewportHeight;
	float focalLength = 1.0;
	vec3 f = { 0, 0, focalLength};
	
	vec3 origin = { 0, 0, 0};
	vec3 horizontal  = {viewportWidth, 0, 0};
	vec3 vertical = {0, viewportHeight, 0};
	vec3 lowerLeftCorner = origin - horizontal/2 - vertical/2 - f;
	
	//Return value 
	std::cout << "P3\n" << ImageWidth << ' ' << ImageHeight << "\n255\n";
	
	for (int j=ImageHeight-1; j >= 0; --j){
		std::cerr << "\rScanlines remaining " << j << ' ' << std::flush;
		for (int i=0; i < ImageWidth; ++i){
			float u = float(i) / (ImageWidth-1);
			float v = float(j) / (ImageHeight-1);
			ray r = {origin, lowerLeftCorner + u*horizontal + v*vertical - origin};
			vec3 PixelColor = ray_color(r);
			write_color(std::cout, PixelColor);
		}
	}
	
	std::cerr << "\nDone.\n";
}
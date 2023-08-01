/* date = July 31st 2023 2:39 pm */

#ifndef VECTOR_H
#define VECTOR_H

struct vec3{
	float x;
	float y;
	float z;
};

struct ray {
	vec3 origin;
	vec3 direction;
};

using point3 = vec3;

vec3 operator+ (vec3 a, vec3 b){
	vec3 c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return c;
}

vec3 operator- (vec3 a, vec3 b){
	vec3 c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return c;
}

vec3 operator/ (vec3 a, vec3 b){
	vec3 c;
	c.x = a.x/b.x;
	c.y = a.y/b.y;
	c.z = a.z/b.z;
	return c;
}

vec3 operator/ (vec3 a, float t){
	vec3 c;
	c.x = a.x/t;
	c.y = a.y/t;
	c.z = a.z/t;
	return c;
}

vec3 operator* (float t, vec3 a){
	vec3 c;
	c.x = a.x * t;
	c.y = a.y * t;
	c.z = a.z * t;
	return c;
}

float vector_length(vec3 v){
	return sqrt( v.x*v.x + v.y*v.y + v.z*v.z);
}

float vector_lengthSquared(vec3 v){
	return v.x*v.x + v.y*v.y + v.z*v.z;
}

vec3 unit_vector(vec3 v){
	return v / vector_length(v);
}

float dot( vec3 v, vec3 u) {
	return v.x * u.x + v.y * u.y + v.z * u.z;
}

point3 at(ray r ,float t) {
	return r.origin + t * r.direction;
}

#endif //VECTOR_H

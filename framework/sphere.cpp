#include "sphere.hpp"
#include <cmath>

Sphere::Sphere(): 
 	Shape{"Sphere",{0.0f,0.0f,0.0f}}, radius_{0.0f}, center_{0.0f,0.0f,0.0f} {}
 
Sphere::Sphere(float const& radius, glm::vec3 const& center): 
 	Shape{"Sphere",{0.0f,0.0f,0.0f}}, radius_{radius}, center_{center} {}
 
Sphere::Sphere(std::string const& name, Color const& color, 
 	float const& radius, glm::vec3 const& center): 
 		Shape{name,color}, radius_{radius}, center_{center} {}
 
float const& Sphere::getRadius() const{
 	return radius_;
}
 
glm::vec3 const& Sphere::getCenter() const{
 	return center_;
}
 
float Sphere::area() const{
 	return 4.0f * M_PI * radius_ * radius_;
}
 
float Sphere::volume() const{
 	return (4.0f/3.0f)*M_PI*radius_*radius_*radius_;
}
 
std::ostream& Sphere::print(std::ostream& os) const {
     Shape::print(os);
     os << "Center: <" << center_.x << ", " 
     << center_.y << ", " 
     << center_.z << ">" << "\n" 
     << "Radius: " << radius_ 
     << std::endl;
     return os;
}
 
bool Sphere::intersect(Ray const& ray, float& distance) const{
	return glm::intersectRaySphere(ray.origin,ray.direction,center_,radius_*radius_,distance);
}

#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include <iostream>
#include "shape.hpp"
#include "ray.hpp"
#include "color.hpp"

class Sphere : public Shape{
 public:
 	Sphere();
 	Sphere(float const& radius, glm::vec3 const& center);
 	Sphere(std::string const& name, Color const& color, 
 	float const& radius, glm::vec3 const& center);
 	float const& getRadius() const;
 	glm::vec3 const& getCenter() const;
 	float area() const override;
 	float volume() const override;
 
 	std::ostream& print(std::ostream& os) const override;
 
 	bool intersect(Ray const& ray, float& distance) const;
 private:
 	float radius_;
 	glm::vec3 center_;
 
};
 
#endif
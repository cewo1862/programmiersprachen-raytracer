#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
 
#include <glm/vec3.hpp>
#include <iostream>
#include "shape.hpp"
#include <string>
 
class Box : public Shape{
public:
 	Box();
 	Box(glm::vec3 const& min, glm::vec3 const& max);
 	Box(std::string const& name, Color const& color, glm::vec3 const& min, glm::vec3 const& max);
 	glm::vec3 const& getMin() const;
 	glm::vec3 const& getMax() const;
 	float area() const override;
 	float volume() const override;

	std::ostream& print(std::ostream& os) const override;
private:
 	glm::vec3 min_;
 	glm::vec3 max_;
};
 
#endif
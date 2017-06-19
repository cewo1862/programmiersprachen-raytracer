#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
 
#include <glm/vec3.hpp>
#include "color.hpp"
#include <string>
#include <iostream>

class Shape{
public:
 	Shape();
 	Shape(std::string const& name, Color const& color);
	virtual ~Shape();
 	virtual float area() const = 0;
 	virtual float volume() const = 0;
 	std::string const& getName() const;
 	Color const& getColor() const;
 
 	virtual std::ostream& print(std::ostream& os) const;
 
protected:
 	std::string name_;
 	Color color_;
 };
 
 std::ostream& operator<<(std::ostream& os, Shape const& s);
 
#endif
#include "shape.hpp"
#include <string>
 
Shape::Shape(): name_{"Shape"}, color_{0.0f,0.0f,0.0f} {
	std::cout << name_ << ": shape constructed" << std::endl;
}
 
Shape::Shape(std::string const& name, Color const& color): 
	name_{name}, color_{color} {
		std::cout << name_ << ": shape constructed" << std::endl;
	}
 
std::string const& Shape::getName() const{
 	return name_;
}
 
Color const& Shape::getColor() const{
 	return color_;
}
 
std::ostream& Shape::print(std::ostream& os) const{
 	os << "Name: " << name_ << "\n"
 	<< "Color (RGB): ("<<color_.r<<","<<color_.g<<","<<color_.b<<")\n";
 	return os;
}

Shape::~Shape(){
	std::cout << name_ << ": shape destroyed" << std::endl;
}
 
std::ostream& operator << (std::ostream& os, Shape const& s){
 	return s.print(os);
}
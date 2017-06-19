#include "box.hpp"
 
Box::Box(): Shape {"Box",{0.0f, 0.0f, 0.0f}}, min_{0.0f,0.0f,0.0f}, max_{0.0f,0.0f,0.0f} {}
 
Box::Box(glm::vec3 const& min, glm::vec3 const& max): Shape {"Box",{0.0f, 0.0f, 0.0f}}, min_{min}, max_{max} {}

Box::Box(std::string const& name, Color const& color, glm::vec3 const& min, glm::vec3 const& max): Shape {name,color}, min_{min}, max_{max} {}
 
glm::vec3 const& Box::getMin() const{
 	return min_;
}
 
glm::vec3 const& Box::getMax() const{
 	return max_;
}
 
float Box::area() const{
 	return 2*((max_.x-min_.x)*(max_.y-min_.y))+
 	2*((max_.x-min_.x)*(max_.z-min_.z))+
 	2*((max_.y-min_.y)*(max_.z-min_.z));

}
 

 float Box::volume() const{
 	return (max_.x-min_.x)*(max_.y-min_.y)*(max_.z-min_.z);
}

std::ostream& Box::print(std::ostream& os) const {
    Shape::print(os);
    os << "Minimum:"<<min_.x<<","<<min_.y<<","<<min_.z<<"\n"<<
    "Maximum:"<<max_.x<<","<<max_.y<<","<<max_.z<<std::endl;
    return os;
}
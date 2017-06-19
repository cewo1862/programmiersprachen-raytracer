#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <shape.hpp>
#include <box.hpp>
#include <sphere.hpp>
#include <string>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>

TEST_CASE("describe_defaultBox","[aufgabe2]")
{
	Box b{};
	REQUIRE(b.getName()=="Box");
	REQUIRE(b.getMin().x==0.0f);
	REQUIRE(b.getMin().y==0.0f);
	REQUIRE(b.getMin().z==0.0f);
	REQUIRE(b.getMax().x==0.0f);
	REQUIRE(b.getMax().y==0.0f);
	REQUIRE(b.getMax().z==0.0f);
}

TEST_CASE("describe_customBox","[aufgabe2]")
{
	Box b1{{0.2f,0.3f,0.4f},{0.5f,0.6f,0.7f}};
	REQUIRE(b1.getName()=="Box");
	REQUIRE(b1.getMin().x==0.2f);
	REQUIRE(b1.getMin().y==0.3f);
	REQUIRE(b1.getMin().z==0.4f);
	REQUIRE(b1.getMax().x==0.5f);
	REQUIRE(b1.getMax().y==0.6f);
	REQUIRE(b1.getMax().z==0.7f);

	/*Box b2{"CustomBox",{},{0.2f,0.3f,0.4f},{0.5f,0.6f,0.7f}};
	REQUIRE(b2.getName()=="CustomBox");
	REQUIRE(b2.getMin().x==0.2f);
	REQUIRE(b2.getMin().y==0.3f);
	REQUIRE(b2.getMin().z==0.4f);
	REQUIRE(b2.getMax().x==0.5f);
	REQUIRE(b2.getMax().y==0.6f);
	REQUIRE(b2.getMax().z==0.7f);*/
}


TEST_CASE("describe_BoxArea","[aufgabe2]")
{
	Box b1{{0.2f,0.3f,0.4f},{0.5f,0.6f,0.7f}};
	REQUIRE(b1.area()==0.54f);
	Box b2{{2.0f,3.0f,4.0f},{5.0f,6.0f,7.0f}};
	REQUIRE(b2.area()==54.0f);
	Box b3{{2.6f,1.0f,3.0f},{7.3f,6.0f,8.3f}};
	REQUIRE(b3.area()==Approx(149.82));
}

TEST_CASE("describe_BoxVolume","[aufgabe2]")
{
	Box b1{{0.2f,0.3f,0.4f},{0.5f,0.6f,0.7f}};
	REQUIRE(b1.volume()==Approx(0.027f));
	Box b2{{2.0f,3.0f,4.0f},{5.0f,6.0f,7.0f}};
	REQUIRE(b2.volume()==27.0f);
	Box b3{{2.6f,1.0f,3.0f},{7.3f,6.0f,8.3f}};
	REQUIRE(b3.volume()==Approx(124.55));
}

TEST_CASE("describe_defaultSphere","[aufgabe2]")
{
	Sphere s{};
	REQUIRE(s.getName()=="Sphere");
	REQUIRE(s.getRadius()==0.0f);
	REQUIRE(s.getCenter().x==0.0f);
	REQUIRE(s.getCenter().y==0.0f);
	REQUIRE(s.getCenter().z==0.0f);
}
TEST_CASE("describe_customSphere","[aufgabe2]")
{
	Sphere s1{5.0f,{1.0f,2.0f,3.0f}};
	REQUIRE(s1.getName()=="Sphere");
	REQUIRE(s1.getRadius()==5.0f);
	REQUIRE(s1.getCenter().x==1.0f);
	REQUIRE(s1.getCenter().y==2.0f);
	REQUIRE(s1.getCenter().z==3.0f);

	/*Sphere s2{"CustomSphere",{},{},{1.0f,2.0f,3.0f}};
	REQUIRE(s2.getName()=="CustomSphere");
	REQUIRE(s2.getRadius()==5.0f);
	REQUIRE(s2.getCenter().x==1.0f);
	REQUIRE(s2.getCenter().y==2.0f);
	REQUIRE(s2.getCenter().z==3.0f);*/
}
TEST_CASE("describe_SphereArea","[aufgabe2]")
{
	Sphere s{5.0f,{0.0f,0.0f,0.0f}};
	REQUIRE(s.area()==Approx(314.159));
}

TEST_CASE("describe_SphereVolume","[aufgabe2]")
{
	Sphere s{5.0f,{0.0f,0.0f,0.0f}};
	REQUIRE(s.volume()==Approx(523.599));

}

TEST_CASE ( "intersectRaySphere" , "[intersect]"){

glm :: vec3 ray_origin {0.0 ,0.0 ,0.0};
glm :: vec3 vect = {1.0,1.5,1.3};
glm :: vec3 v;
v = glm :: normalize(vect);
glm :: vec3 ray_direction {0.0 ,0.0 ,1.0};

glm :: vec3 sphere_center {0.0 ,0.0 ,5.0};
float sphere_radius {1.0};
float distance {0.0};
auto result = glm :: intersectRaySphere(ray_origin , ray_direction ,sphere_center ,sphere_radius * sphere_radius ,distance );
REQUIRE ( distance == Approx(4.0f));
}
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

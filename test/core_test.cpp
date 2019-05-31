
#include "catch.h"

#include "Module.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

TEST_CASE("ModuleTest", "load")
{
  auto render = Module::LoadModule("Render");
  REQUIRE(render != nullptr);
}

TEST_CASE("VectorTest", "reflect")
{
  auto v1 = Vector3f{-1, -1, 0};
  auto ref = v1.reflect({0, 1, 0});
  REQUIRE(ref.x == -1);
  REQUIRE(ref.y == 1);
}

TEST_CASE("MathTest", "lerp")
{
  auto v1 = Vector3f{1, 2, 4};
  auto v2 = Vector3f{1, 3, 6};
  auto l = math::lerp(v1, v2, 0.5);
  REQUIRE(l.y == 2.5);
  REQUIRE(l.z == 5);

  REQUIRE(math::lerp(0.0, 1.0, 0.5) == 0.5);
}

TEST_CASE("Vector::Project", "project")
{
  auto v1 = Vector3f{1, 2, 0};
  auto v2 = Vector3f{1, 0, 0};
  auto l = v1.project(v2);
  REQUIRE(l.y == 0);
  REQUIRE(l.x == 1);

  auto y = v1.project({0, 1, 0});
  auto z = v1.project({0, 0, 1});

  REQUIRE(y.x == 0);
  REQUIRE(y.y == 2);
  REQUIRE(z.x == 0);
  REQUIRE(z.y == 0);
  REQUIRE(z.z == 0);
}

TEST_CASE("Vector::distance", "distance")
{
  auto v1 = Vector3f{1, 2, 4};
  auto v2 = Vector3f{1, 3, 4};
  auto d = v1.distance(v2);
  auto d2 = v2.distance(v1);
  REQUIRE(d == d2);
  REQUIRE(d == 1);
}
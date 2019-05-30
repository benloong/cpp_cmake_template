
#include "utest.h"

#include "Module.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

UTEST(ModuleTest, load)
{
  auto render = Module::LoadModule("Render");
  ASSERT_TRUE(render != nullptr);
  Module::UnloadModule("Render");
}

UTEST(VectorTest, reflect)
{
  auto v1 = Vector3f{-1, -1, 0};
  auto ref = v1.reflect({0, 1, 0});
  ASSERT_TRUE(ref.x == -1);
  ASSERT_TRUE(ref.y == 1);
}

UTEST(MathTest, lerp)
{
  auto v1 = Vector3f{1, 2, 4};
  auto v2 = Vector3f{1, 3, 6};
  auto l = math::lerp(v1, v2, 0.5);
  ASSERT_TRUE(l.y == 2.5);
  ASSERT_TRUE(l.z == 5);

  ASSERT_EQ(math::lerp(0.0, 1.0, 0.5), 0.5);
}

UTEST(VectorTest, project)
{
  auto v1 = Vector3f{1, 2, 0};
  auto v2 = Vector3f{1, 0, 0};
  auto l = v1.project(v2);
  ASSERT_TRUE(l.y == 0);
  ASSERT_TRUE(l.x == 1);

  auto y = v1.project({0, 1, 0});
  auto z = v1.project({0, 0, 1});

  ASSERT_EQ(y.x, 0);
  ASSERT_EQ(y.y, 2);
  ASSERT_EQ(z.x, 0);
  ASSERT_EQ(z.y, 0);
  ASSERT_EQ(z.z, 0);
}

UTEST(VectorTest, distance)
{
  auto v1 = Vector3f{1, 2, 4};
  auto v2 = Vector3f{1, 3, 4};
  auto d = v1.distance(v2);
  auto d2 = v2.distance(v1);
  ASSERT_EQ(d, d2);
  ASSERT_EQ(d, 1);
}
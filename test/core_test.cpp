
#include "utest.h"

#include "Module.h"

UTEST(CoreTest, test1)
{
  ASSERT_TRUE(1);
}

UTEST(CoreTest, module)
{
  auto render = Module::LoadModule("Render");
  ASSERT_TRUE(render != nullptr);
}
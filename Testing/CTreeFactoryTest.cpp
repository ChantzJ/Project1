#include "stdafx.h"
#include "CppUnitTest.h"
#include "BugFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CTreeFactoryTest)
	{
	public:
		
		TEST_METHOD(TestCTreeFactoryCreate)
		{

            CBugFactory factory;
            auto tree = factory.CreateBug();
            Assert::IsTrue(tree != nullptr);
		}

	};
}
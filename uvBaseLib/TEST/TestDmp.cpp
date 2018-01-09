#include <conio.h>
#include <assert.h>
#include "TestDmp.h"
#include "ExceptionHandler.h"

#ifdef NDEBUG
#undef NDEBUG
#endif

CTestDmp::CTestDmp()
{

}

CTestDmp::~CTestDmp()
{

}

void CTestDmp::Dump()
{
	assert(0);
	printf("never print.\n");
}

////////////////////////////////////////////////////////////////////////////////

#include "Configure.h"

#ifdef TEST_DMP

int main(int argc, char** argv)
{
	GEH.StartMonitor("TCS");
	GEH.PreventOtherExceptionHandler();

	CTestDmp* dump = new CTestDmp;
	dump->Dump();
	return 0;
}

#endif

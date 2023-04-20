#include "../util/common.h"
#include "../UI/UI.h"
namespace base
{
	void main()
	{

		while (true)
		{
			GUI::tick();
			WAIT(0);
		}
	}

	void ScriptMain()
	{
		srand(GetTickCount());
		main();
	}
}
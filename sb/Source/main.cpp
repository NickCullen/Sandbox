#include <stdio.h>

#include "Core/Engine.h"
#include "Core/LuaState.h"

#include <vector>
#include <string>

using namespace std;

vector<string> ArgsToVector(int argc, char** argv)
{
	vector<string> ret;
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
			ret.push_back(argv[i]);
	}
	return ret;
}

int main(int argc, char** argv)
{
	Engine e;

	if (e.Initialize() == false)
	{
		printf("Could not initialize engine\n");

		return -1;
	}

	vector<string> args = ArgsToVector(argc, argv);

	string file = SB_LUA_DIR + args[0] + ".lua";

	lua_State* state = LuaState::L;


	// start array structure
	lua_newtable(state);

	for (int i = 1; i < args.size(); i++)
	{
		// set first element "1" to value 45
		lua_pushnumber(state, i);
		lua_pushstring(state, args[i].c_str());
		lua_rawset(state, -3);
	}
	

	// set the number of elements (index to the last array element)
	lua_pushliteral(state, "n");
	lua_pushnumber(state, args.size()-1);
	lua_rawset(state, -3);

	// set the name of the array that the script will access
	lua_setglobal(state, "arg");


	int status = luaL_loadfile(state, file.c_str());
	if (status != LUA_OK)
	{
		printf("Error loading file\n");
		char buff[512];
		scanf("%s", buff);
		return -1;
	}


	
	status = lua_pcall(state, 0, 0, 0);
	if (status != LUA_OK)
	{
		LuaState::PrintError();
		char buff[512];
		scanf("%s", buff);
		return -1;
	}

	return 0;
}
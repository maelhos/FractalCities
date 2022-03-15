#include "Debug.h"

int32_t printd(const std::string& message, e_ErrorLevel errLvl) {
	switch (errLvl)
	{
	case d_Info:
		if (DEBUG >= errLvl)
			std::cout << "[Info] : " << message << std::endl;
		return 0;
		break;
	case d_Warning:
		if (DEBUG >= errLvl)
			std::cout << "[Warning] : " << message << std::endl;
		return 0;
		break;
	case d_Error:
		if (DEBUG >= errLvl)
			fprintf(stderr, "[Error] : %s\n", message.c_str());
		return -1;
		break;
	default:
		break;
	}
	return 0;
}

int32_t checkd(bool cond, e_ErrorLevel errLvl) {
	if (!cond)
		return printd("Assertion failed", errLvl);
	return 0;
}

int32_t assertd(bool cond) {
	return checkd(cond, e_ErrorLevel::d_Error);
}
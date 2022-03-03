#pragma once

#include <Windows.h>
#include <debugapi.h>
#include <string>

namespace Shapes2D {
	enum class Shapes2DExceptions {
		DIVIDE_BY_ZERO=0, NO_COLLISION_POI, NO_SHAPE_LINES, INVALID_INDEX, NUM_EXCEPTIONS
	};

	struct ExceptionMessages {
		std::wstring exceptionMessages[(int)Shapes2DExceptions::NUM_EXCEPTIONS] = {
			L"Divide by zero error in ", L"No close point of intersection found in ", L"Shape contains no lines in ", L"Invalid index received in "
		};

		void DisplayError(Shapes2DExceptions err, std::wstring function) {
			std::wstring output = exceptionMessages[(int)err] + function;
			OutputDebugStringA((LPCSTR)output.c_str());
		}
	};
}
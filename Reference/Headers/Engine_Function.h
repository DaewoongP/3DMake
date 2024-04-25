#pragma once
#include <iostream>
#include <cstring>

class DebugFunc
{
public:
	static void Text(const std::string& _text)
	{
#ifdef _DEBUG
		std::cout << _text << std::endl;
#endif // _DEBUG
	}
	static void Text(const std::string& _text, float _timeDelta, float _textTime = 1.f)
	{
#ifdef _DEBUG
		static float timeAcc = 0.f;
		timeAcc += _timeDelta;

		if (timeAcc >= _textTime)
		{
			std::cout << _text << std::endl;
			timeAcc = 0.f;
		}
#endif // _DEBUG
	}
};
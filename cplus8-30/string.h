#pragma once
namespace bit
{
	class string
	{
	public:
		string(const char* str)
			:_str(str)
		{

		}
	private:
		const char* _str;
	};
}
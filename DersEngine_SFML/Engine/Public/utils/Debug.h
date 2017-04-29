#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace DersEngine
{
	namespace Debug
	{
		struct any
		{
			enum type {Int, Float, String};
			any(int e) { m_data.INT = e; m_type = Int; }
			any(float e) { m_data.FLOAT = e; m_type = Float; }
			any(const char* e) { m_data.STRING = e; m_type = String; }
			type get_type() const { return m_type; }
			int get_int() const { return m_data.INT; }
			float get_float() const { return m_data.FLOAT; }
			const char* get_string() const { return m_data.STRING; }

		private:
			type m_type;
			union {
				int   INT;
				float FLOAT;
				const char* STRING;
			} m_data;
		};

		template <class ...Args>
		void Log_imp(const Args&... args)
		{
			std::vector<any> paramList = { args... };

			for (const auto& elem : paramList)
			{
				switch (elem.get_type()) 
				{
				case any::Int:
					std::cout << elem.get_int();
					break;
				case any::Float:
					std::cout << elem.get_float();
					break;
				case any::String:
					std::cout << elem.get_string();
					break;
				}
			}

			std::cout << "\n";
		}

		template <class ...Args>
		static void Log(Args... args)
		{
			Log_imp(any(args)...);
		}
	}
}
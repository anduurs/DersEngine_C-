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
			enum type {Int, Float, Double, String};

			any(int e) { m_Data.INT = e; m_Type = Int; }
			any(float e) { m_Data.FLOAT = e; m_Type = Float; }
			any(double e) { m_Data.DOUBLE = e; m_Type = Double; }
			any(const char* e) { m_Data.STRING = e; m_Type = String; }

			type get_type() const { return m_Type; }

			int get_int() const { return m_Data.INT; }
			float get_float() const { return m_Data.FLOAT; }
			double get_double() const { return m_Data.DOUBLE; }
			const char* get_string() const { return m_Data.STRING; }

		private:
			type m_Type;

			union 
			{
				int INT;
				float FLOAT;
				double DOUBLE;
				const char* STRING;
			} m_Data;
		};

		template <class ...Args>
		void LogImplementation(const Args&... args)
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
				case any::Double:
					std::cout << elem.get_double();
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
			LogImplementation(any(args)...);
		}
	}
}
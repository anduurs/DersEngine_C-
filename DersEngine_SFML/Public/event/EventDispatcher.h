#pragma once

#include <unordered_map>
#include <string>
#include <deque>
#include <functional>
#include <utility>    
#include <vector>

#include "utils/Debug.h"

namespace DersEngine
{
	namespace events
	{
		using namespace utils;

		class EventDispatcher
		{
			using EventTable = std::unordered_map<std::string, std::vector<std::function<void()>>>;
			using EventQueue = std::deque<std::string>;

		public:
			template<typename T>
			static void Register(const std::string& eventType, T&& eventDelegate)
			{
				GetEventTable()[eventType].emplace_back(std::forward<T>(eventDelegate));
			}

			static void Dispatch(const std::string& eventType)
			{
				GetEventQueue().emplace_back(eventType);
			}

			static void Notify(const std::string& eventType)
			{
				for (const auto& eventDelegate : GetEventTable()[eventType])
				{
					eventDelegate();
				}
			}

			static void ProcessEvents()
			{
				if (GetEventQueue().size() > 0)
				{
					std::string eventKey = GetEventQueue().front();
					GetEventQueue().pop_front();
			
					for (const auto& eventDelegate : GetEventTable()[eventKey])
					{
						eventDelegate();
					}
				}
			}

			static void UnRegister()
			{

			}

			static EventTable& GetEventTable()
			{
				static EventTable eventTable;
				return eventTable;
			}

			static EventQueue& GetEventQueue()
			{
				static EventQueue eventQueue;
				return eventQueue;
			}
		};

	}
}
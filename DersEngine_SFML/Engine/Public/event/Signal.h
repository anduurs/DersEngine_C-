#pragma once

#include <functional>
#include <unordered_map>
#include <vector>
#include <memory>
#include <algorithm>

namespace DersEngine 
{
	namespace events 
	{
		using token = std::shared_ptr<void>;

		template <class ...Args>
		class Signal
		{
			using target = std::function<void(Args...)>;
			using wp_target = std::weak_ptr<target>;
			using sp_target = std::shared_ptr<target>;

		private:
			std::vector<wp_target> m_Targets;

			sp_target make_target(target t) 
			{
				return std::make_shared<target>(std::move(t));
			}

			void CleanUp()
			{
				m_Targets.erase(
					std::remove_if(m_Targets.begin(), m_Targets.end(),
					[](wp_target t) 
					{
						return !t.lock(); 
					}), 
					m_Targets.end());
			}
		public:

			token AddListener(target callBackFunction)
			{
				auto t = make_target(std::move(callBackFunction));
				m_Targets.push_back(wp_target(t));
				return t;
			}

			void RemoveListener(token& t)
			{
				t.reset();
			}

			void Dispatch(Args... args)
			{
				CleanUp();

				for (auto wp : m_Targets)
				{
					if (auto sp = wp.lock())
					{
						(*sp)(args...);
					}
				}
			}
		};
	}
}
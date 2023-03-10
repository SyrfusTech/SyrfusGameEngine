#ifndef ITERABLE_STACK_GUARD
#define ITERABLE_STACK_GUARD

#include <vector>

namespace SyrfusGameEngine
{
	template <typename T>
	class IterableStack
	{
	public:
		inline IterableStack() = default;
		inline ~IterableStack() = default;

		inline void Push(T datum) { m_Data.push_back(datum); }
		inline T Pop() { T temp = m_Data[m_Data.size()]; m_Data.pop_back(); return temp; }
		inline unsigned int Size() { return m_Data.size(); }

		inline std::vector<T>::reverse_iterator begin() { return m_Data.rbegin(); }
		inline std::vector<T>::reverse_iterator end() { return m_Data.rend(); }
		inline std::vector<T>::iterator rbegin() { return m_Data.begin(); }
		inline std::vector<T>::iterator rend() { return m_Data.end(); }

		inline std::vector<T>::const_reverse_iterator begin() const { return m_Data.rbegin(); }
		inline std::vector<T>::const_reverse_iterator end() const { return m_Data.rend(); }
		inline std::vector<T>::const_iterator rbegin() const { return m_Data.begin(); }
		inline std::vector<T>::const_iterator rend() const { return m_Data.end(); }

	private:
		IterableStack(const IterableStack& other) = delete;
		IterableStack& operator=(const IterableStack& other) = delete;
		IterableStack(IterableStack&&) = delete;
		IterableStack& operator=(IterableStack&&) = delete;

	private:
		std::vector<T> m_Data;
	};
}

#endif
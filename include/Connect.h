#ifndef _UV_LIB_CONNECT_H_
#define _UV_LIB_CONNECT_H_

#include <vector>
#include <functional>

#define emit
#define slots
#define signals public
#define connect(sender, signal, slot) ((sender)->signal.bind(slot))

template<typename... Args>
class Slot
{
public:
	using OnFunc = std::function<void(Args&&...)>;

	Slot(const OnFunc& func) : m_func(func) {}

	void exec(Args&&... args)
	{
		m_func(std::forward<Args>(args)...);
	}

private:
	OnFunc m_func = nullptr;
};

template<typename... Args>
class Signal
{
public:
	using SlotPtr = std::shared_ptr<Slot<Args&&...>>;
	using OnFunc = std::function<void(Args&&...)>;

	void bind(const OnFunc& func)
	{
		SlotPtr s = std::make_shared<Slot<Args&&...>>(func);
		m_slotVec.emplace_back(s);
	}

	void operator()(Args&&... args)
	{
		for (auto& iter : m_slotVec) {
			iter->exec(std::forward<Args>(args)...);
		}
	}

private:
	std::vector<SlotPtr> m_slotVec;
};

#endif

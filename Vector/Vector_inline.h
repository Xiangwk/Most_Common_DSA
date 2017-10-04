#include "Vector.h"

namespace dsa
{
	template<typename T>
	std::allocator<T> Vector<T>::alloc = std::allocator<T>();

	template<typename T>
	void swap<T>(Vector<T> &lhs, Vector<T> &rhs)
	{
		using std::swap;
		swap(lhs.elements, rhs.elements);
		swap(lhs.firstFree, rhs.firstFree);
		swap(lhs.cap, rhs.cap);
	}

	template<typename T>
	Vector<T>::Vector(std::size_t n)
	{
		elements = alloc.allocate(n);
		firstFree = cap = std::uninitialized_fill_n(elements, n, T());
	}

	template<typename T>
	Vector<T>::Vector(const std::initializer_list<T> &li)
	{
		elements = alloc.allocate(li.size());
		if (elements)
			firstFree = cap = std::uninitialized_copy(li.begin(), li.end(), elements);
	}

	template<typename T>
	Vector<T>::Vector(const Vector<T> &v)
	{
		auto newdata = allocAndCopy(v.begin(), v.end());
		elements = newdata.first;
		firstFree = cap = newdata.second;
	}

	template<typename T>
	Vector<T>::~Vector()
	{
		free();
	}

	template<typename T>
	Vector<T>& Vector<T>::operator=(const Vector<T> &rhs)
	{
		auto newdata = allocAndCopy(rhs.begin(), rhs.end());
		free();
		elements = newdata.first;
		firstFree = cap = newdata.second;

		return *this;
	}

	template<typename T>
	void Vector<T>::push_back(const T &e)
	{
		checkAndAlloc();
		alloc.construct(firstFree++, e);
	}

	template<typename T>
	void Vector<T>::push_back(T &&e)
	{
		checkAndAlloc();
		alloc.construct(firstFree++, std::move(e));
	}

	template<typename T>
	void Vector<T>::pop_back()
	{
		if (empty())
		{
			std::cerr << "pop_back() on empty Vector!" << std::endl;
			std::abort();
		}
		alloc.destroy(--firstFree);
	}

	template<typename T>
	template<typename... Args>
	void Vector<T>::emplace_back(Args&&... args)
	{
		checkAndAlloc();
		alloc.construct(firstFree++, std::forward<Args>(args)...);
	}

	template<typename T>
	void Vector<T>::reserve(std::size_t n)
	{
		if (capacity() < n)
			reallocate(n);
	}

	template<typename T>
	void Vector<T>::resize(std::size_t n, const T &e)
	{
		std::size_t sz = size();
		if (sz < n)
		{

			for (std::size_t i = 0; i < n - sz; ++i)
				push_back(e);
		}
		else if (n < sz)
		{
			for (std::size_t i = 0; i < sz - n; ++i)
				alloc.destroy(--firstFree);
		}
		else
			return;
	}

	template<typename T>
	std::pair<T*, T*> Vector<T>::allocAndCopy(const T* b, const T *e)
	{
		if (b == e) return{ nullptr, nullptr };

		auto dest = alloc.allocate(e - b);
		auto last = std::uninitialized_copy(b, e, dest);

		return{ dest, last };
	}

	template<typename T>
	void Vector<T>::free()
	{
		//不能传递给deallocate一个空指针
		//对于空vector，由于我们没有分配内存，所有析构时什么也不做
		if (elements)
		{
			while (firstFree != elements)
				alloc.destroy(--firstFree);
			alloc.deallocate(elements, cap - elements);
		}
	}

	template<typename T>
	void Vector<T>::checkAndAlloc()
	{
		//注意对于一个空数组，扩容结果为1
		if (size() == capacity())
			reallocate(size() ? size() * 2 : 1);
	}

	template<typename T>
	void Vector<T>::reallocate(std::size_t newCapacity)
	{
		auto newdata = alloc.allocate(newCapacity);
		auto dest = newdata;
		auto elem = elements;
		std::size_t sz = size();
		//这里使用move，调用T的移动构造函数（如果有的话）来提高性能
		for (std::size_t i = 0; i < sz; ++i)
			alloc.construct(dest++, std::move(*elem++));
		free();
		elements = newdata;
		firstFree = dest;
		cap = elements + newCapacity;
	}
}
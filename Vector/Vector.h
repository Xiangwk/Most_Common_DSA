#pragma once
//在visual studio下用这个宏定义来解除编译器对uninitialize_copy的限制
#define _SCL_SECURE_NO_WARNINGS

#include <memory>
#include <utility>
#include <initializer_list>

//避免名称和标准库的有重复，我们使用自己的namespace
namespace dsa
{
	template<typename> class Vector;
	template<typename T>
	void swap(Vector<T> &lhs, Vector<T> &rhs);

	template<typename T>
	class Vector
	{
		friend void swap<T>(Vector<T> &lhs, Vector<T> &rhs);
	public:
		//对于默认构造的空vector，我们不分配内存
		Vector() : elements(nullptr), firstFree(nullptr), cap(nullptr) {}
		//用T的默认构造函数初始化一个有n个T元素的vector
		explicit Vector(std::size_t n);
		//使用初始化列表初始化一个vector
		Vector(const std::initializer_list<T> &li);

		//拷贝构造和拷贝赋值
		Vector(const Vector<T> &v);
		Vector<T>& operator=(const Vector<T> &rhs);

		~Vector();

		T* begin() const { return elements; }
		T* end() const { return firstFree; }
		std::size_t size() const { return firstFree - elements; }
		std::size_t capacity() const { return cap - elements; }
		bool empty() const { return elements == firstFree; }

		void push_back(const T &e);
		void push_back(T &&e);
		void pop_back();
		//直接使用T的构造函数在Vector中构造元素
		template<typename... Args>
		void emplace_back(Args&&...);

		void reserve(std::size_t);
		void resize(std::size_t n, const T &e = T());

	private:
		T *elements;
		T *firstFree;
		T *cap;

		//使用allocator来分配内存并构造vector中的元素
		//allocator可以将内存分配与对象构造分离，从而避免无意义的构造动作造成资源的浪费
		static std::allocator<T> alloc;

		//我们用这个功能函数来实现内存的分配以及元素的复制
		//因为在拷贝操作时都要用到，可以避免代码的重复
		std::pair<T*, T*> allocAndCopy(const T* b, const T *e);

		//由于赋值和析构中都需要释放资源，所以我们将释放资源的任务交给我们自己定义的功能函数
		//以此来避免代码的重复
		void free();

		void checkAndAlloc();
		void reallocate(std::size_t newCapacity);
	};
	
} //namespace dsa end

#include "Vector_inline.h"
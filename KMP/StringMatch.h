#pragma once

#include <string>

int* buildNext(const char *str);

#ifdef KMP__

//KMP
int match(const char *p, const char *s)
{
	int *next = buildNext(p);
	//这里注意一定要先把size()返回的值用int型保存，否则后面比较的时候会出问题，我们的i是有可能小于0的
	int m = strlen(p), n = strlen(s);
	int i = 0, j = 0;
	while (i < m && j < n)
	{
		//i < 0 的情况对应我们next表中的通配符-1，也就是比较操作从模式串的头重新开始，此操作之后，i为0，j递进一步
		if (i < 0 || p[i] == s[j])
		{
			++i; ++j;
		}
		else
		{
			//找到i应该回退到的位置
			i = next[i];
		}
	}
	delete[]next;

	return j - i;
}

#ifdef KMP_OPTIMIZE

int* buildNext(const char *p)
{
	int m = strlen(p);
	int *next = new int[m];

	int i = 0;
	int t = next[0] = -1;

	while (i < m - 1)
	{
		if (t < 0 || p[i] == p[t])
		{
			++i; ++t;
			next[i] = (p[i] != p[t] ? t : next[t]);
		}
		else
		{
			t = next[t];
		}
	}

	return next;
}

#else

int* buildNext(const char *p)
{
	int m = strlen(p);
	int i = 0;
	int *next = new int[m];
	int t = next[0] = -1;

	while (i < m - 1)
	{
		if (t < 0 || p[i] == p[t])
		{
			++i; ++t;
			next[i] = t;
		}
		else
		{
			t = next[t];
		}
	}

	return next;
}

#endif

#else

//brute
int match(const char *p, const char *s)
{
	size_t i = 0, j = 0;
	int m = strlen(p), n = strlen(s);
	while (i < m && j < n)
	{
		if (p[i] == s[j])
		{
			++i; ++j;
		}
		else
		{
			j = j - i + 1;
			i = 0;
		}
	}
	return j - i;
}

#endif
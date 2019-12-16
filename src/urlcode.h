
#ifndef __URLCODE_H_
#define __URLCODE_H_

__inline static
std::string url_encode(const std::string& d)
{
#define _INLINE_C_2_H(x) (unsigned char)(x > 9 ? x + 55 : x + 48)
	std::string e = "";
	std::size_t size = d.size();
	for (std::size_t i = 0; i < size; i++)
	{
		if (isalnum((unsigned char)d.at(i)) ||
			(d.at(i) == '-') ||
			(d.at(i) == '_') ||
			(d.at(i) == '.') ||
			(d.at(i) == '~'))
		{
			e.append(1, d.at(i));
		}
		else if (d.at(i) == ' ')
		{
			e.append(1, '+');
		}
		else
		{
			e.append(1, '%');
			e.append(1, _INLINE_C_2_H((unsigned char)d.at(i) >> 4));
			e.append(1, _INLINE_C_2_H((unsigned char)d.at(i) % 16));
		}
	}
	return e;
}

__inline static
std::string url_decode(const std::string& e)
{
#define __INLINE_H_2_C(x) ((x >= 'A' && x <= 'Z') ? (x - 'A' + 10) : ((x >= 'a' && x <= 'z') ? (x - 'a' + 10) : ((x >= '0' && x <= '9') ? (x - '0') : x)))
	std::string d = "";
	std::size_t size = e.size();
	for (std::size_t i = 0; i < size; i++)
	{
		if (e.at(i) == '+')
		{
			d.append(1, ' ');
		}
		else if (e.at(i) == '%')
		{
			if (i + 2 < size)
			{
				d.append(1, (unsigned char)(__INLINE_H_2_C((unsigned char)e.at(i + 1)) * 16 + __INLINE_H_2_C((unsigned char)e.at(i + 2))));
				i += 2;
			}
			else
			{
				for (; i < size; i++)
				{
					d.append(1, e.at(i));
				}
			}
		}
		else
		{
			d.append(1, e.at(i));
		}
	}
	return d;
}

#endif //__URLCODE_H_
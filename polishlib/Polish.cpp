#include "Polish.h"

int Polish::GetPriority(char op)
{
	switch (op) {
	case '*': return 3;
	case '/': return 3;
	case '+': return 2;
	case '-': return 2;
	case '(': return 1;
	case '=': return 0;
	default: return-1;
	}
}

int Polish::IsOperation(char op)
{
	if (op == ')' || op == '(' || op == '+' || op == '-' || op == '*' || op == '/' || op == '=')
		return 1;
	return 0;
}

Polish::Polish(char * exp)
{
	str = Convert(exp);
}

Polish::~Polish()
{
	delete[] str;
}

double Polish::Calculate()
{
	TStackList<int> st;
	int res;
	int i = 0;
	int j;
	while (str[i] != '=')
	{
		if (!IsOperation(str[i]))
		{
			j = 0;
			char* buff = new char[strlen(str)];
			while (str[i] != ' ')
				buff[j++] = str[i++];
			buff[j] = '\n';
			st.Put(atoi(buff));
			delete[] buff;
		}
		else
		{
			double x, y;
			y = st.Get();
			x = st.Get();
			double z;
			switch (str[i])
			{
			case '*': z = x * y;
				break;
			case '/': z = x / y;
				break;
			case '+': z = x + y;
				break;
			case '-': z = x - y;
				break;
			default: 
				throw(1);
			}
			st.Put(z);
		}
		i++;
	}
	res = st.Get();
	return res;
}

char* Polish::Convert(char * exp)
{
	TStackList<char> operation, polish;
	int i = 0;
	char t;
	while (i < strlen(exp))
	{
		if (!IsOperation(exp[i]))
		{
			while (!IsOperation(exp[i]))
			{
				polish.Put(exp[i++]);
			}
			i--;
			polish.Put(' ');
		}
		else if (exp[i] == '(')
			operation.Put('(');
		else if (exp[i] == ')')
		{
			while (1)
			{
				char k = operation.Get();
				if (k == '(')
					break;
				polish.Put(k);
			}
		}
		else
		{
			while (!operation.IsEmpty())
			{
				t = operation.Get();
				if (GetPriority(exp[i]) <= GetPriority(t))
					polish.Put(t);
				else
				{
					operation.Put(t);
					break;
				}
			}
			operation.Put(exp[i]);
		}
		if (exp[i] == '=')
			break;
		i++;
	}
	int pos = polish.GetLen() + operation.GetLen();
	char * mem = new char[pos + 1];
	mem[pos] = '\0';
	mem[--pos] = '=';
	while (!polish.IsEmpty())
		mem[--pos] = polish.Get();
	return mem;
}

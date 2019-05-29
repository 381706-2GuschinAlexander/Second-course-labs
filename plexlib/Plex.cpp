#include "Plex.h"

Plex::Plex()
{
}

Plex::Plex(Plex & plex)
{
	lineList = plex.lineList;
}

Plex::~Plex()
{
}

Plex & Plex::operator+=(Line & line)
{
	TLink<Line>* tmp = lineList.GetFirstLink();
	if (tmp == NULL)
	{
		lineList.InsFirst(line);
		return *this;
	}
	else
	{
		while (tmp != NULL)
		{

			if (tmp->GetValue().GetA() == line.GetA() || tmp->GetValue().GetA() == line.GetB())
			{
				lineList.InsLast(line);
				return *this;
			}

			if (tmp == NULL)
				if (tmp->GetValue().GetB() == line.GetA() || tmp->GetValue().GetB() == line.GetB())
				{
					lineList.InsLast(line);
					return *this;
				}

			tmp = tmp->GetNextLink();
		}
	}
	throw(1);
}

bool Plex::DeleteLine(const Line & line)
{

	TLink<Line>* tmp = lineList.GetFirstLink();
	int count = 0;
	while (tmp != NULL)
	{
		if (tmp->GetValue() == line)
		{
			lineList.DelCustom(count);
			return true;
		}

		count++;
		tmp = tmp->GetNextLink();
	}
	return false;
}

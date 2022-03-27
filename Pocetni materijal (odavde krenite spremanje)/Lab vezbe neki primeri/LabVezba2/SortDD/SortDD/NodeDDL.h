#pragma once

class NodeDDL
{
public:

	int value;
	int prev;
	int next;
public:
	NodeDDl()
	{
		value=0;
		prev=-1;
		next=-1;
	}
	NodeDDL(int val)
	{
		value=val;
		prev=-1;
		next=-1;
	}
	NodeDDl(int val,int p,int n)
	{
		value=val;
		priv=p;
		next=n;
	}
};

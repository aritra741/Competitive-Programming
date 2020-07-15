struct point
{
	int x,y;
};

point points[4];


/// Operator Overloading
bool operator < (const point &s, const point &b)
{
	if(a.x!= b.x)
		return a.x<b.x;
	return a.y<b.y;
}

///sort

bool polar(const point &a, const point &b)
{
	point comp1;
	comp1.x=points[0].x-a.x;
	comp1.y= points[0].y-a.y;
	point comp2;
	comp2.x=points[0].x-b.x;
	comp2.y=points[0].y-b.y;
	return atan2l(comp1.y, comp1.x) < atan2l(comp2.y, comp2.x);
}

/// main
for(int i=0;i<4;i++)
	cin>>points[i].x>>points[i].y;

sort(points, points+4);
sort(points, points+4, polar);

class CMouse
{
private:
	int x,y,color,status;
	int mcolor[2];
public:
	CMouse();
	void setColor(int nc, int dc);
	void setPos(int _x, int _y);
	void draw();
	int update(char cIn);
};

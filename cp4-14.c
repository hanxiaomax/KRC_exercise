#define swap(t,x,y) { 	t _z;\
						_z=y;\
						y=x;\
						x=_z;}

/*swap(int,a,b)*/
/*{int _z;_z=a;a=b;b=_z;}*/

/*在调用该宏的时候，程序块展开，首先定义一个相应类型的变量 _z，再进行交换*/

#include <iostream>
using namespace std;
template <typename T>
class counter_ptr;
template <typename T>
class int_array_cell
{
private:
	int _counter;
	int* _memory;
public:
	int_array_cell()
	{
		_counter = 0;		//initialize counter = 0
		_memory = NULL;		// initialize _memory to NULL
	}
	int_array_cell(T* ptr) // 初始化，一個pointer指向記憶體位置
	{
		_counter = 1;		 //只有一個指標指
		_memory = ptr;		 //記憶體配置的位置存在_memory
		cout << "int_array_cell is allocated" << endl;
	}
	~int_array_cell()
	{
		delete[]_memory;	_memory = NULL;	//刪掉記憶體位置
	}

	void print_count() { cout << _counter << endl; }	//印counter的數值
	int get_counter() { return _counter; }	//回傳現在counter的數值
	void counter_minus_one() { _counter--; }	//一個指標移走時
	void counter_add_one() { _counter++; }		//多一個指標指向時
	void write_into_memory(T number, T index) { *(_memory + index) = number; }	//將DATA寫入記憶體位置
	int& operator[](T index) { return _memory[index]; }
};

template <typename T>
class counter_ptr
{
private:
	char* _name;
	int_array_cell<T>* _cell_ptr;
public:
	counter_ptr(const char* str)
	{
		_name = new char;	//配置名稱儲存位置
		*_name = *str;		//將名稱寫入
		_cell_ptr = new int_array_cell<T>;	//配置_cell_ptr，counter = 0, _memory = NULL
		if (_cell_ptr->get_counter() == 0)
			cout << "counter_ptr " << *_name << " is not assigned to an int_array_cell" << endl;	// not assigned to, yet
	}
	counter_ptr(const char* str, T* alloc)
	{
		_cell_ptr = new int_array_cell<T>(alloc);	//配置_cell_ptr，counter = 1, _memory = alloc的位置
		_name = new char;						//配置名稱儲存位置
		*_name = *str;							//將名稱寫入
		cout << "counter_ptr " << *_name << " is assigned to an int_array_cell: counter ";
		_cell_ptr->print_count();				//輸出counter 的數值
	}
	~counter_ptr()
	{
		this->_cell_ptr->counter_minus_one();	//指標移開後，所以減一
		cout << "counter_ptr " << *_name << " is deleted" << endl;	//	表示哪個指標被刪掉了
		if (this->_cell_ptr->get_counter() == 0)	//out of scope 時，該記憶體位置是否還有指標指向，若沒有
		{
			this->_cell_ptr->~int_array_cell();		//把該記憶體位置刪掉
			cout << "int_array_cell counter 0: deleted" << endl;
			this->_cell_ptr = NULL;
		}
		else if (this->_cell_ptr->get_counter() > 0)      // 若還有指標指向該記憶體位置，則輸出目前指標的數量
			cout << "int_array_cell counter is decreased: counter " << this->_cell_ptr->get_counter() << endl;
		delete _name;	//刪除_name記憶體位置
	}
	counter_ptr& operator= (T* alloc)		//設定 counter_ptr T = new int [100];
	{
		_cell_ptr->counter_minus_one();		//因為移走，所以要減一
		if (_cell_ptr->get_counter() == 0)	//若是0，表示要自動刪除記憶體位置
		{
			delete _cell_ptr;				//刪除_cell_ptr所配置的記憶體
			cout << "int_array_cell counter 0: deleted" << endl;
		}
		_cell_ptr = new int_array_cell<T>(alloc);	//配置新的記憶體位置(新指向的), counter initialize to 1
		cout << "counter_ptr " << *_name << " is assigned to an int_array_cell : counter ";
		_cell_ptr->print_count();				//輸出新指向的位置的指標個數
		return *this;
	}
	counter_ptr& operator= (counter_ptr& CP2)	//設定類似B = A 的這種計算的operator
	{
		if (this->_cell_ptr->get_counter() == 0)	//例如B原本就是指向NULL，未指向任何記憶體位置
		{
			this->_cell_ptr = CP2._cell_ptr;		//指向新的記憶體，此為A
			this->_cell_ptr->counter_add_one();		//新指到的記憶體位置的counter ++
			cout << "int_array_cell counter is increased: counter " << CP2._cell_ptr->get_counter() << endl;
			cout << "counter_ptr " << this->_name[0] << " is assigned to an int_array_cell: counter " << this->_cell_ptr->get_counter() << endl;
		}
		else if (this->_cell_ptr->get_counter() == 1)    //B所指的記憶體位置因為B移走而沒有任何指標指向，要執行自動刪除
		{
			this->_cell_ptr->counter_minus_one();		//將counter - 1 ，所以應該等於0
			this->_cell_ptr->~int_array_cell();			//釋放記憶體
			delete _cell_ptr;							//刪除_cell_ptr所配置的記憶體
			cout << "int_array_cell counter 0: deleted" << endl;
			this->_cell_ptr = CP2._cell_ptr;			//指向新的記憶體，此為A
		}
		else                               //counter - 1 後不為0
		{
			this->_cell_ptr->counter_minus_one();		//將counter - 1
			this->_cell_ptr = CP2._cell_ptr;			//指向新的記憶體，此為A
		}
		return *this;
	}
	counter_ptr& operator= (T number)
	{
		this->_cell_ptr->write_into_memory(number, number);		//寫資料到memory
		return *this;
	}
	int& operator[](T index)
	{
		return this->_cell_ptr->operator[](index);
	}
	void release()
	{
		_cell_ptr->counter_minus_one();	//該指標移走後，數值減一
		if (this->_cell_ptr->get_counter() != 0)	//移走後，還有其他指標，所以顯示現在的指標個數
			cout << "int_array_cell counter is decreased: counter " << _cell_ptr->get_counter() << endl;
		else
		{
			this->_cell_ptr->~int_array_cell();		//把該記憶體位置刪掉
			cout << "int_array_cell counter 0: deleted" << endl;
			_cell_ptr = NULL;
		}
		cout << "counter_ptr " << *_name << " is not assigned to an int_array_cell" << endl;
	}
};
int main()
{

	// PART 一  (40分)

	counter_ptr<int> b("b", new int[10]);
	// stdout 輸出: int_array_cell is allocated
	// stdout 輸出: counter_ptr b is assigned to an int_array_cell: counter 1

	{

		b = new int[100];
		// stdout 輸出: int_array_cell counter 0: deleted
		// stdout 輸出: int_array_cell is allocated
		// stdout 輸出: counter_ptr b is assigned to an int_array_cell: counter 1

		counter_ptr<int> a("a");
		// stdout 輸出: counter_ptr a is not assigned to an int_array_cell

		a = b;
		// stdout 輸出: int_array_cell counter is increased: counter 2
		// stdout 輸出: counter_ptr a is assigned to an int_array_cell: counter 2

	}
	// a leaves it scope:
	// stdout 輸出: counter_ptr a is deleted
	// stdout 輸出: int_array_cell counter is decreased: counter 1


// PART 二  (40分)

	for (int i = 0; i < 10; i++)
		b[i] = i;

	for (int i = 0; i < 10; i++)
		cout << b[i] << ' ';
	cout << endl;
	// stdout 輸出: 0 1 2 3 4 5 6 7 8 9

	counter_ptr<int> c("c");
	// stdout 輸出: counter_ptr c is not assigned to an int_array_cell

	c = b;
	// stdout 輸出: int_array_cell counter is increased: counter 2
	// stdout 輸出: counter_ptr c is assigned to an int_array_cell: counter 2

	b.release();
	// stdout 輸出: int_array_cell counter is decreased: counter 1
	// stdout 輸出: counter_ptr b is not assigned to an int_array_cell

}
// stdout 輸出: counter_ptr c is deleted
// stdout 輸出: int_array_cell counter 0: deleted
// stdout 輸出: counter_ptr b is deleted

/*
PART 三 (20分)
	1) 用 template 改寫 class counter_ptr
	2) 重覆 PART 一  二 的測試
*/

/*
PART 四 (20分)
用 template counter_ptr 寫 stack

1.	輸入資料為BIG5漢字(character)：
		BIG5內碼包含兩個位元組
		例子:
		我	內碼 (-89 -38)

2. 輸入資料功能：
用I開頭表示


3.	列印stack資料功能:
用P開頭表示


4.	列印stack料內碼功能:
用B開頭表示

	依照r順序將目前的資料的BIG5內碼列印出來
	例子:
	stack資料順序
	我是
	內碼列印 =>
	(-89 -38) (-84 79)

5.	拿一個資料
用R表示

6.	完全清除stack資料功能
用C表示

7. 查尋資料功能:
用?開頭表示
	查尋一個BIG5漢字是否在stack中：
	結果:	是		否


=======================================================================
test example
I 程式必須要能讀入測試檔
I 程式要徹底清除樹中資料使用的記憶體
? 程
? 體
R
? 程
? 體
P
B
C
P
I 程式要徹底清除樹中資料使用的記憶體
P
B
? 讀
=======================================================================


*/
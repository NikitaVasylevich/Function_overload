#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 4;

void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(int arr[ROWS][COLS], const int ROWS,const int COLS);
void FillRand(float frr[], const int m);
void FillRand(char crr[], const int s);
void OffsetLeft(int arr[], const int n);
void OffsetLeft(double arr[], const int n);	 /* Вопрос #1 к Олегу Анатольевичу :
											почему программа работает с обявлением "arr" конкретно здесь, после "double", 
											ведь в реализации прописан массив с именем "brr", и по логике следовало бы объявлять
											void OfsetLeft(double brr[], const int n) */
void OffsetLeft(float arr_l[], const int n);
void OffsetLeft(char arr[], const int n);
void OffsetRight(int arr[], const int n);
void OffsetRight(double arr[], const int n);
void OffsetRight(float arr[], const int n);
void OffsetRight(char arr[], const int n);

void Print(int arr[], const int n);
void Print(double arr[], const int n);
void Print(int arr[ROWS][COLS], const int ROWS,const int COLS);
void Print(float frr[], const int m);
void Print(char crr[], const int s);

void Sort(int arr[], const int n);
void Sort(double arr[], const int n);
void Sort(float frr[], const int m);
void Sort(char crr[], const int s);


int Sum(int arr[], const int n);
double Sum(double arr[], const int n);
float Sum(float frr[], const int m);
char Sum(char crr[], const int s);

double AVG(int arr[], const int n);
double AVG(double arr[], const int n);
float AVG(float frr[], const int m);
char AVG(char crr[], const int s);

int minValueIn(int arr[], const int n);
double minValueIn(double arr[], const int n);
float minValueIn(float frr[], const int m);
char minValueIn(char crr[], const int s);

int maxValueIn(int arr[], const int n);
double maxValueIn(double arr[], const int n);
float maxValueIn(float frr[], const int m);
char maxValueIn(char crr[], const int s);


void main()
{
	setlocale(LC_ALL, "Rus");
	const int n = 5;
	int arr[n];
	int arr_l[n];
	cout <<"\t\t" << "Реализация одномерного массива типа int:\n";
	FillRand(arr, n);
	Print(arr, n);
	Sort(arr, n);
	Print(arr, n);

	for (int i = 0; i < n; i++)		//так пришлось сделать, чтобы создать доп. массив (копию arr);
	{ 							// без этого получалось так, что операцией смещения вправо, смещался массив
		arr_l[i] = arr[i];		// который до этого смещался влево, а не отсортированный первоисточник arr
	}

	OffsetLeft(arr_l, n);
	OffsetRight(arr, n);
	cout << "Сумма элементов массива: "<< Sum(arr, n) << endl;
	cout << "Ср. арифм. элементов массива: "<< AVG(arr, n) << endl;
	cout << "Миним. знач. элементов массива: "<< minValueIn(arr, n) << endl;
	cout << "Макс. знач. элементов массива: "<< maxValueIn(arr, n) << endl<<endl;

	cout <<"\t\t" << "Реализация одномерного массива типа double:\n";
	const int SIZE = 8;
	double brr[SIZE];
	double brr_l[SIZE];
	FillRand(brr, SIZE);
	Print(brr, SIZE);
	Sort(brr, SIZE);
	Print(brr, SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		brr_l[i] = brr[i];
	}

	OffsetLeft(brr_l, SIZE);
	OffsetRight(brr, SIZE);
	cout << "Сумма элементов массива: "<< Sum(brr, SIZE) << endl;
	cout << "Ср. арифм. элементов массива: "<< AVG(brr, SIZE) << endl;
	cout << "Миним. знач. элементов массива: "<< minValueIn(brr, SIZE) << endl;
	cout << "Макс. знач. элементов массива: "<< maxValueIn(brr, SIZE) << endl<<endl;

	cout <<"\t\t" << "Реализация двухмерного массива:\n";
	cout << "Вывод на экран:\n";
	int i_arr_2[ROWS][COLS];
	FillRand(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);
	cout << endl;

	cout <<"\t\t" << "Реализация одномерного массива типа float:\n";
	const int m = 6;
	float frr[m];
	float frr_l[m];
	FillRand(frr, m);
	Print(frr, m);
	Sort(frr, m);
	Print(frr, m);

	for (int i = 0; i < m; i++)
	{
		frr_l[i] = frr[i];
	}

	OffsetLeft(frr_l, m);
	OffsetRight(frr, m);
	cout << "Сумма элементов массива: " << Sum(frr, m) << endl;
	cout << "Ср. арифм. элементов массива: " << AVG(frr, m) << endl;
	cout << "Миним. знач. элементов массива: " << minValueIn(frr, m) << endl;
	cout << "Макс. знач. элементов массива: " << maxValueIn(frr, m) << endl<<endl;

	cout <<"\t\t" << "Реализация одномерного массива типа char:\n";
	const int s = 7;
	char crr[s];
	char crr_l[s];
	FillRand(crr, s);
	Print(crr, s);
	Sort(crr, s);
	Print(crr, s);

	for (int i = 0; i < m; i++)
	{
		crr_l[i] = crr[i];
	}

	OffsetLeft(crr_l, s);
	OffsetRight(crr, s);
	cout << "Сумма элементов массива: " << Sum(crr, s) << endl;
	cout << "Ср. арифм. элементов массива: " << AVG(crr, s) << endl;
	cout << "Миним. знач. элементов массива: " << minValueIn(crr, s) << endl;
	cout << "Макс. знач. элементов массива: " << maxValueIn(crr, s) << endl << endl;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10000;
		arr[i] /= 100;
	}
}
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(float frr[], const int m)
{
	for (int i = 0; i < m; i++)
	{
		frr[i] = rand() % 1000;
		frr[i] /= 10;
	}
}
void FillRand(char crr[], const int s)
{
	for (int i = 0; i < s; i++)
	{
		crr[i] = rand() % 1000;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}
	cout << endl;
	}
}
void Print(float frr[], const int m)
{
	for (int i = 0; i < m; i++)
	{
		cout << frr[i] << "\t";
	}
	cout << endl;
}
void Print(char crr[], const int s)
{
	for (int i = 0; i < s; i++)
	{
		cout << crr[i] << "\t";
	}
	cout << endl;
}

void Sort(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				int bufer = arr[i];
				arr[i] = arr[j];
				arr[j] = bufer;
			}
		}
	}
}
void Sort(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				double bufer = arr[i];
				arr[i] = arr[j];
				arr[j] = bufer;
			}
		}
	}
}
void Sort(float frr[], const int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (frr[j] < frr[i])
			{
				float bufer = frr[i];
				frr[i] = frr[j];
				frr[j] = bufer;
			}
		}
	}
}
void Sort(char crr[], const int s)
{
	for (int i = 0; i < s; i++)
	{
		for (int j = i + 1; j < s; j++)
		{
			if (crr[j] < crr[i])
			{
				float bufer = crr[i];
				crr[i] = crr[j];
				crr[j] = bufer;
			}
		}
	}
}

int Sum(int arr[], const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}
double Sum(double arr[], const int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}
float Sum(float frr[], const int m)
{
	float sum = 0;
	for (int i = 0; i < m; i++)
	{
		sum += frr[i];
	}
	return sum;
}
char Sum(char crr[], const int s)
{
	char sum = 0;
	for (int i = 0; i < s; i++)
	{
		sum += crr[i];
	}
	return sum;
}

double AVG(int arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
double AVG(double arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
float AVG(float frr[], const int m)
{
	return (float)Sum(frr, m) / m;
}
char AVG(char crr[], const int s)
{
	return (float)Sum(crr, s) / s;
}
int minValueIn(int arr[], const int n)
{
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}
double minValueIn(double arr[], const int n)
{
	double min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}
float minValueIn(float frr[], const int m)
{
	float min = frr[0];
	for (int i = 0; i < m; i++)
	{
		if (frr[i] < min)
		{
			min = frr[i];
		}
	}
	return min;
}
char minValueIn(char crr[], const int s)
{
	char min = crr[0];
	for (int i = 0; i < s; i++)
	{
		if (crr[i] < min)
		{
			min = crr[i];
		}
	}
	return min;
}
int maxValueIn(int arr[], const int n)
{
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
double maxValueIn(double arr[], const int n)
{
	double max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
float maxValueIn(float frr[], const int m)
{
	float max = frr[0];
	for (int i = 0; i < m; i++)
	{
		if (frr[i] > max)
		{
			max = frr[i];
		}
	}
	return max;
}
char maxValueIn(char crr[], const int s)
{
	char max = crr[0];
	for (int i = 0; i < s; i++)
	{
		if (crr[i] > max)
		{
			max = crr[i];
		}
	}
	return max;
}

void OffsetLeft(int arr_l[], const int n)
{
	int t = 0;
	const int q = 5; /* Вопрос #2 к Олегу Анатольевичу: как можно связать значения "q" и "b",
					 чтобы значение "q" по умолчанию принималось равным "n" 
					 Например: хотел записать "const int q = n" - но тогда функция не работает */
	int ar2[q];
	cout << "Введите значение смещения отсортированного массива влево: "; cin >> t;
	for (int i = 0; i < q; i++)
	{
		ar2[i] = arr_l[i];
	}
	for (int i = 0; i < n - t; i++)
	{
		arr_l[i] = arr_l[i + t];
	}
	for (int i = n - t; i < n; i++)
	{
		arr_l[i] = ar2[i-n+t];
	}
	cout << "Вывод смещенного массива: \n";
	for (int i = 0; i < n; i++)
	{
		cout << arr_l[i] << "\t";
	}
	cout << endl;
}

void OffsetLeft(double brr_l[], const int n)
{
	int t = 0;
	const int q = 8;
	double ar2[q];
	cout << "Введите значение смещения отсортированного массива влево: "; cin >> t;
	for (int i = 0; i < q; i++)
	{
		ar2[i] = brr_l[i];
	}
	for (int i = 0; i < n - t; i++)
	{
		brr_l[i] = brr_l[i + t];
	}
	for (int i = n - t; i < n; i++)
	{
		brr_l[i] = ar2[i - n + t];
	}
	cout << "Вывод смещенного массива: \n";
	for (int i = 0; i < n; i++)
	{
		cout << brr_l[i] << "\t";
	}
	cout << endl;
}

void OffsetLeft(float frr_l[], const int n)
{
	int t = 0;
	const int q = 6;
	float ar2[q];
	cout << "Введите значение смещения отсортированного массива влево: "; cin >> t;
	for (int i = 0; i < q; i++)
	{
		ar2[i] = frr_l[i];
	}
	for (int i = 0; i < n - t; i++)
	{
		frr_l[i] = frr_l[i + t];
	}
	for (int i = n - t; i < n; i++)
	{
		frr_l[i] = ar2[i - n + t];
	}
	cout << "Вывод смещенного массива: \n";
	for (int i = 0; i < n; i++)
	{
		cout << frr_l[i] << "\t";
	}
	cout << endl;
}

void OffsetLeft(char crr_l[], const int n)
{
	int t = 0;
	const int q = 7;
	char ar2[q];
	cout << "Введите значение смещения отсортированного массива влево: "; cin >> t;
	for (int i = 0; i < q; i++)
	{
		ar2[i] = crr_l[i];
	}
	for (int i = 0; i < n - t; i++)
	{
		crr_l[i] = crr_l[i + t];
	}
	for (int i = n - t; i < n; i++)
	{
		crr_l[i] = ar2[i - n + t];
	}
	cout << "Вывод смещенного массива: \n";
	for (int i = 0; i < n; i++)
	{
		cout << crr_l[i] << "\t";
	}
	cout << endl;
}

void OffsetRight(int arr[], const int n)
{
	int t = 0;
	const int q = 5;
	int ar2[q];
	cout << "Введите значение смещения отсортированного массива вправо: "; cin >> t;
	for (int i = 0; i < q; i++)
	{
		ar2[i] = arr[i];
	}
	for (int i = 0; i <t; i++)
	{
		arr[i] = ar2[n-t+i];
	}
	for (int i = t; i < n; i++)
	{
		arr[i] = ar2[i-t];
	}
	cout << "Вывод смещенного массива: \n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void OffsetRight(double brr[], const int n)
{
	int t = 0;
	const int q = 8;
	double ar2[q];
	cout << "Введите значение смещения отсортированного массива вправо: "; cin >> t;
	for (int i = 0; i < q; i++)
	{
		ar2[i] = brr[i];
	}
	for (int i = 0; i < t; i++)
	{
		brr[i] = ar2[n - t + i];
	}
	for (int i = t; i < n; i++)
	{
		brr[i] = ar2[i - t];
	}
	cout << "Вывод смещенного массива: \n";
	for (int i = 0; i < n; i++)
	{
		cout << brr[i] << "\t";
	}
	cout << endl;
}

void OffsetRight(float frr[], const int n)
{
	int t = 0;
	const int q = 6;
	float ar2[q];
	cout << "Введите значение смещения отсортированного массива вправо: "; cin >> t;
	for (int i = 0; i < q; i++)
	{
		ar2[i] = frr[i];
	}
	for (int i = 0; i < t; i++)
	{
		frr[i] = ar2[n - t + i];
	}
	for (int i = t; i < n; i++)
	{
		frr[i] = ar2[i - t];
	}
	cout << "Вывод смещенного массива: \n";
	for (int i = 0; i < n; i++)
	{
		cout << frr[i] << "\t";
	}
	cout << endl;
}

void OffsetRight(char crr[], const int n)
{
	int t = 0;
	const int q = 7;
	char ar2[q];
	cout << "Введите значение смещения отсортированного массива вправо: "; cin >> t;
	for (int i = 0; i < q; i++)
	{
		ar2[i] = crr[i];
	}
	for (int i = 0; i < t; i++)
	{
		crr[i] = ar2[n - t + i];
	}
	for (int i = t; i < n; i++)
	{
		crr[i] = ar2[i - t];
	}
	cout << "Вывод смещенного массива: \n";
	for (int i = 0; i < n; i++)
	{
		cout << crr[i] << "\t";
	}
	cout << endl;
}
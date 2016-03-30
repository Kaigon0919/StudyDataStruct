#include"SingleList.h"
void ShowList(SingleList * ref)
{
	for (int i = 0; i < ref->Length(); ++i)
		cout << ref->Search(i) << ", ";
	cout << endl<<  "=========================" << endl;;
}
void main()
{
	SingleList a;

	a.Add(10);
	a.Add(2);
	a.Add(4);
	ShowList(&a);


	a.Add(3, 3);
	ShowList(&a);

	a.Delete(1);
	cout << "Index :1 , delete" << endl;
	ShowList(&a);

	a.Add(5);
	a.Add(6);
	ShowList(&a);
	
	a.Delete(3);
	cout << "Index :3 , delete" << endl;

	ShowList(&a);
	cout << endl;
}
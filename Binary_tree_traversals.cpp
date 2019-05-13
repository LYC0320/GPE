#include <iostream>
#include <vector>

using namespace std;

void printPost(int start, int end, vector<char> &preorder, vector<char> &inorder, int arrNum, bool first)
{
	if (start > end)
		return;

	if (start == end)
	{
		if (arrNum == 1)
			cout << inorder[start] << endl;
		else
			cout << inorder[start] << " ";
		return;
	}

	int myMin = 27;
	int mid = 0;
	for (int i = start; i <= end; i++)
	{
		char tmp = inorder[i];
		for (int j = start; j < arrNum; j++)
		{
			if (tmp == preorder[j])
			{
				if (myMin > j)
				{
					mid = i;
					myMin = j;
				}
			}
		}
	}


	printPost(start, mid - 1, preorder, inorder, arrNum, false);
	printPost(mid + 1, end, preorder, inorder, arrNum, false);

	if (first)
		cout << inorder[mid] << endl;
	else
		cout << inorder[mid] << " ";
}

int main()
{
	int dataNum;
	cin >> dataNum;

	for (int k = 0; k < dataNum; k++)
	{
		int arrNum;
		cin >> arrNum;

		vector<char> preorder(arrNum, ' ');
		vector<char> inorder(arrNum, ' ');

		cin.ignore();


		string tmp;
		getline(cin, tmp);

		int index = 0;
		for (int i = 0; i < tmp.size(); i++)
		{
			if (tmp[i] == ' ')
				continue;

			preorder[index] = tmp[i];
			index++;
		}

		getline(cin, tmp);

		index = 0;
		for (int i = 0; i < tmp.size(); i++)
		{
			if (tmp[i] == ' ')
				continue;

			inorder[index] = tmp[i];
			index++;
		}

		int s = 0, e = arrNum - 1;
		bool first = true;
		printPost(s, e, preorder, inorder, arrNum, first);
	}
}
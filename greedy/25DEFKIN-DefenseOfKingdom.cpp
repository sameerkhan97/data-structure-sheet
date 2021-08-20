/*  ~~~~~Question Link :  https://www.spoj.com/problems/DEFKIN/ 
Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular
 grid of cells. The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column.
 No two towers share a row or a column.The penalty of the position is the number of cells in the largest undefended rectangle. For example, 
 the position shown on the picture has penalty 12.This position has a penalty of 12.Help Theodore write a program that calculates the penalty
 of the given position.

Input : The first line of the input file contains the number of test cases.Each test case consists of a line with three integer numbers: 
w — width of the grid, h — height of the grid and n — number of crossbow towers (1 ≤ w, h ≤ 40 000; 0 ≤ n ≤ min(w, h)).
Each of the following n lines contains two integer numbers xi and yi — the coordinates of the cell occupied by a tower (1 ≤ xi ≤ w; 1 ≤ yi ≤ h).

Output : For each test case, output a single integer number — the number of cells in the largest rectangle that is not defended by the towers.

Example
Input:
15 8 3
3 8
11 2
8 6

Output:
12
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,w,h;
	cout<<"\nEnter width,height & number of towers ";
	cin>>w>>h>>n;
	//for storing x coordinates of tower
	vector<int> a;
	//for storing y coordinates of tower
	vector<int> b;
	a.push_back(0);
	b.push_back(0);
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		a.push_back(x);
		b.push_back(y);
	}
	a.push_back(w+1);
	b.push_back(h+1);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int mx=INT_MIN,my=INT_MIN;
	for(int i=0;i<a.size()-1;i++){
		mx=max(mx,a[i+1]-a[i]-1);	//finding maximum horizontal distance between 2 towers
		my=max(my,b[i+1]-b[i]-1);   //finding maximum vertical distance between 2 towers
	}
	//multiplying max horizontal and vertical distance to get area of biggest undefended site
	cout<<"\n"<<mx*my;
	
}
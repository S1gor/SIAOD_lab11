#include "Graph.h"

/*� ����������� ������ ������������� ������� ����������� ����� ����� ����������,
����������� � �������� �������� ������� � ���c�������� �� ������������ �� ����� 1000 ���������.
������ ������� ����� ����� ���� �� ����� ��� ������������, ��� � �������� �������������.
������� � ������ �������� ����� ������������ �� ������ ����� ������������ ����� ������������� ���������.
� ��� ������, ����� ��� �������� ���������� � ���� �������������� � ��� ������� �� ����� ����, �� ����� ��������� ��������������� ����������.
��������������� ������� ��������� ���������� �� ���������. ���������� ����������� ����� �� ������ � ��������
�������� ����� ���� �������� ��������� � ����������� ������ ������������� �������.*/

int main()
{
	vector<Edge> edges = { {0, 1}, {1, 2}, {2, 0}, {3, 2}, {4, 5}, {5, 4}, {2, 1}, {2,5}, {0,3} };
	int size = 6;
	
	Graph graph(edges, size);

	LoopGraph(graph, size);

	return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
int h1,h2,k;
int cnt = 0;
string s;
// ��������ĳ�ڵ����ڲ��� = ���ڵ��ڶ������в��� + �˽ڵ�Ϊ�丸�ڵ�ڼ������ӽڵ�
void calc(int l1, int l2, int son)
{
    int tson = 0; // ���㵱ǰ�㣬�ڵ��ǵڼ�������
    while(s[k] == 'd')
    {
        k++; tson++; // ���ӽڵ���ż�һ
        calc(l1+1,l2+tson,tson);
    }
    h1 = max(h1,l1); // ����Ϊ������
    h2 = max(h2,l2);
    k++; // ���˵�u������
}
int main()
{
    cin >> s;
    while(s[0] != '#')
    {
        k = h1 = h2 = 0;
        calc(0,0,1);
        cout << "Tree " << ++cnt << ": " << h1 << " => " << h2 << endl;
        cin >> s;
    }
}

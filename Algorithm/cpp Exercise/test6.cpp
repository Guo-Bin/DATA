#include <iostream>
#include <cstdio>
using namespace std;
int h1,h2,k;
int cnt = 0;
string s;
// 二叉树中某节点所在层数 = 父节点在二叉树中层数 + 此节点为其父节点第几个孩子节点
void calc(int l1, int l2, int son)
{
    int tson = 0; // 计算当前层，节点是第几个孩子
    while(s[k] == 'd')
    {
        k++; tson++; // 孩子节点序号加一
        calc(l1+1,l2+tson,tson);
    }
    h1 = max(h1,l1); // 树高为最大层数
    h2 = max(h2,l2);
    k++; // 过滤掉u，回溯
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

//��ʶ�߾��� 
#include <stdio.h>
#include <string.h>

struct num {
	char s[101];
	int ls;
};
struct num a[20];

int main()
{
	int n,flag = 0;
	scanf("%d",&n); //����������n 
	//����Ʊ�� 
	for(int i = 0; i < n; i++) {
		scanf("%s",&a[i].s);
		a[i].ls = strlen(a[i].s);
	}
	//ȡ��һ�� 
	int t = 0;
	//�ӵڶ�����ʼ���� 
	for(int i = 1; i < n; i++) {
		if(a[t].ls < a[i].ls) t = i; //λ��С�������±� 
		else if(a[t].ls == a[i].ls){ //λ����ȣ����ж� 
			//���λ���ж� 
			for(int j = 0; j < a[t].ls; j++) { 
				if(a[t].s[j]-'0' > a[i].s[j]-'0'){
					flag = 1;//t������ 
					break;
				} else if(a[t].s[j]-'0' < a[i].s[j]-'0') {
					break;
				}
			}
			//�ж�������˳�ѭ�� 
			if(flag == 1){
				flag = 0;
				continue;
			} else if(flag == 0) t = i;//����t 
		}
		else if(a[t].ls > a[i].ls) continue;
	}
	printf("%d\n",t+1);
	printf("%s",a[t].s);
	return 0;
}


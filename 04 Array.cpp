#include <iostream>
using namespace std;

#include <cmath>
#include <algorithm>

int main(){
	
	// ���飬�����ͬ����Ԫ�صļ��ϡ�
	// 1. ÿ��Ԫ�ض�������ͬ����������
	// 2. ���������ڴ�ռ���ɵ�
	
	// ���巽ʽ
	// 1. �������� ������[���鳤��];
	/*
	int arr0[5];
	arr0[0] = 0;
	arr0[1] = 1;
	arr0[2] = 2;
	arr0[3] = 3;
	arr0[4] = 4;
	*/
	// 2. �������� ������[���鳤��] = {Ԫ��1, Ԫ��2 ...};
	// int arr1[5] = {0, 1, 2, 3, 4};
	// 3. �������� ������[] = {Ԫ��1, Ԫ��2 ...};
	int arr2[] = {0, 1, 2};
	
	
	//! һά������������������
	// 1. ����ͳ���������ڴ��еĳ���
	cout << "����ռ���ڴ�ռ�Ϊ��" << sizeof(arr2) << endl;
	cout << "������ÿ��Ԫ��ռ���ڴ�ռ�Ϊ��" << sizeof(arr2[0]) << endl;
	cout << "������Ԫ�ظ���Ϊ��" << sizeof(arr2) / sizeof(arr2[0]) << endl;
	
	// 2. ���ڻ�ȡ������׵�ַ
	cout << "�����׵�ַΪ��" << arr2 << endl;
	// ʹ��&�鿴�����ĵ�ַ 
	cout << "�����һ��Ԫ�ص��׵�ַΪ��" << &arr2[0] << endl;
	cout << "����ڶ���Ԫ�ص��׵�ַΪ��" << &arr2[1] << endl;
	
	// ��������һ���������������������׵�ַ�������Խ����޸�
	
	
	// ��ϰ1
	// �ҳ������е����ֵ
	
	int arr_lianxi[] = {1, 3, 2, 5, 4};
	int maxx = arr_lianxi[0];
	for(int i =1; i<(int)(sizeof(arr_lianxi)/sizeof(arr_lianxi[0])); i++){
		if(maxx < arr_lianxi[i]){
			maxx = arr_lianxi[i];
		}
	}
	cout << "���ֵ�ǣ�" << maxx << endl;
	
	// ʹ��algorithmͷ�ļ��е�max_element������������ֵ����
	int n = sizeof(arr_lianxi)/sizeof(arr_lianxi[0]);
	int* max_iter = max_element(arr_lianxi, arr_lianxi+n);
	cout << "���ֵ�ǣ�" << *max_iter << endl;
	
	// ��ϰ2����������
	for(int i=0; i<n/2; i++){
		// ʹ��swap������������ֵ
		swap(arr_lianxi[i], arr_lianxi[n-i-1]);
		
		// a=a+b; a=a-b; a=a-b;
		//arr_lianxi[i] = arr_lianxi[i] + arr_lianxi[n-i-1];
		//arr_lianxi[n-i-1] = arr_lianxi[i] - arr_lianxi[n-i-1];
		//arr_lianxi[i] = arr_lianxi[i] - arr_lianxi[n-i-1];
	}
	
	for(int i=0;i<n;i++){
		cout << arr_lianxi[i] << endl;
	}
	
	cout << "----ð������----" <<  endl;
	// ��ϰ3�� ð������
	// ���ѭ��i<n���ڲ�ѭ��j<n-i-1������j>j+1(����) j<j+1(����)
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1-i; j++){
			if(arr_lianxi[j]>arr_lianxi[j+1]){
				swap(arr_lianxi[j], arr_lianxi[j+1]);
			}
		}
	}
	
	for(int i=0;i<n;i++){
		cout << arr_lianxi[i] << endl;
	}
	
	
	// ��ά����
	cout << "-------��ά����-------" << endl;
	// ���巽ʽ
	// 1. �������� ������[����][����];
	int arr_2wei0[2][2];
	arr_2wei0[0][0]=1;
	arr_2wei0[0][1]=2;
	arr_2wei0[1][0]=3;
	arr_2wei0[1][1]=4;
	cout << arr_2wei0[0][0] << endl;
	// 2. �������� ������[����][����] = {{��һ������}, {�ڶ�������}};
	// int arr_2wei1[2][2] = {{1, 2}, {3, 4}};
	// 3. �������� ������[����][����] = {����1, ����2 ...};
	// int arr_2wei2[2][2] = {1, 2, 3, 4};
	// 4. �������� ������[][����] = {����1, ����2 ...};
	int arr_2wei3[][2] = {1, 2, 3, 4};
	
	// ע�⣺�����Ǳ���ģ�������ʡ��
	
	//! ��ά���������������
	// 1. �鿴��ά������ռ�ռ�λ��
	cout << "��ά����ռ���ڴ�ռ�Ϊ��" << sizeof(arr_2wei3) << endl;
	cout << "��ά����һ��ռ���ڴ�ռ�Ϊ��" << sizeof(arr_2wei3[0]) << endl;
	cout << "��ά����һ��Ԫ��ռ���ڴ�ռ�Ϊ��" << sizeof(arr_2wei3[0][0]) << endl;
	
	cout << "��ά��������Ϊ��" << sizeof(arr_2wei3)/sizeof(arr_2wei3[0]) << endl;
	cout << "��ά��������Ϊ��" << sizeof(arr_2wei3[0])/sizeof(arr_2wei3[0][0]) << endl;
	// 2. ��ά�����׵�ַ
	cout << "��ά������׵�ַΪ��" << arr_2wei3 << endl;
	cout << "��ά�����һ�е��׵�ַΪ��" << &arr_2wei3[0] << endl;
	
	system("pause");
	return 0;
}

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const double INFINITE = 1000;
double x, y, pminx = INFINITE, pminy = INFINITE, pmaxx = 0, pmaxy = 0, nminx = 0, nminy = 0, nmaxx = INFINITE, nmaxy = INFINITE;
int mode, label; //label:�����1,�����0;

int main(){
//�w�K��
	cout << "�����`�w�K�Q�[��" <<endl;
	cout << "x���W, y���W, ���Ⴉ���Ⴉ�̏��ɓ��͂��Ă�������" <<endl;
	cout << "x, y�ɂ�1000�ȉ��̐��̎�������͂�, �����1, �����0�ŕ\���Ă�������" <<endl;
	cout << "ex) 2.2 4.8 1" <<endl;
	cout << "�w�K���I���������ꍇ�͕��̐������Ă�������" <<endl;
	ifstream ifs;
	ifs.open("test.txt");
	while(1){ 
		ifs >> x >> y >> label;
		//cout << x << " " << y << " " << label << endl;

		if(x < 0 || y < 0 || (label != 0 && label != 1)) break;
		if(label == 1){	
			if(x < pminx) pminx = x;
			if(x > pmaxx) pmaxx = x;
			if(y < pminy) pminy = y;
			if(y > pmaxy) pmaxy = y;
		}
	}
	ifs.close();
	ifs.open("test.txt");
	while(1){
		ifs >> x >> y >> label;
		if(x < 0 || y < 0 || (label != 0 && label != 1)) break;
		if(label == 0){
			if(x < pminx && x > nminx) nminx = x;
			if(x > pmaxx && x < nmaxx) nmaxx = x;
			if(y < pminy && y > nminy) nminy = y;
			if(y > pmaxy && y < nmaxy) nmaxy = y;
		}
	}
	ifs.close();
	ofstream ofs;
	ofs.open( "result.txt" );
	ofs << "pminx = " << pminx << endl;
	ofs << "pminy = " << pminy << endl;
	ofs << "pmaxx = " << pmaxx << endl;
	ofs << "pmaxy = " << pmaxy << endl;
	ofs << "nminx = " << nminx << endl;
	ofs << "nminy = " << nminy << endl;
	ofs << "nmaxx = " << nmaxx << endl;
	ofs << "nmaxy = " << nmaxy << endl;
	ofs.close();

//�w�K���ʂ̔�I
	cout << "�w�K���ʂ��I���܂�" <<endl;
	cout << "pminx = " << pminx << endl;
	cout << "pminy = " << pminy << endl;
	cout << "pmaxx = " << pmaxx << endl;
	cout << "pmaxy = " << pmaxy << endl;
	cout << "nminx = " << nminx << endl;
	cout << "nminy = " << nminy << endl;
	cout << "nmaxx = " << nmaxx << endl;
	cout << "nmaxy = " << nmaxy << endl;
	cout << "�S�Ă̐���ɑ΂��ĊԈ��Ȃ��ꍇ��0��" <<endl;
	cout << "�S�Ă̕���ɑ΂��ĊԈ��Ȃ��ꍇ��1����͂��Ă�������" <<endl;
	while(1){
		cin >> mode;
		if(mode ==0 || mode == 1) break;
		else cout << "���������͂��Ă�������" <<endl;
	}
	if(mode == 0) cout << "����ɑ΂��ĕK�����������x����Ԃ��܂�" <<endl;
	if(mode == 1) cout << "����ɑ΂��ĕK�����������x����Ԃ��܂�" <<endl;
	cout << "x���W, y���W�̏��ɓ��͂��Ă�������" <<endl;
	cout << "x, y�ɂ�1000�ȉ��̐��̎�������͂��Ă�������" <<endl;
	cout << "ex) 2.9 9.8" <<endl;
	cout << "��I���I���������ꍇ�͕��̐������Ă�������" <<endl;
	while(1){
		cin >> x >> y;
		if(x < 0 || y < 0) break;
		if(mode == 0){
			if(x <= nmaxx && x >= nminx && y <= nmaxy && y >= nminy) cout << "���x����\"��\"�ł�" <<endl;
			else cout << "���x����\"��\"�ł�" <<endl;
		}
		else if(mode == 1){
			if(x <= pmaxx && x >= pminx && y <= pmaxy && y >= pminy) cout << "���x����\"��\"�ł�" <<endl;
			else cout << "���x����\"��\"�ł�" <<endl;
		}
	}
}